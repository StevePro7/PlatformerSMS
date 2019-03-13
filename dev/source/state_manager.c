#include "state_manager.h"
#include "font_manager.h"
//#include "level_object.h"
//#include "player_object.h"
//#include "enemy_object.h"
#include "level_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"

void engine_state_manager_load()
{
	struct_level_object *lo = &global_level_object;
	struct_player_object *po = &global_player_object;
	struct_enemy_object *eo;

	//struct_enemy_common *ec = &global_enemy_common;
	unsigned char idx, max_enemies;

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
	max_enemies = lo->enemyCount;
	for( idx = 0; idx < max_enemies; idx++ )
	{
		eo = &global_enemy_objects[ idx ];
		eo->sprite_type = lo->enemys_type[ idx ];
		eo->action_type = lo->enemys_action[ idx ];
		eo->spotY = lo->enemys_spot[ idx ] / lo->draw_cols;
		eo->spotX = lo->enemys_spot[ idx ] % lo->draw_cols;

		//engine_font_manager_draw_data( eo->sprite_type, 10, 12 );
		//engine_font_manager_draw_data( eo->action_type, 10, 13 );
		engine_font_manager_draw_data( eo->spotX, 10, 4 );
		engine_font_manager_draw_data( eo->spotY, 10, 5 );
	}
}
