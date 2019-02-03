#include "test_screen.h"

//#include "hack_manager.h"
#include "enum_manager.h"
#include "font_manager.h"

void screen_test_screen_load()
{
	//unsigned char index = hacker_level;
	//const unsigned char *data = leveldata[ index ];
	//const unsigned char size = levelsize[ index ];
	//const unsigned char bank = levelbank[ index ];

	//engine_font_manager_draw_text( "TEST SCREEN", 10, 4 );
	//engine_font_manager_draw_data( index, 15, 5 );
	//engine_font_manager_draw_data( size, 15, 6 );
	//engine_font_manager_draw_data( bank, 15, 7 );
}

void screen_test_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_test;
}