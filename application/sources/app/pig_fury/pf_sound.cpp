#include "pf_sound.h"

pf_sound game_sound;

void pf_sound::play(pf_sound_t sound) {
	if (!enable_) return;
	switch (sound)
	{
		case PF_SOUND_GAME_INTRO:
			BUZZER_PlaySound(BUZZER_SOUND_GAME_INTRO);
			break;
		case PF_SOUND_MENU_SCROLL:
			BUZZER_PlaySound(BUZZER_SOUND_MENU_SCROLL);
			break;
		case PF_SOUND_MENU_SELECT:
			BUZZER_PlaySound(BUZZER_SOUND_MENU_SELECT);
			break;
		case PF_SOUND_CONFIG_SCROLL:
			BUZZER_PlaySound(BUZZER_SOUND_CONFIG_SCROLL);
			break;
		case PF_SOUND_CONFIG_SELECT:
			BUZZER_PlaySound(BUZZER_SOUND_CONFIG_SELECT);
			break;
		case PF_SOUND_PIG_PUNCH:
			BUZZER_PlaySound(BUZZER_SOUND_PIG_PUNCH);
			break;
		case PF_SOUND_ENEMY_ATTACK:
			BUZZER_PlaySound(BUZZER_SOUND_ENEMY_ATTACK);
			break;
		case PF_SOUND_GAME_OVER:
			BUZZER_PlaySound(BUZZER_SOUND_GAME_OVER);
			break;
		case PF_SOUND_WEAPON_HIT_ENEMY:
			BUZZER_PlaySound(BUZZER_SOUND_WEAPON_HIT_ENEMY);
			break;
		default:
			break;
	}
}