#include "game_manager.h"
#include "global_manager.h"
#include "enum_manager.h"
#include <stdbool.h>

// Global variable.
struct_game_object global_game_object;

void engine_game_manager_init()
{
	struct_game_object *go = &global_game_object;

	go->invincible = false;
	go->difficulty = diff_type_easy;
	go->world_no = 0;
	go->round_no = 0;
}