#include "beat_screen.h"
#include "_sms_manager.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "text_manager.h"
#include "tile_manager.h"
#include "memo_manager.h"
#include <stdlib.h>

void screen_beat_screen_load()
{
	//unsigned char x, tile;
	//unsigned char left, wide;
	
	devkit_SMS_displayOff();
	engine_text_manager_clear_all();
	/*for( x = 2; x < SCREEN_TILE_WIDE; x += 2 )
	{
		tile = rand() % MAX_BLOCK_TILES + 1;
		engine_tile_manager_draw_tile( tile, x, 0 );
		tile = rand() % MAX_BLOCK_TILES + 1;
		engine_tile_manager_draw_tile( tile, x, 22 );
	}

	left = 8;
	wide = 19;
	x = 10;
	engine_memo_manager_draw( left, wide );
	engine_font_manager_draw_text( LOCALE_BEAT_MESSAGE1, 10, MEMO_TEXT_TOP );
	engine_font_manager_draw_text( LOCALE_BEAT_MESSAGE2, 10, MEMO_TEXT_BOT );*/
	devkit_SMS_displayOn();
}

void screen_beat_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_beat;
}