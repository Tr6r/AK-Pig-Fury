#include "pf_wolf_basic.h"
#include "pf_weapon.h"

void pf_wolf_basic::init() {
	hp_ = PF_WOLF_BASIC_MAX_HP;
	st_ = PF_ENEMY_ST_IDLE;
	width_ = PF_WOLF_BASIC_WIDTH;
	height_ = PF_WOLF_BASIC_HEIGHT;
	char_st_ = PF_CHAR_ST_IDLE;
	anim_duration_tick_ = PF_WOLF_BASIC_MOVE_FRAME_TICK;
}

void pf_wolf_basic::spawn(pf_char_dir dir) {
	pos_x_ = (dir == PF_CHAR_DIR_LEFT) ? PF_WOLF_BASIC_SPAWN_LEFT_X : PF_WOLF_BASIC_SPAWN_RIGHT_X;
	pos_y_ = PF_WOLF_BASIC_POS_Y; 
	dir_ = dir;
	update_weapon();
}

void pf_wolf_basic::update() {
	anim_duration_tick_--;
	switch (st_) {
		case PF_ENEMY_ST_IDLE:
			st_ = PF_ENEMY_ST_MOVE;
		case PF_ENEMY_ST_MOVE: {
			update_move();
			break;
		}
		case PF_ENEMY_ST_HIT: {
			update_hit();
			break;
		}
		case PF_ENEMY_ST_KNOCKBACK: {
			update_knockback();
			break;
		}
		case PF_ENEMY_ST_DEAD: {
			update_dead();
			break;
		}
		case PF_ENEMY_ST_ATTACK: {
			update_attack();
			break;
		}
		default:
			break;
	}
	update_weapon();

}

void pf_wolf_basic::update_attack() {
	update_atk_state();
	update_weapon();
}

void pf_wolf_basic::update_dead() {
	if (anim_duration_tick_ <= 0) {
		st_ = PF_ENEMY_ST_DELETE;
		return;
	}
	if (anim_duration_tick_ >= PF_WOLF_BASIC_DEAD_FRAME_TICK /2)
	{
		pos_y_ -= 3;
	}
}

void pf_wolf_basic::update_knockback() {
	if (anim_duration_tick_ <= 0) {
		pos_y_ += 15;
		anim_duration_tick_ =  PF_WOLF_BASIC_DEAD_FRAME_TICK;
		st_ = PF_ENEMY_ST_DEAD;
		return;
	}
	if (anim_duration_tick_ >= PF_WOLF_BASIC_KNOCKBACK_FRAME_TICK/2)
	{
		pos_y_ -= 2;
	}
	else 
	{
		pos_y_ += 2;
	}
	pos_x_ += (dir_ == PF_CHAR_DIR_LEFT) ? -2 : 2;
}

void pf_wolf_basic::update_hit() {
	switch (anim_duration_tick_)
	{
		case 0: {
			st_ = PF_ENEMY_ST_MOVE;
			anim_duration_tick_ = PF_WOLF_BASIC_MOVE_FRAME_TICK;
			weapon_->set_visible(true);
			break;
		}
		case 3:
		case 2: {
			pos_y_ = pos_y_ + 2;
			break;
		}
		case 5:
		case 4: {
			pos_y_ = pos_y_ - 2;
			break;
		}
	}
	pos_x_ += (dir_ == PF_CHAR_DIR_LEFT) ? -1 : 1;
}

void pf_wolf_basic::update_move() {
	update_move_state();
	switch (dir_) {
		case PF_CHAR_DIR_LEFT: {
			if (pos_x_ + PF_WOLF_BASIC_UPDATE_STEP_PIXEL >= PF_WOLF_BASIC_LIMITED_MOVE_LEFT) {
				st_ = PF_ENEMY_ST_ATTACK;
				atk_st_ = PF_WOLF_BASIC_ATK_1;
				anim_duration_tick_ = PF_WOLF_BASIC_ATK_COOLDOWN_FRAME_TICK;
				return;
			}
			pos_x_ += PF_WOLF_BASIC_UPDATE_STEP_PIXEL;
			weapon_->set_rotation(PF_WOLF_BASIC_MOVE_LEFT_WEAPON_ROTATION);
			break;
		}
		case PF_CHAR_DIR_RIGHT: {
			if (pos_x_ - PF_WOLF_BASIC_UPDATE_STEP_PIXEL <= PF_WOLF_BASIC_LIMITED_MOVE_RIGHT) {
				st_ = PF_ENEMY_ST_ATTACK;
				atk_st_ = PF_WOLF_BASIC_ATK_1;
				anim_duration_tick_ = PF_WOLF_BASIC_ATK_COOLDOWN_FRAME_TICK;
				return;
			}
			pos_x_ -= PF_WOLF_BASIC_UPDATE_STEP_PIXEL;
			weapon_->set_rotation(PF_WOLF_BASIC_MOVE_RIGHT_WEAPON_ROTATION);
			break;
		}
		default:
			break;
	}
}

