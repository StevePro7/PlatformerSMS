#ifndef _LEVEL_MANAGER_H_
#define _LEVEL_MANAGER_H__

#include "level_object.h"

//#define COLS 15
//#define ROWS 12

void engine_level_manager_init_level();
void engine_level_manager_load_level( const unsigned char *level, const unsigned char bank, const unsigned char size );
void engine_level_manager_load_index( const unsigned char index );
void engine_level_manager_draw_level_column( unsigned char column );
void engine_level_manager_draw_level_column_side( unsigned side_type, unsigned char column );
void engine_level_manager_draw_level();
void engine_level_manager_draw_blank( unsigned char x, unsigned char y );
void engine_level_manager_get_collision( unsigned char *coll_type, unsigned char x, unsigned char y );

//TODO delete this method
void engine_level_manager_load_levelX();

// Global variable.
extern struct_level_object global_level_object;

#endif//_LEVEL_MANAGER_H_