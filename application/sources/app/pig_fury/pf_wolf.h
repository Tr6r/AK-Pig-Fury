#ifndef __PF_WOLF_H__
#define __PF_WOLF_H__

#include <stdint.h>

#include "app.h"

#include "pf_char.h"

enum pf_wolf_st : uint8_t
{
	PF_WOLF_ST_NONE,
	PF_WOLF_ST_MOVE,
	PF_WOLF_ST_ATK,
};

class pf_wolf : public pf_char
{
public:
	pf_wolf();
	~pf_wolf() override = default;

	void update() override;
	void render() override;
	void init() override;

	void attack();
	void take_damage();

	// getter
	uint8_t get_hp() { return hp_;}
	pf_wolf_st get_st() { return st_;}

	// setter
	void set_hp(uint8_t hp) { hp_ = hp;}
	void set_st(pf_wolf_st st) { st_ = st;}

private:
	uint8_t hp_;
	pf_wolf_st st_;
};

#endif //__PF_WOLF_H__
