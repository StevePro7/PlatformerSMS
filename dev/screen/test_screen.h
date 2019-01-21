#ifndef _TEST_SCREEN_H_
#define _TEST_SCREEN_H_

#include <math.h>

void screen_test_screen_load()
{
	int test;
	float numb = 2.3f;
	//float data = powf( 2, 3 );
	float data = ceilf( numb );
	//float data = floorf( numb );

	test = ( int ) ( data * 1000 );
	//float test = powf( 2, 3 ) * 1000;
	//float test = sqrtf( 225 ) * 1000;

	//engine_font_manager_draw_data( test, 10, 4 );
	engine_font_manager_draw_text( "TEST FUNCTIONS", 10, 4 );
}

void screen_test_screen_update( enum_screen_type *screen_type )
{
	float numb = 2.3f;
	float data;
	//float data = powf( 2, 3 );
	//float data = ceilf( numb );
	//float data = floorf( numb );

	bool test = engine_input_manager_hold_up();
	if( test )
	{
		data = powf( 2, 3 ) * 1000;
		engine_font_manager_draw_data( data, 13, 5 );
		//engine_font_manager_draw_text( "TEST UP", 10, 5 );
	}

	test = engine_input_manager_hold_down();
	if( test )
	{
		data = sqrtf( 225 ) * 1000;
		engine_font_manager_draw_data( data, 13, 6 );
		//engine_font_manager_draw_text( "TEST DOWN", 10, 6 );
	}

	test = engine_input_manager_hold_left();
	if( test )
	{
		data = floorf( numb ) * 1000;
		engine_font_manager_draw_data( data, 13, 7 );
		//engine_font_manager_draw_text( "TEST LEFT", 10, 5 );
	}

	test = engine_input_manager_hold_right();
	if( test )
	{
		data = ceilf( numb ) * 1000;
		engine_font_manager_draw_data( data, 13, 8 );
		//engine_font_manager_draw_text( "TEST LEFT", 10, 5 );
	}

	*screen_type = screen_type_test;
}

#endif//_TEST_SCREEN_H_