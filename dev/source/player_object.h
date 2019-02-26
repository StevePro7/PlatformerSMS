#ifndef _PLAYER_OBJECT_H_
#define _PLAYER_OBJECT_H_

#include "enum_manager.h"

typedef struct tag_struct_player_object
{
	enum_move_type player_move_type;
	//unsigned char sx, sy;
	int posX, posY;
	int velX, velY;
	unsigned char deltaX, deltaY;
	unsigned char player_idxX;
	unsigned char bl, br;
	unsigned char fr, fm;
	signed char vx, vy;

} struct_player_object;

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