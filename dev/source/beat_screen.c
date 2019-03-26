#include "beat_screen.h"
#include "enum_manager.h"
#include "memo_manager.h"
#include "delay_manager.h"
#include "input_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include <stdlib.h>
#include "audio_manager.h"

#define BEAT_SCREEN_DELAY	50

void screen_beat_screen_load()
{
	engine_audio_manager_music_beat();
	engine_delay_manager_load( BEAT_SCREEN_DELAY );
	engine_memo_manager_draw_beat();
}

void screen_beat_screen_update( unsigned char *screen_type )
{
	unsigned char delay;
	//unsigned char input;

	// Draw enemies first!
	engine_enemyX_manager_draw_enemys();
	engine_player_manager_draw();

	delay = engine_delay_manager_update();
//	input = engine_input_manager_hold_fire1();

	//if( delay || input )
	if( delay )
	{
		*screen_type = screen_type_begin;
		return;
	}

	*screen_type = screen_type_beat;
}