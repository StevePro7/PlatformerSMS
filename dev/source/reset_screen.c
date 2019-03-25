#include "reset_screen.h"
#include "delay_manager.h"
#include "enum_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "audio_manager.h"

#define RESET_SCREEN_DELAY		75

void screen_reset_screen_load()
{
	engine_audio_manager_sound_reset();
	engine_delay_manager_load( RESET_SCREEN_DELAY );
}

void screen_reset_screen_update( unsigned char *screen_type )
{
	unsigned char delay;

	engine_enemyX_manager_draw_enemys();	

	delay = engine_delay_manager_update();
	if( delay )
	{
		*screen_type = screen_type_ready;
		return;
	}

	// Draw enemies first!

//	engine_player_manager_draw();

	*screen_type = screen_type_reset;
}