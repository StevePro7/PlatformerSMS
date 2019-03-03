#include "state_manager.h"
#include "font_manager.h"
#include "level_object.h"
#include "player_object.h"
#include "level_manager.h"
#include "player_manager.h"

void engine_state_manager_load()
{
	struct_level_object *lo = &global_level_object;
	struct_player_object *po = &global_player_object;

	po->spotY = lo->player_spot / lo->draw_cols;
	po->spotX = lo->player_spot % lo->draw_cols;
}