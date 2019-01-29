#ifndef _SPRITE_MANAGER_H_
#define _SPRITE_MANAGER_H_

void engine_sprite_manager_draw( unsigned char x, unsigned char y, enum_sprite_type sprite_type )
{
	const unsigned char tile = list_sprite_tile_offset[ sprite_type ];

	SMS_addSprite( x + 0, y + 0, tile + 0 );
	SMS_addSprite( x + 8, y + 0, tile + 1 );
	SMS_addSprite( x + 0, y + 8, tile + 2 );
	SMS_addSprite( x + 8, y + 8, tile + 3 );

	SMS_addSprite( x + 0, y + 16, tile + 4 );
	SMS_addSprite( x + 8, y + 16, tile + 5 );
	SMS_addSprite( x + 0, y + 24, tile + 6 );
	SMS_addSprite( x + 8, y + 24, tile + 7 );
}

void engine_sprite_manager_draw_player( unsigned char x, unsigned char y )
{
	engine_sprite_manager_draw( x, y, sprite_type_player );
}

//void engine_sprite_manager_draw_enemyA( unsigned char x, unsigned char y )
//{
//	engine_sprite_manager_draw( x, y, sprite_type_enemyA );
//}
//void engine_sprite_manager_draw_enemyB( unsigned char x, unsigned char y )
//{
//	engine_sprite_manager_draw( x, y, sprite_type_enemyB );
//}
//void engine_sprite_manager_draw_enemyC( unsigned char x, unsigned char y )
//{
//	engine_sprite_manager_draw( x, y, sprite_type_enemyC );
//}
//void engine_sprite_manager_draw_enemyD( unsigned char x, unsigned char y )
//{
//	engine_sprite_manager_draw( x, y, sprite_type_enemyD );
//}



#endif//_SPRITE_MANAGER_H_