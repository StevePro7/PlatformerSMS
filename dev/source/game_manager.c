#include "game_manager.h"
#include "global_manager.h"
#include <stdbool.h>

// Global variable.
struct_game_object global_game_object;

void engine_game_manager_load()
{
	struct_game_object *go = &global_game_object;

	go->invincible = false;
	go->number_lives = NUMBER_LIVES;
}