#include "beat_screen.h"
#include "_sms_manager.h"
//#include "global_manager.h"
//#include "locale_manager.h"
#include "enum_manager.h"
//#include "font_manager.h"
#include "text_manager.h"
//#include "tile_manager.h"
#include "memo_manager.h"
#include <stdlib.h>

void screen_beat_screen_load()
{
	devkit_SMS_displayOff();
	engine_text_manager_clear_all();
	engine_memo_manager_draw_beat();
	devkit_SMS_displayOn();
}

void screen_beat_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_beat;
}