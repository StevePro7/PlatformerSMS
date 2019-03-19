#include "test_screen.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "content_manager.h"
#include "tile_manager.h"

void screen_test_screen_load()
{
	unsigned char x, y;
	x = 4;
	y = 10;
	engine_font_manager_draw_text( "TEST SCREEN!!", 10, 0 );
	engine_content_manager_load_guards();

	engine_tile_manager_draw_guard( x, y, sprite_type_enemyA );
	engine_tile_manager_draw_guard( 12, y, sprite_type_enemyB );
	engine_tile_manager_draw_guard( 20, y, sprite_type_enemyC );
	engine_tile_manager_draw_guard( 28, y, sprite_type_enemyD );
}

void screen_test_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_test;
}