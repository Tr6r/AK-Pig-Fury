#ifndef __PF_AXE_H__
#define __PF_AXE_H__

#include "pf_weapon.h"

#define PF_AXE_WIDTH 13
#define PF_AXE_HEIGH 6
#define PF_AXE_ATK_FRAME_TICK 6

class pf_axe : public pf_weapon {
public:
	pf_axe() = default;
	~pf_axe() override = default;

	void init(pf_char_dir dir) override;
	void update() override;
	void render() override;
	void attack() override;

	// setter
	void set_anchor(uint8_t x, uint8_t y);

private:
	void update_attach();
	void update_fly();

	int16_t anchor_x_;
	int16_t anchor_y_;
	int16_t render_x_;
	int16_t render_y_;
	uint8_t width_;
	uint8_t height_;
	uint8_t speed_;
	uint16_t angle_;
	uint8_t anim_tick_;
};

static const uint8_t axe[]  = {
	0x7C, 0x07, 0x82, 0x07, 0x44, 0x07,
	0x44, 0x07, 0x83, 0xFF, 0x7F, 0xFF
};

#endif // __PF_AXE_H__