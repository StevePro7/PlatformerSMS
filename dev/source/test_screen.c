#include "test_screen.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "memo_manager.h"
#include "input_manager.h"
#include "audio_manager.h"

void screen_test_screen_load()
{
	/*unsigned char y, m, d;
	for( y = 0; y < 24; y++ )
	{
		m = rand() % 2;
		engine_font_manager_draw_data( m, 10, y );
		d = m * 2;
		engine_font_manager_draw_data( d, 25, y );
	}*/

	//engine_font_manager_draw_text( "TEST SCREENX", 10, 0 );

	//engine_memo_manager_draw_dead();
	//engine_memo_manager_draw_over();
	//engine_memo_manager_draw_level( 0, 0 );
	engine_memo_manager_draw_beat();

	//engine_content_manager_load_guards();
	//engine_tile_manager_draw_guard( x, y, sprite_type_enemyA );
	//engine_tile_manager_draw_guard( 12, y, sprite_type_enemyB );
	//engine_tile_manager_draw_guard( 20, y, sprite_type_enemyC );
	//engine_tile_manager_draw_guard( 28, y, sprite_type_enemyD );
}

void screen_test_screen_update( unsigned char *screen_type )
{
	unsigned char test[ 4 ] = { 0,0,0,0 };

	test[ 0 ] = engine_input_manager_hold_left();
	if( test[ 0 ] )
	{
		engine_font_manager_draw_text( "PRESS LEFT", 10, 1 );
		engine_audio_manager_sound_accept();
	}

	*screen_type = screen_type_test;
}