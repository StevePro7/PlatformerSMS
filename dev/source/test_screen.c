#include "test_screen.h"

//#include "hack_manager.h"
#include "global_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "tile_manager.h"
#include "level_manager.h"
#include "player_manager.h"
#include <stdlib.h>

static void dynamic_memory_allocation()
{
	/*
	struct_level_object *lo = &global_level_object;

	//engine_font_manager_draw_data( 100, 6, 6 );
	
	unsigned char idx;
	unsigned char ww = 15;
	unsigned char hh = 12;
	unsigned char size = ww * hh;
	unsigned char row = 1;
	unsigned char col = 2;

	idx = ww * row + col;


	for( x = 0; x < 32; x += 2 )
	{
		tile_type = rand() % MAX_BLOCK_TILES + 1;				// rand() <stdlib.h>
		engine_tile_manager_draw_tile( tile_type, x, 4 );
		//tile_type = rand() % MAX_BLOCK_TILES + 1;
		//engine_tile_manager_draw_tile( tile_type, x, 22 );
	}

	//tile_type = rand() % MAX_BLOCK_TILES + 1;
	//engine_tile_manager_draw_tile( tile_type, 14, 12 );	engine_tile_manager_draw_tile( tile_type, 14, 14 );
	//tile_type = rand() % MAX_BLOCK_TILES + 1;
	//engine_tile_manager_draw_tile( tile_type, 14, 18 );	engine_tile_manager_draw_tile( tile_type, 14, 16 );

	//tile_type = rand() % MAX_BLOCK_TILES + 1;
	//engine_tile_manager_draw_tile( tile_type, 12, 14 );

	engine_font_manager_draw_data( idx, 16, 10 );

	// NULL <stdlib.h>
	if( NULL == lo->collision_matrix )
	{
		engine_font_manager_draw_data( 2, 15, 11 );
		lo->collision_matrix = malloc( size * sizeof( unsigned char ) );
		lo->collision_matrix[ 17 ] = 9;

		engine_font_manager_draw_data( 4, 15, 12 );
		engine_font_manager_draw_data( lo->collision_matrix[ 0 ], 25, 12 );

		if( NULL == lo->collision_matrix )
		{
			engine_font_manager_draw_data( 55, 25, 12 );
		}
		engine_font_manager_draw_data( lo->collision_matrix[ idx ], 25, 14 );

		free( lo->collision_matrix );
		lo->collision_matrix = NULL;
		engine_font_manager_draw_data( 6, 15, 13 );
		if( NULL == lo->collision_matrix )
		{
			engine_font_manager_draw_data( 66, 25, 13 );
		}
	}
	else
	{
		free( lo->collision_matrix );
		lo->collision_matrix = NULL;
	}
	*/
}
void screen_test_screen_load()
{
	/*unsigned char x;
	enum_tile_type tile_type;
	for( x = 0; x < 32; x += 2 )
	{
		tile_type = rand() % MAX_BLOCK_TILES + 1;
		engine_tile_manager_draw_tile( tile_type, x, 20 );
		tile_type = rand() % MAX_BLOCK_TILES + 1;
		engine_tile_manager_draw_tile( tile_type, x, 22 );
	}

	tile_type = rand() % MAX_BLOCK_TILES + 1;
	engine_tile_manager_draw_tile( tile_type, 14, 12 );	engine_tile_manager_draw_tile( tile_type, 14, 14 );
	tile_type = rand() % MAX_BLOCK_TILES + 1;
	engine_tile_manager_draw_tile( tile_type, 14, 18 );	engine_tile_manager_draw_tile( tile_type, 14, 16 );*/

	//tile_type = rand() % MAX_BLOCK_TILES + 1;
	//engine_tile_manager_draw_tile( tile_type, 12, 14 );B

	//engine_level_manager_load_levelX();


	engine_level_manager_load_index( 1 );
	//engine_level_manager_draw_level_column( 5 );
	//engine_level_manager_draw_level_column_side( side_type_left, 6 );
	//engine_level_manager_draw_level_column( 7 );

	engine_level_manager_draw_level();
	engine_player_manager_load();
}

void screen_test_screen_update( unsigned char *screen_type )
{
	engine_player_manager_get_input();
	engine_player_manager_draw();

	*screen_type = screen_type_test;
}