#ifndef _ENEMYK_OBJECT_H_
#define _ENEMYK_OBJECT_H_

typedef struct tag_struct_enemy_common
{
	unsigned char num_enemies;

} struct_enemy_common;


typedef struct tag_struct_enemy_object
{
	unsigned char sx, sy;
	void( *draw )( void );

} struct_enemy_object;

#endif//_ENEMYK_OBJECT_H_