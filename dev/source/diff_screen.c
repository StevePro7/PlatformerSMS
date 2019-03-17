#include "diff_screen.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "text_manager.h"
#include "input_manager.h"
#include "game_manager.h"

#define TEXT_X				9
#define TEXT_Y				18
#define OPT1_X				TEXT_X + 0
#define OPT2_X				TEXT_X + 11

static unsigned char cursorX[ 2 ] = { OPT1_X, OPT2_X };
static void display_cursor();

void screen_diff_screen_load()
{
	/*unsigned char cnt;
	for( cnt = 0; cnt < 3; cnt++ )
	{
		engine_font_manager_draw_text( LOCALE_BLANK_WIDTH, 2, TEXT_Y + cnt );
	}*/

	engine_text_manager_cleat_three();
	engine_font_manager_draw_text( LOCALE_SELECT_DIFF, TEXT_X, TEXT_Y );
	engine_font_manager_draw_text( LOCALE_DIFF_EASY, TEXT_X + 2, TEXT_Y + 1 );
	engine_font_manager_draw_text( LOCALE_DIFF_HARD, TEXT_X + 13, TEXT_Y + 1 );

	display_cursor();
}

void screen_diff_screen_update( unsigned char *screen_type )
{
	struct_game_object *go = &global_game_object;
	unsigned char test1, test2, test3;

	test1 = engine_input_manager_hold_left();
	test2 = engine_input_manager_hold_right();
	if( test1 || test2 )
	{
		go->difficulty = 1 - go->difficulty;
		display_cursor();
	}

	test3 = engine_input_manager_hold_fire1();
	if( test3 )
	{
		*screen_type = screen_type_level;
		return;
	}

	*screen_type = screen_type_diff;
}

static void display_cursor()
{
	struct_game_object *go = &global_game_object;
	engine_font_manager_draw_text( LOCALE_SELECT_BLANK, OPT1_X, TEXT_Y + 1 );
	engine_font_manager_draw_text( LOCALE_SELECT_BLANK, OPT2_X, TEXT_Y + 1 );
	engine_font_manager_draw_text( LOCALE_SELECT_ARROW, cursorX[ go->difficulty ], TEXT_Y + 1 );
}