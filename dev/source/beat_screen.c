#include "beat_screen.h"
#include "enum_manager.h"
#include "locale_manager.h"
#include "font_manager.h"
#include "delay_manager.h"

#define TEXT_X	11
#define TEXT_Y	12

static unsigned char flash;

void screen_beat_screen_load()
{
	engine_delay_manager_load( 50 );
	flash = 0;

	engine_font_manager_draw_text( LOCALE_PRESS_START, TEXT_X, TEXT_Y );
}

void screen_beat_screen_update( unsigned char *screen_type )
{
	unsigned char delay = engine_delay_manager_update();
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


	*screen_type = screen_type_beat;
}