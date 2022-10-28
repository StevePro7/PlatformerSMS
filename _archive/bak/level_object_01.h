#ifndef _LEVEL_OBJECT_H_
#define _LEVEL_OBJECT_H_

#include "global_manager.h"

typedef struct tag_struct_level_object
{
	//unsigned char *collision_matrix;
	//unsigned char *drawtiles_matrix;
	unsigned char collision_array[ MAX_ROWS * MAX_COLS ];
	unsigned char drawtiles_array[ MAX_ROWS * MAX_COLS ];
	unsigned int load_cols;
	unsigned int draw_cols;
	signed char exit_spotX, exit_spotY;		// Compatible with collX, collY
	unsigned int player_spot;
	unsigned int enemys_spot[ MAX_ENEMIES ];
	unsigned int enemys_spotX[ MAX_ENEMIES ];
	unsigned int enemys_spotY[ MAX_ENEMIES ];
	unsigned char enemys_type[ MAX_ENEMIES ];
	//unsigned char enemys_botX[ MAX_ENEMIES ];
	//unsigned char enemys_botX[ MAX_ENEMIES ];
	unsigned char enemys_minX[ MAX_ENEMIES ];
	unsigned char enemys_maxX[ MAX_ENEMIES ];
	unsigned char enemys_action[ MAX_ENEMIES ];
	unsigned char enemyCount;

} struct_level_object;

extern const unsigned char *levelAAdata[];
//extern const unsigned char *levelBBdata[];
//extern const unsigned char *world03data[];
//extern const unsigned char *world04data[];

extern const unsigned char levelAAsize[];
//extern const unsigned char levelBBsize[];
//extern const unsigned char world03size[];
//extern const unsigned char world04size[];

extern const unsigned char levelAAbank[];
//extern const unsigned char levelBBbank[];
//extern const unsigned char world03bank[];
//extern const unsigned char world04bank[];

/*
extern const unsigned char *leveldata[];
extern const unsigned char levelsize[];
extern const unsigned char levelbank[];
*/
#endif//_LEVEL_OBJECT_H_