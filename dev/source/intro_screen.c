#include "intro_screen.h"
#include "_sms_manager.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "content_manager.h"
#include "tile_manager.h"
#include "memo_manager.h"
#include <stdlib.h>

void screen_intro_screen_load()
{
	unsigned char x, tile;

	devkit_SMS_displayOff();
	//engine_content_manager_load_title();
	for( x = 2; x < SCREEN_TILE_WIDE; x += 2 )
	{
		tile = rand() % MAX_BLOCK_TILES + 1;
		engine_tile_manager_draw_tile( tile, x, 0 );
		tile = rand() % MAX_BLOCK_TILES + 1;
		engine_tile_manager_draw_tile( tile, x, 22 );
	}
	for( x = 2; x < SCREEN_TILE_HIGH; x += 2 )
	{
		tile = rand() % MAX_BLOCK_TILES + 1;
		engine_tile_manager_draw_tile( tile, 2, x );
		tile = rand() % MAX_BLOCK_TILES + 1;
		engine_tile_manager_draw_tile( tile, 30, x );
	}


	devkit_SMS_displayOn();
}

void screen_intro_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_intro;
}