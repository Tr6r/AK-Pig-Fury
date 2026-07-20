#include "task_display.h"

#include "pf_menu_icon.h"
#include "pf_menu.h"

void pf_gameplay_icon::init(int8_t x, int8_t y) {
	anim_phase = 0;
	anim_duration_tick_ = PF_MENU_HEART_ICON_ACT_FRAME;
	uint8_t pos_x = x + PF_MENU_HEART_ICON_OFFSET_X;
	for (int i = 0;i <PF_MENU_HEART_ICON_COUNT;i++) {
		heart_icons_[i].pos_x = pos_x;
		heart_icons_[i].pos_y = y + PF_MENU_HEART_ICON_OFFSET_Y; 
		pos_x += PF_MENU_HEART_ICON_GAP;
	}
}

void pf_gameplay_icon::update()
{
	if (anim_duration_tick_ == 0) {
		if (!is_idle_) anim_phase = (anim_phase + 1) % PF_MENU_HEART_ICON_COUNT;
		if (anim_phase == 0 && !is_idle_) {
			is_idle_ = true;
			anim_duration_tick_ = PF_MENU_HEART_ICON_IDLE_FRAME;
		}
		else {
			is_idle_ = false;
			anim_duration_tick_ = PF_MENU_HEART_ICON_ACT_FRAME;
		}
	}
	if (is_idle_) {
		anim_duration_tick_ --;
		return;
	}
	int8_t cur_y = 0;
	(anim_duration_tick_ > (PF_MENU_HEART_ICON_ACT_FRAME / 2) ? cur_y = -2 : cur_y = 2);
	heart_icons_[anim_phase].pos_y += cur_y;
	anim_duration_tick_--;
}

void pf_gameplay_icon::render(int8_t x, int8_t y) {
	for (int i = 0;i <PF_MENU_HEART_ICON_COUNT;i++) {
		view_render.drawBitmap(x + heart_icons_[i].pos_x,y + heart_icons_[i].pos_y, heart_icon_bitmap, PF_MENU_HEART_ICON_WIDTH, PF_MENU_HEART_ICON_HEIGHT, WHITE);
	}
}

void pf_config_icon::init(int8_t x, int8_t y)
{
	int8_t line_x = x + PF_MENU_CONFIG_ICON_OFFSET_X;
	int8_t line_y = y + PF_MENU_CONFIG_ICON_OFFSET_Y;
	int8_t dot_x = line_x;
	int8_t dot_y = line_y - 1;
	for (uint8_t i = 0; i < PF_MENU_CONFIG_ICON_COUNT; i++) {
		auto &icon = config_icons_[i];
		icon.line_pos_x = line_x;
		icon.line_pos_y = line_y;
		icon.dot_pos_x = dot_x;
		icon.target_dot_pos_x = dot_x;
		icon.dot_pos_y = dot_y;
		icon.rand_idx = i * 10;
		icon.dir = PF_MENU_ANIM_RIGHT;
		line_y += PF_MENU_LINE_ICON_GAP;
		dot_y += PF_MENU_LINE_ICON_GAP;
		dot_x += PF_MENU_DOT_ICON_GAP;
	}
	arrive_mask = 0x07;
	is_idle_ = true;
	anim_duration_tick_ = PF_MENU_CONFIG_ICON_IDLE_FRAME;
}

void pf_config_icon::update() {
	for (uint8_t i = 0; i < PF_MENU_CONFIG_ICON_COUNT; i++) {
		auto &icon = config_icons_[i];
		if (icon.dot_pos_x < icon.target_dot_pos_x) {
			icon.dot_pos_x++;
			if (icon.dot_pos_x >= icon.target_dot_pos_x) icon.dot_pos_x = icon.target_dot_pos_x;
		}
		else if (icon.dot_pos_x > icon.target_dot_pos_x) {
			icon.dot_pos_x--;
			if (icon.dot_pos_x <= icon.target_dot_pos_x) icon.dot_pos_x = icon.target_dot_pos_x;
		}
		if (icon.dot_pos_x == icon.target_dot_pos_x) arrive_mask |= (1 << i);
	}
	if (arrive_mask == 0x07) {
		if (!is_idle_) {
			anim_duration_tick_ = PF_MENU_CONFIG_ICON_IDLE_FRAME;
			is_idle_ = true;
		}
		else anim_duration_tick_ --;
		if (anim_duration_tick_ == 0) {
			is_idle_ = false;
			for (uint8_t i = 0; i < PF_MENU_CONFIG_ICON_COUNT; i++) dot_get_new_pos(&config_icons_[i]);
			arrive_mask = 0;
		}
	}
}

void pf_config_icon::dot_get_new_pos(pf_menu_config_icon *icon) {
	int8_t new_pos;
	do {
		new_pos = dot_pos_x_table[dot_pos_seq[icon->rand_idx]];
		icon->rand_idx++;
		if (icon->rand_idx >= PF_MENU_CONFIG_POS_SEQ_COUNT)icon->rand_idx = 0;
	} while (new_pos == (icon->dot_pos_x - icon->line_pos_x));
	icon->target_dot_pos_x = icon->line_pos_x + new_pos;
	icon->dir = (icon->target_dot_pos_x > icon->dot_pos_x) ? PF_MENU_ANIM_RIGHT : PF_MENU_ANIM_LEFT;
}

void pf_config_icon::render(int8_t x, int8_t y) {
	for (int i = 0; i < PF_MENU_CONFIG_ICON_COUNT; i++) {
		view_render.drawLine(x + config_icons_[i].line_pos_x, y + config_icons_[i].line_pos_y, x + config_icons_[i].line_pos_x + PF_MENU_LINE_ICON_WIDTH, y + config_icons_[i].line_pos_y, WHITE);
		view_render.drawRect(x + config_icons_[i].dot_pos_x, y + config_icons_[i].dot_pos_y, PF_MENU_DOT_ICON_WIDTH, PF_MENU_DOT_ICON_HEIGHT, WHITE);													
	}
}