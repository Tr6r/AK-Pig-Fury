#include "pf_wolf_basic.h"

void pf_wolf_basic::init(pf_char_dir dir) {
	if (dir == PF_CHAR_DIR_LEFT) pos_x_ = PF_WOLF_BASIC_SPAWN_LEFT_X;
	else pos_x_ = PF_WOLF_BASIC_SPAWN_RIGHT_X;
	pos_y_ = PF_WOLF_BASIC_POS_Y; 
	hp_ = PF_WOLF_BASIC_MAX_HP;
	st_ = PF_ENEMY_ST_SPAWN;
	width_ = PF_WOLF_BASIC_WIDTH;
	height_ = PF_WOLF_BASIC_HEIGHT;
	char_st_ = PF_CHAR_ST_IDLE;
	move_dur_tick_ = PF_WOLF_BASIC_MOVE_FRAME_TICK;
	dir_ = dir;
}

void pf_wolf_basic::update() {
	if (hp_ == 0) st_ = PF_ENEMY_ST_DEAD;
	switch (st_) {
		case PF_ENEMY_ST_SPAWN:
		case PF_ENEMY_ST_MOVE: {
			update_move();
			break;
		}
		default:
			break;
	}
}

void pf_wolf_basic::update_move() {
	update_move_state();
	switch (dir_) {
		case PF_CHAR_DIR_LEFT: {
			if (pos_x_ + PF_WOLF_BASIC_UPDATE_STEP_PIXEL >= PF_WOLF_BASIC_LIMITED_MOVE_LEFT) {
				st_ = PF_ENEMY_ST_ATTACK;
				return;
			}
			pos_x_ += PF_WOLF_BASIC_UPDATE_STEP_PIXEL;
			break;
		}
		case PF_CHAR_DIR_RIGHT: {
			if (pos_x_ - PF_WOLF_BASIC_UPDATE_STEP_PIXEL <= PF_WOLF_BASIC_LIMITED_MOVE_RIGHT) {
				st_ = PF_ENEMY_ST_ATTACK;
				return;
			}
			pos_x_ -= PF_WOLF_BASIC_UPDATE_STEP_PIXEL;
			break;
		}
		default:
			break;
	}
}

void pf_wolf_basic::render() {
	render_move();
}

void pf_wolf_basic::render_move() {
	switch (move_st_) {
		case PF_WOLF_BASIC_MOVE_1 :{
			if (dir_ == PF_CHAR_DIR_LEFT) view_render.drawBitmap(pos_x_, pos_y_,wolf_run_1_left, PIG_WIDTH, PIG_HEIGHT, WHITE);
			else view_render.drawBitmap(pos_x_, pos_y_,wolf_run_1_right, PIG_WIDTH, PIG_HEIGHT, WHITE);
			break;
		}
		case PF_WOLF_BASIC_MOVE_2 :{
			if (dir_ == PF_CHAR_DIR_LEFT) view_render.drawBitmap(pos_x_, pos_y_,wolf_run_2_left, PIG_WIDTH, PIG_HEIGHT, WHITE);
			else view_render.drawBitmap(pos_x_, pos_y_,wolf_run_2_right, PIG_WIDTH, PIG_HEIGHT, WHITE);
			break;
		}
		case PF_WOLF_BASIC_MOVE_3 :{
			if (dir_ == PF_CHAR_DIR_LEFT) view_render.drawBitmap(pos_x_, pos_y_,wolf_run_3_left, PIG_WIDTH, PIG_HEIGHT, WHITE);
			else view_render.drawBitmap(pos_x_, pos_y_,wolf_run_3_right, PIG_WIDTH, PIG_HEIGHT, WHITE);
			break;
		}
		case PF_WOLF_BASIC_MOVE_4 :{
			if (dir_ == PF_CHAR_DIR_LEFT) view_render.drawBitmap(pos_x_, pos_y_,wolf_run_4_left, PIG_WIDTH, PIG_HEIGHT, WHITE);
			else view_render.drawBitmap(pos_x_, pos_y_,wolf_run_4_right, PIG_WIDTH, PIG_HEIGHT, WHITE);
			break;
		}
		default:
			break;
	}
}

void pf_wolf_basic::attack() {

}

void pf_wolf_basic::take_damage() {
	hp_ --;
}
