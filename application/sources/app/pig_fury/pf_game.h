#ifndef __PF_GAME_H__
#define __PF_GAME_H__

#include <stdint.h>
#include "app.h"

#include "pf_pig.h"
#include "pf_enemy_manager.h"
#include "pf_weapon_manager.h"
class pig_fury_game
{
public:
	pig_fury_game() = default;
	~pig_fury_game() = default;

	void init();
	void update();
	void render();

	void pig_attack(pf_char_dir dir) {pig_.attack(dir);}
	void pig_jump() {pig_.jump();}
	void check_pig_attack_hit();
	void update_spawn();
	bool should_spawn();
	bool check_pig_attack_weapon();
	
private:
	pf_pig pig_;
	pf_enemy_manager enemy_mng_;
	pf_weapon_manager weapon_mng_;
};

void pf_game_init();
void pf_game_update();
void pf_game_render();
void pf_pig_atk(pf_char_dir dir);
void pf_pig_jump();
bool pf_pig_try_pickup_weapon(pf_char_dir dir);

#endif //__PF_GAME_H__
