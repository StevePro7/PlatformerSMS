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

static unsigned char get_tile();

void engine_memo_manager_draw( unsigned char left, unsigned char wide )
{
	unsigned char max, x, y;
	max = MEMO_HIGH - 1;
	for( x = 0; x < wide; x++)
	{
		engine_tile_manager_draw_small( left + x, MEMO_Y + 0, get_tile() );
		engine_tile_manager_draw_small( left + x, MEMO_Y + max, get_tile() );
	}

	for( y = 1; y < max; y++ )
	{
		engine_tile_manager_draw_small( left + 0, MEMO_Y + y, get_tile() );
		engine_tile_manager_draw_small( left + wide - 1, MEMO_Y + y, get_tile() );

		for( x = 1; x < wide - 1; x++ )
		{
			engine_font_manager_draw_text( LOCALE_SELECT_SPACE, left + x, MEMO_Y + y );
		}
	}
}


static unsigned char get_tile()
{
	unsigned char idx = rand() % MAX_SMALL_TILES;
	return small_tiles[ idx ];
}