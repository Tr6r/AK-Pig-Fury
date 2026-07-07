#include "pf_weapon_manager.h"

void pf_weapon_manager::init() {
	weapon_count_ = 0;
	for (uint8_t i = 0; i < PF_GAME_MAX_WEAPON; i++) {
		axes_[i].init();
		weapons_[i] = nullptr;
	}
}

pf_weapon *pf_weapon_manager::spawn_weapon(pf_weapon_type type, pf_char_dir dir) {
	switch (type) {
		case PF_WEAPON_TYPE_AXE:
			return spawn_axe(dir);
		default:
			return nullptr;
	}
}

pf_weapon *pf_weapon_manager::spawn_axe(pf_char_dir dir) {
	for (uint8_t i = 0; i < PF_GAME_MAX_WEAPON; i++) {
		if (axes_[i].get_st() != PF_WEAPON_ST_IDLE)
			continue;
		axes_[i].set_dir(dir);
		axes_[i].set_st(PF_WEAPON_ST_ATTACH);
		axes_[i].set_visible(true);
		weapons_[weapon_count_] = &axes_[i];
		weapon_count_++;
		return &axes_[i];
	}
	return nullptr;
}

void pf_weapon_manager::update() {
	for (uint8_t i = 0; i < weapon_count_; i++) {
		weapons_[i]->update();
		if (weapons_[i]->get_st() == PF_WEAPON_ST_DELETE) {
			remove_weapon(i);
			i--;
		}
	}
}

void pf_weapon_manager::render() {
	for (uint8_t i = 0; i < weapon_count_; i++)
		weapons_[i]->render();
}

void pf_weapon_manager::remove_weapon(uint8_t index)
{
	if (index >= weapon_count_)
		return;
	weapons_[index]->init();
	for (uint8_t i = index; i < weapon_count_ - 1; i++)
		weapons_[i] = weapons_[i + 1];
	weapons_[weapon_count_ - 1] = nullptr;
	weapon_count_--;
}