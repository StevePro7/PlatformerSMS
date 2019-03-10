#include "audio_manager.h"
#include "_psg_manager.h"
#include "..\psg.h"

#define MUSIC_PSG			music_psg
#define FINISH_PSG			finish_psg
#define SOUND1_PSG			sfx_right_psg
#define SOUND2_PSG			sfx_wrong_psg
#define SOUND3_PSG			sfx_cheat_psg

void engine_audio_manager_start_music()
{
	//if( hacker_music )
	{
		devkit_PSGSetMusicVolumeAttenuation( 0 );
		devkit_PSGPlayNoRepeat( ( unsigned char* ) MUSIC_PSG );
	}
}

void engine_audio_manager_finish_music()
{
	//if( hacker_music )
	{
		devkit_PSGSetMusicVolumeAttenuation( 0 );
		devkit_PSGPlayNoRepeat( ( unsigned char* ) FINISH_PSG );
	}
}

void engine_audio_manager_stop_music()
{
	//if( hacker_music )
	{
		devkit_PSGStop();
	}
}

void engine_audio_manager_sound_right()
{
	//if( hacker_sound )
	{
		devkit_PSGSFXPlay( ( unsigned char* ) SOUND1_PSG, devkit_SFX_CHANNEL2() );
	}
}

void engine_audio_manager_sound_wrong()
{
	//if( hacker_sound )
	{
		devkit_PSGSFXPlay( ( unsigned char* ) SOUND2_PSG, devkit_SFX_CHANNEL2() );
	}
}

void engine_audio_manager_sound_cheat()
{
	//if( hacker_sound )
	{
		devkit_PSGSFXPlay( ( unsigned char* ) SOUND3_PSG, devkit_SFX_CHANNEL2() );
	}
}

