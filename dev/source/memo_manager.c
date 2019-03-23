#include "memo_manager.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "content_manager.h"
#include "tile_manager.h"
#include <stdlib.h>

#define MEMO_Y			9
#define MEMO_HIGH		6

static unsigned char small_tiles[ MAX_SMALL_TILES ] =
{
	tile_type_blockA,
	tile_type_blockB,
	tile_type_blockC,
};

static unsigned char border;
static unsigned char get_tile();
static void draw_tile( unsigned char left, unsigned char wide );
static void draw_memo( unsigned char *blank, unsigned char *text1, unsigned char *text2, unsigned char x, unsigned char wide );

void engine_memo_manager_init()
{
	border = 1;
}

void engine_memo_manager_draw_level( const unsigned char world, const unsigned char round )
{
	unsigned char x = 12;
	unsigned char wide = 12;
	draw_memo( LOCALE_BLANK_SIZE10, LOCALE_SELECT_WORLD, LOCALE_SELECT_ROUND, x, wide );

	engine_font_manager_draw_text( count_text[ world ], x + 7, 11 );
	engine_font_manager_draw_text( count_text[ round ], x + 7, 12 );
}

void engine_memo_manager_draw_pass( unsigned char perfect )
{
	unsigned char x = 13;
	unsigned char wide = 12;

	if( perfect )
	{
		draw_memo( LOCALE_BLANK_SIZE10, LOCALE_PASS_MESSAGE1, LOCALE_PASS_MESSAGE3, x, wide );
	}
	else
	{
		draw_memo( LOCALE_BLANK_SIZE10, LOCALE_PASS_MESSAGE1, LOCALE_PASS_MESSAGE2, x, wide );
	}
	
}
void engine_memo_manager_draw_gems()
{
	unsigned char x = 12;
	unsigned char wide = 14;
	draw_memo( LOCALE_BLANK_SIZE12, LOCALE_PASS_COLLECT, LOCALE_BLANK_SIZE12, x, wide );
}

void engine_memo_manager_draw_dead()
{
	unsigned char x = 13;
	unsigned char wide = 12;
	draw_memo( LOCALE_BLANK_SIZE10, LOCALE_DEAD_MESSAGE1, LOCALE_DEAD_MESSAGE2, x, wide );
}

void engine_memo_manager_draw_cont()
{
	unsigned char x = 9;
	unsigned char wide = 18;
	draw_memo( LOCALE_BLANK_SIZE10, LOCALE_CONT_MESSAGE, LOCALE_CONT_YESORNO, x, wide );
}

void engine_memo_manager_draw_over()
{
	unsigned char x = 15;
	unsigned char wide = 8;
	draw_memo( LOCALE_BLANK_SIZE8, LOCALE_GAME_MESSAGE1, LOCALE_GAME_MESSAGE2, x, wide );
}

static unsigned char get_tile()
{
	unsigned char idx = rand() % MAX_SMALL_TILES;
	return small_tiles[ idx ];
}
static void draw_tile( unsigned char left, unsigned char wide )
{
	unsigned char max, x, y;
	max = MEMO_HIGH - 1;

	for( x = 0; x < wide; x++ )
	{
		engine_tile_manager_draw_small( left + x, MEMO_Y + 0, get_tile() );
		engine_tile_manager_draw_small( left + x, MEMO_Y + max, get_tile() );
	}

	for( y = 1; y < max; y++ )
	{
		engine_tile_manager_draw_small( left + 0, MEMO_Y + y, get_tile() );
		engine_tile_manager_draw_small( left + wide - 1, MEMO_Y + y, get_tile() );
	}
}
static void draw_memo( unsigned char *blank, unsigned char *text1, unsigned char *text2, unsigned char x, unsigned char wide )
{
	unsigned char left = x - 1;
	engine_font_manager_draw_text( blank, x, 10 );
	engine_font_manager_draw_text( text1, x, 11 );
	engine_font_manager_draw_text( text2, x, 12 );
	engine_font_manager_draw_text( blank, x, 13 );

	if( !border )
	{
		return;
	}

	engine_font_manager_draw_text( blank, x, 9 );
	engine_font_manager_draw_text( blank, x, 14 );
	draw_tile( left, wide );
}