#ifndef _TILE_MANAGER_H_
#define _TILE_MANAGER_H_

#define BASE_TILE_OFFSET	64

void engine_tile_manager_draw_tile( unsigned char index, unsigned char x, unsigned char y )
{
	const unsigned char *pnt = back_tiles__tilemap__bin;
	index = BASE_TILE_OFFSET + (index / 8 ) * 16 + index * 2;

	SMS_setNextTileatXY( x + 0, y + 0 );	SMS_setTile( *pnt + index + 0 );
	SMS_setNextTileatXY( x + 1, y + 0 );	SMS_setTile( *pnt + index + 1 );
	SMS_setNextTileatXY( x + 0, y + 1 );	SMS_setTile( *pnt + index + 16 );
	SMS_setNextTileatXY( x + 1, y + 1 );	SMS_setTile( *pnt + index + 17 );
}

#endif//_TILE_MANAGER_H_