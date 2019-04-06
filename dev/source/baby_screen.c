#include "baby_screen.h"
#include "enum_manager.h"
#include "memo_manager.h"
#include "delay_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "audio_manager.h"

void screen_baby_screen_load()
{
}

void screen_baby_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_baby;
}