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
//static void wipe_memo( unsigned char *text );
static unsigned char get_tile();

void engine_memo_manager_init()
{
	border = 1;
}

void engine_memo_manager_draw( unsigned char left, unsigned char wide )
{
	unsigned char max, x, y;
	max = MEMO_HIGH - 1;
	//max = MEMO_HIGH - 2;
	
	for( x = 0; x < wide; x++)
	{
		engine_tile_manager_draw_small( left + x, MEMO_Y + 0, get_tile() );
		engine_tile_manager_draw_small( left + x, MEMO_Y + max, get_tile() );
	}

	for( y = 1; y < max; y++ )
	{
		engine_tile_manager_draw_small( left + 0, MEMO_Y + y, get_tile() );
		engine_tile_manager_draw_small( left + wide - 1, MEMO_Y + y, get_tile() );

		/*for( x = 1; x < wide - 1; x++ )
		{
			engine_font_manager_draw_text( LOCALE_SELECT_SPACE, left + x, MEMO_Y + y );
		}*/
	}

	//for( x = 0; x < wide / 2; x += 2 )
	//{
	//	tile = rand() % MAX_BLOCK_TILES + 1;
	//	engine_tile_manager_draw_tile( tile, left + x, MEMO_Y + 0 );
	//	tile = rand() % MAX_BLOCK_TILES + 1;
	//	engine_tile_manager_draw_tile( tile, left + x, MEMO_Y + max );

	//	//engine_tile_manager_draw_small( left + x, MEMO_Y + 0, get_tile() );
	//	//engine_tile_manager_draw_small( left + x, MEMO_Y + max, get_tile() );
	//}
}

void engine_memo_manager_draw_level( const unsigned char world, const unsigned char round )
{
	engine_font_manager_draw_text( LOCALE_BLANK_SIZE10, 12, 10 );
	engine_font_manager_draw_text( LOCALE_SELECT_WORLD, 12, 11 );
	engine_font_manager_draw_text( count_text[ world ], 19, 11 );

	engine_font_manager_draw_text( LOCALE_SELECT_ROUND, 12, 12 );
	engine_font_manager_draw_text( count_text[ round ], 19, 12 );
	engine_font_manager_draw_text( LOCALE_BLANK_SIZE10, 12, 13 );

	if( !border )
	{
		return;
	}

	engine_font_manager_draw_text( LOCALE_BLANK_SIZE10, 12, 9 );
	engine_font_manager_draw_text( LOCALE_BLANK_SIZE10, 12, 14 );
	engine_memo_manager_draw( 11, 12 );
}

//void engine_memo_manager_wipe_level()
//{
//	wipe_memo( LOCALE_BLANK_SIZE10 );
//}

void engine_memo_manager_draw_pass()
{
}
void engine_memo_manager_draw_gems()
{
}

void engine_memo_manager_draw_cont()
{
	engine_font_manager_draw_text( LOCALE_BLANK_SIZE16, 9, 10 );
	engine_font_manager_draw_text( LOCALE_CONT_MESSAGE, 9, 11 );
	engine_font_manager_draw_text( LOCALE_CONT_YESORNO, 9, 12 );
	engine_font_manager_draw_text( LOCALE_BLANK_SIZE16, 9, 13 );
}

void engine_memo_manager_draw_over()
{
}
/*
static void wipe_memo( unsigned char *text )
{
	engine_font_manager_draw_text( text, 12, 11 );
	engine_font_manager_draw_text( text, 12, 12 );

	if( !border )
	{
		return;
	}

	engine_font_manager_draw_text( text, 12, 9 );
	engine_font_manager_draw_text( text, 12, 13 );
}
*/
static unsigned char get_tile()
{
	unsigned char idx = rand() % MAX_SMALL_TILES;
	return small_tiles[ idx ];
}