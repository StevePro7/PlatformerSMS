#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifdef _CONSOLE
#include "..\tmp\SMSlib.h"
#include "..\tmp\PSGlib.h"
#else
#include "..\lib\SMSlib.h"
#include "..\lib\PSGlib.h"
#endif

#include "gfx.h"

// BANKS
#include "banks\bank2.h"
#include "banks\bank3.h"
#include "banks\bank4.h"

// OBJECTS
#include "object\enemy_object.h"
#include "object\player_object.h"

// MANAGERS
#include "engine\global_manager.h"
#include "engine\locale_manager.h"
#include "engine\enum_manager.h"
#include "engine\content_manager.h"
#include "engine\font_manager.h"
#include "engine\sprite_manager.h"
#include "engine\tile_manager.h"
#include "engine\level_manager.h"
#include "engine\input_manager.h"
#include "engine\player_manager.h"
#include "engine\asm_manager.h"

// SCREENS
#include "screen\none_screen.h"
#include "screen\test_screen.h"
#include "screen\init_screen.h"
#include "screen\load_screen.h"
#include "screen\play_screen.h"
#include "screen\splash_screen.h"


// LEVEL_MANAGER
unsigned char level_map[ ROWS * COLS ];
unsigned char tiles_map[ ROWS * COLS ];
unsigned char crash_map[ ROWS * COLS ];
unsigned char level_mat[ ROWS ][ COLS ];
unsigned char tiles_mat[ ROWS ][ COLS ];
unsigned char crash_mat[ ROWS ][ COLS ];

// PLAYER_MANAGER
//struct_player_object player_object;
//MyStruct theVar;