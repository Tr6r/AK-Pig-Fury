#ifndef __PF_GAME_H__
#define __PF_GAME_H__

#include <stdint.h>
#include "app.h"

#include "pf_menu.h"
#include "pf_config.h"
#include "pf_pig.h"
#include "pf_enemy_manager.h"
#include "pf_weapon_manager.h"

class pig_fury_game
{
public:
	pig_fury_game() = default;
	~pig_fury_game() = default;

	void init();
	void gameplay_init();
	void menu_update();
	void menu_render();
	void config_update();
	void config_render();
	void change_config();
	pf_config_item get_cur_config_item();
	void menu_move_next_item(pf_menu_anim_dir dir);
	void config_move_next_item(pf_menu_anim_dir dir);
	void game_play_update();
	void game_play_render();

	void pig_attack(pf_char_dir dir) {pig_.attack(dir);}
	void pig_jump() {pig_.jump();}
	void check_pig_attack_hit();
	void update_spawn();
	bool should_spawn();
	bool check_pig_attach_weapon();
	bool check_weapon_hit_enemy(pf_weapon *weapon, pf_enemy *enemy);
	void check_throw_weapon_attack_hit();
	void check_enemy_attack_hit();
	pf_menu_item_st get_menu_st();

private:
	pf_menu menu_;
	pf_config conf_;
	pf_pig pig_;
	pf_enemy_manager enemy_mng_;
	pf_weapon_manager weapon_mng_;
	bool is_initialized_;
};

void pf_game_init();
void pf_gameplay_init();
void pf_menu_render();
void pf_menu_update();
void pf_config_render();
void pf_config_update();
void pf_change_config();
pf_config_item pf_get_cur_config_item();
void pf_menu_move_next_item(pf_menu_anim_dir dir);
void pf_config_move_next_item(pf_menu_anim_dir dir);
void pf_game_update();
void pf_game_render();
void pf_pig_atk(pf_char_dir dir);
void pf_pig_jump();
bool pf_pig_try_pickup_weapon(pf_char_dir dir);
pf_menu_item_st pf_get_menu_st();

#endif //__PF_GAME_H__
