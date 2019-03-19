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

// Private helper method.
static unsigned char ground_collision();

void screen_play_screen_load()
{
	struct_game_object *go = &global_game_object;
	struct_stats_object *so = &global_stats_object;

	enum_diff_type difficulty;
	invincible = go->invincible;
	difficulty = go->difficulty;
	collision = so->collision_offsets[ difficulty ];
}

void screen_play_screen_update( unsigned char *screen_type )
{
	struct_level_object *lo = &global_level_object;
	struct_player_object *po = &global_player_object;
	struct_enemy_master *em = &global_enemy_master;
	struct_enemy_object *eo;
	unsigned char idx;
	unsigned char evt;
	int coll_diff;

	// Check reset first.

	// Player movement.
	engine_player_manager_get_input();
	engine_player_manager_apply_physics();
	engine_player_manager_handle_collisions();
	engine_player_manager_cleanup();

	// Enemy(s) movement.
	engine_enemyX_manager_update();

	// Draw enemies first!
	engine_enemyX_manager_draw_enemys();
	engine_player_manager_draw();

	// Collision detection while player on ground.
	if( po->isOnGround )
	{
		if( po->coll_left == po->coll_rght )
		{
			// Gems + power up.
			evt = ground_collision();
			if( event_type_none != evt )
			{
				if( event_type_exit == evt )
				{
					*screen_type = screen_type_pass;
					return;
				}
				else if( event_type_gemscorehi == evt || event_type_gemscorelo == evt )
				{
					// TODO
					// Increase gems - score_manager + sound effect.
				}
				else if( event_type_gempowerhi == evt || event_type_gempowerlo == evt )
				{
					// Enable immunability = temp invincible to enemy/guard but can still fall down pits...
					engine_font_manager_draw_text( "POWER", 10, 10 );		// TODO implement code
				}
			}
		}
	}

	// If invincible then ignore collisions and pits.
	if( invincible )
	{
		*screen_type = screen_type_play;
		return;
	}

	// If jump above "ceiling" then cannot collide with anything
	if( po->posnY < 0 )
	{
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

	// Enemy + guard collisions.
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

static unsigned char ground_collision()
{
	struct_level_object *lo = &global_level_object;
	struct_player_object *po = &global_player_object;
	unsigned char evt;
	unsigned char tile;
	unsigned int cell_top, cell_bot;

	evt = event_type_none;
	cell_top = lo->draw_cols *  ( po->coll_topX + 0 ) + po->coll_left;
	cell_bot = lo->draw_cols *  ( po->coll_topX + 1 ) + po->coll_left;

	// Exit sign.
	if( po->coll_left == lo->exit_spotX && po->coll_topX + 1 == lo->exit_spotY )
	{
		return event_type_exit;
	}

	// Check top section.
	tile = lo->drawtiles_array[ cell_top ];
	if( tile_type_blankGap != tile )
	{
		if( tile_type_gemscore == tile || tile_type_gempower == tile )
		{
			lo->drawtiles_array[ cell_top ] = tile_type_blankGap;
			engine_level_manager_draw_blank( po->coll_left, po->coll_topX );
		}
		if( tile_type_gemscore == tile )
		{
			return event_type_gemscorehi;
		}
		else if( tile_type_gempower == tile )
		{
			return event_type_gempowerhi;
		}
	}

	// Check bot section.
	tile = lo->drawtiles_array[ cell_bot ];
	if( tile_type_blankGap != tile )
	{
		if( tile_type_gemscore == tile || tile_type_gempower == tile )
		{
			lo->drawtiles_array[ cell_bot ] = tile_type_blankGap;
			engine_level_manager_draw_blank( po->coll_left, po->coll_topX + 1 );
		}
		if( tile_type_gemscore == tile )
		{
			return event_type_gemscorelo;
		}
		else if( tile_type_gempower == tile )
		{
			return event_type_gempowerlo;
		}
	}

	return evt;
}