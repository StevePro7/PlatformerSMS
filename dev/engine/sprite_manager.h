#ifndef _SPRITE_MANAGER_H_
#define _SPRITE_MANAGER_H_

#define ENEMYS_TILES_OFFSET		SPRITE_TILES_OFFSET + 32

// Private helper method.
//static void engine_sprite_manager_draw( unsigned char x, unsigned char y, unsigned char tile );


void engine_sprite_manager_draw_player( unsigned char x, unsigned char y )
{
//	engine_sprite_manager_draw( x, y, SPRITE_TILES_OFFSET );
	SMS_addSprite( x + 0, y + 0, SPRITE_TILES_OFFSET + 0 );
	SMS_addSprite( x + 8, y + 0, SPRITE_TILES_OFFSET + 1 );
	SMS_addSprite( x + 0, y + 8, SPRITE_TILES_OFFSET + 2 );
	SMS_addSprite( x + 8, y + 8, SPRITE_TILES_OFFSET + 3 );

	SMS_addSprite( x + 0, y + 16, SPRITE_TILES_OFFSET + 4 );
	SMS_addSprite( x + 8, y + 16, SPRITE_TILES_OFFSET + 5 );
	SMS_addSprite( x + 0, y + 24, SPRITE_TILES_OFFSET + 6 );
	SMS_addSprite( x + 8, y + 24, SPRITE_TILES_OFFSET + 7 );
}

void engine_sprite_manager_draw_enemyA( unsigned char x, unsigned char y )
{
	//	engine_sprite_manager_draw( x, y, SPRITE_TILES_OFFSET );
	SMS_addSprite( x + 0, y + 0, ENEMYS_TILES_OFFSET + 0 );
	SMS_addSprite( x + 8, y + 0, ENEMYS_TILES_OFFSET + 1 );
	SMS_addSprite( x + 0, y + 8, ENEMYS_TILES_OFFSET + 2 );
	SMS_addSprite( x + 8, y + 8, ENEMYS_TILES_OFFSET + 3 );

	SMS_addSprite( x + 0, y + 16, ENEMYS_TILES_OFFSET + 4 );
	SMS_addSprite( x + 8, y + 16, ENEMYS_TILES_OFFSET + 5 );
	SMS_addSprite( x + 0, y + 24, ENEMYS_TILES_OFFSET + 6 );
	SMS_addSprite( x + 8, y + 24, ENEMYS_TILES_OFFSET + 7 );
}

//static void engine_sprite_manager_draw(unsigned char x, unsigned char y, unsigned char tile)
//{
//    //SMS_addSprite(x + 0, y + 0, tile + 0);
//    /*SMS_addSprite(x + 8, y + 0, tile + 1);
//    SMS_addSprite(x + 16, y + 0, tile + 2);
//    SMS_addSprite(x + 24, y + 0, tile + 3);
//
//    SMS_addSprite(x + 0, y + 8, tile + 4);
//    SMS_addSprite(x + 8, y + 8, tile + 5);
//    SMS_addSprite(x + 16, y + 8, tile + 6);
//    SMS_addSprite(x + 24, y + 8, tile + 7);
//
//    SMS_addSprite(x + 0, y + 16, tile + 8);
//    SMS_addSprite(x + 8, y + 16, tile + 9);
//    SMS_addSprite(x + 16, y + 16, tile + 10);
//    SMS_addSprite(x + 24, y + 16, tile + 11);
//
//    SMS_addSprite(x + 0, y + 24, tile + 12);
//    SMS_addSprite(x + 8, y + 24, tile + 13);
//    SMS_addSprite(x + 16, y + 24, tile + 14);
//    SMS_addSprite(x + 24, y + 24, tile + 15);*/
//}

#endif//_SPRITE_MANAGER_H_