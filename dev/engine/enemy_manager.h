#ifndef _ENEMY_MANAGER_H_
#define _ENEMY_MANAGER_H_

void engine_enemy_manager_load()
{
	struct_enemy_object *eo;
	eo = &enemy_object[ 0 ];
	eo->sprite_type = sprite_type_enemyA;
	eo->sx = 16; eo->sy = 96; eo->bl = 0; eo->br = 48; eo->vx = -1; eo->vy = 0;
	eo = &enemy_object[ 1 ];
	eo->sprite_type = sprite_type_enemyB;
	eo->sx = 224; eo->sy = 96; eo->bl = 176; eo->br = 224; eo->vx = -1; eo->vy = 0;
}

void engine_enemy_manager_update()
{
	unsigned char index;
	struct_enemy_object *eo;

	for( index = 0; index < MAX_ENEMIES; index++ )
	{
		eo = &enemy_object[ index ];

		eo->sx += eo->vx;
		if( eo->sx <= eo->bl || eo->sx >= eo->br )
		{
			eo->vx = -eo->vx;
			//eo->vx = 0;
		}
	}
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