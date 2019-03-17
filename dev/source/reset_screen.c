#include "reset_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "delay_manager.h"

void screen_reset_screen_load()
{
	engine_font_manager_draw_text( "RESET SCREEN", 10, 10 );
}

void screen_reset_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_reset;
}