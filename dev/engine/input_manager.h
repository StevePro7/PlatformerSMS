#ifndef _INPUT_MANAGER_H_
#define _INPUT_MANAGER_H_

// Must be static to persist values!
static unsigned int curr_joypad1 = 0;
static unsigned int prev_joypad1 = 0;

// Private helper methods.
static unsigned char engine_input_manager_hold( unsigned int data );
static unsigned char engine_input_manager_move( unsigned int data );

// Public method.
void engine_input_manager_update()
{
	prev_joypad1 = curr_joypad1;
	curr_joypad1 = SMS_getKeysStatus();
}

// Public methods HOLD.
unsigned char engine_input_manager_hold_up()
{
	return engine_input_manager_hold( PORT_A_KEY_UP );
}
unsigned char engine_input_manager_hold_down()
{
	return engine_input_manager_hold( PORT_A_KEY_DOWN );
}
unsigned char engine_input_manager_hold_left()
{
	return engine_input_manager_hold( PORT_A_KEY_LEFT );
}
unsigned char engine_input_manager_hold_right()
{
	return engine_input_manager_hold( PORT_A_KEY_RIGHT );
}
unsigned char engine_input_manager_hold_fire1()
{
	return engine_input_manager_hold( PORT_A_KEY_1 );
}
unsigned char engine_input_manager_hold_fire2()
{
	return engine_input_manager_hold( PORT_A_KEY_2 );
}

// Public methods MOVE.
unsigned char engine_input_manager_move_up()
{
	return engine_input_manager_move( PORT_A_KEY_UP );
}
unsigned char engine_input_manager_move_down()
{
	return engine_input_manager_move( PORT_A_KEY_DOWN );
}
unsigned char engine_input_manager_move_left()
{
	return engine_input_manager_move( PORT_A_KEY_LEFT );
}
unsigned char engine_input_manager_move_right()
{
	return engine_input_manager_move( PORT_A_KEY_RIGHT );
}
unsigned char engine_input_manager_move_fire1()
{
	return engine_input_manager_move( PORT_A_KEY_1 );
}
unsigned char engine_input_manager_move_fire2()
{
	return engine_input_manager_move( PORT_A_KEY_2 );
}

// Private helper methods.
static unsigned char engine_input_manager_hold( unsigned int data )
{
	//bool input = false;
	if( curr_joypad1 & data && !( prev_joypad1 & data ) )
	{
		return true;
	}

	return false;
}
static unsigned char engine_input_manager_move( unsigned int data )
{
	//bool input = false;
	if( curr_joypad1 & data )
	{
		return true;
	}

	return false;
}

#endif//_INPUT_MANAGER_H_