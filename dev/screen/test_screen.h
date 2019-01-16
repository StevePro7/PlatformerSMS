#ifndef _TEST_SCREEN_H_
#define _TEST_SCREEN_H_

void screen_test_screen_load()
{
	engine_font_manager_draw_text( "STEVEPRO", 1, 2 );
}

void screen_test_screen_update( enum_screen_type *screen_type )
{
	bool test = engine_input_manager_hold_right();
	if( test )
	{
		*screen_type = screen_type_splash;
		return;
	}

	*screen_type = screen_type_test;
}

#endif//_TEST_SCREEN_H_