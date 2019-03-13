#ifndef _ENEMYK_OBJECT_H_
#define _ENEMYK_OBJECT_H_

#include "enum_manager.h"

//typedef struct tag_struct_enemy_common
//{
//	unsigned char max_enemies;
//
//} struct_enemy_common;


typedef struct tag_struct_enemy_object
{
	enum_sprite_type sprite_type;
	enum_action_type action_type;
	unsigned char enemyX_botX;
	unsigned char spotX, spotY;
	unsigned char posnX, posnY;
	unsigned char drawX, drawY;
	unsigned char velX;
	void( *update )( void );

} struct_enemy_object;

#endif//_ENEMYK_OBJECT_H_