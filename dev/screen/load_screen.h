#ifndef _LOAD_SCREEN_H_
#define _LOAD_SCREEN_H_

void screen_load_screen_load()
{
	engine_level_manager_load_level( level0204_txt, 2 );

	//engine_level_manager_text_level();
	engine_level_manager_draw_level();

	//engine_level_manager_draw_level_column( 0 );
	//engine_level_manager_draw_level_column( 1 );

	//engine_level_manager_draw_level_column_side( side_type_left, 1 );
	//engine_level_manager_draw_level_column_side( side_type_rght, 0 );
}

void screen_load_screen_update( enum_screen_type *screen_type )
{
	*screen_type = screen_type_play;
	//*screen_type = screen_type_init;
}

#endif//_LOAD_SCREEN_H_