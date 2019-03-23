#include "score_manager.h"
#include "global_manager.h"
#include "font_manager.h"
#include "tile_manager.h"

// Global variable.
struct_score_object global_score_object;

void engine_score_manager_init( unsigned char difficulty )
{
	struct_score_object *so = &global_score_object;
	so->tot_lives = NUMBER_LIVES - difficulty;
	so->gem_delta = 0;
	so->gem_level = 0;
	so->gem_total = 0;

	engine_score_manager_reset();
}

void engine_score_manager_reset()
{
	struct_score_object *so = &global_score_object;
	so->num_lives = so->tot_lives;
}

void engine_score_manager_update_lives( signed char delta )
{
	struct_score_object *so = &global_score_object;
	if( so->num_lives > 0 && so->num_lives < MAMNUM_LIVES )
	{
		so->num_lives += delta;
		engine_score_manager_draw_lives();
	}
}

void engine_score_manager_draw_heart()
{
	engine_tile_manager_draw_small( 30, 23, tile_type_heart );
}

void engine_score_manager_draw_lives()
{
	struct_score_object *so = &global_score_object;
	unsigned char index = so->num_lives;
	engine_font_manager_draw_text( lives_text[ index ], 31, 23 );
}