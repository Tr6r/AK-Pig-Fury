#ifndef __PF_PIG_H__
#define __PF_PIG_H__

#include <stdint.h>

#include "app.h"

#include "pf_char.h"

enum pf_pig_st : uint8_t
{
	PF_PIG_ST_NONE,
	PF_PIG_ST_JUMP,
	PF_PIG_ST_SQUAT
};

enum pf_atk_st : uint8_t
{
	PF_PIG_ATTACK_ST_NONE,
	PF_PIG_ATTACK_ST_PUNCH,
	PF_PIG_ATTACK_ST_SQUAT_PUNCH,
	PF_PIG_ATTACK_ST_JUMP_KICK
};

class pf_pig : public pf_char
{
public:
	pf_pig();
	~pf_pig() override = default;

	void update() override;
	void render() override;
	void init() override;

	void jump();
	void squat();
	void attack();
	void take_damage();

	// getter
	uint8_t get_hp() { return hp_;}
	pf_pig_st get_st() { return st_;}
	pf_atk_st get_atk_st() { return atk_st_;}

	// setter
	void set_st(pf_pig_st st) { st_ = st;}
	void set_atk_st(pf_atk_st atk_st) { atk_st_ = atk_st;}

private:
	uint8_t hp_;
	pf_pig_st st_;
	pf_atk_st atk_st_;
};

#endif //__PF_PIG_H__
