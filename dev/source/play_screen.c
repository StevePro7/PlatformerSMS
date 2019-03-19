#include "play_screen.h"
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

// Cache values for entire class.
static unsigned char invincible;
static unsigned char collision;
//static unsigned char pitstokill;		// TODO - calculate this bool on load level

void screen_play_screen_load()
{
	struct_game_object *go = &global_game_object;
	struct_stats_object *so = &global_stats_object;

	//struct_hack_object *ho = &global_hack_object;
	//struct_level_object *lo = &global_level_object;
	enum_diff_type difficulty;
	invincible = go->invincible;
	difficulty = go->difficulty;
	collision = so->collision_offsets[ difficulty ];
}

void screen_play_screen_update( unsigned char *screen_type )
{
	struct_player_object *po = &global_player_object;
	struct_enemy_master *em = &global_enemy_master;
	struct_enemy_object *eo;
	unsigned char idx;
	int coll_diff;

	// Check reset first.
	engine_player_manager_get_input();
	engine_player_manager_apply_physics();
	engine_player_manager_handle_collisions();
	engine_player_manager_cleanup();

	// Draw enemies first!
	engine_enemyX_manager_draw_enemys();
	engine_player_manager_draw();

	// Gems + power up.


	// If invincible then ignore collisions and pits.
	if( invincible )
	{
		*screen_type = screen_type_play;
		return;
	}

	// If jump above "ceiling" then cannot collide with anything
	if( po->posnY < 0 )
	{
		engine_font_manager_draw_text( "HIGH", 20, 10 );
		*screen_type = screen_type_play;
		return;
	}

	// TODO extract if no pits in level then only check if there is...
	// could leave this in for the moment to stress test redundant check
	// Check if fell into pit.
	if( health_type_death == po->player_health_type )
	{
		*screen_type = screen_type_dead;
		return;
	}

	// Collisions.
	for( idx = 0; idx < em->max_enemies; idx++ )
	{
		eo = &global_enemy_objects[ idx ];
		if( ( signed char ) eo->spotY >= po->coll_topX && ( signed char ) eo->spotY <= po->coll_botX )
		{
			coll_diff = myabs( po->posnX - eo->posnX );
			if( coll_diff <= collision )
			{
				*screen_type = screen_type_dead;
				return;
			}
		}
	}

	*screen_type = screen_type_play;
}

/*
void screen_play_screen_updateX( unsigned char *screen_type )
{
	struct_hack_object *ho = &global_hack_object;
	struct_level_object *lo = &global_level_object;
	struct_player_object *po = &global_player_object;
	unsigned int cell_top, cell_bot;
	unsigned char tile;
	int enemA_left, enemA_rght, enemA_topX, enemA_botX;
	int enemB_left, enemB_rght, enemB_topX, enemB_botX;
	int enemC_left, enemC_rght, enemC_topX, enemC_botX;
	int enemD_left, enemD_rght, enemD_topX, enemD_botX;
	signed char coll_topX;

	enemA_left = enemB_left = enemC_left = enemD_left = 240;
	enemA_rght = enemB_rght = enemC_rght = enemD_rght = 240;
	enemA_topX = 0;  enemB_topX = 48;  enemC_topX = 96;  enemD_topX = 144;
	enemA_botX = 32; enemB_botX = 80;  enemC_botX = 128; enemD_botX = 276;

	coll_topX = po->coll_topX + 1;

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

	*screen_type = screen_type_play;
}
*/