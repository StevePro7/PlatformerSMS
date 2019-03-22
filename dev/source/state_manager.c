#include "state_manager.h"
#include "hack_manager.h"
#include "memo_manager.h"
#include "level_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "stats_manager.h"
#include "game_manager.h"

void engine_state_manager_init()
{
	struct_hack_object *ho = &global_hack_object;
	struct_game_object *go = &global_game_object;

	// Initialize hack manager.
	engine_hack_manager_init();
	engine_hack_manager_invert();

	// Initialize other managers.
	engine_memo_manager_init();
	engine_stats_manager_init();
	engine_game_manager_init();


	// Setup hacked variables.
	go->invincible = ho->hack_invincible;
	go->localcheat = ho->hack_localcheat;
	go->difficulty = ho->hack_difficulty;
	go->world_no = ho->hack_world;
	go->round_no = ho->hack_round;
}

void engine_state_manager_load()
{
	struct_game_object *go = &global_game_object;
	struct_level_object *lo = &global_level_object;
	struct_player_object *po = &global_player_object;
	struct_stats_object *so = &global_stats_object;

	struct_enemy_master *em = &global_enemy_master;
	struct_enemy_object *eo;

	unsigned char idx;

	// This should never happen!
	if( 0 == lo->draw_cols )
	{
		return;
	}

	// Player setup.
	po->spotY = lo->player_spot / lo->draw_cols;
	po->spotX = lo->player_spot % lo->draw_cols;
	po->anim_count = 5;								// TODO #define in playerManager

	// EnemyX setup.
	em->max_enemies = lo->enemyCount;
	for( idx = 0; idx < em->max_enemies; idx++ )
	{
		eo = &global_enemy_objects[ idx ];

		eo->sprite_type = lo->enemys_type[ idx ];
		eo->action_type = lo->enemys_action[ idx ];
		eo->spotY = lo->enemys_spotY[ idx ];
		eo->spotX = lo->enemys_spotX[ idx ];

		// Don't set movement data for guards.
		if( action_type_guard == eo->action_type )
		{
			continue;
		}

		eo->minX = lo->enemys_minX[ idx ];
		eo->maxX = lo->enemys_maxX[ idx ];

		eo->velX = so->enemys_velX[ eo->sprite_type ][ go->world_no ];
		//eo->velX += go->difficulty;
		if( eo->velX > MAX_ENEMY_VELX )
		{
			eo->velX = MAX_ENEMY_VELX;
		}

		eo->wait = so->enemys_wait[ eo->sprite_type ][ go->world_no ];
		if( eo->wait > MAX_ENEMY_WAIT )
		{
			eo->wait = MAX_ENEMY_WAIT;
		}
		if( 0 != eo->wait )
		{
			eo->wait -= go->difficulty;
		}

		// If walk count zero then always walk i.e. enemy does not stutter.
		eo->walkCount = so->enemys_walk[ eo->sprite_type ][ go->world_no ];
		if( 0 == eo->walkCount )
		{
			eo->walkFlag = 1;
		}
	}

}
