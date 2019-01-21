#ifndef _LEVEL_MANAGER_H_
#define _LEVEL_MANAGER_H__

extern unsigned char level_map[ ROWS * COLS ];

void engine_level_manager_load_level( const unsigned char *level )
{
	const unsigned char *o = level;
	unsigned char x, y, ch;
	unsigned int index;

	for( y = 0; y < ROWS; y++ )
	{
		for( x = 0; x < COLS + 2; x++ )
		{
			ch = *o;
			if( !(ch == CR || ch == LF ) )
			{
				index = y * COLS + x;
				level_map[ index ] = ch;
			}

			o++;
		}
	}

	ch = 'c';
}

void engine_level_manager_draw_level()
{
	unsigned char x, y, ch;
	unsigned int index;

	for( y = 0; y < ROWS; y++ )
	{
		for( x = 0; x < COLS; x++ )
		{
			index = y * COLS + x;
			ch = level_map[ index ];

			engine_font_manager_draw_char( ch, x, y );
		}
	}
}

void engine_level_manager_load_levelXX( const unsigned char *level )
{
	const unsigned char *o = level;
	unsigned char i, j, x, y, ch;
	unsigned int index;

	i = COLS;
	j = ROWS;
	//for( y = 0; y < ROWS; y++ )
	for( y = 0; y < j; y++ )
	{
		//for( x = 0; x < COLS + 2; x++ )
		for( x = 0; x < i + 2; x++ )
		{
			ch = *o;
			/*if( ch == '\n' || ch == '\r' )
			{
			}
			else
			{
			index = y * i + x;
			level_map[ index ] = ch;
			}*/

			if( !( ch == CR || ch == LF ) )
			{
				index = y * i + x;
				level_map[ index ] = ch;
			}

			o++;
		}
	}

	ch = 'c';
}

void engine_level_manager_load_levelX( const unsigned char *level )
{
	unsigned int index = 0;
	unsigned char level_wide = 0;
	unsigned char level_high = 0;

	size_t size = sizeof level;

	//const unsigned char *level = level0201_txt;
	//while( level[ index++ ] != '0x0d' )
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


	level_high = 1;// sizeof( *level );// / sizeof( unsigned char );
	//engine_font_manager_draw_text( "SUZANNE", 1, 5 );

}

void load_room( const unsigned char *map, unsigned char bank )
{
	//const unsigned char *map = level_txt;

	const unsigned char *o = map;// , *line;
	unsigned char i, j, x, y, ch;

	//engine_font_manager_draw_data(3, 10, 1);
	//SMS_mapROMBank( 2 );		// bank2
	SMS_mapROMBank( bank );		// bank4

	for( j = 0; j < ROWS; j++ )
	{
		for( i = 0; i < COLS + 2; i++ )
		{
			ch = *o;
			if( ch == '\n' || ch == '\r' )
			{
			}
			else
			{
				x = i * 2 + TILE_X_OFFSET;
				y = j * 2;
				//engine_font_manager_draw_char(ch, i * 2, j * 2);
				if( ch == '#' )
				{
					//No passable
					//unsigned char rnd = rand() % 9;
					//engine_tile_manager_draw_tile(rnd + 1, i * 2, j * 2);
					unsigned char rnd = rand() % 10;
					engine_tile_manager_draw_tile( rnd, x, y );
				}
				if( ch == 'G' )
				{
					engine_tile_manager_draw_tile( gemscore, x, y );
				}
				if( ch == 'X' )
				{
					engine_tile_manager_draw_tile( exitgame, x, y );
				}
			}

			o++;
		}
	}

	//engine_font_manager_draw_data(5, 10, 0);
}

#endif//_LEVEL_MANAGER_H_