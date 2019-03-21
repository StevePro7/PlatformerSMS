#include "intro_screen.h"
#include "_sms_manager.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "content_manager.h"
#include "tile_manager.h"
#include <stdlib.h>

void screen_intro_screen_load()
{
	unsigned char x, tile;

	devkit_SMS_displayOff();
	engine_content_manager_load_title();
	for( x = 2; x < SCREEN_TILE_WIDE; x += 2 )
	{
		tile = rand() % MAX_BLOCK_TILES + 1;
		engine_tile_manager_draw_tile( tile, x, 0 );
		tile = rand() % MAX_BLOCK_TILES + 1;
		engine_tile_manager_draw_tile( tile, x, 22 );
	}

	//engine_font_manager_draw_text( LOCALE_BUILD_VERSION, 28, 21 );

	//engine_font_manager_draw_text( LOCALE_SELECT_DIFF, 9, 17 );
	//engine_font_manager_draw_text( LOCALE_PRESS_START, 11, 18 );
	//engine_font_manager_draw_text( LOCALE_BEAT_MESSAGE1, 10, 19 );
	//engine_font_manager_draw_text( LOCALE_BEAT_MESSAGE2, 10, 20 );

	devkit_SMS_displayOn();
}

void screen_intro_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_intro;
}