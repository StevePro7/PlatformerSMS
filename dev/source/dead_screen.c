#include "dead_screen.h"
#include "global_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "memo_manager.h"
#include "input_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"


#define DECAPITATE	20

void screen_dead_screen_load()
{
	struct_player_object *po = &global_player_object;

	// If player jumps through ceiling and dies then ouch!
	if( po->posnY < 2 * TILE_HIGH )
	{
		po->posnY = DECAPITATE;
	}

	engine_memo_manager_draw_dead();
}

void screen_dead_screen_update( unsigned char *screen_type )
{
	struct_player_object *po = &global_player_object;
	unsigned char test;

	const unsigned char leftX = 4;
	const unsigned char rghtX = 10;

	test = engine_input_manager_hold_fire2();
	if( test )
	{
		*screen_type = screen_type_ready;
		return;
	}

	// Draw enemies first!
	engine_enemyX_manager_hide_enemys( leftX, rghtX );

	// Don't draw if player in pit
	if( po->posnY >= 0 )
	{
		engine_player_manager_hide( leftX, rghtX );
	}

	*screen_type = screen_type_dead;
}