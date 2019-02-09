#include "sprite_manager.h"
#include "_sms_manager.h"
#include "global_manager.h"
#include "enum_manager.h"
#include "..\gfx.h"

void engine_sprite_manager_draw( unsigned char x, unsigned char y, unsigned char sprite_type )
{
	const unsigned char tile = list_sprite_tile_offset[ sprite_type ];
	//const int tile = 128 + 128 ;

	devkit_SMS_addSprite( x + 0, y + 0, tile + 0 );
	devkit_SMS_addSprite( x + 8, y + 0, tile + 1 );
	devkit_SMS_addSprite( x + 0, y + 8, tile + 2 );
	devkit_SMS_addSprite( x + 8, y + 8, tile + 3 );

	devkit_SMS_addSprite( x + 0, y + 16, tile + 4 );
	devkit_SMS_addSprite( x + 8, y + 16, tile + 5 );
	devkit_SMS_addSprite( x + 0, y + 24, tile + 6 );
	devkit_SMS_addSprite( x + 8, y + 24, tile + 7 );
}

void engine_sprite_manager_draw_player( unsigned char x, unsigned char y )
{
	engine_sprite_manager_draw( x, y, ( enum_sprite_type ) sprite_type_player );
}