#ifndef _ENEMY_MANAGER_H_
#define _ENEMY_MANAGER_H_

void engine_enemy_manager_load()
{
	struct_enemy_object *eo;
	eo = &enemy_object[ 0 ];
	eo->sprite_type = sprite_type_enemyA;
	eo->sx = 0; eo->sy = 96; eo->bl = 0; eo->br = 48; eo->vx = +1; eo->vy = 0;
	eo->fr = 1; eo->fm = 5;
	eo = &enemy_object[ 1 ];
	eo->sprite_type = sprite_type_enemyB;
	eo->sx = 224; eo->sy = 96; eo->bl = 176; eo->br = 224; eo->vx = -1; eo->vy = 0;
	eo->fr = 2; eo->fm = 5;

	eo = &enemy_object[ 2 ];
	eo->sprite_type = sprite_type_enemyC;
	eo->sx = 32; eo->sy = 48; eo->bl = 16; eo->br = 64; eo->vx = +1; eo->vy = 0;
	eo->fr = 3; eo->fm = 5;
	eo = &enemy_object[ 3 ];
	eo->sprite_type = sprite_type_enemyD;
	eo->sx = 192; eo->sy = 48; eo->bl = 160; eo->br = 208; eo->vx = -1; eo->vy = 0;
	eo->fr = 4; eo->fm = 5;

	eo = &enemy_object[ 4 ];
	eo->sprite_type = sprite_type_enemyB;
	eo->sx = 64; eo->sy = 0; eo->bl = 32; eo->br = 80; eo->vx = +1; eo->vy = 0;
	eo->fr = 2; eo->fm = 5;
	eo = &enemy_object[ 5 ];
	eo->sprite_type = sprite_type_enemyC;
	eo->sx = 160; eo->sy = 0; eo->bl = 144; eo->br = 192; eo->vx = -1; eo->vy = 0;
	eo->fr = 3; eo->fm = 5;

	eo = &enemy_object[ 6 ];
	eo->sprite_type = sprite_type_enemyB;
	eo->sx = 100; eo->sy = 100; eo->bl = 0; eo->br = 255; eo->vx = 0; eo->vy = 0;
	eo->fr = 2; eo->fm = 5;
	eo = &enemy_object[ 7 ];
	eo->sprite_type = sprite_type_enemyC;
	eo->sx = 100; eo->sy = 50; eo->bl = 0; eo->br = 255; eo->vx = 0; eo->vy = 0;
	eo->fr = 2; eo->fm = 5;
}

void engine_enemy_manager_animate( unsigned char index, enum_sprite_type sprite_type )
{
	const unsigned char *tilemap = ( unsigned char * ) stageinitdata[ index ];
	SMS_loadPSGaidencompressedTiles( tilemap, list_sprite_tile_offset[ sprite_type ] );
}

void engine_enemy_manager_update()
{
	unsigned char count;
	unsigned char index;

	struct_enemy_object *eo;
	//count = 0;
	for( count = 0; count < MAX_ENEMIES; count++ )
	{
		eo = &enemy_object[ count ];

		index = eo->fr;
		engine_enemy_manager_animate( index, eo->sprite_type );
		//eo->fr++;
		if( eo->fr >= eo->fm )
		{
			eo->fr = 0;
		}

		eo->sx += eo->vx;
		if( eo->sx <= eo->bl || eo->sx >= eo->br )
		{
			eo->vx = -eo->vx;
			//eo->vx = 0;
		}

	}
	//for( index = 0; index < MAX_ENEMIES; index++ )
	//{
	//	eo = &enemy_object[ index ];

	//	count = eo->fr;
	//	engine_enemy_manager_animate( index, eo->sprite_type );
	//	eo->fr++;
	//	if( eo->fr >= eo->fm )
	//	{
	//		eo->fr = 0;
	//	}

	//	eo->sx += eo->vx;
	//	if( eo->sx <= eo->bl || eo->sx >= eo->br )
	//	{
	//		eo->vx = -eo->vx;
	//		//eo->vx = 0;
	//	}
	//}
}

void engine_enemy_manager_draw()
{
	unsigned char x, y;
	unsigned char index;
	struct_enemy_object *eo;

	for( index = 0; index < MAX_ENEMIES; index++ )
	{
		eo = &enemy_object[ index ];

		x = eo->sx + GAME_X_OFFSET;
		y = eo->sy;
		engine_sprite_manager_draw( x, y, eo->sprite_type );
	}
}

#endif//_ENEMY_MANAGER_H_