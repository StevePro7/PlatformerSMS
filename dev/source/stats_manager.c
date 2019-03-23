#include "stats_manager.h"
#include "global_manager.h"
#include "enum_manager.h"

// Global variable.
struct_stats_object global_stats_object;

void engine_stats_manager_init()
{
	struct_stats_object *so = &global_stats_object;
	unsigned idx;

	// Collision offsets.
	so->collision_offsets[ diff_type_easy ] = ENEMYS_COLL_EASY;
	so->collision_offsets[ diff_type_hard ] = ENEMYS_COLL_HARD;

	// Enemy velX.
	so->enemys_velX[ sprite_type_enemyA ][ 0 ] = 1;
	so->enemys_velX[ sprite_type_enemyA ][ 1 ] = 1;
	so->enemys_velX[ sprite_type_enemyA ][ 2 ] = 1;
	so->enemys_velX[ sprite_type_enemyA ][ 3 ] = 2;
	so->enemys_velX[ sprite_type_enemyA ][ 4 ] = 1;
	so->enemys_velX[ sprite_type_enemyA ][ 5 ] = 1;
	so->enemys_velX[ sprite_type_enemyA ][ 6 ] = 2;
	so->enemys_velX[ sprite_type_enemyA ][ 7 ] = 2;

	so->enemys_velX[ sprite_type_enemyB ][ 0 ] = 1;
	so->enemys_velX[ sprite_type_enemyB ][ 1 ] = 2;
	so->enemys_velX[ sprite_type_enemyB ][ 2 ] = 2;
	so->enemys_velX[ sprite_type_enemyB ][ 3 ] = 2;
	so->enemys_velX[ sprite_type_enemyB ][ 4 ] = 1;
	so->enemys_velX[ sprite_type_enemyB ][ 5 ] = 1;
	so->enemys_velX[ sprite_type_enemyB ][ 6 ] = 1;
	so->enemys_velX[ sprite_type_enemyB ][ 7 ] = 1;

	so->enemys_velX[ sprite_type_enemyC ][ 0 ] = 1;
	so->enemys_velX[ sprite_type_enemyC ][ 1 ] = 1;
	so->enemys_velX[ sprite_type_enemyC ][ 2 ] = 1;
	so->enemys_velX[ sprite_type_enemyC ][ 3 ] = 2;
	so->enemys_velX[ sprite_type_enemyC ][ 4 ] = 2;
	so->enemys_velX[ sprite_type_enemyC ][ 5 ] = 1;
	so->enemys_velX[ sprite_type_enemyC ][ 6 ] = 1;
	so->enemys_velX[ sprite_type_enemyC ][ 7 ] = 2;

	so->enemys_velX[ sprite_type_enemyD ][ 0 ] = 2;
	so->enemys_velX[ sprite_type_enemyD ][ 1 ] = 3;
	so->enemys_velX[ sprite_type_enemyD ][ 2 ] = 2;
	so->enemys_velX[ sprite_type_enemyD ][ 3 ] = 3;
	so->enemys_velX[ sprite_type_enemyD ][ 4 ] = 1;
	so->enemys_velX[ sprite_type_enemyD ][ 5 ] = 1;
	so->enemys_velX[ sprite_type_enemyD ][ 6 ] = 1;
	so->enemys_velX[ sprite_type_enemyD ][ 7 ] = 1;


	// Enemy wait.
	so->enemys_wait[ sprite_type_enemyA ][ 0 ] = 250;
	so->enemys_wait[ sprite_type_enemyA ][ 1 ] = 225;
	so->enemys_wait[ sprite_type_enemyA ][ 2 ] = 200;
	so->enemys_wait[ sprite_type_enemyA ][ 3 ] = 175;
	so->enemys_wait[ sprite_type_enemyA ][ 4 ] = 150;
	so->enemys_wait[ sprite_type_enemyA ][ 5 ] = 150;
	so->enemys_wait[ sprite_type_enemyA ][ 6 ] = 125;
	so->enemys_wait[ sprite_type_enemyA ][ 7 ] = 125;

	so->enemys_wait[ sprite_type_enemyB ][ 0 ] = 20;
	so->enemys_wait[ sprite_type_enemyB ][ 1 ] = 10;
	so->enemys_wait[ sprite_type_enemyB ][ 2 ] = 10;
	so->enemys_wait[ sprite_type_enemyB ][ 3 ] = 10;
	so->enemys_wait[ sprite_type_enemyB ][ 4 ] = 15;
	so->enemys_wait[ sprite_type_enemyB ][ 5 ] = 15;
	so->enemys_wait[ sprite_type_enemyB ][ 6 ] = 15;
	so->enemys_wait[ sprite_type_enemyB ][ 7 ] = 15;

	so->enemys_wait[ sprite_type_enemyC ][ 0 ] = 200;
	so->enemys_wait[ sprite_type_enemyC ][ 1 ] = 175;
	so->enemys_wait[ sprite_type_enemyC ][ 2 ] = 150;
	so->enemys_wait[ sprite_type_enemyC ][ 3 ] = 150;
	so->enemys_wait[ sprite_type_enemyC ][ 4 ] = 125;
	so->enemys_wait[ sprite_type_enemyC ][ 5 ] = 125;
	so->enemys_wait[ sprite_type_enemyC ][ 6 ] = 100;
	so->enemys_wait[ sprite_type_enemyC ][ 7 ] = 100;

	so->enemys_wait[ sprite_type_enemyD ][ 0 ] = 10;
	so->enemys_wait[ sprite_type_enemyD ][ 1 ] = 10;
	so->enemys_wait[ sprite_type_enemyD ][ 2 ] = 10;
	so->enemys_wait[ sprite_type_enemyD ][ 3 ] = 10;
	so->enemys_wait[ sprite_type_enemyD ][ 4 ] = 15;
	so->enemys_wait[ sprite_type_enemyD ][ 5 ] = 15;
	so->enemys_wait[ sprite_type_enemyD ][ 6 ] = 15;
	so->enemys_wait[ sprite_type_enemyD ][ 7 ] = 15;


	// Enemy walk - if 0 then continuous walk.
	so->enemys_walk[ sprite_type_enemyA ][ 0 ] = 128;
	so->enemys_walk[ sprite_type_enemyA ][ 1 ] = 128;
	so->enemys_walk[ sprite_type_enemyA ][ 2 ] = 128;
	so->enemys_walk[ sprite_type_enemyA ][ 3 ] = 64;
	so->enemys_walk[ sprite_type_enemyA ][ 4 ] = 64;
	so->enemys_walk[ sprite_type_enemyA ][ 5 ] = 64;
	so->enemys_walk[ sprite_type_enemyA ][ 6 ] = 32;
	so->enemys_walk[ sprite_type_enemyA ][ 7 ] = 32;

	so->enemys_walk[ sprite_type_enemyC ][ 0 ] = 64;
	so->enemys_walk[ sprite_type_enemyC ][ 1 ] = 64;
	so->enemys_walk[ sprite_type_enemyC ][ 2 ] = 32;
	so->enemys_walk[ sprite_type_enemyC ][ 3 ] = 32;
	so->enemys_walk[ sprite_type_enemyC ][ 4 ] = 16;
	so->enemys_walk[ sprite_type_enemyC ][ 5 ] = 16;
	so->enemys_walk[ sprite_type_enemyC ][ 6 ] = 16;
	so->enemys_walk[ sprite_type_enemyC ][ 7 ] = 8;

	for( idx = 0; idx < MAX_STATUS; idx++ )
	{
		so->enemys_walk[ sprite_type_enemyB ][ idx ] = 0;
		so->enemys_walk[ sprite_type_enemyD ][ idx ] = 0;
	}
}

//unsigned char *count_text[] =
//{
//	"01",
//	"02",
//	"03",
//	"04",
//	"05",
//	"06",
//	"07",
//	"08",
//	"09",
//	"10",
//};