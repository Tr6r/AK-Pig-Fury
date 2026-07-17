#ifndef __PF_MENU_H__
#define __PF_MENU_H__

#include "stdint.h"

#include "task_display.h"

#define PF_MENU_ICON_W     32
#define PF_MENU_ICON_H     32
#define PF_MENU_INIT_POS_X (LCD_WIDTH - PF_MENU_ICON_W)/2
#define PF_MENU_INIT_POS_Y (LCD_HEIGHT - PF_MENU_ICON_H)/2
#define PF_MENU_SPACING    40 

enum pf_menu_item : uint8_t {
	PF_MENU_GAMEPLAY,
	PF_MENU_CONFIG,
	PF_MENU_TOP,
	PF_MENU_ITEM_COUNT,
};

class pf_menu {
public:
	pf_menu() = default;
	~pf_menu() = default;
	void init();
	void update();
	void move_left();
	void move_right();

private:
	int16_t get_item_x(pf_menu_item item) const;
	const uint8_t* get_bitmap(pf_menu_item item) const;

	int16_t pos_x_;
	int16_t pos_y_;
	uint8_t current_item_;
};

#endif //__PF_MENU_H__
