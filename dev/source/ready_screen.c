#include "ready_screen.h"
#include "enum_manager.h"
#include "font_manager.h"

void screen_ready_screen_load()
{
	engine_font_manager_draw_text( "READY", 10, 10 );
}

void screen_ready_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_ready;
}