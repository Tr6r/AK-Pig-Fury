#include "pf_game.h"
#include "pf_wolf_basic.h"

pig_fury_game game;
void pf_game_init() {
	game.init();
}

void pf_pig_atk(pf_char_dir dir) {
	game.pig_attack(dir);
}

void pf_pig_jump()
{
	game.pig_jump();
}

void pf_game_render() {
	game.render();
}

void pf_game_update() {
	game.update();
}

void pig_fury_game::init() {
	pig_.init();
	enemy_mng_.init();
	weapon_mng_.init();
}

void pig_fury_game::render() {
	pig_.render();
	enemy_mng_.render();
	weapon_mng_.render();
}

void pig_fury_game::update() {
	update_spawn();
	pig_.update();
	enemy_mng_.update();
	weapon_mng_.update();
	check_pig_attack_hit();
}

void pig_fury_game::update_spawn() {
	if (!should_spawn())
		return;
	pf_enemy *enemy = enemy_mng_.spawn_random_enemy();
	pf_weapon *weapon = weapon_mng_.spawn_weapon(PF_WEAPON_TYPE_AXE, enemy->get_dir());
	enemy->set_weapon(weapon);
}

bool pig_fury_game::should_spawn() {
	if (enemy_mng_.get_enemy_count() >= PF_GAME_MAX_ENEMY)
		return false;
	if (weapon_mng_.get_weapon_count() >= PF_GAME_MAX_WEAPON)
		return false;
	return true;
}

void pig_fury_game::check_pig_attack_hit() {
	if (!pig_.is_attack_hit_frame()) return;
	for (int i=0;i<enemy_mng_.get_enemy_count();i++)
	{
		pf_enemy *enemy = enemy_mng_.get_enemy(i);
		switch (pig_.get_dir())
		{
		case PF_CHAR_DIR_LEFT: {
			if (enemy->get_pos_x() + enemy->get_width() >= pig_.get_pos_x() - PIG_ATK_RANGE && enemy->get_pos_x() <= pig_.get_pos_x()) {
				enemy->take_damage();
				return;
			}
			break;
		}
		case PF_CHAR_DIR_RIGHT: {
			if (enemy->get_pos_x() <= pig_.get_pos_x() + PIG_WIDTH + PIG_ATK_RANGE && enemy->get_pos_x() + enemy->get_width() >= pig_.get_pos_x() + PIG_WIDTH) {
				enemy->take_damage();
				return;
			}
			break;
		}
		default:
			break;
		 }
	}
}