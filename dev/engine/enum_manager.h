#ifndef _ENUM_MANAGER_H_
#define _ENUM_MANAGER_H_

typedef enum tag_enum_screen_type
{
	screen_type_none = 0,
	screen_type_test = 1,
	screen_type_load = 2,
	screen_type_splash = 3,

} enum_screen_type;

typedef enum tag_enum_tile_type
{
	tile_type_blankGap = 0,
	tile_type_blockerA = 1,
	tile_type_blockerB = 2,
	tile_type_blockerC = 3,
	tile_type_blockerD = 4,
	tile_type_blockerE = 5,
	tile_type_blockerF = 6,
	tile_type_blockerG = 7,
	tile_type_blockerH = 8,
	tile_type_blockerI = 9,
	tile_type_platform = 10,
	tile_type_exitgame = 11,
	tile_type_gemscore = 12,

} enum_tile_type;

typedef enum tag_enum_crash_type
{
	crash_type_passable = 0,
	crash_type_impassable = 1,
	crash_type_platform = 2,

} enum_crash_type;


typedef enum tag_enum_sprite_type
{
	sprite_type_player = 0,
	sprite_type_enemyA = 1,
	sprite_type_enemyB = 2,
	sprite_type_enemyC = 3,
	sprite_type_enemyD = 4,

} enum_sprite_type;

#endif//_ENUM_MANAGER_H_