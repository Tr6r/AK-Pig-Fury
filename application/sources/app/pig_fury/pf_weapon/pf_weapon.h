#ifndef __PF_WEAPON_H__
#define __PF_WEAPON_H__

#include <stdint.h>

#include "pf_char.h"

enum pf_weapon_st : uint8_t {
	PF_WEAPON_ST_IDLE,
	PF_WEAPON_ST_ATTACH,
	PF_WEAPON_ST_PENDING_ATTACH,
	PF_WEAPON_ST_DETACH,
	PF_WEAPON_ST_FLY,
	PF_WEAPON_ST_FALL,
	PF_WEAPON_ST_THROW,
	PF_WEAPON_ST_DELETE,
};

enum pf_pig_weapon_action: uint8_t {
	PF_PIG_WEAPON_ACTION_MELEE,
	PF_PIG_WEAPON_ACTION_THROW,
};

class pf_weapon {
public:
	pf_weapon() = default;
	virtual ~pf_weapon() = default;

	virtual void update() = 0;
	virtual void render() = 0;
	virtual void init() = 0;
	virtual void attack() = 0;
	virtual pf_pig_weapon_action get_pig_action() const = 0;
	virtual void next_action() = 0;

	// getter
	pf_weapon_st get_st() const { return st_; }
	pf_char_dir get_dir() const { return dir_; }
	int8_t get_pos_x() { return pos_x_; }
	int8_t get_pos_y() { return pos_y_; }
	uint8_t get_width() { return width_; }
	uint8_t get_height() { return height_; }
	uint8_t get_damage() { return damage_; }
	bool is_pickup() { return is_pickup_; }

	// setter
	void set_st(pf_weapon_st st) { st_ = st; }
	void set_dir(pf_char_dir dir) { dir_ = dir; }
	void set_rotation(uint16_t degree) {rotation_ = degree; }
	void set_visible(bool flag) { is_visible_ = flag; }
	void set_anchor(uint8_t x, uint8_t y) { pos_x_ = x; pos_y_ = y; }
	void set_pickup(bool flag) { is_pickup_ = flag; }

protected:
	uint8_t damage_;
	pf_weapon_st st_;
	int16_t pos_x_;
	int16_t pos_y_;
	uint16_t rotation_;
	uint8_t width_;
	uint8_t height_;
	pf_char_dir dir_;
	bool is_visible_;
	bool is_pickup_;
	uint8_t anim_duration_tick_;
	const pf_pig_weapon_action *action_;
	uint8_t action_count_;
};

#endif // __PF_WEAPON_H__