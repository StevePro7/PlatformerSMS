#ifndef _SPRITE_MANAGER_H_
#define _SPRITE_MANAGER_H_

// Private helper method.
static void engine_sprite_manager_draw( unsigned char x, unsigned char y, enum_entity_type entity );


void engine_sprite_manager_draw_player( unsigned char x, unsigned char y )
{
	engine_sprite_manager_draw( x, y, player );
}

void engine_sprite_manager_draw_enemyA( unsigned char x, unsigned char y )
{
	engine_sprite_manager_draw( x, y, enemyA );
}
void engine_sprite_manager_draw_enemyB( unsigned char x, unsigned char y )
{
	engine_sprite_manager_draw( x, y, enemyB );
}
void engine_sprite_manager_draw_enemyC( unsigned char x, unsigned char y )
{
	engine_sprite_manager_draw( x, y, enemyC );
}
void engine_sprite_manager_draw_enemyD( unsigned char x, unsigned char y )
{
	engine_sprite_manager_draw( x, y, enemyD );
}

static void engine_sprite_manager_draw( unsigned char x, unsigned char y, enum_entity_type entity )
{
	const unsigned char tile = list_entity_type[ entity ];

	SMS_addSprite( x + 0, y + 0, tile + 0 );
	SMS_addSprite( x + 8, y + 0, tile + 1 );
	SMS_addSprite( x + 0, y + 8, tile + 2 );
	SMS_addSprite( x + 8, y + 8, tile + 3 );

	SMS_addSprite( x + 0, y + 16, tile + 4 );
	SMS_addSprite( x + 8, y + 16, tile + 5 );
	SMS_addSprite( x + 0, y + 24, tile + 6 );
	SMS_addSprite( x + 8, y + 24, tile + 7 );
}

#endif//_SPRITE_MANAGER_H_