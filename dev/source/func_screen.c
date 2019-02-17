#include "func_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include <math.h>
#include <stdlib.h>

void screen_func_screen_load()
{
	float data = -5;
	float test = 0;

	engine_font_manager_draw_data( ( int ) data, 10, 10 );
	engine_font_manager_draw_data( ( int ) test, 10, 11 );
	test = fabsf( data );
	engine_font_manager_draw_data( ( int ) test, 10, 12 );
}

void screen_func_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_func;
}