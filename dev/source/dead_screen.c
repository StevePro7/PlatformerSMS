#include "dead_screen.h"
#include "enum_manager.h"
#include "font_manager.h"

void screen_dead_screen_load()
{
	engine_font_manager_draw_text( "DEAD!", 10, 10 );
}

void screen_dead_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_dead;
}