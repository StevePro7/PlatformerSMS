#include "player_manager.h"
#include "player_object.h"
//#include "hack_manager.h"
#include "font_manager.h"
#include "sprite_manager.h"
#include "input_manager.h"

void engine_player_manager_load()
{
	struct_player_object *po = &player_object;
//	struct_hack_object *ho = &global_hack_object;
	po->sx = 32;
	po->sy = 128;
	engine_font_manager_draw_data( po->sx, 15, 5 );
}

void engine_player_manager_update()
{
	unsigned char test;
	struct_player_object *po = &player_object;
	engine_font_manager_draw_data( po->sx, 15, 6 );
	test = engine_input_manager_hold_right();

	//engine_sprite_manager_draw_player( po->sx, po->sy );
}