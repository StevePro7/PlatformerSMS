#include "stats_manager.h"
#include "global_manager.h"
#include "enum_manager.h"

// Global variable.
struct_stats_object global_stats_object;

void engine_stats_manager_init()
{
	struct_stats_object *so = &global_stats_object;
	so->collision_offsets[ diff_type_easy ] = ENEMYS_COLL_EASY;
	so->collision_offsets[ diff_type_hard ] = ENEMYS_COLL_HARD;
}