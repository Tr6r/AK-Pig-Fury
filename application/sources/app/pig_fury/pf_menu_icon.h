#ifndef __PF_MENU_ICON_H__
#define __PF_MENU_ICON_H__

#include "stdint.h"

#define PF_MENU_HEART_ICON_WIDTH 7
#define PF_MENU_HEART_ICON_HEIGHT 6
#define PF_MENU_HEART_ICON_GAP 10
#define PF_MENU_HEART_ICON_COUNT 3
#define PF_MENU_HEART_ICON_ACT_FRAME 4
#define PF_MENU_HEART_ICON_IDLE_FRAME 10
#define PF_MENU_HEART_ICON_OFFSET_X -2
#define PF_MENU_HEART_ICON_OFFSET_Y -8


struct pf_menu_heart_icon {
	int8_t pos_x;
	int8_t pos_y;
};

// heart icon
static const uint8_t heart_icon_bitmap[]  = {
	0x6D, 0x93, 0x83, 0x45, 0x29, 0x11
};

class pf_menu_icon {
public:
	pf_menu_icon() = default;
	virtual ~pf_menu_icon() = default;
	virtual void init(int8_t x, int8_t y) = 0;
	virtual void update() = 0;
	virtual void render(int8_t x, int8_t y) = 0;
};

class pf_gameplay_icon : public pf_menu_icon {
public:
	pf_gameplay_icon() = default;
	~pf_gameplay_icon() override = default;

	void init(int8_t x, int8_t y) override;
	void update() override;
	void render(int8_t x, int8_t y) override;

private:
	pf_menu_heart_icon heart_icons_[PF_MENU_HEART_ICON_COUNT];
	uint8_t anim_phase;
	uint8_t anim_duration_tick_;
	bool is_idle_ = false;
};

class pf_config_icon : public pf_menu_icon {
public:
	pf_config_icon() = default;
	~pf_config_icon() override = default;

	void init(int8_t x, int8_t y) override;
	void update() override;
	void render(int8_t x, int8_t y) override;
};

#endif //__PF_MENU_ICON_H__
