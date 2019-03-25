#include "gems_screen.h"
#include "enum_manager.h"
#include "tile_manager.h"
#include "memo_manager.h"
#include "delay_manager.h"
#include "input_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "score_manager.h"
#include "game_manager.h"

#define GEMS_SCREEN_DELAY		150

void screen_gems_screen_load()
{
	engine_delay_manager_load( GEMS_SCREEN_DELAY );
	engine_memo_manager_draw_gems();

	engine_tile_manager_draw_tile( tile_type_gemscore, 13, 21 );
	engine_score_manager_draw_score( 20, 22 );
}

void screen_gems_screen_update( unsigned char *screen_type )
{
	unsigned char delay;
	unsigned char input;

	//const unsigned char leftX = 4;
	//const unsigned char rghtX = 11;

	//engine_enemyX_manager_hide_enemys( leftX, rghtX );
	//engine_player_manager_hide( leftX, rghtX );

	delay = engine_delay_manager_update();
	input = engine_input_manager_hold_fire1();

	if( delay || input )
	{
		*screen_type = screen_type_load;
		return;
	}

	// Draw enemies first!
	engine_enemyX_manager_draw_enemys();
	engine_player_manager_hide();

	*screen_type = screen_type_gems;
}