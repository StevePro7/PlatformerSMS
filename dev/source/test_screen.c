#include "test_screen.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "content_manager.h"
#include "sprite_manager.h"

void screen_test_screen_load()
{
	unsigned char x, y;
	x = 10;
	y = 10;
	engine_font_manager_draw_text( "TEST SCREEN!!", 10, 0 );
	engine_content_manager_load_enemies();

	engine_sprite_manager_draw_guard( x, y );
}

void screen_test_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_test;
}