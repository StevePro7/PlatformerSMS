#include "reset_screen.h"
#include "delay_manager.h"
#include "enum_manager.h"
#include "memo_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "audio_manager.h"

#define RESET_SCREEN_DELAY		75

static unsigned char stage;

void screen_reset_screen_load()
{
	engine_audio_manager_sound_reset();
	engine_delay_manager_load( RESET_SCREEN_DELAY );
	engine_memo_manager_draw_reset();
	stage = event_stage_start;
}

void screen_reset_screen_update( unsigned char *screen_type )
{
	unsigned char delay;
	engine_enemyX_manager_draw_enemys();

	if( event_stage_pause == stage )
	{
		delay = engine_delay_manager_update();
		if( delay )
		{
			*screen_type = screen_type_ready;
			return;
		}
		else
		{
			*screen_type = screen_type_reset;
			return;
		}
	}

	delay = engine_delay_manager_update();
	if( delay )
	{
		//*screen_type = screen_type_ready;
		stage = event_stage_pause;
		engine_delay_manager_load( 25 );
		return;
	}

	// Draw enemies first!
	engine_player_manager_draw();

	*screen_type = screen_type_reset;
}