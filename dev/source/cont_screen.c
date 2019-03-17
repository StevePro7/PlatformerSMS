#include "cont_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "delay_manager.h"

void screen_cont_screen_load()
{
	engine_font_manager_draw_text( "CONT SCREEN", 10, 10 );
	engine_delay_manager_load( 100 );
}

void screen_cont_screen_update( unsigned char *screen_type )
{
	unsigned char test = engine_delay_manager_update();
	engine_font_manager_draw_data( test, 10, 15 );

	if( test )
	{
		*screen_type = screen_type_reset;
		return;
	}

	*screen_type = screen_type_cont;
}