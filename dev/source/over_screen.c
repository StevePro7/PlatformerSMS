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
	engine_memo_manager_draw_over();
}

void screen_over_screen_update( unsigned char *screen_type )
{
	unsigned char test;

	const unsigned char leftX = 5;
	const unsigned char rghtX = 10;

	// Draw enemies first!
	engine_enemyX_manager_hide_enemys( leftX, rghtX );
	engine_player_manager_hide( leftX, rghtX );


	test = engine_input_manager_hold_fire2();
	if( test )
	{
		//*screen_type = screen_type_title;
		return;
	}

	*screen_type = screen_type_over;
}