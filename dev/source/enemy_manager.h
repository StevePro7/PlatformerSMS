#ifndef _ENEMY_MANAGER_H_
#define _ENEMY_MANAGER_H_

#include "enemy_object.h"
#include "global_manager.h"

#define MAX_ENEMY_VELX	4
#define MAX_ENEMY_WAIT	128

// Global variables.
extern struct_enemy_master global_enemy_master;
extern struct_enemy_object global_enemy_objects[ MAX_ENEMIES ];

// Methods.
void engine_enemyX_manager_init();
void engine_enemyX_manager_load();
void engine_enemyX_manager_update();
void engine_enemyX_manager_draw_enemys();
void engine_enemyX_manager_hide_enemys( int leftX, int rghtX );
void engine_enemyX_manager_draw_guards();

#endif//_ENEMY_MANAGER_H_