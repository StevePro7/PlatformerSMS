#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#include <stdlib.h>

typedef struct tag_struct_game_object
{
	unsigned char invincible;
	unsigned char difficulty;
	unsigned char number_lives;
	unsigned char world_no;
	unsigned char round_no;

} struct_game_object;

#endif//_GAME_OBJECT_H_