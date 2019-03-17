#include "intro_screen.h"
#include "enum_manager.h"
#include "font_manager.h"

void screen_intro_screen_load()
{
	engine_font_manager_draw_text( "INTRO", 6, 9 );
}

void screen_intro_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_intro;
}