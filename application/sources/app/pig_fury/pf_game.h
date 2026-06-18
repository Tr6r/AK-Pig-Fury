#ifndef __PF_GAME_H__
#define __PF_GAME_H__

#include <stdint.h>
#include "app.h"

#include "pf_pig.h"

class pig_fury_game
{
public:
	pig_fury_game() = default;
	~pig_fury_game() = default;
	void init();
	void update();
	void render();

private:
	pf_pig pig_;
};

extern pig_fury_game game;
void pf_game_init();
void pf_game_render();

#endif //__PF_GAME_H__
