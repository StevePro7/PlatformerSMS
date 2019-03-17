#include "diff_screen.h"
#include "enum_manager.h"
#include "font_manager.h"

void screen_diff_screen_load()
{
	engine_font_manager_draw_text( "DIFF SCREEN", 11, 19 );
}

void screen_diff_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_diff;
}