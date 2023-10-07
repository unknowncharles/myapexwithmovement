#include "Utils.cpp"
#include "Memory.cpp"
#include "LocalPlayer.cpp"
#include "ButtonController.cpp"

class Movement
{
private:
    long ptrLongForward;
    LocalPlayer *m_localPlayer;
    ButtonController buttonController;


public:
 Movement(LocalPlayer *localPlayer)
    {
        ptrLongForward = offsets::REGION + offsets::OFFSET_IN_FORWARD;
        m_localPlayer = localPlayer;
    }
   
    void update()
    {
        buttonController.forward.update(ptrLongForward);
         
        if (!m_localPlayer->isOnGround() && !m_localPlayer->isSkyDiving())
        {
             if(!m_localPlayer-> isMovingForward()){
                buttonController.forward.force = true;
        }
        else{
            buttonController.forward.force = true;
        }
        
                
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








 