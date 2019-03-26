#include "over_screen.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "sprite_manager.h"
#include "tile_manager.h"
#include "memo_manager.h"
#include "delay_manager.h"
#include "input_manager.h"
#include "level_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "audio_manager.h"

#define OVER_SCREEN_DELAY		250

void screen_over_screen_load()
{
	engine_audio_manager_music_over();
	engine_delay_manager_load( OVER_SCREEN_DELAY );
	//engine_level_manager_draw_section();
//	engine_enemyX_manager_draw_guards();
	engine_memo_manager_draw_over();
}

void screen_over_screen_update( unsigned char *screen_type )
{
	unsigned char delay;
	//unsigned char input;

	// Draw enemies first!
	engine_enemyX_manager_draw_enemys();
	engine_player_manager_draw();

	delay = engine_delay_manager_update();
	//input = engine_input_manager_hold_fire1();

	//if( delay || input )
	if( delay )
	{
		engine_audio_manager_music_stop();
		*screen_type = screen_type_begin;
		return;
	}

	*screen_type = screen_type_over;
}