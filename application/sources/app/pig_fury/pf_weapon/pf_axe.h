#ifndef __PF_AXE_H__
#define __PF_AXE_H__

#include "pf_weapon.h"

#define PF_AXE_WIDTH 13
#define PF_AXE_HEIGHT 6
#define PF_AXE_ATK_FRAME_TICK 6

class pf_axe : public pf_weapon {
public:
	pf_axe() = default;
	~pf_axe() override = default;

	void init(pf_char_dir dir);
	void update() override;
	void render() override;
	void attack() override;

	// setter
	void set_anchor(uint8_t x, uint8_t y) { pos_x_ = x; pos_y_ = y; }

private:
	void update_attach();
	void update_fly();
};

static const uint8_t axe_left[]  = {
	0x7C, 0x07, 0x82, 0x07, 0x44, 0x07,
	0x44, 0x07, 0x83, 0xFF, 0x7F, 0xFF
};

static const uint8_t axe_right[] = {
	0x01, 0xF7, 0x02, 0x0F, 0x01, 0x17,
	0x01, 0x17, 0xFE, 0x0F, 0xFF, 0xF7
};

#endif // __PF_AXE_H__
