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

	//engine_memo_manager_draw( 13, 8 );
	engine_memo_manager_draw( 12, 10 );

	/*engine_tile_manager_draw_small( 10, 18, tile_type_blockA );
	engine_tile_manager_draw_small( 14, 18, tile_type_blockB );
	engine_tile_manager_draw_small( 18, 19, tile_type_blockC );*/
	//engine_tile_manager_draw_small( 22, 19, tile_type_heart );

	//engine_font_manager_draw_text( LOCALE_BEAT_MESSAGE1, 10, 19 );
	//engine_font_manager_draw_text( LOCALE_BEAT_MESSAGE2, 10, 20 );
	engine_font_manager_draw_text( LOCALE_GAME_MESSAGE1, 15, 11 );
	engine_font_manager_draw_text( LOCALE_GAME_MESSAGE2, 15, 12 );

	//engine_font_manager_draw_text( LOCALE_CONT_MESSAGE, 10, 18 );
	//engine_font_manager_draw_text( LOCALE_SELECT_ARROW, 10, 19 );
	//engine_font_manager_draw_text( LOCALE_CONT_YES, 12, 19 );
	//engine_font_manager_draw_text( LOCALE_SELECT_ARROW, 19, 19 );
	//engine_font_manager_draw_text( LOCALE_CONT_NO, 21, 19 );


	devkit_SMS_displayOn();
}

void screen_intro_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_intro;
}