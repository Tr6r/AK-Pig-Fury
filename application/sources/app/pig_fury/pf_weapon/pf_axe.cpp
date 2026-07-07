#include "app.h"
#include "task_display.h"

#include "pf_axe.h"
#include "pf_wolf_basic.h"

void pf_axe::init() {
	st_ = PF_WEAPON_ST_IDLE;
	width_ = PF_AXE_WIDTH;
	height_ = PF_AXE_HEIGHT;
	pos_x_ = 0;
	pos_y_ = 0;
	rotation_ = 0;
	is_visible_ = false;
}

void pf_axe::update() {
	switch (st_)
	{
		case PF_WEAPON_ST_DETACH:
		{
			st_ = PF_WEAPON_ST_FLY;
			rotation_ = 0;
		}
		case PF_WEAPON_ST_FLY: {
			update_fly();
			break;
		}
		case PF_WEAPON_ST_FALL: {
			update_fall();
			break;
		}
		default:
			break;
	}
}

void pf_axe::update_fall() {
	update_detach_rotation();
	pos_y_ += PF_AXE_UPDATE_STEP_PIXEL;
	if (pos_y_ >= LCD_HEIGHT) {
		pos_y_ = LCD_HEIGHT;
		st_ = PF_WEAPON_ST_DELETE;
	}
}

void pf_axe::update_fly() {
	update_detach_rotation();
	pos_y_ -= PF_AXE_UPDATE_STEP_PIXEL;
	if (pos_y_ <= PF_AXE_FLY_MAX_HEIGHT) {
		pos_y_ = PF_AXE_FLY_MAX_HEIGHT;
		st_ = PF_WEAPON_ST_FALL;
	}
}

void pf_axe::render() {
	if (!is_visible_) return; 
	switch (st_)
	{
		case PF_WEAPON_ST_DETACH:
		case PF_WEAPON_ST_FLY:
		case PF_WEAPON_ST_FALL:
		case PF_WEAPON_ST_ATTACH: {
			const uint8_t *axe =  (dir_ == PF_CHAR_DIR_LEFT) ? axe_left : axe_right ;
			view_render.drawBitmapRotate(pos_x_, pos_y_,axe, PF_AXE_WIDTH, PF_AXE_HEIGHT, (float)rotation_, WHITE);
			break;
		}
		default:
			break;
	}
}

void pf_axe::attack() {

}