#include "pf_game.h"

pig_fury_game game;

void pf_game_init()
{
	game.init();
}

void pf_game_render()
{
	game.render();
}

void pig_fury_game::init()
{
	pig_.init();
}

void pig_fury_game::render()
{
	pig_.render();
}
void pig_fury_game::update(){}
