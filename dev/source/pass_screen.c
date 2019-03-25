#include "pass_screen.h"
#include "_snd_manager.h"
//#include "hack_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "memo_manager.h"
#include "delay_manager.h"
#include "level_manager.h"
#include "input_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "score_manager.h"
#include "audio_manager.h"
#include "game_manager.h"

#define PASS_SCREEN_DELAY	250

static unsigned char gem_level;

void screen_pass_screen_load()
{
	//struct_hack_object *ho = &global_hack_object;
	struct_level_object *lo = &global_level_object;
	struct_score_object *so = &global_score_object;
	unsigned char perfect = 0;

	//if( ho->hack_delayspeed)
	//{
		engine_audio_manager_sound_level();
	//}

	// Check if player collected all available gems.
	gem_level = so->gem_level;
	if( 0 != lo->gem_level )
	{
		if( gem_level == lo->gem_level )
		{
			perfect = 1;
		}
	}

	engine_delay_manager_load( PASS_SCREEN_DELAY );
	engine_memo_manager_draw_pass( perfect );
}

void screen_pass_screen_update( unsigned char *screen_type )
{
	struct_player_object *po = &global_player_object;
	struct_score_object *so = &global_score_object;
	struct_game_object *go = &global_game_object;

	unsigned char delay;
	//unsigned char input;

	//const unsigned char leftX = 4;
	//const unsigned char rghtX = 11;

	//engine_enemyX_manager_hide_enemys( leftX, rghtX );
	//engine_player_manager_hide( leftX, rghtX );

	delay = engine_delay_manager_update();
	//input = engine_input_manager_hold_fire1();

	//if( delay || input )
	if( delay )
	{
		go->round_no++;
		if( go->round_no >= MAX_ROUNDS )
		{
			go->round_no = 0;
			go->world_no++;

			if( go->world_no >= MAX_WORLDS )
			{
				go->world_no = 0;
				*screen_type = screen_type_beat;
				return;
			}
		}

		// Don't navigate to gems screen until collected at least one gem.
		//if( 0 == so->gem_total )
		//{
			*screen_type = screen_type_load;
			return;
		//}
		//else
		//{
		//	*screen_type = screen_type_gems;
		//	return;
		//}
	}

	// Draw enemies first!
	engine_enemyX_manager_draw_enemys();
	//engine_player_manager_draw();
	engine_player_manager_hide();

	*screen_type = screen_type_pass;
}