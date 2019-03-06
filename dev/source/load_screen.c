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

#define PLAYER_TILE		256
//#define PLAYER_TILE		328
#define ENEMYA_TILE		292
//#define ENEMYB_TILE		256 + 24
#define ENEMYB_TILE		328
#define ENEMYC_TILE		364//256 + 36
#define ENEMYD_TILE		436//256 + 48

static unsigned char enemyA_index, enemyB_index, enemyC_index, enemyD_index;

void screen_load_screen_load()
{
	struct_hack_object *ho = &global_hack_object;

	//engine_debug_manager_draw_grid();		// TODO remove this!

	engine_level_manager_load_index( 1 );
	engine_level_manager_draw_level();
	//engine_level_manager_load_levelX();

	engine_state_manager_load();
	engine_player_manager_load();

	enemyA_index = enemyB_index = enemyC_index, enemyD_index = 0;

	engine_anim_manager_enemyA_load( enemyA_index, ENEMYA_TILE );
	engine_anim_manager_enemyB_load( enemyB_index, ENEMYB_TILE );
	engine_anim_manager_enemyC_load( enemyC_index, ENEMYC_TILE );
	engine_anim_manager_enemyD_load( enemyD_index, ENEMYD_TILE );
}

void screen_load_screen_update( unsigned char *screen_type )
{
	const unsigned char x = 60;
	unsigned char test1, test2, test3, test4;

	engine_player_manager_get_input();
	engine_player_manager_apply_physics();
	engine_player_manager_handle_collisions();
	engine_player_manager_cleanup();

	//engine_font_manager_draw_data( enemyA_index, 20, 11 );
	//engine_font_manager_draw_data( enemyB_index, 20, 12 );
	//engine_font_manager_draw_data( enemyC_index, 20, 13 );
	//engine_font_manager_draw_data( enemyD_index, 20, 14 );

	//test1 = engine_input_manager_move_left();
	test1 = true;
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
	test2 = true;
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
	test3 = true;
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
	test4 = true;
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
	

	engine_anim_manager_draw( x, 0, ENEMYA_TILE );
	engine_anim_manager_draw( x + 16, 48, ENEMYB_TILE );
	engine_anim_manager_draw( x, 96, ENEMYC_TILE );
	engine_anim_manager_draw( x, 144, ENEMYD_TILE );

	engine_player_manager_draw();
	*screen_type = screen_type_load;
}