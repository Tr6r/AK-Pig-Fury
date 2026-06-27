#ifndef __PF_ENEMY_H__
#define __PF_ENEMY_H__

#include <stdint.h>

#include "app.h"

#include "pf_char.h"

enum pf_eneymy_st : uint8_t
{
	PF_ENEMY_ST_SPAWN,
	PF_ENEMY_ST_MOVE,
	PF_ENEMY_ST_ATTACK,
	PF_ENEMY_ST_HIT,
	PF_ENEMY_ST_DEAD,
};

class pf_eneymy : public pf_char
{
public:
	pf_eneymy() = default;
	~pf_eneymy() override = default;

	virtual void update() override = 0;
	virtual void render() override = 0;
	virtual void init() override = 0;
	virtual void attack() = 0;
	virtual void take_damage() = 0;

	// getter
	uint8_t get_hp() const { return hp_; }
	pf_eneymy_st get_st() const { return st_; }

	// setter
	void set_hp(uint8_t hp) { hp_ = hp; }
	void set_st(pf_eneymy_st st) { st_ = st; }

protected:
	uint8_t hp_;
	uint8_t move_speed_;
	pf_eneymy_st st_;
};

#endif // __PF_ENEMY_H__