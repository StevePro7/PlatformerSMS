#ifndef _TILE_MANAGER_H_
#define _TILE_MANAGER_H_

#define BASE_TILE_OFFSET	64

void engine_tile_manager_draw_tile( unsigned char index, unsigned char x, unsigned char y )
{
	const unsigned char *pnt = back_tiles__tilemap__bin;
	index = BASE_TILE_OFFSET + ( index / 8 ) * 16 + index * 2;

	SMS_setNextTileatXY( x + 0, y + 0 );	SMS_setTile( *pnt + index + 0 );
	SMS_setNextTileatXY( x + 1, y + 0 );	SMS_setTile( *pnt + index + 1 );
	SMS_setNextTileatXY( x + 0, y + 1 );	SMS_setTile( *pnt + index + 16 );
	SMS_setNextTileatXY( x + 1, y + 1 );	SMS_setTile( *pnt + index + 17 );
}

void engine_tile_manager_draw_tile_side( unsigned char index, unsigned char x, unsigned char y )
{
}

void engine_tile_manager_get_tile( enum_tile_type *tile_type, unsigned char tile )
{
	if( '#' == tile )
	{
		*tile_type = rand() % MAX_BLOCK_TILES + 1;
		return;
	}
	if( '-' == tile )
	{
		*tile_type = tile_type_platform;
		return;
	}
	if( 'X' == tile )
	{
		*tile_type = tile_type_exitgame;
		return;
	}
	if( 'G' == tile )
	{
		*tile_type = tile_type_gemscore;
		return;
	}

	*tile_type = tile_type_blankGap;
}

void engine_tile_manager_get_crash( enum_crash_type *crash_type, unsigned char tile )
{
	if( '#' == tile )
	{
		*crash_type = crash_type_impassable;
		return;
	}
	if( '-' == tile )
	{
		*crash_type = crash_type_platform;
		return;
	}

	*crash_type = crash_type_passable;
}

#endif//_TILE_MANAGER_H_