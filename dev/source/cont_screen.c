#include "cont_screen.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "memo_manager.h"
#include "input_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "score_manager.h"

#define TEXT_X				10
#define TEXT_Y				11
#define OPT1_X				TEXT_X + 0
#define OPT2_X				TEXT_X + 9

static unsigned char cursor;
static unsigned char cursorX[ 2 ] = { OPT1_X, OPT2_X };
static void display_cursor();

void screen_cont_screen_load()
{
	engine_memo_manager_draw_cont();
	cursor = 0;
	display_cursor();
}

void screen_cont_screen_update( unsigned char *screen_type )
{
	unsigned char test[ 4 ] = { 0, 0, 0, 0 };

	const unsigned char leftX = 3;
	const unsigned char rghtX = 11;

	// Draw enemies first!
	engine_enemyX_manager_hide_enemys( leftX, rghtX );
	engine_player_manager_hide( leftX, rghtX );


	test[ 0 ] = engine_input_manager_hold_left();
	test[ 1 ] = engine_input_manager_hold_right();
	if( test[ 0 ] || test[ 1 ] )
	{
		cursor = 1 - cursor;
		display_cursor();
	}

	//test[ 2 ] = engine_input_manager_hold_fire1();
	test[ 2 ] = engine_input_manager_move_fire1();
	if( test[ 2 ] )
	{
		if( 0 == cursor )
		{
			engine_score_manager_reset();
			*screen_type = screen_type_ready;
			return;
		}
		else
		{
			*screen_type = screen_type_over;
			return;
		}
	}

	// if input_manager( fire1 ) then
	// Clear middle section
	// Draw level mid section
	// goto Ready screen
	*screen_type = screen_type_cont;
}

static void display_cursor()
{
	engine_font_manager_draw_text( LOCALE_SELECT_BLANK, OPT1_X, TEXT_Y + 1 );
	engine_font_manager_draw_text( LOCALE_SELECT_BLANK, OPT2_X, TEXT_Y + 1 );
	engine_font_manager_draw_text( LOCALE_SELECT_ARROW, cursorX[ cursor ], TEXT_Y + 1 );
}