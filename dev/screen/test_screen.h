#ifndef _TEST_SCREEN_H_
#define _TEST_SCREEN_H_

#include <math.h>

void screen_test_screen_load()
{
	engine_font_manager_draw_text( "TEST SCREEN", 10, 4 );
}

void screen_test_screen_update( enum_screen_type *screen_type )
{
	*screen_type = screen_type_test;
}

#endif//_TEST_SCREEN_H_