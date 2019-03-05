#include "anim_object.h"

#include "..\sprites\enemyA.h"
//#include "..\sprites\enemyB.h"
#include "..\sprites\enemyC.h"

// EnemyA
const unsigned char *anemyA_anim_data[] =
{
	enemyA_idle__tiles__psgcompr,
	enemyA_run_left_01__tiles__psgcompr,
	enemyA_run_left_02__tiles__psgcompr,
};
const unsigned char anemyA_anim_bank[] =
{
	enemyA_idle__tiles__psgcompr_bank,
	enemyA_run_left_01__tiles__psgcompr_bank,
	enemyA_run_left_02__tiles__psgcompr_bank,
};

// EnemyC
const unsigned char *anemyC_anim_data[] =
{
	enemyC_idle__tiles__psgcompr,
	enemyC_run_left_01__tiles__psgcompr,
	enemyC_run_left_02__tiles__psgcompr,
};
const unsigned char anemyC_anim_bank[] =
{
	enemyC_idle__tiles__psgcompr_bank,
	enemyC_run_left_01__tiles__psgcompr_bank,
	enemyC_run_left_02__tiles__psgcompr_bank,
};