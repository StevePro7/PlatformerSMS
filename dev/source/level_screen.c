#include "level_screen.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "input_manager.h"
#include "stats_manager.h"
#include "game_manager.h"
#include "content_manager.h"
#include "tile_manager.h"
#include <stdlib.h>

#define TEXT_X				11
#define TEXT_Y				18
#define OPT1_X				TEXT_X + 7
#define OPT1_Y				TEXT_Y + 1
#define OPT2_Y				TEXT_Y + 2

static unsigned char cursor;
static unsigned char cursorY[ 2 ] = { OPT1_Y, OPT2_Y };
static void display_options();

void screen_level_screen_load()
{
	unsigned char cnt;
	unsigned char x, tile;
	engine_content_manager_load_title();
	for( x = 2; x < SCREEN_TILE_WIDE; x += 2 )
	{
		tile = rand() % MAX_BLOCK_TILES + 1;
		engine_tile_manager_draw_tile( tile, x, 0 );
		tile = rand() % MAX_BLOCK_TILES + 1;
		engine_tile_manager_draw_tile( tile, x, 22 );
	}

	for( cnt = 0; cnt < 3; cnt++ )
	{
		engine_font_manager_draw_text( LOCALE_BLANK_WIDTH, 2, TEXT_Y + cnt );
	}

	engine_font_manager_draw_text( LOCALE_SELECT_LEVEL, TEXT_X + 0, TEXT_Y + 0 );
	engine_font_manager_draw_text( LOCALE_SELECT_WORLD, TEXT_X + 1, TEXT_Y + 1 );
	engine_font_manager_draw_text( LOCALE_SELECT_ROUND, TEXT_X + 1, TEXT_Y + 2 );

	cursor = 1;
	display_options();
}

void screen_level_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_level;
}

static void display_options()
{
	struct_game_object *go = &global_game_object;

	engine_font_manager_draw_text( LOCALE_SELECT_BLANK, OPT1_X, OPT1_Y );
	engine_font_manager_draw_text( LOCALE_SELECT_BLANK, OPT1_X, OPT2_Y );
	engine_font_manager_draw_text( LOCALE_SELECT_ARROW, OPT1_X, cursorY[ cursor ] );

	engine_font_manager_draw_text( count_text[ go->world_no ], OPT1_X + 2, OPT1_Y );
	engine_font_manager_draw_text( count_text[ go->round_no ], OPT1_X + 2, OPT2_Y );
}