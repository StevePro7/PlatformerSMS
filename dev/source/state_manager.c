#include "state_manager.h"
#include "hack_manager.h"
#include "font_manager.h"
#include "level_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "game_manager.h"

void engine_state_manager_init()
{
	struct_hack_object *ho = &global_hack_object;
	struct_game_object *go = &global_game_object;

	// Initialize hack manager.
	engine_font_manager_draw_data( ho->hacker_difficulty, 20, 5 );
	engine_font_manager_draw_data( go->difficulty, 20, 6 );
	
	engine_hack_manager_init();

	engine_font_manager_draw_data( ho->hacker_difficulty, 20, 8 );
	engine_font_manager_draw_data( go->difficulty, 20, 9 );

	engine_hack_manager_invert();

	engine_font_manager_draw_data( ho->hacker_difficulty, 20, 11 );
	engine_font_manager_draw_data( go->difficulty, 20, 12 );


	engine_game_manager_init();

	engine_font_manager_draw_data( ho->hacker_difficulty, 20, 14 );
	engine_font_manager_draw_data( go->difficulty, 20, 15 );


	// Setup hacked variables.
	go->difficulty = ho->hacker_difficulty;

	engine_font_manager_draw_data( ho->hacker_difficulty, 20, 17 );
	engine_font_manager_draw_data( go->difficulty, 20, 18 );
}

void engine_state_manager_load()
{
	struct_level_object *lo = &global_level_object;
	struct_player_object *po = &global_player_object;

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
	po->anim_count = 5;

	// EnemyX setup.
	em->max_enemies = lo->enemyCount;
	for( idx = 0; idx < em->max_enemies; idx++ )
	{
		eo = &global_enemy_objects[ idx ];


		eo->spotY = lo->enemys_spotY[ idx ];
		eo->spotX = lo->enemys_spotX[ idx ];
		eo->spotY = lo->enemys_spot[ idx ] / lo->draw_cols;
		eo->spotX = lo->enemys_spot[ idx ] % lo->draw_cols;


		eo->sprite_type = lo->enemys_type[ idx ];
		eo->action_type = lo->enemys_action[ idx ];

		eo->spotY = lo->enemys_spotY[ idx ];
		eo->spotX = lo->enemys_spotX[ idx ];
		eo->spotY = lo->enemys_spot[ idx ] / lo->draw_cols;
		eo->spotX = lo->enemys_spot[ idx ] % lo->draw_cols;

		//engine_font_manager_draw_data( eo->sprite_type, 10, 12 );
		//engine_font_manager_draw_data( eo->action_type, 10, 13 );
		//engine_font_manager_draw_data( eo->spotX, 10, 4 );
		//engine_font_manager_draw_data( eo->spotY, 10, 5 );
	}
}
