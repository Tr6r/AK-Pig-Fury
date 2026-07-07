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
}

void pf_axe::render() {
	if (!is_visible_) return; 
	switch (st_)
	{
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