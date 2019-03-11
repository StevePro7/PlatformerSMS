#include "load_screen.h"
#include "global_manager.h"
#include "hack_manager.h"
#include "debug_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "tile_manager.h"
#include "level_manager.h"
#include "anim_manager.h"
#include "player_manager.h"
#include "input_manager.h"
#include "state_manager.h"

//#define PLAYER_TILE		256 + 0
#define ENEMYA_TILE		256 + 6 * 12
#define ENEMYB_TILE		256 + 12 * 12
#define ENEMYC_TILE		256 + 13 * 12
#define ENEMYD_TILE		256 + 14 * 12

static unsigned char enemyA_index, enemyB_index, enemyC_index, enemyD_index;
static unsigned char counter;

void screen_load_screen_load()
{
	struct_hack_object *ho = &global_hack_object;
	unsigned char player_index;
	counter = 0;
	//engine_debug_manager_draw_grid();		// TODO remove this!

	engine_level_manager_load_index( 2 );
	engine_level_manager_draw_level();
	//engine_level_manager_load_levelX();

	engine_state_manager_load();
	engine_player_manager_load();

	enemyA_index = enemyB_index = enemyC_index, enemyD_index = 0;

	player_index = 0;
	//engine_anim_manager_player_load( player_index, PLAYER_TILE + player_index * SPRITE_TILES_NUMBER );

	for( player_index = 0; player_index < 6; player_index++ )
	{
		//engine_anim_manager_player_load( player_index, PLAYER_TILE + player_index * SPRITE_TILES_NUMBER );
	}

	//engine_anim_manager_enemyA_load( 0, ENEMYA_TILE + 0 * SPRITE_TILES_NUMBER );
	for( enemyA_index = 1; enemyA_index < 6; enemyA_index++ )
	{
		//engine_anim_manager_enemyA_load( enemyA_index, ENEMYA_TILE + enemyA_index * SPRITE_TILES_NUMBER );
		//engine_anim_manager_enemyB_load( enemyA_index, ENEMYA_TILE + enemyA_index * SPRITE_TILES_NUMBER );
		//engine_anim_manager_enemyC_load( enemyA_index, ENEMYA_TILE + enemyA_index * SPRITE_TILES_NUMBER );
		//engine_anim_manager_enemyD_load( enemyA_index, ENEMYA_TILE + enemyA_index * SPRITE_TILES_NUMBER );
	}

	//engine_anim_manager_enemyB_load( enemyB_index + 0, ENEMYB_TILE + 0 * SPRITE_TILES_NUMBER );
	//engine_anim_manager_enemyC_load( enemyC_index + 0, ENEMYC_TILE + 0 * SPRITE_TILES_NUMBER );
	//engine_anim_manager_enemyD_load( enemyD_index + 0, ENEMYD_TILE + 0 * SPRITE_TILES_NUMBER );
	//engine_anim_manager_enemyA_load( enemyA_index + 2, PLAYER_TILE + 13 * SPRITE_TILES_NUMBER );
	//engine_anim_manager_enemyA_load( enemyA_index + 3, PLAYER_TILE + 14 * SPRITE_TILES_NUMBER );
	//engine_anim_manager_enemyA_load( enemyA_index + 4, PLAYER_TILE + 15 * SPRITE_TILES_NUMBER );

	//engine_anim_manager_player_load( 3, PLAYER_TILE + 0 * SPRITE_TILES_NUMBER );

	//engine_anim_manager_enemyA_load( enemyA_index, ENEMYA_TILE );
	//engine_anim_manager_enemyB_load( enemyB_index, ENEMYB_TILE );
	//engine_anim_manager_enemyC_load( enemyC_index, ENEMYC_TILE );
	//engine_anim_manager_enemyD_load( enemyD_index, ENEMYD_TILE );
	enemyA_index = enemyB_index = 0;
}

