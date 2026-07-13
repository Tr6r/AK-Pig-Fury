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
#define PIG_ATK_FRAME_TICK 6
#define PIG_ATK_RANGE 2
#define PIG_ATK_DAMAGE 1
#define PIG_COLLECT_WEAPON_RANGE 10

// idle weapon
#define PIG_HOLD_WEAPON_LEFT_ROTATION 215
#define PIG_HOLD_WEAPON_LEFT_POS_X 67
#define PIG_HOLD_WEAPON_RIGHT_ROTATION 360 - PIG_HOLD_WEAPON_LEFT_ROTATION
#define PIG_HOLD_WEAPON_RIGHT_POS_X 44
#define PIG_HOLD_WEAPON_POS_Y 55

// melee weapon
#define PIG_ATK_WEAPON_MELEE_1_LEFT_ROTATION 330
#define PIG_ATK_WEAPON_MELEE_1_LEFT_POS_X 42
#define PIG_ATK_WEAPON_MELEE_1_RIGHT_ROTATION 360 - PIG_ATK_WEAPON_MELEE_1_LEFT_ROTATION
#define PIG_ATK_WEAPON_MELEE_1_RIGHT_POS_X 68
#define PIG_ATK_WEAPON_MELEE_1_POS_Y 50

#define PIG_ATK_WEAPON_MELEE_2_LEFT_ROTATION 220
#define PIG_ATK_WEAPON_MELEE_2_LEFT_POS_X 42
#define PIG_ATK_WEAPON_MELEE_2_RIGHT_ROTATION 360 - PIG_ATK_WEAPON_MELEE_2_LEFT_ROTATION
#define PIG_ATK_WEAPON_MELEE_2_RIGHT_POS_X 70
#define PIG_ATK_WEAPON_MELEE_2_POS_Y 41

// throw weapon
#define PIG_ATK_WEAPON_THROW_LEFT_ROTATION 180
#define PIG_ATK_WEAPON_THROW_LEFT_POS_X 42
#define PIG_ATK_WEAPON_THROW_RIGHT_ROTATION 360 - PIG_ATK_WEAPON_THROW_LEFT_ROTATION
#define PIG_ATK_WEAPON_THROW_RIGHT_POS_X 68
#define PIG_ATK_WEAPON_THROW_POS_Y 40

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
	PF_PIG_ATTACK_ST_JUMP_KICK,
	PF_PIG_ATTACK_WEAPON_PICKUP,
	PF_PIG_ATTACK_WEAPON_MELEE_1,
	PF_PIG_ATTACK_WEAPON_MELEE_2,
	PF_PIG_ATTACK_WEAPON_THROW,
};

class pf_pig : public pf_char
{
public:
	pf_pig() = default;
	~pf_pig() override = default;

	void update() override;
	void render() override;
	void init() override;
	void get_hand_pos(int8_t &pos_x, int8_t &pos_y) override;
	void set_weapon(pf_weapon *weapon) override;
	void take_damage(uint8_t damage) override;

	// input
	void jump();
	void squat();
	void attack(pf_char_dir dir);
	
	// getter
	pf_pig_st get_st() { return pig_st_;}
	pf_atk_st get_atk_st() { return atk_st_;}
	bool is_attack_hit_frame();

	// setter
	void set_st(pf_pig_st st) { pig_st_ = st;}
	void set_atk_st(pf_atk_st atk_st) { atk_st_ = atk_st;}

private:
	// output
	void update_st();
	void render_st();
	void update_atk();
	void render_atk();
	void render_weapon_atk();
	void render_unarmed_atk();
	void attack_no_weapon(pf_char_dir dir);
	void attack_with_weapon(pf_char_dir dir);
	void update_weapon_attach_pose();

	pf_pig_st pig_st_;
	pf_atk_st atk_st_;
};

#endif //__PF_PIG_H__
