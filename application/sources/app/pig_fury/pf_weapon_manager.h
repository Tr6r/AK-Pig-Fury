#ifndef __PF_WEAPON_MANAGER_H__
#define __PF_WEAPON_MANAGER_H__

#include "pf_enemy_manager.h"
#include "pf_weapon.h"
#include "pf_axe.h"

#define PF_GAME_MAX_WEAPON (PF_GAME_MAX_ENEMY + 4)

enum pf_weapon_type : uint8_t {
	PF_WEAPON_TYPE_AXE = 0,
	PF_WEAPON_TYPE_COUNT,
};

class pf_weapon_manager {
public:
	pf_weapon_manager() = default;
	~pf_weapon_manager() = default;

	void init();
	void update();
	void render();

	pf_weapon *spawn_weapon(pf_weapon_type type);
	pf_weapon *spawn_axe();

	void remove_weapon(uint8_t index);

private:
	pf_axe axes_[PF_GAME_MAX_WEAPON];

	pf_weapon *weapons_[PF_GAME_MAX_WEAPON];
	uint8_t weapon_count_;
};

#endif // __PF_WEAPON_MANAGER_H__