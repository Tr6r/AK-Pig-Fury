#ifndef __PF_AXE_H__
#define __PF_AXE_H__

#include "pf_weapon.h"

#define PF_AXE_WIDTH 13
#define PF_AXE_HEIGHT 6
#define PF_AXE_ATK_FRAME_TICK 6
#define PF_AXE_UPDATE_STEP_PIXEL 2
#define PF_AXE_FLY_MAX_HEIGHT 30

static const pf_pig_weapon_action axe_actions[] = {
	PF_PIG_WEAPON_ACTION_THROW
};

class pf_axe : public pf_weapon {
public:
	pf_axe() = default;
	~pf_axe() override = default;

	void init();
	void update() override;
	void render() override;
	void attack() override;
	pf_pig_weapon_action get_pig_action() const override { return axe_actions[action_count_]; };
	void next_action() override { action_count_++; }

private:
	void update_attach();
	void update_fly();
	void update_fall();
	void update_detach_rotation() {
		rotation_ = (rotation_ + 45) % 360;
	}
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
