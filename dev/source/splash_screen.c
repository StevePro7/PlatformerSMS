#include "splash_screen.h"
#include "_sms_manager.h"
#include "enum_manager.h"
#include "content_manager.h"

void screen_splash_screen_load()
{
	devkit_SMS_displayOff();
	engine_content_manager_load_splash();
	devkit_SMS_displayOn();
}

void screen_splash_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_splash;
}