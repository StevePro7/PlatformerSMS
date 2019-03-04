#include "tile_manager.h"
#include "_sms_manager.h"
#include "global_manager.h"
#include "level_object.h"
#include "..\gfx.h"
#include <stdlib.h>

#define BASE_TILE_OFFSET	64

void engine_tile_manager_draw_tile( unsigned char index, unsigned char x, unsigned char y )
{
	const unsigned char *pnt = back_tiles__tilemap__bin;
	index = BASE_TILE_OFFSET + ( index / 8 ) * 16 + index * 2;

	devkit_SMS_setNextTileatXY( x + 0, y + 0 );	devkit_SMS_setTile( *pnt + index + 0 );
	devkit_SMS_setNextTileatXY( x + 1, y + 0 );	devkit_SMS_setTile( *pnt + index + 1 );
	devkit_SMS_setNextTileatXY( x + 0, y + 1 );	devkit_SMS_setTile( *pnt + index + 16 );
	devkit_SMS_setNextTileatXY( x + 1, y + 1 );	devkit_SMS_setTile( *pnt + index + 17 );
}

void engine_tile_manager_draw_tile_side( enum_side_type side_type, unsigned char index, unsigned char x, unsigned char y )
{
	const unsigned char *pnt = back_tiles__tilemap__bin;
	index = BASE_TILE_OFFSET + ( index / 8 ) * 16 + index * 2;

	if( side_type_left == side_type )
	{
		devkit_SMS_setNextTileatXY( x + 0, y + 0 );	devkit_SMS_setTile( *pnt + index + 0 );
		devkit_SMS_setNextTileatXY( x + 0, y + 1 );	devkit_SMS_setTile( *pnt + index + 16 );
	}
	else if( side_type_rght == side_type )
	{
		devkit_SMS_setNextTileatXY( x + 1, y + 0 );	devkit_SMS_setTile( *pnt + index + 1 );
		devkit_SMS_setNextTileatXY( x + 1, y + 1 );	devkit_SMS_setTile( *pnt + index + 17 );
	}
}

void engine_tile_manager_get_tile( enum_tile_type *tile_type, unsigned char tile )
{
	if( '#' == tile )
	{
		//*tile_type = rand() % MAX_BLOCK_TILES + 1;
		*tile_type = tile_type_blockerA;
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

void engine_tile_manager_get_collision( enum_coll_type *coll_type, unsigned char tile )
{
	if( '#' == tile )
	{
		*coll_type = coll_type_impassable;
		return;
	}
	if( '-' == tile )
	{
		*coll_type = coll_type_platform;
		return;
	}

	*coll_type = coll_type_passable;
}

void engine_tile_manager_get_sprite( enum_sprite_type *sprite_type, unsigned char tile )
{
	if( '1' == tile )
	{
		*sprite_type = sprite_type_player;
		return;
	}
	if( 'A' == tile )
	{
		*sprite_type = sprite_type_enemyA;
		return;
	}
	if( 'B' == tile )
	{
		*sprite_type = sprite_type_enemyB;
		return;
	}
	if( 'C' == tile )
	{
		*sprite_type = sprite_type_enemyC;
		return;
	}
	if( 'D' == tile )
	{
		*sprite_type = sprite_type_enemyD;
		return;
	}

	*sprite_type = sprite_type_unknown;
}