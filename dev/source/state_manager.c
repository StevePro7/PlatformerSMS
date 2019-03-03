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

	/*po->spotX = 0;
	po->spotY = 0;*/
	//unsigned char idx;
	po->spotY = lo->player_spot / lo->draw_cols;
	po->spotX = lo->player_spot % lo->draw_cols;
	//idx = 0;

	//po->spotY = 2;
	//po->spotX = 3;

	engine_font_manager_draw_data( lo->player_spot, 20, 12 );
	engine_font_manager_draw_data( lo->draw_cols, 20, 13 );
	engine_font_manager_draw_data( po->spotX, 20, 14 );
	//engine_font_manager_draw_data( 16 % 15, 20, 14 );
	engine_font_manager_draw_data( po->spotY, 20, 15 );
	
	//engine_font_manager_draw_data( rectX, 20, 12 );
	//engine_font_manager_draw_data( rectB, 20, 13 );
	//engine_font_manager_draw_data( po->posnX, 20, 14 );
	//engine_font_manager_draw_data( po->posnY, 20, 15 );

	//po->posnX
}