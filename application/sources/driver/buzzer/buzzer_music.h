#ifndef __BUZZER_MUSIC_H__
#define __BUZZER_MUSIC_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

// Single tone definition. Duration unit is 10 ms.
typedef struct {
	uint16_t frequency;
	uint8_t  duration;
} Tone_TypeDef;

typedef enum {
	BUZZER_SOUND_STARTUP = 0,
	BUZZER_SOUND_GAME_INTRO,
	/* Menu */
	BUZZER_SOUND_MENU_SCROLL,
	BUZZER_SOUND_MENU_SELECT,
	/* Config */
	BUZZER_SOUND_CONFIG_SCROLL,
	BUZZER_SOUND_CONFIG_SELECT,
	/* Gameplay */
	BUZZER_SOUND_PIG_PUNCH,
	BUZZER_SOUND_ENEMY_ATTACK,
	BUZZER_SOUND_WEAPON_HIT_ENEMY,

	BUZZER_SOUND_GAME_OVER,

	/* Game State */
	BUZZER_SOUND_MAX
} buzzer_sound_t;


extern const Tone_TypeDef tones_startup[];
extern const Tone_TypeDef tones_pf_intro[];
extern const Tone_TypeDef tones_pf_choose_item[];
extern const Tone_TypeDef tones_pf_menu_scroll[];
extern const Tone_TypeDef tones_pf_enemy_atk[];
extern const Tone_TypeDef tones_pf_pig_punch[];
extern const Tone_TypeDef tones_pf_change_item[];
extern const Tone_TypeDef tones_pf_change_config[];
extern const Tone_TypeDef tones_pf_game_over[];
extern const Tone_TypeDef tones_pf_weapon_hit_enemy[];

#ifdef __cplusplus
}
#endif

#endif // __BUZZER_MUSIC_H__
