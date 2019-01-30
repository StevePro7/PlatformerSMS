#ifndef _TILE_MANAGER_H_
#define _TILE_MANAGER_H_

#include "enum_manager.h"

void engine_tile_manager_draw_tile( unsigned char index, unsigned char x, unsigned char y );
void engine_tile_manager_draw_tile_side( enum_side_type side_type, unsigned char index, unsigned char x, unsigned char y );
void engine_tile_manager_get_tile( enum_tile_type *tile_type, unsigned char tile );
void engine_tile_manager_get_crash( enum_crash_type *crash_type, unsigned char tile );

#endif//_TILE_MANAGER_H_