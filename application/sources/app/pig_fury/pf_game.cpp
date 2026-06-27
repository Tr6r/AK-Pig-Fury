#include "pf_game.h"

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
	pig_.init(PF_CHAR_DIR_LEFT);
}

void pig_fury_game::render() {
	pig_.render();
}

void pig_fury_game::update() {
	pig_.update();
}