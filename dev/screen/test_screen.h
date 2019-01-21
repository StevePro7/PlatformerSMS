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

	engine_font_manager_draw_data( test, 10, 4 );

	/*while( true )
	{
		unsigned char rnd = rand() % MAX_BLOCK_TILES + 1;
		if( 9 == rnd )
		{
			int x = 7;
		}
	}*/
}

void screen_test_screen_update( enum_screen_type *screen_type )
{
	bool test = engine_input_manager_hold_left();
	if( test )
	{
		*screen_type = screen_type_load;
		return;
	}

	*screen_type = screen_type_test;
}

#endif//_TEST_SCREEN_H_