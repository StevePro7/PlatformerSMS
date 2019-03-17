#include "title_screen.h"
#include "_sms_manager.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "content_manager.h"
#include "delay_manager.h"
#include "input_manager.h"
#include "tile_manager.h"
#include <stdlib.h>

#define FLASH_DELAY			50
#define TEXT_X				11
#define TEXT_Y				18

static unsigned char flash;

void screen_title_screen_load()
{
	unsigned char x, tile;
	engine_delay_manager_load( FLASH_DELAY );

	devkit_SMS_displayOff();
	engine_content_manager_load_title();
	for( x = 2; x < SCREEN_TILE_WIDE; x += 2 )
	{
		tile = rand() % MAX_BLOCK_TILES + 1;
		engine_tile_manager_draw_tile( tile, x, 0 );
		tile = rand() % MAX_BLOCK_TILES + 1;
		engine_tile_manager_draw_tile( tile, x, 22 );
	}

	engine_font_manager_draw_text( LOCALE_BLANK_WIDTH, 2, TEXT_Y );
	engine_font_manager_draw_text( LOCALE_PRESS_START, TEXT_X, TEXT_Y );

	engine_font_manager_draw_text( LOCALE_BUILD_VERSION, 28, 21 );
	devkit_SMS_displayOn();
}

void screen_title_screen_update( unsigned char *screen_type )
{
	unsigned char delay;
	unsigned char input;

	delay = engine_delay_manager_update();
	if( delay )
	{
		flash = 1 - flash;
		if( flash )
		{
			engine_font_manager_draw_text( LOCALE_BLANK_WIDTH, 2, TEXT_Y );
		}
		else
		{
			engine_font_manager_draw_text( LOCALE_PRESS_START, TEXT_X, TEXT_Y );
		}
	}

	input = engine_input_manager_hold_fire1();
	if( input )
	{
		*screen_type = screen_type_diff;
		return;
	}

	rand();
	*screen_type = screen_type_title;
}