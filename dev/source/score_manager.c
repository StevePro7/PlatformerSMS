#include "score_manager.h"
#include "global_manager.h"

// Global variable.
struct_score_object global_score_object;

void engine_score_manager_load()
{
	struct_score_object *so = &global_score_object;
	so->num_lives = NUMBER_LIVES;
	so->gem_delta = 0;
	so->gem_level = 0;
	so->gem_total = 0;
}