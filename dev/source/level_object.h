#ifndef _LEVEL_OBJECT_H_
#define _LEVEL_OBJECT_H_

#include "global_manager.h"

typedef struct tag_struct_level_object
{
	unsigned char *collision_matrix;
	unsigned char *drawtiles_matrix;
	unsigned char collision_array[ MAX_ROWS * MAX_COLS ];
	unsigned char drawtiles_array[ MAX_ROWS * MAX_COLS ];
	unsigned int load_cols;
	unsigned int draw_cols;
	unsigned int player_spot;

} struct_level_object;

extern const unsigned char *leveldata[];
extern const unsigned char levelsize[];
extern const unsigned char levelbank[];

#endif//_LEVEL_OBJECT_H_