#include "game_manager.h"
#include "global_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include <stdbool.h>

// Global variable.
struct_game_object global_game_object;

void engine_game_manager_init()
{
	struct_game_object *go = &global_game_object;
	go->invincible = false;
	go->world_no = 0;
	go->round_no = 0;
}

void engine_game_manager_draw()
{
	struct_game_object *go = &global_game_object;
	engine_font_manager_draw_text( count_text[ go->world_no ], 2, 22 );
	engine_font_manager_draw_text( count_text[ go->round_no ], 2, 23 );
}