#include "level_manager.h"
#include "level_object.h"
#include "_sms_manager.h"
#include "global_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "tile_manager.h"
#include <stdlib.h>

// Global variable.
struct_level_object global_level_object;

#define CRlf	2				// char
#define CR		'\r'			// 0x0d
#define LF		'\n'			// 0x0a

//unsigned char level_map[ ROWS * COLS ];
//unsigned char tiles_map[ ROWS * COLS ];
//unsigned char crash_map[ ROWS * COLS ];
//unsigned char level_mat[ ROWS ][ COLS ];
//unsigned char tiles_mat[ ROWS ][ COLS ];
//unsigned char crash_mat[ ROWS ][ COLS ];

// Private helper methods.
static void engine_level_manager_draw_tiles( unsigned char x, unsigned char y );
static void load_entities( enum_sprite_type sprite_type, unsigned char index );

void engine_level_manager_init_level()
{
	struct_level_object *lo = &global_level_object;
	unsigned char idx, row, col;

	for( row = 0; row < MAX_ROWS; row++ )
	{
		for( col = 0; col < MAX_COLS; col++ )
		{
			idx = row * MAX_COLS + col;
			lo->collision_array[ idx ] = 0;
		}
	}
}

static void load_entities( enum_sprite_type sprite_type, unsigned char index )
{
	struct_level_object *lo = &global_level_object;
	if( sprite_type_player == sprite_type )
	{
		engine_font_manager_draw_data( index, 10, 10 );
	}
}

void engine_level_manager_load_level( const unsigned char *level, const unsigned char bank, const unsigned char size )
{
	struct_level_object *lo = &global_level_object;
	const unsigned char *o = level;
	//unsigned char x, y, tile;
	unsigned char row, col;
	unsigned char tile;
	
	//unsigned char idx, row, col;
	unsigned int idx;
	enum_tile_type tile_type;
	enum_coll_type coll_type;
	enum_sprite_type sprite_type;

	lo->load_cols = size / MAX_ROWS;
	lo->draw_cols = lo->load_cols - CRlf;

	devkit_SMS_mapROMBank( bank );
	for( row = 0; row < MAX_ROWS; row++ )
	{
		//y = row;
		for( col = 0; col < lo->load_cols; col++ )
		{
			//x = col;
			tile = *o;
			if( !( tile == CR || tile == LF ) )
			{
				//idx = y * COLS + x;
				idx = row * COLS + col;
				//level_map[ idx ] = tile;
				//level_mat[ row ][ col ] = tile;

				engine_tile_manager_get_tile( &tile_type, tile );
				lo->drawtiles_array[ idx ] = tile_type;
				//tiles_map[ idx ] = tile_type;
				//tiles_mat[ row ][ col ] = tile_type;

				engine_tile_manager_get_collision( &coll_type, tile );
				//crash_map[ idx ] = coll_type;
				//crash_mat[ row ][ col ] = coll_type;

				engine_tile_manager_get_sprite( &sprite_type, tile );
				if( sprite_type_unknown != sprite_type )
				{
					load_entities( sprite_type, idx );
				}

				//lo->collision_matrix[ index ] = coll_type;
				lo->collision_array[ idx ] = coll_type;
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
	struct_level_object *lo = &global_level_object;
	unsigned char row, col;

	for( row = 0; row < MAX_ROWS; row++ )
	{
		for( col = 0; col < lo->draw_cols; col++ )
		{
			engine_level_manager_draw_tiles( col, row );
		}
	}
}
void engine_level_manager_draw_levelX()
{
	struct_level_object *lo = &global_level_object;
	unsigned char x, y;
	for( y = 0; y < MAX_ROWS; y++ )
	{
		for( x = 0; x < lo->draw_cols; x++ )
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
	struct_level_object *lo = &global_level_object;
	unsigned char x, y, tile;
	unsigned int idx;

	x = column;
	for( y = 0; y < MAX_ROWS; y++ )
	{
		idx = y * lo->draw_cols + x;
		//tile = tiles_map[ index ];
		tile = lo->drawtiles_array[ idx ];
		//tile = tiles_mat[ y ][ x ];

		if( tile_type_blankGap != tile )
		{
			engine_tile_manager_draw_tile_side( side_type, tile, x * 2 + TILE_X_OFFSET, y * 2 );
		}
	}
}

//TODO delete this method
void engine_level_manager_load_levelX()
{
	enum_tile_type tile_type;
	unsigned char x;

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
}

void engine_level_manager_get_collision( unsigned char *coll_type, unsigned char x, unsigned char y )
{
	struct_level_object *lo = &global_level_object;
	unsigned int idx;

	idx = y * lo->draw_cols + x;
	*coll_type = lo->collision_array[ idx ];
}

static void engine_level_manager_draw_tiles( unsigned char x, unsigned char y )
{
	struct_level_object *lo = &global_level_object;
	unsigned char tile;
	unsigned int idx;

	//idx = y * COLS + x;
	idx = y * lo->draw_cols + x;
	//tile = tiles_map[ idx ];
	tile = lo->drawtiles_array[ idx ];
	//tile = tiles_map[ index ];
	//tile = tiles_mat[ y ][ x ];

	if( tile_type_blankGap != tile )
	{
		engine_tile_manager_draw_tile( tile, x * 2 + TILE_X_OFFSET, y * 2 );
	}
}