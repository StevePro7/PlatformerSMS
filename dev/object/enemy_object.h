#ifndef _ENEMY_OBJECT_H_
#define _ENEMY_OBJECT_H_

typedef struct tag_struct_enemy_object
{
	enum_sprite_type sprite_type;
	unsigned char sx, sy;
	unsigned char bl, br;
	signed char vx, vy;

} struct_enemy_object;

//struct_enemy_object enemy_object1;
struct_enemy_object enemy_object[ MAX_ENEMIES ];

#endif//_ENEMY_OBJECT_H_