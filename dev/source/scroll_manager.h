#ifndef _SCROLL_MANAGER_H_
#define _SCROLL_MANAGER_H_

#include "player_object.h"

void engine_scroll_manager_load();
void engine_scroll_manager_update();
void engine_scroll_manager_draw();

// Global variable.
extern struct_player_object global_player_object;


#endif//_SCROLL_MANAGER_H_