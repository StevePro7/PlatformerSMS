#include "over_screen.h"
#include "global_manager.h"
#include "debug_manager.h"
#include "hack_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "tile_manager.h"
#include "level_manager.h"
#include "anim_manager.h"
#include "input_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "state_manager.h"
#include "audio_manager.h"

void screen_over_screen_load()
{
}

void screen_over_screen_update( unsigned char *screen_type )
{
	unsigned char test;
	test = engine_input_manager_hold_fire2();
	if( test )
	{
		*screen_type = screen_type_title;
		return;
	}

	// Draw enemies first!
	engine_enemyX_manager_draw_enemys();
	engine_player_manager_draw();

	*screen_type = screen_type_over;
}