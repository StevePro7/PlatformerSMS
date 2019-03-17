#include "init_screen.h"
#include "global_manager.h"
#include "hack_manager.h"
#include "debug_manager.h"
#include "enum_manager.h"
#include "font_manager.h"

void screen_init_screen_load()
{
	engine_font_manager_draw_text( "INIT SCREEN", 10, 10 );
}

void screen_init_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_init;
}