#include "pf_enemy_manager.h"
#include "pf_config.h"

void pf_enemy_manager::init(pf_config_data data) {
	enemy_count_ = 0;
	for (uint8_t i = 0; i < PF_GAME_MAX_ENEMY; i++)
		enemies_[i] = nullptr;
	for (uint8_t i = 0; i < PF_GAME_MAX_WOLF_BASIC; i++)
		wolves_[i].init(data);
}

void pf_enemy_manager::update(pf_config_data data) {
	for (uint8_t i = 0; i < enemy_count_; i++) {
		enemies_[i]->update();
		if (enemies_[i]->get_st() == PF_ENEMY_ST_DELETE) {
			remove_enemy(i, data);
			i--;
		}
	}
}

void pf_enemy_manager::render() {
for (uint8_t i = 0; i < enemy_count_; i++) 	
	enemies_[i]->render();
}

pf_enemy *pf_enemy_manager::spawn_random_enemy() {
	pf_enemy_type type = static_cast<pf_enemy_type>(rand() % PF_ENEMY_TYPE_COUNT);
	switch (type) {
		case PF_ENEMY_TYPE_WOLF_BASIC:
			return spawn_wolf_basic();
		default:
			return nullptr;
	}
}

pf_wolf_basic *pf_enemy_manager::spawn_wolf_basic() {
	for (uint8_t i = 0; i < PF_GAME_MAX_WOLF_BASIC; i++) {
		if (wolves_[i].get_st() != PF_ENEMY_ST_IDLE)
			continue;
		int r = rand();
		pf_char_dir dir = static_cast<pf_char_dir>(r % 2);
		wolves_[i].spawn(dir);
		enemies_[enemy_count_] = &wolves_[i];
		enemy_count_++;
		return &wolves_[i];
	}
	return nullptr;
}

void pf_enemy_manager::remove_enemy(uint8_t index, pf_config_data data) {
	if (index >= enemy_count_)
		return;
	enemies_[index]->init(data);
	for (uint8_t i = index; i < enemy_count_ - 1; i++)
		enemies_[i] = enemies_[i + 1];
	enemies_[enemy_count_ - 1] = nullptr;
	enemy_count_--;
}