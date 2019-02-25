#ifndef _PLAYER_OBJECT_H_
#define _PLAYER_OBJECT_H_

#include "enum_manager.h"
#include "..\gfx.h"

typedef struct tag_struct_player_object
{
	enum_move_type player_move_type;
	unsigned char sx, sy;
	unsigned char bl, br;
	unsigned char fr, fm;
	signed char vx, vy;

} struct_player_object;

struct_player_object player_object;


const unsigned char *stageinitdata[] =
{
	Player_Idle__tiles__psgcompr,
	EnemyA_Idle__tiles__psgcompr,
	EnemyB_Idle__tiles__psgcompr,
	EnemyC_Idle__tiles__psgcompr,
	EnemyD_Idle__tiles__psgcompr,
};

//TODO delete
//typedef struct playershoot
//{
//	unsigned char playershootx;
//	unsigned char playershooty;
//	unsigned char playershoottype;
//	signed char playershootvelx;
//	unsigned char playershootvely;
//
//} playershoot;
//
//playershoot playershoots[ 5 ];
//playershoot playershoot1;

#endif//_PLAYER_OBJECT_H_