#ifndef _PLAYER_OBJECT_H_
#define _PLAYER_OBJECT_H_

typedef struct tag_struct_player_object
{
	unsigned char sx, sy;
	unsigned char bl, br;
	signed char vx, vy;

} struct_player_object;

struct_player_object player_object;

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