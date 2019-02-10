#include "test_screen.h"

//#include "hack_manager.h"
#include "global_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "tile_manager.h"
#include "level_manager.h"
#include "player_manager.h"
#include <stdlib.h>

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
	//engine_tile_manager_draw_tile( tile_type, 12, 14 );

	engine_level_manager_load_levelX();


	//engine_level_manager_load_index( 0 );
	//engine_level_manager_draw_level_column( 5 );
	//engine_level_manager_draw_level_column_side( side_type_left, 6 );
	//engine_level_manager_draw_level_column( 7 );

	//engine_level_manager_draw_level();			// TODO this now has issues!!

	engine_player_manager_load();
}

void screen_test_screen_update( unsigned char *screen_type )
{
	engine_player_manager_update();
	*screen_type = screen_type_test;
}