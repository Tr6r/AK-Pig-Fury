#include "buzzer_music.h"

const Tone_TypeDef tones_startup[] = {
	{2000, 3},
	{   0, 3},
	{3000, 3},
	{   0, 3},
	{4000, 3},
	{   0, 3},
	{1200, 4},
	{   0, 6},
	{4500, 6},
	{   0, 0}
};

const Tone_TypeDef tones_pf_intro[] =   {
	{1175,12},   // D6
	{0,3},
	{1568,10},   // G6
	{0,2},
	{1976,10},   // B6
	{0,3},
	{1568,8},    // G6
	{1760,8},    // A6
	{1976,12},   // B6
	{1760,8},    // A6
	{1568,20},   // G6
	{0,0}
};

const Tone_TypeDef tones_pf_choose_item[] = {
	{1319,2},
	{1568,2},
	{1976,2},
	{2349,2},
	{2637,2},
	{3136,2},
	{3520,2},
	{3136,2},
	{2637,2},
	{2349,2},
	{3136,8},
	{0,0}
};

const Tone_TypeDef tones_pf_menu_scroll[] = {
	{1200,1},
	{1500,1},
	{1800,1},
	{2100,1},
	{2400,1},
	{0,0}
};

const Tone_TypeDef tones_pf_enemy_atk[] = {
	// Impact
	{1300,1},
	{900 ,2},
	{650 ,2},
	// Blink
	{520 ,3},
	{0   ,1},
	{0   ,1},
	{520 ,3},
	{0   ,1},
	{0   ,1},
	{480 ,3},
	{0,0}
};

const Tone_TypeDef tones_pf_pig_punch[] = {
	{1700, 1},
	{1300, 1},
	{950 , 1},
	{700 , 2},
	{500 , 2},
	{0,0}
};

const Tone_TypeDef tones_pf_change_item[] = {
	{4200, 1},
	{3000, 1},
	{1800, 1},
	{900,  1},
	{0,    0},
};

const Tone_TypeDef tones_pf_change_config[] = {
	{2200, 2},
	{2800, 3},
	{2400, 2},
	{0,    0},
};

const Tone_TypeDef tones_pf_game_over[] = {
	{1800, 4},
	{1600, 4},
	{1400, 4},
	{1200, 5},
	{950,  8},
	{0,    0},
};

const Tone_TypeDef tones_pf_weapon_hit_enemy[] = {
	{2200,1},
	{1700,1},
	{1300,2},
	{0,0},
};