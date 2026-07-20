#include "pf_menu.h"

void pf_menu::init() {
	pos_x_ = PF_MENU_INIT_POS_X;
	pos_y_ = PF_MENU_INIT_POS_Y;
	cur_index_ = PF_MENU_GAMEPLAY;
	target_index_ = PF_MENU_GAMEPLAY;
	cur_menu_item_ = &menu_items_[cur_index_];
	target_menu_item_ = &menu_items_[target_index_];
	menu_arrow_[0].init(0);
	menu_arrow_[1].init(1);
	for (uint8_t i = 0; i < PF_MENU_ITEM_COUNT; i++) {
		menu_items_[i].icon->init(pos_x_, pos_y_);
	}
}

void pf_menu::render() {
	menu_arrow_[0].render();
	menu_arrow_[1].render();
	if (!is_animating()) {
		view_render.drawBitmap(pos_x_, pos_y_, cur_menu_item_->bitmap, PF_MENU_ICON_W, PF_MENU_ICON_H, WHITE);
		cur_menu_item_->icon->render(pos_x_, pos_y_);
		return;
	}
	int16_t cur_x;
	int16_t target_x;
	get_render_pos(cur_x, target_x);
	// cur item
	view_render.drawBitmap(cur_x, pos_y_, cur_menu_item_->bitmap, PF_MENU_ICON_W, PF_MENU_ICON_H, WHITE);
	cur_menu_item_->icon->render(cur_x, pos_y_);
	
	// target item
	view_render.drawBitmap(target_x, pos_y_, target_menu_item_->bitmap, PF_MENU_ICON_W, PF_MENU_ICON_H, WHITE);
	target_menu_item_->icon->render(target_x, pos_y_);
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
	menu_arrow_[0].update();
	menu_arrow_[1].update();
	if (!is_animating()) {
		cur_menu_item_->icon->update();
		return;
	}
	cur_menu_item_->icon->update();
	target_menu_item_->icon->update();
	anim_offset_ += PF_MENU_SCROLL_SPEED;
	if (anim_offset_ >= PF_MENU_SCROLL_DISTANCE) {
		anim_offset_ = 0;
		animating_ = false;
		menu_arrow_[0].set_enable_(true);
		menu_arrow_[1].set_enable_(true);
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
	menu_arrow_[0].set_enable_(false);
	menu_arrow_[1].set_enable_(false);
	anim_offset_ = 0;
}

void pf_menu::move_pre_item() {
	if (is_animating())
		return;
	dir_ = PF_MENU_ANIM_RIGHT;
	target_index_ = (cur_index_ + PF_MENU_ITEM_COUNT - 1) % PF_MENU_ITEM_COUNT;
	target_menu_item_ = &menu_items_[target_index_];
	animating_ = true;
	menu_arrow_[0].set_enable_(false);
	menu_arrow_[1].set_enable_(false);
	anim_offset_ = 0;
}

void pf_menu_arrow::init(uint8_t index) {
	dir_ = (index == 0 ? PF_MENU_ANIM_LEFT : PF_MENU_ANIM_RIGHT);
	pos_x_ = dir_ == PF_MENU_ANIM_LEFT ? PF_MENU_ARROW_LEFT_POS_X : PF_MENU_ARROW_RIGHT_POS_X;
	pos_y_ = PF_MENU_ARROW_POS_Y;
	visible_ = true;
	enable_ = true;
	blink_tick_ = PF_MENU_ARROW_BLINK_FRAME;
}

void pf_menu_arrow::update() {
	if (--blink_tick_ == 0) {
		visible_ = !visible_;
		blink_tick_ = PF_MENU_ARROW_BLINK_FRAME;
	}
}

void pf_menu_arrow::render() {
	if (!visible_ || !enable_)
		return;
	const uint8_t *bitmap = dir_ == PF_MENU_ANIM_LEFT ? menu_arrow_left_bitmap : menu_arrow_right_bitmap;
	view_render.drawBitmap(pos_x_, pos_y_, bitmap, PF_MENU_ARROW_WIDTH, PF_MENU_ARROW_HEIGHT, WHITE);
}