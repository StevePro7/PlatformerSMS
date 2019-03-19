#include "intro_screen.h"
#include "enum_manager.h"
#include "locale_manager.h"
#include "font_manager.h"
#include "input_manager.h"

void screen_intro_screen_load()
{
	engine_font_manager_draw_text( "INTRO", 6, 9 );
}

void screen_intro_screen_update( unsigned char *screen_type )
{
	/*unsigned char test;
	test = engine_input_manager_hold_fire1();
	if( test )
	{
		*screen_type = screen_type_diff;
		return;
	}*/

	*screen_type = screen_type_intro;
}