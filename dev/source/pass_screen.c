#include "pass_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "memo_manager.h"
#include "delay_manager.h"
#include "input_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "score_manager.h"
#include "game_manager.h"

#define PASS_SCREEN_DELAY	20

static enum_pass_type pass_type;

void screen_pass_screen_load()
{
	unsigned char perfect = 0;
	pass_type = pass_type_prev;

	engine_delay_manager_load( PASS_SCREEN_DELAY );
	engine_memo_manager_draw_pass( perfect );
}

void screen_pass_screen_update( unsigned char *screen_type )
{
	struct_score_object *so = &global_score_object;
	struct_game_object *go = &global_game_object;
	unsigned char delay;
	unsigned char input;

	const unsigned char leftX = 4;
	const unsigned char rghtX = 11;

	// Draw enemies first!
	engine_enemyX_manager_hide_enemys( leftX, rghtX );
	engine_player_manager_hide( leftX, rghtX );

	delay = engine_delay_manager_update();
	input = engine_input_manager_hold_fire1();

	if( delay || input )
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
		if( 0 == so->gem_total )
		{
			*screen_type = screen_type_load;
			return;
		}
		else
		{
			*screen_type = screen_type_gems;
			return;
		}
		
	}

	*screen_type = screen_type_pass;
}