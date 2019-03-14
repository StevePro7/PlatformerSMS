#include "load_screen.h"
#include "global_manager.h"
#include "hack_manager.h"
#include "debug_manager.h"
#include "enum_manager.h"
//#include "font_manager.h"
#include "tile_manager.h"
#include "level_manager.h"
#include "anim_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "input_manager.h"
#include "state_manager.h"
#include "game_manager.h"

void screen_load_screen_load()
{
	struct_hack_object *ho = &global_hack_object;
	struct_level_object *lo = &global_level_object;

	//engine_debug_manager_draw_grid();		// TODO remove this!

	engine_game_manager_load();

	// Load animations.
	engine_anim_manager_player_load_idle();
	engine_anim_manager_player_load_run();
	engine_anim_manager_enemyX_load_idle();

	engine_level_manager_init_level();
	engine_level_manager_load_index( 0 );
	engine_level_manager_draw_level();

	engine_state_manager_load();
	engine_player_manager_load();
	engine_enemyX_manager_load();
}

void screen_load_screen_update( unsigned char *screen_type )
{
	struct_game_object *go = &global_game_object;
	struct_hack_object *ho = &global_hack_object;
	struct_level_object *lo = &global_level_object;
	struct_player_object *po = &global_player_object;
	struct_enemy_master *em = &global_enemy_master;
	struct_enemy_object *eo;
	unsigned char idx;
	int coll_diff;

	engine_player_manager_get_input();
	engine_player_manager_apply_physics();
	engine_player_manager_handle_collisions();
	engine_player_manager_cleanup();

	// Draw enemies first!
	engine_enemyX_manager_draw();
	engine_player_manager_draw();


	// Collisions.
	//engine_font_manager_draw_text( "TEST", 10, 4 );

	// If invincible then ignore collisions.
	if( go->invincible )
	{
		*screen_type = screen_type_load;
		return;
	}
	// If jump above "ceiling" then cannot collide.
	if( po->posnY < 0 )
	{
		*screen_type = screen_type_load;
		return;
	}

	//engine_font_manager_draw_text( "COLL", 10, 5 );
	for( idx = 0; idx < em->max_enemies; idx++ )
	{
		eo = &global_enemy_objects[ idx ];
		if( ( signed char ) eo->spotY >= po->coll_topX && ( signed char ) eo->spotY <= po->coll_botX )
		{
			//engine_font_manager_draw_text( "DIFF", 10, 6 );
			//coll_diff = myabs( po->posnX - eo->posnX );
			if( coll_diff <= 12 )								// TODO replace hardcode value
			{
		//		engine_font_manager_draw_data( po->posnX, 10, 7 );
		//		engine_font_manager_draw_data( eo->posnX, 10, 8 );
				*screen_type = screen_type_dead;
				return;
			}
		}
		
		//engine_font_manager_draw_data( eo->spotY, 10, 7 );
		//engine_font_manager_draw_data( po->coll_topX, 10, 8 );

	}

	*screen_type = screen_type_load;
}