#ifndef __PF_CHAR_H__
#define __PF_CHAR_H__

#include <stdint.h>
#include "app.h"

enum pf_char_dir : uint8_t
{
	LEFT,
	RIGHT
};

enum pf_char_st : uint8_t
{
	PF_CHAR_ST_IDLE,
	PF_CHAR_ST_HIT,
	PF_CHAR_ST_DEAD
};

class pf_char
{
public:
	pf_char() = default;
	virtual ~pf_char() = default;

	virtual void update() = 0;
	virtual void render() = 0;
	virtual void init() = 0;

	// getter
	uint8_t get_pos_x() { return pos_x_; }
	uint8_t get_pos_y() { return pos_y_; }
	uint8_t get_width() { return width_; }
	uint8_t get_height() { return height_; }
	pf_char_st get_st() { return st_; }
	pf_char_dir get_dir() { return dir_; }

	// setter
	void set_pos_x(uint8_t x) { pos_x_ = x; }
	void set_pos_y(uint8_t y) { pos_y_ = y; }
	void set_width(uint8_t w) { width_ = w; }
	void set_height(uint8_t h) { height_ = h; }
	void set_st(pf_char_st st) { st_ = st; }
	void set_dir(pf_char_dir dir) { dir_ = dir; }

private:
	uint8_t pos_x_;
	uint8_t pos_y_;
	uint8_t width_;
	uint8_t height_;
	pf_char_st st_;
	pf_char_dir dir_;
};

#endif //__PF_CHAR_H__
