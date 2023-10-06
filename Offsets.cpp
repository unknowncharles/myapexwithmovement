

    #pragma once
    namespace offsets
    {
        // buttons
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        constexpr long IN_ATTACK = (0x07420848);            // [Buttons] -> in_attack
        const long OFFSET_FLAGS	= 0x00c8;
        const long OFFSET_IN_FORWARD= 0x07420798;
    // core
        
        // core !
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        constexpr long REGION = 0x140000000;              // [Mine]          -> Region                                                      // i have no idea?
        constexpr long LEVEL = 0x16f51c0;                 // ! [Miscellaneous] -> LevelName
        constexpr long LOCAL_PLAYER = 0x21d1738;      // ! [Miscellaneous] -> AVC_GameMovement+0x8
        constexpr long ENTITY_LIST = 0x1e213f8;           // ! [Miscellaneous] -> cl_entitylist
        // entity
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        constexpr long LOCAL_ORIGIN = 0x0188; // ! [DataMap.CBaseViewModel]    -> m_localOrigin
        // player
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        constexpr long GLOW_ENABLE = 0x294;              // ! [RecvTable.DT_HighlightSettings] -> m_highlightServerContextID + 0x8            //unsure
        constexpr long GLOW_THROUGH_WALL = 0x278;               // ! [RecvTable.DT_HighlightSettings] -> m_highlightServerContextID + 0x10    //unsure
        constexpr long GLOW_COLOR = 0x1D0;                  // ! [Miscellaneous]                  -> glow_color                               //didnt find
        constexpr long TEAM_NUMBER = 0x037c;                // ! [RecvTable.DT_BaseEntity]        -> m_iTeamNum
        constexpr long NAME = 0x04b9;                       // ! [RecvTable.DT_BaseEntity]        -> m_iName
        constexpr long LIFE_STATE = 0x06c8;                 // ! [RecvTable.DT_Player]            -> m_lifeState
        constexpr long VEC_PUNCH_WEAPON_ANGLE = 0x23f8;     // ! [DataMap.C_Player]               -> m_currentFrameLocalPlayer.m_vecPunchWeapon_Angle
        constexpr long VIEW_ANGLE = (0x24f4 - 0x14);        // ! [DataMap.C_Player]               -> m_ammoPoolCapacity - 0x14
        constexpr long BLEEDOUT_STATE = 0x26a0;             // ! [RecvTable.DT_Player]            -> m_bleedoutState
        constexpr long ZOOMING = 0x1b91;                    // ! [RecvTable.DT_Player]            -> m_bZooming
        constexpr long LAST_VISIBLE_TIME = 0x19b0;          // ! [Miscellaneous]                  -> CPlayer!lastVisibleTime                  //unsure
        constexpr long CURRENT_SHIELDS = 0x01a0;            // ! m_shieldHealth
        constexpr long CURRENT_HEALTH = 0x036c;                  // m_iHealth
        constexpr long ARMOR_TYPE = 0x45c4;             // ! m_armorType
        constexpr long OFFSET_ViewModels = 0x2ce0;         // ! m_hViewModels
        constexpr long thirdperson_override = 0x01db0f50;          // !m_thirdPersonOverride                                                 // really unsure
        constexpr long m_thirdPersonShoulderView = 0x3650;    // !m_thirdPersonShoulderView
    }