void screen_load_screen_update( unsigned char *screen_type )
{
	const unsigned char x = 60;
	int mod;
	//unsigned char test1, test2, test3, test4;

	counter++;
	if( counter > 40 )
	{
		counter = 0;
	}

	//mod = counter % 4;
	mod = INVALID_INDEX;

	//engine_font_manager_draw_data( counter, 20, 11 );
	//engine_font_manager_draw_data( mod, 20, 12 );

	engine_player_manager_get_input();
	engine_player_manager_apply_physics();
	engine_player_manager_handle_collisions();
	engine_player_manager_cleanup();

	//engine_font_manager_draw_data( enemyA_index, 20, 11 );
	//engine_font_manager_draw_data( enemyB_index, 20, 12 );
	//engine_font_manager_draw_data( enemyC_index, 20, 13 );
	//engine_font_manager_draw_data( enemyD_index, 20, 14 );
	/*
	//test1 = engine_input_manager_move_left();
	test1 = mod == 0;// true;
	if (test1 )
	{
		enemyA_index++;
		if( enemyA_index >= MAX_ENEMYX_ANIMS )
		{
			enemyA_index = 0;
		}

		//engine_font_manager_draw_data( enemyA_index, 20, 11 );
		engine_anim_manager_enemyA_load( enemyA_index, ENEMYA_TILE );
	}

	//test2 = engine_input_manager_move_right();
	test2 = mod == 1;// true;
	if( test2 )
	{
		enemyB_index++;
		if( enemyB_index >= MAX_ENEMYX_ANIMS )
		{
			enemyB_index = 0;
		}

		//engine_font_manager_draw_data( enemyB_index, 20, 12 );
		engine_anim_manager_enemyB_load( enemyB_index, ENEMYB_TILE );
	}

	//test3 = engine_input_manager_move_up();
	test3 = mod == 2;// true;
	if( test3 )
	{
		enemyC_index++;
		if( enemyC_index >= MAX_ENEMYX_ANIMS )
		{
			enemyC_index = 0;
		}

		//engine_font_manager_draw_data( enemyC_index, 20, 13 );
		engine_anim_manager_enemyC_load( enemyC_index, ENEMYC_TILE );
	}

	//test4 = engine_input_manager_move_down();
	test4 = mod == 3;// true;
	if( test4 )
	{
		enemyD_index++;
		if( enemyD_index >= MAX_ENEMYX_ANIMS )
		{
			enemyD_index = 0;
		}

		//engine_font_manager_draw_data( enemyD_index, 20, 14 );
		engine_anim_manager_enemyD_load( enemyD_index, ENEMYD_TILE );
	}
	*/

	//engine_anim_manager_draw( x, 0, PLAYER_TILE + 0 * SPRITE_TILES_NUMBER );
	//engine_anim_manager_draw( x, 64, PLAYER_TILE + 11 * SPRITE_TILES_NUMBER );
	//engine_anim_manager_draw( x + 32, 64, PLAYER_TILE + 12 * SPRITE_TILES_NUMBER );
	//engine_anim_manager_draw( x + 0, 96, PLAYER_TILE + 13 * SPRITE_TILES_NUMBER );
	//engine_anim_manager_draw( x + 32, 96, PLAYER_TILE + 14 * SPRITE_TILES_NUMBER );

	//engine_anim_manager_draw( x + 64, 64, ENEMYA_TILE + 2 * SPRITE_TILES_NUMBER );
	enemyB_index++;
	if( enemyB_index >= 20 )
	{
		enemyB_index = 0;
		enemyA_index++;
		if( enemyA_index >= 6 )
		{
			/*for( enemyC_index = 6; enemyC_index < 10; enemyC_index++ )
			{
				engine_anim_manager_enemyA_load( enemyC_index, ENEMYA_TILE + 1 * SPRITE_TILES_NUMBER );
			}*/
			enemyA_index = 1;
		}
		/*else if( enemyA_index >= 11 )
		{
			for( enemyC_index = 1; enemyC_index < 6; enemyC_index++ )
			{
				engine_anim_manager_enemyA_load( enemyC_index, ENEMYA_TILE + 1 * SPRITE_TILES_NUMBER );
			}
			enemyA_index = 1;
		}*/
	}
	
	//engine_anim_manager_draw( x + 64, 64, ENEMYA_TILE + enemyA_index * SPRITE_TILES_NUMBER );
	//engine_anim_manager_draw( x + 128, 0, ENEMYB_TILE + 0 * SPRITE_TILES_NUMBER );
	//engine_anim_manager_draw( x - 32, 128, ENEMYC_TILE + 0 * SPRITE_TILES_NUMBER );
	//engine_anim_manager_draw( 236-16, 48, ENEMYD_TILE + 0 * SPRITE_TILES_NUMBER );

	engine_player_manager_draw();
	*screen_type = screen_type_load;
}
