#include "sys_ctrl.h"

#include "pf_game.h"
#include "pf_wolf_basic.h"

pig_fury_game game;
void pf_game_init() {
	game.init();
}

void pf_gameplay_init() {
	game.gameplay_init();
}

void pf_pig_atk(pf_char_dir dir) {
	game.pig_attack(dir);
}

void pf_pig_jump()
{
	game.pig_jump();
}

void pf_game_render() {
	game.game_play_render();
}

void pf_game_update() {
	game.game_play_update();
}

void pf_menu_render() {
	game.menu_render();
}

void pf_config_render() {
	game.config_render();
}

void pf_config_update() {
	game.config_update();
}

void pf_change_config() {
	game.change_config();
}

pf_config_item pf_get_cur_config_item() {
	return game.get_cur_config_item();
}

void pf_menu_update() {
	game.menu_update();
}

pf_menu_item_st pf_get_menu_st() {
	return game.get_menu_st();
}

pf_menu_item_st pig_fury_game::get_menu_st() {
	return menu_.get_menu_st();
}

bool pf_pig_try_pickup_weapon(pf_char_dir dir) {
	return game.check_pig_attach_weapon();
}

void pf_menu_move_next_item(pf_menu_anim_dir dir) {
	game.menu_move_next_item(dir);
}

void pf_config_move_next_item(pf_menu_anim_dir dir) {
	game.config_move_next_item(dir);
}

bool pf_check_pig_dead() {
	return game.check_pig_dead();
}

void pig_fury_game::menu_move_next_item(pf_menu_anim_dir dir) {
	(dir == PF_MENU_ANIM_LEFT ? menu_.move_pre_item() : menu_.move_next_item());
}

void pig_fury_game::config_move_next_item(pf_menu_anim_dir dir) {
	(dir == PF_MENU_ANIM_LEFT ? conf_.move_down() : conf_.move_up());
}

void pig_fury_game::init() {
	if (is_initialized_) return;
	is_initialized_ = true;
	menu_.init();
	conf_.init();
}

void pig_fury_game::gameplay_init() {
	pf_config_data data = conf_.get_config_data();
	pig_.init(data);
	enemy_mng_.init(data);
	weapon_mng_.init();
}

void pig_fury_game::menu_update() {
	menu_.update();
}

void pig_fury_game::menu_render() {
	menu_.render();
}

void pig_fury_game::config_render() {
	conf_.render();
}

void pig_fury_game::config_update() {
	conf_.update();
}

void pig_fury_game::change_config() {
	conf_.change_config();
}

pf_config_item pig_fury_game::get_cur_config_item() {
	return conf_.get_cur_item();
}


void pig_fury_game::game_play_render() {
	pig_.render();
	enemy_mng_.render();
	weapon_mng_.render();
}

void pig_fury_game::game_play_update() {
	update_spawn();
	pf_config_data data = conf_.get_config_data();
	pig_.update();
	enemy_mng_.update(data);
	weapon_mng_.update();
	check_throw_weapon_attack_hit();
	check_pig_attack_hit();
	check_enemy_attack_hit();
}

void pig_fury_game::check_enemy_attack_hit() {
	if (pig_.get_hit_duration_frame() > 0)
		return;
	for (int i = 0; i < enemy_mng_.get_enemy_count(); i++) {
		pf_enemy *enemy = enemy_mng_.get_enemy(i);
		if (!enemy->is_attack_hit_frame())
			continue;
		pig_.take_damage(enemy->get_damage());
		break;
	}
}

