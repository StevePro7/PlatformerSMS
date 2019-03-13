#ifndef _ENUM_MANAGER_H_
#define _ENUM_MANAGER_H_

typedef enum tag_enum_screen_type
{
	screen_type_none = 0,
	screen_type_test = 1,
	screen_type_init = 2,
	screen_type_load = 3,
	screen_type_play = 4,
	screen_type_pass = 5,
	screen_type_dead = 6,
	screen_type_over = 7,
	screen_type_func = 8,
	screen_type_splash = 9,

} enum_screen_type;

typedef enum tag_enum_diff_type
{
	diff_type_easy = 0,
	diff_type_hard = 1,

} enum_diff_type;

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
	tile_type_gempower = 13,
	tile_type_emptyspc = 14,
	tile_type_gridline = 15,

} enum_tile_type;

typedef enum tag_enum_coll_type
{
	coll_type_passable = 0,
	coll_type_impassable = 1,
	coll_type_platform = 2,

} enum_coll_type;

typedef enum tag_enum_sprite_type
{
	sprite_type_enemyA = 0,
	sprite_type_enemyB = 1,
	sprite_type_enemyC = 2,
	sprite_type_enemyD = 3,
	sprite_type_player = 4,
	sprite_type_unknown = 5,

} enum_sprite_type;

typedef enum tag_enum_side_type
{
	side_type_left = 0,
	side_type_rght = 1,

} enum_side_type;

typedef enum tag_enum_move_type
{
	move_type_left = 0,
	move_type_idle = 1,
	move_type_rght = 2,

} enum_move_type;

typedef enum tag_enum_half_type
{
	half_type_prev = 0,
	half_type_next = 1,

} enum_half_type;

typedef enum tag_enum_health_type
{
	health_type_alive = 0,
	health_type_death = 1,

} enum_health_type;

#endif//_ENUM_MANAGER_H_