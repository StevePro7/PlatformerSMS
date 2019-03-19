#include "ready_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "stats_manager.h"

void screen_ready_screen_load()
{
	struct_stats_object *so = &global_stats_object;

	engine_font_manager_draw_text( "READY", 10, 10 );

	engine_font_manager_draw_data( so->collision_offsets[ 0 ], 10, 12 );
	engine_font_manager_draw_data( so->collision_offsets[ 1 ], 10, 14 );
}

void screen_ready_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_ready;
}