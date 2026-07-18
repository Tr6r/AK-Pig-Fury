#include "pf_menu.h"

void pf_menu::init() {
	pos_x_ = PF_MENU_INIT_POS_X;
	pos_y_ = PF_MENU_INIT_POS_Y;
	cur_index_ = PF_MENU_GAMEPLAY;
	target_index_ = PF_MENU_GAMEPLAY;
	cur_menu_item_ = &menu_items_[cur_index_];
	target_menu_item_ = &menu_items_[target_index_];
}

void pf_menu::render() {
	if (!is_animating()) {
		view_render.drawBitmap(pos_x_, pos_y_, cur_menu_item_->bitmap, PF_MENU_ICON_W, PF_MENU_ICON_H, WHITE);
		return;
	}
	int16_t cur_x;
	int16_t target_x;
	get_render_pos(cur_x, target_x);
	view_render.drawBitmap(cur_x, pos_y_, cur_menu_item_->bitmap, PF_MENU_ICON_W, PF_MENU_ICON_H, WHITE);
	view_render.drawBitmap(target_x, pos_y_, target_menu_item_->bitmap, PF_MENU_ICON_W, PF_MENU_ICON_H, WHITE);
}

void pf_menu::get_render_pos(int16_t &cur_x, int16_t &target_x) const {
	switch (dir_) {
		case PF_MENU_ANIM_LEFT: {
			cur_x = pos_x_ - anim_offset_;
			target_x = LCD_WIDTH - anim_offset_;
			break;	
		}
		case PF_MENU_ANIM_RIGHT: {
			cur_x = pos_x_ + anim_offset_;
			target_x = -PF_MENU_ICON_W + anim_offset_;
			break;
		}
		default: {
			cur_x = pos_x_;
			target_x = pos_x_;
			break;
		}
	}
}

void pf_menu::update() {
	if (!is_animating())
		return;
	anim_offset_ += PF_MENU_SCROLL_SPEED;
	if (anim_offset_ >= PF_MENU_SCROLL_DISTANCE) {
		anim_offset_ = 0;
		animating_ = false;
		cur_index_ = target_index_;
		cur_menu_item_ = &menu_items_[cur_index_];
	}
}

void pf_menu::move_next_item() {
	if (is_animating())
		return;
	dir_ = PF_MENU_ANIM_LEFT;
	target_index_ = (cur_index_ + 1) % PF_MENU_ITEM_COUNT;
	target_menu_item_ = &menu_items_[target_index_];
	animating_ = true;
	anim_offset_ = 0;
}

void pf_menu::move_pre_item() {
	if (is_animating())
		return;
	dir_ = PF_MENU_ANIM_RIGHT;
	target_index_ = (cur_index_ + PF_MENU_ITEM_COUNT - 1) % PF_MENU_ITEM_COUNT;
	target_menu_item_ = &menu_items_[target_index_];
	animating_ = true;
	anim_offset_ = 0;
}
