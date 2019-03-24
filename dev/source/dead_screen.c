#include "dead_screen.h"
#include "global_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "memo_manager.h"
#include "delay_manager.h"
#include "input_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "score_manager.h"
#include "audio_manager.h"

#define DEAD_SCREEN_DELAY		200
#define DEAD_DECAPITATE			20

void screen_dead_screen_load()
{
	struct_player_object *po = &global_player_object;

	engine_audio_manager_sound_death();
	engine_delay_manager_load( DEAD_SCREEN_DELAY );

	// If player jumps through ceiling and dies then ouch!
	if( po->posnY < 2 * TILE_HIGH )
	{
		po->posnY = DEAD_DECAPITATE;
	}

	engine_memo_manager_draw_dead();
	engine_score_manager_update_lives( -1 );
}

void screen_dead_screen_update( unsigned char *screen_type )
{
	struct_player_object *po = &global_player_object;
	struct_score_object *so = &global_score_object;
	unsigned char delay;
	unsigned char input;

	//const unsigned char leftX = 4;
	//const unsigned char rghtX = 10;

	// Draw enemies first!
	engine_enemyX_manager_draw_enemys();
	//engine_enemyX_manager_hide_enemys( leftX, rghtX );

	// Don't draw if player in pit.
	if( po->posnY >= 0 )
	{
		engine_player_manager_draw();
		//engine_player_manager_hide( leftX, rghtX );
	}

	delay = engine_delay_manager_update();
	input = engine_input_manager_hold_fire1();

	if( delay || input )
	{
		if( so->num_lives <= 0 )
		{
			*screen_type = screen_type_cont;
			return;
		}

		*screen_type = screen_type_ready;
		return;
	}

	*screen_type = screen_type_dead;
}