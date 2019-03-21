#include "title_screen.h"
#include "_sms_manager.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "text_manager.h"
#include "content_manager.h"
#include "delay_manager.h"
#include "input_manager.h"
#include "tile_manager.h"
#include <stdlib.h>

#define FLASH_DELAY			50
#define TEXT_X				12
#define TEXT_Y				18

static unsigned char flash;

void screen_title_screen_load()
{
	engine_delay_manager_load( FLASH_DELAY );

	engine_text_manager_clear_three();
	engine_text_manager_cheat_blank();
	engine_font_manager_draw_text( LOCALE_PRESS_START, TEXT_X, TEXT_Y );
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
			engine_font_manager_draw_text( LOCALE_BLANK_WIDTH, 0, TEXT_Y );
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