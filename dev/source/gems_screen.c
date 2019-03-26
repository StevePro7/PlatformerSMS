#include "gems_screen.h"
#include "enum_manager.h"
#include "tile_manager.h"
#include "memo_manager.h"
#include "delay_manager.h"
#include "reset_manager.h"
#include "input_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "score_manager.h"
#include "audio_manager.h"
#include "game_manager.h"

#define GEMS_SCREEN_DELAY1		150
#define GEMS_SCREEN_DELAY2		75

static unsigned char stage;

void screen_gems_screen_load()
{
	engine_audio_manager_music_stop();
	engine_delay_manager_load( GEMS_SCREEN_DELAY1 );
	engine_memo_manager_draw_gems();

	engine_tile_manager_draw_tile( tile_type_gemscore, 13, 21 );
	engine_score_manager_draw_score( 20, 22 );

	engine_reset_manager_load( GEMS_SCREEN_DELAY2 );
	stage = event_stage_start;
}

void screen_gems_screen_update( unsigned char *screen_type )
{
	unsigned char delay;
	unsigned char input;  
	unsigned char check;

	if( event_stage_pause == stage )
	{
		delay = engine_delay_manager_update();
		if( delay )
		{
			*screen_type = screen_type_begin;
			return;
		}
		else
		{
			*screen_type = screen_type_gems;
			return;
		}
	}


	delay = engine_delay_manager_update();
	input = engine_input_manager_move_fire2();

	if( input )
	{
		check = engine_reset_manager_update();
		if( check )
		{
			engine_audio_manager_sound_reset();
			engine_delay_manager_load( GEMS_SCREEN_DELAY2 );
			stage = event_stage_pause;
			//*screen_type = screen_type_begin;
			return;
		}
	}
	else
	{
		engine_reset_manager_reset();
	}

	//if( delay || input )
	if( delay )
	{
		*screen_type = screen_type_load;
		return;
	}

	// Draw enemies first!
	engine_enemyX_manager_draw_enemys();
	engine_player_manager_hide();

	*screen_type = screen_type_gems;
}