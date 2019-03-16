#include "game_manager.h"
#include "global_manager.h"
#include "enum_manager.h"
#include <stdbool.h>

// Global variable.
struct_game_object global_game_object;

void engine_game_manager_init()
{
	struct_game_object *go = &global_game_object;

	//go->invincible = false;
	go->difficulty = diff_type_easy;
	go->difficulty = diff_type_hard;
	go->world_no = 0;
	go->round_no = 0;
	go->number_lives = NUMBER_LIVES;
}

void engine_game_manager_load()
{
	struct_game_object *go = &global_game_object;

	go->invincible = true;
	go->number_lives = NUMBER_LIVES;
}