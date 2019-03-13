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
#include "enemy_manager.h"
#include "state_manager.h"
#include "audio_manager.h"

void screen_play_screen_load()
{
	struct_hack_object *ho = &global_hack_object;
	struct_level_object *lo = &global_level_object;

	/*unsigned char int_coll_type;
	enum_coll_type coll_type;*/

	//engine_debug_manager_draw_grid();		// TODO remove this!

	// Load animations.
	engine_anim_manager_player_load_idle();
	engine_anim_manager_player_load_run();
	engine_anim_manager_enemyX_load_idle();


	engine_level_manager_load_index( 0 );
	//engine_level_manager_load_index( ho->hacker_level );
	engine_level_manager_draw_level();

	//TODO refactor this so can lookup as unsigned char but cast back as enum
	//engine_level_manager_get_collision( &int_coll_type, 9, 5 );
	//coll_type = ( enum_coll_type ) int_coll_type;
	//engine_font_manager_draw_data( coll_type, 9, 10 );

	//engine_level_manager_load_levelX();
	
	engine_state_manager_load();
	engine_player_manager_load();
	engine_enemyX_manager_load();


	// TODO put in the update method
	//engine_player_manager_get_input();
	//engine_player_manager_apply_physics();
	//engine_player_manager_handle_collisions();

	// TODO wire up different game play music...
	//engine_audio_manager_start_music();

	//engine_font_manager_draw_text( "LEFT", 10, 10 );
	//engine_font_manager_draw_text( "RGHT", 10, 11 );
	//engine_font_manager_draw_text( "TOPX", 10, 12 );
	//engine_font_manager_draw_text( "BOTX", 10, 13 );

	//engine_font_manager_draw_data( lo->exit_spotX, 20, 18 );
	//engine_font_manager_draw_data( lo->exit_spotY, 20, 19 );
}

void screen_play_screen_update( unsigned char *screen_type )
{
	struct_level_object *lo = &global_level_object;
	struct_player_object *po = &global_player_object;
	unsigned int cell_top, cell_bot;
	unsigned char tile;

	engine_player_manager_get_input();
	engine_player_manager_apply_physics();
	engine_player_manager_handle_collisions();
	engine_player_manager_cleanup();

	// Draw enemies first!
	engine_enemyX_manager_draw();
	engine_player_manager_draw();

	// TODO extract if no pits in level then only check if there is...
	// could leave this in for the moment to stress test redundant check
	// Check if fell into pit.
	if( health_type_death == po->player_health_type )
	{
		*screen_type = screen_type_dead;
		return;
	}

	// Collision detection while player on ground.
	if( po->isOnGround )
	{
		if( po->coll_left == po->coll_rght )
		{
			cell_top = lo->draw_cols *  ( po->coll_topX + 0 ) + po->coll_left;
			cell_bot = lo->draw_cols *  ( po->coll_topX + 1 ) + po->coll_left;

			//engine_font_manager_draw_data( cell_top, 20, 18 );
			//engine_font_manager_draw_data( cell_bot, 20, 19 );

			// TODO must check cell top + bot for both yellow + red gems i.e. 4x checks
			tile = lo->drawtiles_array[ cell_top ];
			if( tile_type_blankGap != tile )
			{
				if( tile_type_gempower == tile )
				{
					lo->drawtiles_array[ cell_bot ] = tile_type_blankGap;
					engine_level_manager_draw_blank( po->coll_left, po->coll_topX );
				}
			}

			tile = lo->drawtiles_array[ cell_bot ];
			//engine_font_manager_draw_data( tile, 20, 20 );
			if( tile_type_blankGap != tile )
			{
				if( tile_type_gemscore == tile )
				{
					lo->drawtiles_array[ cell_bot ] = tile_type_blankGap;
					engine_level_manager_draw_blank( po->coll_left, po->coll_topX + 1 );
				}
			}

			// Exit sign.
			if( po->coll_left == lo->exit_spotX && po->coll_topX + 1 == lo->exit_spotY )
			{
				*screen_type = screen_type_pass;
				return;
			}
		}
	}

	//engine_font_manager_draw_data( po->coll_left, 20, 10 );
	//engine_font_manager_draw_data( po->coll_rght, 20, 11 );
	//engine_font_manager_draw_data( po->coll_topX, 20, 12 );
	//engine_font_manager_draw_data( po->coll_botX, 20, 13 );

	*screen_type = screen_type_play;
}