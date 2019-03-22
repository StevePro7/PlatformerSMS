#include "over_screen.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "sprite_manager.h"
#include "tile_manager.h"
#include "memo_manager.h"
#include "input_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "audio_manager.h"

void screen_over_screen_load()
{
	unsigned char left, wide, x;
	left = 12;
	wide = 10;
	x = 15;
	engine_memo_manager_draw( left, wide );
	engine_font_manager_draw_text( LOCALE_GAME_MESSAGE1, x, MEMO_TEXT_TOP );
	engine_font_manager_draw_text( LOCALE_GAME_MESSAGE2, x, MEMO_TEXT_BOT );
}

void screen_over_screen_update( unsigned char *screen_type )
{
	unsigned char test;
	test = engine_input_manager_hold_fire2();
	if( test )
	{
		//*screen_type = screen_type_title;
		return;
	}

	// Draw enemies first!
	engine_sprite_manager_draw_enemyX( 160, 80, 388 + 3 * GUARDS_TILES_NUMBER );
	//engine_enemyX_manager_draw_enemys();
	//engine_player_manager_draw();

	*screen_type = screen_type_over;
}