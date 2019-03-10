#include "play_screen.h"
#include "global_manager.h"
#include "debug_manager.h"
#include "hack_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "tile_manager.h"
#include "level_manager.h"
#include "anim_manager.h"
#include "player_manager.h"
#include "state_manager.h"

void screen_play_screen_load()
{
	struct_hack_object *ho = &global_hack_object;
	
	/*unsigned char int_coll_type;
	enum_coll_type coll_type;*/

	//engine_debug_manager_draw_grid();		// TODO remove this!

	engine_level_manager_load_index( 0 );
	//engine_level_manager_load_index( ho->hacker_level );
	engine_level_manager_draw_level();

	//TODO refactor this so can lookup as unsigned char but cast back as enum
	//engine_level_manager_get_collision( &int_coll_type, 9, 5 );
	//coll_type = ( enum_coll_type ) int_coll_type;
	//engine_font_manager_draw_data( coll_type, 9, 10 );

	//engine_level_manager_load_levelX();
	
	engine_state_manager_load();
	engine_anim_manager_player_load_idle();
	engine_anim_manager_player_load_run();
	engine_player_manager_load();


	// TODO put in the update method
	//engine_player_manager_get_input();
	//engine_player_manager_apply_physics();
	//engine_player_manager_handle_collisions();
}

void screen_play_screen_update( unsigned char *screen_type )
{
	engine_player_manager_get_input();
	engine_player_manager_apply_physics();
	engine_player_manager_handle_collisions();
	engine_player_manager_cleanup();

	engine_player_manager_draw();
	*screen_type = screen_type_play;
}