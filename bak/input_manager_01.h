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

// Public methods MOVE.
unsigned char engine_input_manager_move_down()
{
	return engine_input_manager_move( PORT_A_KEY_DOWN );
}

// Private helper methods.
static unsigned char engine_input_manager_hold( unsigned int data )
{
	bool input = false;
	if( curr_joypad1 & data && !( prev_joypad1 & data ) )
	{
		input = true;
	}

	return input;
}
static unsigned char engine_input_manager_move( unsigned int data )
{
	bool input = false;
	if( curr_joypad1 & data )
	{
		input = true;
	}

	return input;
}

#endif//_INPUT_MANAGER_H_