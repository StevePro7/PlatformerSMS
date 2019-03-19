#include "stats_manager.h"
#include "global_manager.h"
#include "enum_manager.h"

// Global variable.
struct_stats_object global_stats_object;

void engine_stats_manager_init()
{
	struct_stats_object *so = &global_stats_object;
	//unsigned idx;

	// Collision offsets.
	so->collision_offsets[ diff_type_easy ] = ENEMYS_COLL_EASY;
	so->collision_offsets[ diff_type_hard ] = ENEMYS_COLL_HARD;

	so->enemys_velX[ sprite_type_enemyA ][ 0 ] = 1;
	so->enemys_velX[ sprite_type_enemyA ][ 1 ] = 2;
	so->enemys_velX[ sprite_type_enemyA ][ 2 ] = 3;
	so->enemys_velX[ sprite_type_enemyA ][ 3 ] = 4;

	so->enemys_velX[ sprite_type_enemyB ][ 0 ] = 11;
	so->enemys_velX[ sprite_type_enemyB ][ 1 ] = 22;
	so->enemys_velX[ sprite_type_enemyB ][ 2 ] = 33;
	so->enemys_velX[ sprite_type_enemyB ][ 3 ] = 44;

	so->enemys_velX[ sprite_type_enemyC ][ 0 ] = 4;
	so->enemys_velX[ sprite_type_enemyC ][ 1 ] = 5;
	so->enemys_velX[ sprite_type_enemyC ][ 2 ] = 6;
	so->enemys_velX[ sprite_type_enemyC ][ 3 ] = 7;

	so->enemys_velX[ sprite_type_enemyD ][ 0 ] = 14;
	so->enemys_velX[ sprite_type_enemyD ][ 1 ] = 15;
	so->enemys_velX[ sprite_type_enemyD ][ 2 ] = 16;
	so->enemys_velX[ sprite_type_enemyD ][ 3 ] = 17;


	so->enemys_wait[ sprite_type_enemyA ][ 0 ] = 10;
	so->enemys_wait[ sprite_type_enemyA ][ 1 ] = 10;
	so->enemys_wait[ sprite_type_enemyA ][ 2 ] = 10;
	so->enemys_wait[ sprite_type_enemyA ][ 3 ] = 10;

	so->enemys_wait[ sprite_type_enemyB ][ 0 ] = 10;
	so->enemys_wait[ sprite_type_enemyB ][ 1 ] = 10;
	so->enemys_wait[ sprite_type_enemyB ][ 2 ] = 10;
	so->enemys_wait[ sprite_type_enemyB ][ 3 ] = 10;

	so->enemys_wait[ sprite_type_enemyC ][ 0 ] = 10;
	so->enemys_wait[ sprite_type_enemyC ][ 1 ] = 10;
	so->enemys_wait[ sprite_type_enemyC ][ 2 ] = 10;
	so->enemys_wait[ sprite_type_enemyC ][ 3 ] = 10;

	so->enemys_wait[ sprite_type_enemyD ][ 0 ] = 10;
	so->enemys_wait[ sprite_type_enemyD ][ 1 ] = 10;
	so->enemys_wait[ sprite_type_enemyD ][ 2 ] = 10;
	so->enemys_wait[ sprite_type_enemyD ][ 3 ] = 10;
}

unsigned char *count_text[] =
{
	"01",
	"02",
	"03",
	"04",
	"05",
	"06",
	"07",
	"08",
	"09",
	"10",
};