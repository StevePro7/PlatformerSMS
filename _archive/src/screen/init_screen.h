#ifndef _INIT_SCREEN_H_
#define _INIT_SCREEN_H_

void screen_init_screen_load()
{
	struct_player_object *po;
	po = &player_object;

	engine_player_manager_load();

	engine_font_manager_draw_data( po->sx, 16, 0 );
	engine_font_manager_draw_data( po->sy, 24, 0 );
}

void screen_init_screen_update( enum_screen_type *screen_type )
{
	bool test;
	struct_player_object *po;
	po = &player_object;

	test = engine_input_manager_move_left();
	if( test )
	{
		po->sx -= 1;
		engine_font_manager_draw_data( po->sx, 16, 0 );
	}
	test = engine_input_manager_move_right();
	if( test )
	{
		po->sx += 1;
		engine_font_manager_draw_data( po->sx, 16, 0 );
	}

	test = engine_input_manager_move_up();
	if( test )
	{
		po->sy -= 1;
		engine_font_manager_draw_data( po->sy, 24, 0 );
	}
	test = engine_input_manager_move_down();
	if( test )
	{
		po->sy += 1;
		engine_font_manager_draw_data( po->sy, 24, 0 );
	}

	engine_player_manager_draw();
	*screen_type = screen_type_init;
}

#endif//_INIT_SCREEN_H_