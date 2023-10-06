#include "Utils.cpp"
#include "Memory.cpp"
#include "ButtonController.cpp"

class Movement
{
private:
    long ptrLongForward;
    long ptrLongFlags;
    long m_basePointer = 0;
    bool didPrevMove;
     ButtonController buttonController;

    long getUnresolvedBasePointer()
    {
        long unresolvedBasePointer = offsets::REGION + offsets::LOCAL_PLAYER;
        return unresolvedBasePointer;
    }
    long getBasePointer()
    {
        if (m_basePointer == 0)
            m_basePointer = mem::ReadLong(getUnresolvedBasePointer());
        return m_basePointer;
    }

public:
    Movement()
    {
        long basePointer = getBasePointer();
        ptrLongForward = offsets::REGION + offsets::OFFSET_IN_FORWARD;
        ptrLongFlags = offsets::REGION + offsets::OFFSET_FLAGS;
    }

    bool isMovingForward()
    {
        long basePointer = getBasePointer();
        long ptrLong = offsets::REGION + offsets::OFFSET_IN_FORWARD;
        int result = mem::ReadInt(ptrLong);
        return result > 0;
    }

    bool isOnGround()
    {
        long basePointer = getBasePointer();
        long ptrLong = basePointer + offsets::OFFSET_FLAGS;
        int result = mem::ReadInt(ptrLong);
        return (result & 0x1) != 0;
    }

    void update()
    {
        buttonController.forward.update(ptrLongForward);

        if (!isOnGround())
        {
          buttonController.forward.force = true;
                
            if (!buttonController.forward.release)
            {
                buttonController.forward.press = false;
                buttonController.forward.release = true;
            }
            else
            {
                buttonController.forward.release = false;
                buttonController.forward.press = true;
            }
        }
        else
        { // prevent stopping when hit the ground
            if (buttonController.forward.release && buttonController.forward.button.down[0] != 0)
            {
                buttonController.forward.release = false;
                buttonController.forward.press = true;
            }
            else if (buttonController.forward.press && buttonController.forward.button.down[0] != 0)
            {
                buttonController.forward.force = false;
            }
            else if (buttonController.forward.press && buttonController.forward.button.down[0] == 0)
            {
                buttonController.forward.release = true;
                buttonController.forward.press = false;
            }
            else if (buttonController.forward.release && buttonController.forward.button.down[0] == 0)
            {
                buttonController.forward.force = false;
            }
        }
        buttonController.forward.post(ptrLongForward);

    }
};