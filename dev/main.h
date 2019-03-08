#ifndef __MAIN__
#define __MAIN__

#include <stdbool.h>
//#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

// disable warning 110: conditional flow changed by optimizer : so said EVELYN the modified DOG.
// SDCC may emil this compiler warning for certain calculations involving int or float data type
// This is just a warning so can be disbled; often replacing data type with unsigned char works!
//#ifdef _CONSOLE
//#else
//	#pragma disable_warning 110
//#endif

//TODO delete this dead code
//const int MoveAcceleration = 13000;
//const int MaxMoveSpeed = 1750;
//const float GroundDragFactor = 0.48f;
//const float AirDragFactor = 0.58f;

#include "gfx.h"

#include "source\_sms_manager.h"
//#include "source\_snd_manager.h"

// BANKS
//#include "banks\bank2.h"
//#include "banks\bank3.h"
//#include "banks\bank4.h"
//#include "banks\bank5.h"

// MANAGERS
#include "source\global_manager.h"
//#include "engine\locale_manager.h"
#include "source\enum_manager.h"
#include "source\hack_manager.h"


// OBJECTS
//#include "object\enemy_object.h"
//#include "object\level_object.h"
//#include "object\player_object.h"

// MANAGERS
#include "source\content_manager.h"
//#include "source\font_manager.h"
//#include "source\sprite_manager.h"
//#include "source\tile_manager.h"
//#include "engine\level_manager.h"
#include "source\input_manager.h"
//#include "engine\enemy_manager.h"
//#include "engine\player_manager.h"
//#include "source\scroll_manager.h"
#include "engine\asm_manager.h"

#include "source\render_manager.h"

// SCREENS
//#include "source\none_screen.h"
//#include "source\test_screen.h"
//#include "source\init_screen.h"
//#include "source\load_screen.h"
//#include "source\play_screen.h"
//#include "source\func_screen.h"
//#include "screen\splash_screen.h"
#include "source\screen_manager.h"

// HACK_MANAGER
//unsigned char hacker_debug;
//unsigned char hacker_level;

// LEVEL_MANAGER
//unsigned char level_map[ ROWS * COLS ];
//unsigned char tiles_map[ ROWS * COLS ];
//unsigned char crash_map[ ROWS * COLS ];
//unsigned char level_mat[ ROWS ][ COLS ];
//unsigned char tiles_mat[ ROWS ][ COLS ];
//unsigned char crash_mat[ ROWS ][ COLS ];

// PLAYER_MANAGER
//struct_player_object player_object;
//MyStruct theVar;


//#ifdef _CONSOLE
//#else
//SMS_EMBED_SEGA_ROM_HEADER( 9999, 0 );
//SMS_EMBED_SDSC_HEADER( 1, 0, 2017, 3, 17, "StevePro Studios", "Platformer Game", "TODO enter description here!" );
//#endif

#endif//__MAIN__