#ifndef _LEVEL_MANAGER_H_
#define _LEVEL_MANAGER_H__

extern unsigned char level_map[ ROWS * COLS ];
extern unsigned char tiles_map[ ROWS * COLS ];
extern unsigned char crash_map[ ROWS * COLS ];
extern unsigned char level_mat[ ROWS ][ COLS ];
extern unsigned char tiles_mat[ ROWS ][ COLS ];
extern unsigned char crash_mat[ ROWS ][ COLS ];

// Private helper methods.
static void engine_level_manager_draw_tiles( unsigned char x, unsigned char y );

void engine_level_manager_load_level( const unsigned char *level, unsigned char bank )
{
	const unsigned char *o = level;
	unsigned char x, y, tile;
	unsigned int index;
	enum_tile_type tile_type;
	enum_crash_type crash_type;

	SMS_mapROMBank( bank );
	for( y = 0; y < ROWS; y++ )
	{
		for( x = 0; x < COLS + 2; x++ )
		{
			tile = *o;
			if( !(tile == CR || tile == LF ) )
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
			}

			o++;
		}
	}

	tile = 'c';
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
void engine_level_manager_draw_level_column_side( enum_side_type side_type, unsigned char column )
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

			engine_tile_manager_draw_tile_side( side_type, tile, x * 2 + TILE_X_OFFSET, y * 2 );
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

	engine_tile_manager_draw_tile( tile, x * 2 + TILE_X_OFFSET, y * 2 );
}

void engine_level_manager_text_level()
{
	unsigned char x, y, ch;
	unsigned int index;

	for( y = 0; y < ROWS; y++ )
	{
		for( x = 0; x < COLS; x++ )
		{
			index = y * COLS + x;
			ch = level_map[ index ];

			engine_font_manager_draw_char( ch, x + TILE_X_OFFSET, y );
		}
	}
}

void engine_level_manager_load_levelX( const unsigned char *level )
{
	unsigned int index = 0;
	unsigned char level_wide = 0;
	unsigned char level_high = 0;

	size_t size = sizeof level;

	while ( true )
	{
		const unsigned char tile = level[ index ];
		if( CR == tile )
		{
			break;
		}

		index++;
	}

	level_wide = index;


	level_high = 1;
}

void load_room( const unsigned char *map, unsigned char bank )
{
	//const unsigned char *map = level_txt;

	const unsigned char *o = map;// , *line;
	unsigned char i, j, x, y, tile;

	//engine_font_manager_draw_data(3, 10, 1);
	//SMS_mapROMBank( 2 );		// bank2
	SMS_mapROMBank( bank );		// bank4

	for( j = 0; j < ROWS; j++ )
	{
		for( i = 0; i < COLS + 2; i++ )
		{
			tile = *o;
			if( tile == '\n' || tile == '\r' )
			{
			}
			else
			{
				x = i * 2 + TILE_X_OFFSET;
				y = j * 2;
				//engine_font_manager_draw_char(tile, i * 2, j * 2);
				if( tile == '#' )
				{
					//No passable
					//unsigned char rnd = rand() % 9;
					//engine_tile_manager_draw_tile(rnd + 1, i * 2, j * 2);
					unsigned char rnd = rand() % 10;
					engine_tile_manager_draw_tile( rnd, x, y );
				}
				if( tile == 'G' )
				{
					engine_tile_manager_draw_tile( tile_type_gemscore, x, y );
				}
				if( tile == 'X' )
				{
					engine_tile_manager_draw_tile( tile_type_exitgame, x, y );
				}
			}

			o++;
		}
	}
}

#endif//_LEVEL_MANAGER_H_