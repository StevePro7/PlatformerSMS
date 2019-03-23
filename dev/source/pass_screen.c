#include "pass_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "memo_manager.h"
#include "input_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"

void screen_pass_screen_load()
{
	unsigned char perfect = 0;
	engine_memo_manager_draw_pass( perfect );

	// Part #2
	//engine_memo_manager_draw_gems();
}

void screen_pass_screen_update( unsigned char *screen_type )
{
	unsigned char test;

	const unsigned char leftX = 4;
	const unsigned char rghtX = 11;

	// Draw enemies first!
	engine_enemyX_manager_hide_enemys( leftX, rghtX );
	engine_player_manager_hide( leftX, rghtX );

	test = engine_input_manager_hold_fire2();
	if( test )
	{
		*screen_type = screen_type_ready;
		return;
	}

	
	*screen_type = screen_type_pass;
}