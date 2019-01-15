#ifndef _LEVEL_MANAGER_H_
#define _LEVEL_MANAGER_H__

#define COLS	15
#define ROWS	12

void load_room( const unsigned char *map )
{
	//const unsigned char *map = level_txt;

	const unsigned char *o = map;// , *line;
	unsigned char i, j, x, y, ch;

	//engine_font_manager_draw_data(3, 10, 1);
	//SMS_mapROMBank( 2 );		// bank2
	SMS_mapROMBank( 4 );		// bank4

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