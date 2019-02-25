#ifndef _HACK_MANAGER_H_
#define _HACK_MANAGER_H_

#include "hack_object.h"

//extern unsigned char hacker_debug;
//extern unsigned char hacker_level;

void engine_hack_manager_init();
void engine_hack_manager_invert();

void engine_hack_manager_draw_grid();

extern struct_hack_object hack_object;

#endif//_HACK_MANAGER_H_