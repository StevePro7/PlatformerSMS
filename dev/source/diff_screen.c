#include "diff_screen.h"
#include "_sms_manager.h"
#include "global_manager.h"
#include "enum_manager.h"
#include "locale_manager.h"
#include "font_manager.h"
#include "content_manager.h"
#include "input_manager.h"
#include "tile_manager.h"
#include "game_manager.h"
#include <stdlib.h>

#define TEXT_X				8
#define TEXT_Y				18
#define OPT1_X				TEXT_X + 0
#define OPT2_X				TEXT_X + 11

static unsigned char cursorX[ 2 ] = { OPT1_X, OPT2_X };
static void display_cursor();

void screen_diff_screen_load()
{
	struct_game_object *go = &global_game_object;
	/*unsigned char x, tile;

	engine_content_manager_load_title();
	for( x = 2; x < SCREEN_TILE_WIDE; x += 2 )
	{
		tile = rand() % MAX_BLOCK_TILES + 1;
		engine_tile_manager_draw_tile( tile, x, 0 );
		tile = rand() % MAX_BLOCK_TILES + 1;
		engine_tile_manager_draw_tile( tile, x, 22 );
	}*/

	engine_font_manager_draw_text( LOCALE_BLANK_WIDTH, 2, TEXT_Y );
	engine_font_manager_draw_text( LOCALE_SELECT_DIFF, TEXT_X, TEXT_Y );

	engine_font_manager_draw_text( LOCALE_DIFF_EASY, TEXT_X + 2, TEXT_Y + 1 );
	engine_font_manager_draw_text( LOCALE_DIFF_HARD, TEXT_X + 13, TEXT_Y + 1 );

	display_cursor();
	engine_font_manager_draw_text( LOCALE_BUILD_VERSION, 28, 21 );
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
		*screen_type = screen_type_intro;
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