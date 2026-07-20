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

protected:
	uint8_t anim_duration_tick_;
	bool is_idle_ = false;
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
};

struct pf_menu_config_icon {
	int8_t dot_pos_x;
	int8_t target_dot_pos_x;
	int8_t dot_pos_y;
	int8_t line_pos_x;
	int8_t line_pos_y;
	uint8_t rand_idx;
	int8_t dir;
}; 

#define PF_MENU_CONFIG_ICON_COUNT 3
#define PF_MENU_DOT_ICON_WIDTH 3
#define PF_MENU_DOT_ICON_HEIGHT 3
#define PF_MENU_DOT_ICON_GAP 11
#define PF_MENU_LINE_ICON_WIDTH 24
#define PF_MENU_LINE_ICON_HEIGHT 1
#define PF_MENU_LINE_ICON_GAP 4
#define PF_MENU_CONFIG_ICON_ACT_FRAME 4
#define PF_MENU_CONFIG_ICON_IDLE_FRAME 10
#define PF_MENU_CONFIG_ICON_OFFSET_X 8
#define PF_MENU_CONFIG_ICON_OFFSET_Y -12
#define PF_MENU_CONFIG_DOT_POS_COUNT 8
#define PF_MENU_CONFIG_POS_SEQ_COUNT 32

static const uint8_t dot_pos_x_table[PF_MENU_CONFIG_DOT_POS_COUNT] = {0, 3, 6, 9, 12, 15, 18, 22};
static const uint8_t dot_pos_seq[PF_MENU_CONFIG_POS_SEQ_COUNT] = {
	3, 0, 6, 2, 7, 1, 5, 4,
	1, 5, 2, 6, 0, 7, 3, 4,
	6, 2, 4, 0, 5, 3, 7, 1,
	4, 7, 1, 5, 2, 0, 6, 3
};

class pf_config_icon : public pf_menu_icon {
public:
	pf_config_icon() = default;
	~pf_config_icon() override = default;

	void init(int8_t x, int8_t y) override;
	void update() override;
	void render(int8_t x, int8_t y) override;

private:
	void dot_get_new_pos(pf_menu_config_icon *icon);
	pf_menu_config_icon config_icons_[PF_MENU_CONFIG_ICON_COUNT];
	uint8_t arrive_mask = 0;
};

#endif //__PF_MENU_ICON_H__
