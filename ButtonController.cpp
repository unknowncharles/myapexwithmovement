#pragma once
#include <iostream>
#include "Utils.cpp"
#include "Memory.cpp"
#include "Offsets.cpp"

class ButtonController
{
public:
    class KButton
    {
    public:
        int down[2];
        int state;
    };

    class InState
    {
    public:
        // The raw button state.
        KButton button;

        // True if the button is held down.
        bool state;
        // Set to true if the button should be overriden.
        bool force;
        // Force the button to be pressed.
        bool press;
        // Force the button to be released.
        bool release;

        void update(long address)
        {
            // Read the current button state from game memory.
            mem::Read(address, &button, sizeof(KButton));
            
            // Update the "state" field based on the "down" array.
            state = (button.state & 1) != 0;
        }

        void post(long address)
        {
            // printf("adrress: %ld\n", address);
            //  mem::Write(address + 8, &state, sizeof(int));
            // mem::WriteInt(address,  1);
            // Write the updated button state to game memory.
            if (force && mem::Read(address, &button, sizeof(KButton)))
            {
                // Get the desired state of the button
                int state;

                if (press && !release)
                {
                    state = 5;
                }
                else if (!press && release)
                {
                    state = 4;
                }
                else
                {

                    state = button.down[0] == 0 && button.down[1] == 0 ? 4 : 5;
                }
                // Gently tell the game to that nobody will be harmed if they just do as told
                if (button.state != state)
                {
                    mem::Write(address + 8, &state, sizeof(int));
                }
            }
        }
    };
    // The "forward" button state.
    InState forward;

    ButtonController()
    {
        // Initialize the "forward" button state with default values.
        forward = InState{};
    }
};
