#ifndef _SPRITE_MANAGER_H_
#define _SPRITE_MANAGER_H_

#include "enum_manager.h"

void engine_sprite_manager_draw( unsigned char x, unsigned char y, enum_sprite_type sprite_type );
void engine_sprite_manager_draw_player( unsigned char x, unsigned char y );

#endif//_SPRITE_MANAGER_H_