#ifndef __PF_PIG_H__
#define __PF_PIG_H__

#include <stdint.h>

#include "app.h"

#include "task_display.h"

#include "pf_char.h"

#define MAX_HP 3
#define PIG_WIDTH 18
#define PIG_HEIGHT 27
#define PIG_POS_X (LCD_WIDTH - PIG_WIDTH)/2
#define PIG_POS_Y (LCD_HEIGHT - PIG_HEIGHT)
#define PIG_UPDATE_STEP_PIXEL 5
#define PIG_JUMP_MAX_HEIGHT 30

enum pf_pig_st : uint8_t
{
	PF_PIG_ST_NONE,
	PF_PIG_ST_JUMP,
	PF_PIG_ST_FALL,
	PF_PIG_ST_SQUAT
};

enum pf_atk_st : uint8_t
{
	PF_PIG_ATTACK_NONE,
	PF_PIG_ATTACK_PUNCH_1,
	PF_PIG_ATTACK_PUNCH_2,
	PF_PIG_ATTACK_PUNCH_3,
	PF_PIG_ATTACK_ST_SQUAT_PUNCH,
	PF_PIG_ATTACK_ST_JUMP_KICK
};

class pf_pig : public pf_char
{
public:
	pf_pig() = default;
	~pf_pig() override = default;

	void update() override;
	void render() override;
	void init(pf_char_dir dir) override;

	// input
	void jump();
	void squat();
	void attack(pf_char_dir dir);
	void take_damage();
	
	// getter
	uint8_t get_hp() { return hp_;}
	pf_pig_st get_st() { return pig_st_;}
	pf_atk_st get_atk_st() { return atk_st_;}

	// setter
	void set_st(pf_pig_st st) { pig_st_ = st;}
	void set_atk_st(pf_atk_st atk_st) { atk_st_ = atk_st;}

private:
	// output
	void update_st();
	void render_st();
	void update_atk();
	void render_atk();

	uint8_t hp_;
	pf_pig_st pig_st_;
	pf_atk_st atk_st_;
};

#endif //__PF_PIG_H__
