#ifndef _SPRITE_MANAGER_H_
#define _SPRITE_MANAGER_H_

//#define ENEMYA_TILES_OFFSET		SPRITE_TILES_OFFSET + 8
//#define ENEMYB_TILES_OFFSET		SPRITE_TILES_OFFSET + 16
//#define ENEMYC_TILES_OFFSET		SPRITE_TILES_OFFSET + 24
//#define ENEMYD_TILES_OFFSET		SPRITE_TILES_OFFSET + 32

//const unsigned char list_entity_type[] =
//{
//	SPRITE_TILES_OFFSET + 0,
//	SPRITE_TILES_OFFSET + 8,
//	SPRITE_TILES_OFFSET + 16,
//	SPRITE_TILES_OFFSET + 24,
//	SPRITE_TILES_OFFSET + 32,
//};

// Private helper method.
static void engine_sprite_manager_draw( unsigned char x, unsigned char y, unsigned char tile );
static void engine_sprite_manager_text( unsigned char x, unsigned char y, enum_entity_type entity );


void engine_sprite_manager_draw_player( unsigned char x, unsigned char y )
{
	engine_sprite_manager_text( x, y, player );
	/*const unsigned char test = entity_type[ player ];
	engine_font_manager_draw_data( test, 12, 2 );*/
	/*SMS_addSprite( x + 0, y + 0, SPRITE_TILES_OFFSET + 0 );
	SMS_addSprite( x + 8, y + 0, SPRITE_TILES_OFFSET + 1 );
	SMS_addSprite( x + 0, y + 8, SPRITE_TILES_OFFSET + 2 );
	SMS_addSprite( x + 8, y + 8, SPRITE_TILES_OFFSET + 3 );

	SMS_addSprite( x + 0, y + 16, SPRITE_TILES_OFFSET + 4 );
	SMS_addSprite( x + 8, y + 16, SPRITE_TILES_OFFSET + 5 );
	SMS_addSprite( x + 0, y + 24, SPRITE_TILES_OFFSET + 6 );
	SMS_addSprite( x + 8, y + 24, SPRITE_TILES_OFFSET + 7 );*/
}

void engine_sprite_manager_draw_enemyA( unsigned char x, unsigned char y )
{
	engine_sprite_manager_text( x, y, enemyA );
}
void engine_sprite_manager_draw_enemyB( unsigned char x, unsigned char y )
{
	engine_sprite_manager_text( x, y, enemyB );
}


static void engine_sprite_manager_draw( unsigned char x, unsigned char y, unsigned char tile )
{
	SMS_addSprite( x + 0, y + 0, tile + 0 );
	SMS_addSprite( x + 8, y + 0, tile + 1 );
	SMS_addSprite( x + 0, y + 8, tile + 2 );
	SMS_addSprite( x + 8, y + 8, tile + 3 );

	SMS_addSprite( x + 0, y + 16, tile + 4 );
	SMS_addSprite( x + 8, y + 16, tile + 5 );
	SMS_addSprite( x + 0, y + 24, tile + 6 );
	SMS_addSprite( x + 8, y + 24, tile + 7 );
}

static void engine_sprite_manager_text( unsigned char x, unsigned char y, enum_entity_type entity )
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