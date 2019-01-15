#ifndef _ENUM_MANAGER_H_
#define _ENUM_MANAGER_H_

typedef enum tag_enum_tile_type
{
	passable = 0,
	blockerA = 1,
	blockerB = 2,
	blockerC = 3,
	blockerD = 4,
	blockerE = 5,
	blockerF = 6,
	blockerG = 7,
	blockerH = 8,
	blockerI = 9,
	exitgame = 10,
	gemscore = 11,

} enum_tile_type;

typedef enum tag_enum_entity_type
{
	player = 0,
	enemyA = 1,
	enemyB = 2,
	enemyC = 3,
	enemyD = 4,

} enum_entity_type;

#endif//_ENUM_MANAGER_H_