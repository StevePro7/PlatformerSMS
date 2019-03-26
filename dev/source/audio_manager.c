#include "audio_manager.h"
#include "_snd_manager.h"
#include "hack_manager.h"
#include "..\psg.h"

//#define MUSIC_PSG			music_psg

#define sfx_accept_psg			sfx_accept_psg
#define sfx_death_psg			sfx_death_psg
#define sfx_gem_psg				sfx_gem_psg
#define sfx_level_psg			sfx_level_psg
#define sfx_power_psg			sfx_power_psg
#define sfx_reset_psg			sfx_reset_psg

// Private helper function.
static void play_sound( unsigned char *sfx );

void engine_audio_manager_music_beat()
{

}
void engine_audio_manager_music_over()
{
	//if( hacker_music )
	{
		devkit_PSGSetMusicVolumeAttenuation( 0 );
		//devkit_PSGPlayNoRepeat( ( unsigned char* ) MUSIC_PSG );
	}
}

void engine_audio_manager_finish_music()
{
	//if( hacker_music )
	{
		//devkit_PSGSetMusicVolumeAttenuation( 0 );
		//devkit_PSGPlayNoRepeat( ( unsigned char* ) FINISH_PSG );
	}
}

void engine_audio_manager_music_stop()
{
	devkit_PSGStop();
}

void engine_audio_manager_sound_accept()
{
	play_sound( ( unsigned char* ) sfx_accept_psg );
}
void engine_audio_manager_sound_death()
{
	play_sound( ( unsigned char* ) sfx_death_psg );
}
void engine_audio_manager_sound_gem()
{
	play_sound( ( unsigned char* ) sfx_gem_psg );
}
void engine_audio_manager_sound_level()
{
	play_sound( ( unsigned char* ) sfx_level_psg );
}
void engine_audio_manager_sound_power()
{
	play_sound( ( unsigned char* ) sfx_power_psg );
}
void engine_audio_manager_sound_reset()
{
	play_sound( ( unsigned char* ) sfx_reset_psg );
}

static void play_sound( unsigned char *sfx )
{
	struct_hack_object *ho = &global_hack_object;
	if( !ho->hack_sound )
	{
		return;
	}

	devkit_PSGSFXPlay( sfx, devkit_SFX_CHANNEL2() );
}