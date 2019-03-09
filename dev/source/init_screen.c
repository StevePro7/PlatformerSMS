#include "init_screen.h"
#include "global_manager.h"
#include "hack_manager.h"
#include "debug_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "tile_manager.h"
#include "level_manager.h"
#include "anim_manager.h"
#include "player_manager.h"
#include "enum_manager.h"
#include "input_manager.h"
#include "state_manager.h"

void screen_init_screen_load()
{
	engine_level_manager_load_index( 4 );
	engine_level_manager_draw_level();
	//engine_level_manager_load_levelX();

	engine_state_manager_load();
	engine_player_manager_load();

	// Load animations.
	engine_anim_manager_player_load_idle();

	//engine_anim_manager_player_load_run( move_type_rght, half_type_prev );
	//engine_anim_manager_player_load_run( move_type_rght, half_type_prev );
	engine_anim_manager_player_load_run( move_type_rght, half_type_next );
}

void screen_init_screen_update( unsigned char *screen_type )
{
	//unsigned char test;

	/*test = engine_input_manager_hold_left();
	if( test )
	{
		engine_anim_manager_player_load_run_left( half_type_prev );
	}*/

	engine_player_manager_draw();
	*screen_type = screen_type_init;
}