bool pig_fury_game::check_pig_attach_weapon()
{
	if (pig_.get_weapon()) return false;
	for (uint8_t i = 0; i < weapon_mng_.get_weapon_count(); i++)
	{
		pf_weapon *weapon = weapon_mng_.get_weapon(i);
		if ((weapon->get_st() != PF_WEAPON_ST_FALL && weapon->get_st() != PF_WEAPON_ST_FLY) || weapon->is_pickup())
			continue;
		switch (pig_.get_dir())
		{
			case PF_CHAR_DIR_LEFT:
				if (weapon->get_pos_x() + weapon->get_width() >= pig_.get_pos_x() - PIG_COLLECT_WEAPON_RANGE && weapon->get_pos_x() <= pig_.get_pos_x()) {
					if (pig_.get_weapon()) pig_.get_weapon()->set_st(PF_WEAPON_ST_FALL);
					pig_.set_weapon(weapon);
					pig_.set_atk_st(PF_PIG_ATTACK_WEAPON_PICKUP);
					pig_.set_atk_dur_tick(PIG_ATK_FRAME_TICK);
					weapon->set_dir(PF_CHAR_DIR_LEFT);
					weapon->set_st(PF_WEAPON_ST_PENDING_ATTACH);
					weapon->set_pickup(true);
					return true;
				}
				break;
			case PF_CHAR_DIR_RIGHT:
				if (weapon->get_pos_x() <= pig_.get_pos_x() + PIG_WIDTH + PIG_COLLECT_WEAPON_RANGE && weapon->get_pos_x() + weapon->get_width() >= pig_.get_pos_x() + PIG_WIDTH) {
					if (pig_.get_weapon()) pig_.get_weapon()->set_st(PF_WEAPON_ST_FALL);
					pig_.set_weapon(weapon);
					pig_.set_atk_st(PF_PIG_ATTACK_WEAPON_PICKUP);
					pig_.set_atk_dur_tick(PIG_ATK_FRAME_TICK);
					weapon->set_dir(PF_CHAR_DIR_RIGHT);
					weapon->set_st(PF_WEAPON_ST_PENDING_ATTACH);
					weapon->set_pickup(true);
					return true;
				}
				break;
		}
	}
	return false;
}

void pig_fury_game::update_spawn() {
	if (!should_spawn())
		return;
	pf_enemy *enemy = enemy_mng_.spawn_random_enemy();
	pf_weapon *weapon = weapon_mng_.spawn_weapon(PF_WEAPON_TYPE_AXE, enemy->get_dir());
	enemy->set_weapon(weapon);
	sys_ctrl_delay_us(2);
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
				if (pig_.get_weapon()) {
					pig_.get_weapon()->next_action();
					enemy->take_damage(pig_.get_weapon()->get_damage());
				}
				else enemy->take_damage(PIG_ATK_DAMAGE);
				return;
			}
			break;
		}
		case PF_CHAR_DIR_RIGHT: {
			if (enemy->get_pos_x() <= pig_.get_pos_x() + PIG_WIDTH + PIG_ATK_RANGE && enemy->get_pos_x() + enemy->get_width() >= pig_.get_pos_x() + PIG_WIDTH) {
				if (pig_.get_weapon()) {
					pig_.get_weapon()->next_action();
					enemy->take_damage(pig_.get_weapon()->get_damage());
				}
				else enemy->take_damage(PIG_ATK_DAMAGE);
				return;
			}
			break;
		}
		default:
			break;
		 }
	}
}

void pig_fury_game::check_throw_weapon_attack_hit() {
	for (uint8_t i = 0; i < weapon_mng_.get_weapon_count(); i++)
	{
		pf_weapon *weapon = weapon_mng_.get_weapon(i);
		if (weapon->get_st() != PF_WEAPON_ST_THROW)
			continue;
		for (uint8_t j = 0; j < enemy_mng_.get_enemy_count(); j++)
		{
			pf_enemy *enemy = enemy_mng_.get_enemy(j);
			if (!check_weapon_hit_enemy(weapon, enemy)||enemy->get_st() == PF_ENEMY_ST_DEAD||enemy->get_st() == PF_ENEMY_ST_DELETE||enemy->get_st() == PF_ENEMY_ST_KNOCKBACK)
				continue;
			enemy->take_damage(weapon->get_damage());
			weapon->set_st(PF_WEAPON_ST_FALL);
			return;
		}
	}
}

bool pig_fury_game::check_weapon_hit_enemy(pf_weapon *weapon, pf_enemy *enemy) {
	return (
		weapon->get_pos_x() < enemy->get_pos_x() + enemy->get_width() &&
		weapon->get_pos_x() + weapon->get_width() > enemy->get_pos_x() &&
		weapon->get_pos_y() < enemy->get_pos_y() + enemy->get_height() &&
		weapon->get_pos_y() + weapon->get_height() > enemy->get_pos_y()
	);
}