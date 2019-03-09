#include "init_screen.h"
#include "global_manager.h"
#include "hack_manager.h"
#include "debug_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "tile_manager.h"
#include "level_manager.h"
#include "anim_manager.h"
#include "player_manager.h"
#include "enum_manager.h"
#include "input_manager.h"
#include "state_manager.h"

static unsigned int index;
static unsigned char half;
static void draw();

void screen_init_screen_load()
{
	engine_level_manager_load_index( 4 );
	engine_level_manager_draw_level();
	//engine_level_manager_load_levelX();

	engine_state_manager_load();
	engine_player_manager_load();

	// Load animations.
	//engine_anim_manager_player_load_idle();

	//engine_anim_manager_player_load_run( move_type_rght, half_type_prev );
	//engine_anim_manager_player_load_run( move_type_rght, half_type_prev );
	//engine_anim_manager_player_load_run( move_type_rght, half_type_next );

	//engine_anim_manager_enemyX_load_move_idle( sprite_type_enemyA );
	half = 0;
	draw();
	index = 1;
	
	engine_font_manager_draw_data( index, 8, 8 );
	engine_font_manager_draw_data( 340, 8, 9 );
}

void screen_init_screen_update( unsigned char *screen_type )
{
	unsigned char test;
	unsigned int tile;

	//tile = 328 + index * 12;			// enemyX
	tile = 256 + index * 12;			// player

	test = engine_input_manager_hold_left();
	if( test )
	{
		index++;
		//engine_font_manager_draw_data( index, 8, 8 );
		if( index >= 6 )
		{
			index = 1;
			//engine_font_manager_draw_data( index, 8, 8 );
			//engine_font_manager_draw_text( "SUZANNE", 8, 10 );
			half = 1 - half;
			engine_font_manager_draw_data( half, 8, 11 );
			draw();
		}

		//tile = 328 + index * 12;			// enemyX
		tile = 256 + index * 12;			// player
		//engine_font_manager_draw_data( tile, 8, 9 );
	}

	//engine_player_manager_draw();
	engine_anim_manager_draw(28, 144, tile );
	*screen_type = screen_type_init;
}

static void draw()
{
	//engine_anim_manager_enemyX_load_move_run( sprite_type_enemyA, move_type_rght, half );
	engine_anim_manager_player_load_run( move_type_left, half );
}