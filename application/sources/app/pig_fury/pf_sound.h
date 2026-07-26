#ifndef __PF_SOUND_H__
#define __PF_SOUND_H__

#include <stdint.h>

#include "buzzer.h"


typedef enum : uint8_t {
	/* Intro */
	PF_SOUND_INTRO = 0,

	PF_SOUND_GAME_INTRO,
	/* Menu */
	PF_SOUND_MENU_SCROLL,
	PF_SOUND_MENU_SELECT,

	/* Config */
	PF_SOUND_CONFIG_SCROLL,
	PF_SOUND_CONFIG_SELECT,

	/* Pig */
	PF_SOUND_PIG_PUNCH,
	PF_SOUND_WEAPON_HIT_ENEMY,

	/* Enemy */
	PF_SOUND_ENEMY_ATTACK,

	/* Gameplay */
	PF_SOUND_GAME_OVER,

	PF_SOUND_COUNT
} pf_sound_t;

class pf_sound {
public:
	pf_sound() = default;
	~pf_sound() = default;

	void init(bool is_enable) { enable_ = is_enable; };

	void play(pf_sound_t sound);

	// getter
	bool is_enable() { return enable_; }
	// setter
	void set_enable(bool enable) { enable_ = enable; }

private:
	bool enable_;
};

extern pf_sound game_sound;


#endif // __PF_SOUND_H__