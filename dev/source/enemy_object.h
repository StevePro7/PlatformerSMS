#ifndef _ENEMYK_OBJECT_H_
#define _ENEMYK_OBJECT_H_

#include "enum_manager.h"

typedef struct tag_struct_enemy_master
{
	unsigned char max_enemies;

} struct_enemy_master;


typedef struct tag_struct_enemy_object
{
	enum_sprite_type sprite_type;
	enum_action_type action_type;
	enum_move_type curr_move_type;
	enum_move_type next_move_type;
	unsigned char spotX, spotY;		// IMPORTANT enemy bottom = spotY and never changes
	unsigned char posnX, posnY;
	unsigned char drawX, drawY;
	unsigned char leftX, rghtX;
	unsigned char minX, maxX;
	unsigned char velX;
	unsigned int wait, loop;
	void( *update )( void );

} struct_enemy_object;

#endif//_ENEMYK_OBJECT_H_