void pf_wolf_basic::render() {
	switch (st_)
	{
		case PF_ENEMY_ST_MOVE: {
			render_move();
			break;
		}
		case PF_ENEMY_ST_HIT: {
			render_hit();
			break;
		}
		case PF_ENEMY_ST_ATTACK: {
			render_attack();
			break;
		}
		case PF_ENEMY_ST_KNOCKBACK: {
			render_knockback();
			break;
		}
		case PF_ENEMY_ST_DEAD: {
			render_dead();
			break;
		}
		default:
			break;
	}
}

void pf_wolf_basic::render_attack() {
	const uint8_t *wolf;
	switch (atk_st_)
	{
	case PF_WOLF_BASIC_ATK_1: {
		wolf = (dir_ == PF_CHAR_DIR_LEFT) ? wolf_atk_left_1 : wolf_atk_right_1 ;
		view_render.drawBitmap(pos_x_, pos_y_,wolf, PIG_WIDTH, PIG_HEIGHT, WHITE);
		break;
	}
	case PF_WOLF_BASIC_ATK_2:
	case PF_WOLF_BASIC_ATK_4: {
		wolf = (dir_ == PF_CHAR_DIR_LEFT) ? wolf_atk_left_2 : wolf_atk_right_2 ;
		view_render.drawBitmap(pos_x_, pos_y_,wolf, PIG_WIDTH, PIG_HEIGHT, WHITE);
		break;
	}
	case PF_WOLF_BASIC_ATK_3: {
		wolf = (dir_ == PF_CHAR_DIR_LEFT) ? wolf_atk_left_3 : wolf_atk_right_3 ;
		view_render.drawBitmap(pos_x_, pos_y_,wolf, PIG_WIDTH, PIG_HEIGHT, WHITE);
		break;
	}
	default:
		break;
	}
}

void pf_wolf_basic::render_dead() {
	view_render.drawBitmap(pos_x_, pos_y_,wolf_dead, PIG_WIDTH, PIG_HEIGHT, WHITE);
}

void pf_wolf_basic::render_knockback() {
	if (dir_ == PF_CHAR_DIR_LEFT) view_render.drawBitmap(pos_x_, pos_y_,wolf_knockback_left, PIG_WIDTH, PIG_HEIGHT, WHITE);
			else view_render.drawBitmap(pos_x_, pos_y_,wolf_knockback_right, PIG_WIDTH, PIG_HEIGHT, WHITE);
}

