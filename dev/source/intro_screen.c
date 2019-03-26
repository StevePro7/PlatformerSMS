#include "intro_screen.h"
#include "_sms_manager.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "content_manager.h"
#include "text_manager.h"
#include "tile_manager.h"
#include "delay_manager.h"
#include "input_manager.h"
#include "..\engine\asm_manager.h"
#include <stdlib.h>

#define INTRO_SCREEN_DELAY		150

void screen_intro_screen_load()
{
	unsigned char x, tile;
	engine_delay_manager_load( INTRO_SCREEN_DELAY );

	// Unload VRAM each begin to remove any unwanted graphics glitches...!
	devkit_SMS_displayOff();
	engine_asm_manager_clear_VRAM();
	engine_text_manager_clear_all();

	engine_content_manager_load_back_tiles();
	engine_content_manager_load_sprites();

	//engine_text_manager_clear_all();
	engine_content_manager_load_title();

	for( x = 2; x < SCREEN_TILE_WIDE; x += 2 )
	{
		tile = rand() % MAX_BLOCK_TILES + 1;
		engine_tile_manager_draw_tile( tile, x, 0 );
		tile = rand() % MAX_BLOCK_TILES + 1;
		engine_tile_manager_draw_tile( tile, x, 22 );
	}

	engine_font_manager_draw_text( LOCALE_BUILD_VERSION, 28, 21 );
	engine_font_manager_draw_text( "INTRO", 10, 20 );
	devkit_SMS_displayOn();
}

void screen_intro_screen_update( unsigned char *screen_type )
{
	unsigned char delay;
	unsigned char input;

	delay = engine_delay_manager_update();
	input = engine_input_manager_hold_fire1();

	if( delay || input )
	{
		*screen_type = screen_type_begin;
		return;
	}

	*screen_type = screen_type_intro;
}