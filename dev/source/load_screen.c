#include "load_screen.h"
#include "global_manager.h"
#include "hack_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "tile_manager.h"
#include "level_manager.h"
#include "anim_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "input_manager.h"
#include "state_manager.h"
#include "stats_manager.h"
#include "game_manager.h"

static unsigned char invincible;
static unsigned char collision;

void screen_load_screen_load()
{
	struct_game_object *go = &global_game_object;
	struct_level_object *lo = &global_level_object;
	struct_stats_object *so = &global_stats_object;
	enum_diff_type difficulty;


	invincible = go->invincible;
	difficulty = go->difficulty;
	collision = so->collision_offsets[ difficulty ];


	engine_enemyX_manager_init();
	engine_level_manager_init_level();
	engine_level_manager_load_level( go->world_no, go->round_no, go->invincible, go->difficulty );
	engine_level_manager_draw_level();

	engine_state_manager_load();
	engine_enemyX_manager_load();

	//engine_player_manager_load();			// done in the ready screen
	//engine_enemyX_manager_draw_guards();	// done in the ready screen
}

void screen_load_screen_update( unsigned char *screen_type )
{
	/*
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
	engine_enemyX_manager_draw_enemys();
	engine_player_manager_draw();

	// TODO extract if no pits in level then only check if there is...
	// could leave this in for the moment to stress test redundant check
	// Check if fell into pit.
	if( health_type_death == po->player_health_type )
	{
		*screen_type = screen_type_dead;
		return;
	}


	// Collisions.

	// If invincible then ignore collisions.
	if( invincible )
	{
		*screen_type = screen_type_load;
		return;
	}

	//engine_font_manager_draw_text( "TEST", 10, 4 );

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
			coll_diff = myabs( po->posnX - eo->posnX );
			if( coll_diff <= collision )
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
	*/

	*screen_type = screen_type_ready;
}