void pf_wolf_basic::render_hit() {
	if (dir_ == PF_CHAR_DIR_LEFT) view_render.drawBitmap(pos_x_, pos_y_,wolf_hit_left, PIG_WIDTH, PIG_HEIGHT, WHITE);
			else view_render.drawBitmap(pos_x_, pos_y_,wolf_hit_right, PIG_WIDTH, PIG_HEIGHT, WHITE);
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

void pf_wolf_basic::take_damage(uint8_t damage) {
	if (st_ == PF_ENEMY_ST_HIT || st_ == PF_ENEMY_ST_KNOCKBACK)
		return;
	hp_ -= damage;
	if (hp_ <= 0) {
		anim_duration_tick_ = PF_WOLF_BASIC_KNOCKBACK_FRAME_TICK;
		weapon_->set_anchor((dir_ == PF_CHAR_DIR_LEFT ? weapon_->get_pos_x() + 10 : weapon_->get_pos_x() - 10 ), get_pos_y());
		weapon_->set_st(PF_WEAPON_ST_DETACH);
		set_weapon(nullptr);
		st_ = PF_ENEMY_ST_KNOCKBACK;
		return;
	}
	anim_duration_tick_ = PF_WOLF_BASIC_HIT_FRAME_TICK;
	st_ = PF_ENEMY_ST_HIT;
	weapon_->set_visible(false);
}

void pf_wolf_basic::get_hand_pos(int8_t &pos_x, int8_t &pos_y) {
	switch (st_)
	{
		case PF_ENEMY_ST_IDLE:
		case PF_ENEMY_ST_MOVE: {
			pos_x = pos_x_ + ((dir_ == PF_CHAR_DIR_LEFT) ? PF_WOLF_BASIC_MOVE_LEFT_HAND_OFFSET_X : PF_WOLF_BASIC_MOVE_RIGHT_HAND_OFFSET_X );
			pos_y = pos_y_ + PF_WOLF_BASIC_MOVE_HAND_OFFSET_Y;
			break;
		}
		case PF_ENEMY_ST_ATTACK: {
			switch (atk_st_)
			{
			case PF_WOLF_BASIC_ATK_1: {
				pos_x = pos_x_ + ((dir_ == PF_CHAR_DIR_LEFT) ? PF_WOLF_BASIC_ATK_1_LEFT_HAND_OFFSET_X : PF_WOLF_BASIC_ATK_1_RIGHT_HAND_OFFSET_X );
				pos_y = pos_y_ + PF_WOLF_BASIC_ATK_1_HAND_OFFSET_Y;
				weapon_->set_rotation((dir_ == PF_CHAR_DIR_LEFT ? PF_WOLF_BASIC_ATK_1_LEFT_WEAPON_ROTATION : PF_WOLF_BASIC_ATK_1_RIGHT_WEAPON_ROTATION));
				break;
			}
			case PF_WOLF_BASIC_ATK_2: 
			case PF_WOLF_BASIC_ATK_4: {
				pos_x = pos_x_ + ((dir_ == PF_CHAR_DIR_LEFT) ? PF_WOLF_BASIC_ATK_2_LEFT_HAND_OFFSET_X : PF_WOLF_BASIC_ATK_2_RIGHT_HAND_OFFSET_X );
				pos_y = pos_y_ + PF_WOLF_BASIC_ATK_2_HAND_OFFSET_Y;
				weapon_->set_rotation((dir_ == PF_CHAR_DIR_LEFT ? PF_WOLF_BASIC_ATK_2_LEFT_WEAPON_ROTATION : PF_WOLF_BASIC_ATK_2_RIGHT_WEAPON_ROTATION));
				break;
			}
			case PF_WOLF_BASIC_ATK_3: {
				pos_x = pos_x_ + ((dir_ == PF_CHAR_DIR_LEFT) ? PF_WOLF_BASIC_ATK_3_LEFT_HAND_OFFSET_X : PF_WOLF_BASIC_ATK_3_RIGHT_HAND_OFFSET_X );
				pos_y = pos_y_ + PF_WOLF_BASIC_ATK_3_HAND_OFFSET_Y;
				weapon_->set_rotation((dir_ == PF_CHAR_DIR_LEFT ? PF_WOLF_BASIC_ATK_3_LEFT_WEAPON_ROTATION : PF_WOLF_BASIC_ATK_3_RIGHT_WEAPON_ROTATION));
				break;
			}
			default:
				break;
			}
			break;
		}
		default:
			break;
	}
}

void pf_wolf_basic::update_weapon()
{
	if (weapon_->get_st() != PF_WEAPON_ST_ATTACH) return;
	int8_t hand_pos_x, hand_pos_y;
	get_hand_pos(hand_pos_x, hand_pos_y);
	weapon_->set_anchor(hand_pos_x, hand_pos_y);
}

bool pf_wolf_basic::is_attack_hit_frame()
{
	if (st_ != PF_ENEMY_ST_ATTACK || atk_st_ != PF_WOLF_BASIC_ATK_3)
		return false;
	return PF_WOLF_BASIC_ATK_COOLDOWN_FRAME_TICK - anim_duration_tick_ <= 2;
}
