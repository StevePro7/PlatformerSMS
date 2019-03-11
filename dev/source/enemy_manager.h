#ifndef _ENEMY_MANAGER_H_
#define _ENEMY_MANAGER_H_

#include "enemy_object.h"

void engine_enemyX_manager_load();
void engine_enemyX_manager_draw();

// Global variable.
extern struct_enemy_object global_enemy_object;
//extern struct_enemy_object global_enemy_object[ MAX_ENEMIES ];

#endif//_ENEMY_MANAGER_H_