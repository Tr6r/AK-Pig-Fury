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

static const uint8_t axe_left[] = {
	0x7C, 0x00, 0xFC, 0x00, 0x78, 0x00,
	0x78, 0x00, 0xFF, 0xF8, 0x7F, 0xF8
};

static const uint8_t axe_right[] = {
	0x03, 0xE0, 0x03, 0xF0, 0x01, 0xE0,
	0x01, 0xE0, 0xFF, 0xF8, 0xFF, 0xF0
};

#endif // __PF_AXE_H__
