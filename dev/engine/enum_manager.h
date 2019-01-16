#ifndef _ENUM_MANAGER_H_
#define _ENUM_MANAGER_H_

typedef enum tag_enum_screen_type
{
	screen_type_none = 0,
	screen_type_test = 1,
	screen_type_splash = 2,

} enum_screen_type;

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

typedef enum tag_enum_sprite_type
{
	sprite_type_player = 0,
	sprite_type_enemyA = 1,
	sprite_type_enemyB = 2,
	sprite_type_enemyC = 3,
	sprite_type_enemyD = 4,

} enum_sprite_type;

#endif//_ENUM_MANAGER_H_