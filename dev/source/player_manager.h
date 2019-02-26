#ifndef _PLAYER_MANAGER_H_
#define _PLAYER_MANAGER_H_

#include "player_object.h"

void engine_player_manager_load();
void engine_player_manager_update();
void engine_player_manager_draw();

// Global variable.
extern struct_player_object global_player_object;

#endif//_PLAYER_MANAGER_H_