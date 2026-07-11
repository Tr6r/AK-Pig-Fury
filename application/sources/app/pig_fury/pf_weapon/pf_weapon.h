#ifndef __PF_WEAPON_H__
#define __PF_WEAPON_H__

#include <stdint.h>

#include "pf_char.h"

enum pf_weapon_st : uint8_t {
	PF_WEAPON_ST_IDLE,
	PF_WEAPON_ST_ATTACH,
	PF_WEAPON_ST_DETACH,
	PF_WEAPON_ST_FLY,
	PF_WEAPON_ST_FALL,
	PF_WEAPON_ST_DELETE,
};

class pf_weapon {
public:
	pf_weapon() = default;
	virtual ~pf_weapon() = default;

	virtual void update() = 0;
	virtual void render() = 0;
	virtual void init() = 0;
	virtual void attack() = 0;

	// getter
	pf_weapon_st get_st() const { return st_; }
	pf_char_dir get_dir() const { return dir_; }
	int8_t get_pos_x() { return pos_x_; }
	int8_t get_pos_y() { return pos_y_; }

	// setter
	void set_st(pf_weapon_st st) { st_ = st; }
	void set_dir(pf_char_dir dir) { dir_ = dir; }
	void set_rotation(uint16_t degree) {rotation_ = degree; }
	void set_visible(bool flag) { is_visible_ = flag; }
	void set_anchor(uint8_t x, uint8_t y) { pos_x_ = x; pos_y_ = y; }

protected:
	pf_weapon_st st_;
	int8_t pos_x_;
	int8_t pos_y_;
	uint16_t rotation_;
	uint8_t width_;
	uint8_t height_;
	pf_char_dir dir_;
	bool is_visible_;
	uint8_t anim_duration_tick_;
};

#endif // __PF_WEAPON_H__