#include "level_manager.h"
#include "level_object.h"
#include "_sms_manager.h"
#include "global_manager.h"
#include "font_manager.h"
#include "tile_manager.h"
#include <stdlib.h>

// Global variable.
struct_level_object global_level_object;

unsigned char level_map[ ROWS * COLS ];
unsigned char tiles_map[ ROWS * COLS ];
unsigned char crash_map[ ROWS * COLS ];
unsigned char level_mat[ ROWS ][ COLS ];
unsigned char tiles_mat[ ROWS ][ COLS ];
unsigned char crash_mat[ ROWS ][ COLS ];

// Private helper methods.
static void engine_level_manager_draw_tiles( unsigned char x, unsigned char y );

void engine_level_manager_load_levelX()
{
	struct_level_object *lo = &global_level_object;

	enum_tile_type tile_type;
	//engine_font_manager_draw_data( 100, 6, 6 );
	unsigned char x;
	unsigned char idx;
	unsigned char ww = 15;
	unsigned char hh = 12;
	unsigned char size = ww * hh;
	unsigned char row = 1;
	unsigned char col = 2;

	idx = ww * row + col;

	
	for( x = 0; x < 32; x += 2 )
	{
		tile_type = rand() % MAX_BLOCK_TILES + 1;				// rand() <stdlib.h>
		engine_tile_manager_draw_tile( tile_type, x, 4 );
		//tile_type = rand() % MAX_BLOCK_TILES + 1;
		//engine_tile_manager_draw_tile( tile_type, x, 22 );
	}

	//tile_type = rand() % MAX_BLOCK_TILES + 1;
	//engine_tile_manager_draw_tile( tile_type, 14, 12 );	engine_tile_manager_draw_tile( tile_type, 14, 14 );
	//tile_type = rand() % MAX_BLOCK_TILES + 1;
	//engine_tile_manager_draw_tile( tile_type, 14, 18 );	engine_tile_manager_draw_tile( tile_type, 14, 16 );

	//tile_type = rand() % MAX_BLOCK_TILES + 1;
	//engine_tile_manager_draw_tile( tile_type, 12, 14 );

	engine_font_manager_draw_data( idx, 15, 10 );

	// NULL <stdlib.h>
	if( NULL == lo->collision_matrix )
	{
		engine_font_manager_draw_data( 2, 15, 11 );
		lo->collision_matrix = malloc( size * sizeof( unsigned char ) );
		lo->collision_matrix[ 17 ] = 9;

		engine_font_manager_draw_data( 4, 15, 12 );
		engine_font_manager_draw_data( lo->collision_matrix[ 0 ], 25, 12 );

		if( NULL == lo->collision_matrix )
		{
			engine_font_manager_draw_data( 55, 25, 12 );
		}
		engine_font_manager_draw_data( lo->collision_matrix[ idx ], 25, 14 );

		free( lo->collision_matrix );
		lo->collision_matrix = NULL;
		engine_font_manager_draw_data( 6, 15, 13 );
		if( NULL == lo->collision_matrix )
		{
			engine_font_manager_draw_data( 66, 25, 13 );
		}
	}
	else
	{
		free( lo->collision_matrix );
		lo->collision_matrix = NULL;
	}
}

void engine_level_manager_load_level( const unsigned char *level, const unsigned char bank, const unsigned char size )
{
	struct_level_object *lo = &global_level_object;
	const unsigned char *o = level;
	unsigned char x, y, tile;
	unsigned int index;
	enum_tile_type tile_type;
	enum_crash_type crash_type;
	index = size;					// TODO use size to calculate wide i.e. (size / 12) - 2		12=high	2=CRLF

	devkit_SMS_mapROMBank( bank );
	for( y = 0; y < ROWS; y++ )
	{
		for( x = 0; x < COLS + 2; x++ )
		{
			tile = *o;
			if( !( tile == CR || tile == LF ) )
			{
				index = y * COLS + x;
				level_map[ index ] = tile;
				level_mat[ y ][ x ] = tile;

				engine_tile_manager_get_tile( &tile_type, tile );
				tiles_map[ index ] = tile_type;
				tiles_mat[ y ][ x ] = tile_type;

				engine_tile_manager_get_crash( &crash_type, tile );
				crash_map[ index ] = crash_type;
				crash_mat[ y ][ x ] = crash_type;

				//lo->collision_matrix[ index ] = crash_type;
			}

			o++;
		}
	}
}

void engine_level_manager_load_index( const unsigned char index )
{
	const unsigned char *level = leveldata[ index ];
	const unsigned char bank = levelbank[ index ];
	const unsigned char size = levelsize[ index ];

	engine_level_manager_load_level( level, bank, size );
}

void engine_level_manager_draw_level()
{
	unsigned char x, y;
	for( y = 0; y < ROWS; y++ )
	{
		for( x = 0; x < COLS; x++ )
		{
			engine_level_manager_draw_tiles( x, y );
		}
	}
}

void engine_level_manager_draw_level_column( unsigned char column )
{
	unsigned char x, y;

	x = column;
	for( y = 0; y < ROWS; y++ )
	{
		engine_level_manager_draw_tiles( x, y );
	}
}
void engine_level_manager_draw_level_column_side( unsigned side_type, unsigned char column )
{
	unsigned char x, y, tile;
	unsigned int index;

	for( y = 0; y < ROWS; y++ )
	{
		x = column;
		for( y = 0; y < ROWS; y++ )
		{
			index = y * COLS + x;
			//tile = tiles_map[ index ];
			tile = tiles_mat[ y ][ x ];

			if( 0 != tile )
			{
				engine_tile_manager_draw_tile_side( side_type, tile, x * 2 + TILE_X_OFFSET, y * 2 );
			}
		}
	}
}

static void engine_level_manager_draw_tiles( unsigned char x, unsigned char y )
{
	unsigned char tile;
	unsigned int index;

	index = y * COLS + x;
	//tile = tiles_map[ index ];
	tile = tiles_mat[ y ][ x ];

	if( 0 != tile )
	{
		engine_tile_manager_draw_tile( tile, x * 2 + TILE_X_OFFSET, y * 2 );
	}
}