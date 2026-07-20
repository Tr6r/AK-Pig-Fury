#include "task_display.h"

#include "pf_menu_icon.h"

void pf_gameplay_icon::init(int8_t x, int8_t y) {
	anim_phase = 0;
	anim_duration_tick_ = 0;
	uint8_t pos_x = x + PF_MENU_HEART_ICON_OFFSET_X;
	for (int i = 0;i <PF_MENU_HEART_ICON_COUNT;i++) {
		heart_icons_[i].pos_x = pos_x;
		heart_icons_[i].pos_y = y + PF_MENU_HEART_ICON_OFFSET_Y; 
		pos_x += PF_MENU_HEART_ICON_GAP;
	}
}

void pf_gameplay_icon::update() {
}

void pf_gameplay_icon::render(int8_t x, int8_t y) {
	for (int i = 0;i <PF_MENU_HEART_ICON_COUNT;i++) {
		view_render.drawBitmap(x + heart_icons_[i].pos_x,y + heart_icons_[i].pos_y, heart_icon_bitmap, PF_MENU_HEART_ICON_WIDTH, PF_MENU_HEART_ICON_HEIGHT, WHITE);
	}
}

void pf_config_icon::init(int8_t x, int8_t y) {
}

void pf_config_icon::update() {
}

void pf_config_icon::render(int8_t x, int8_t y) {
}