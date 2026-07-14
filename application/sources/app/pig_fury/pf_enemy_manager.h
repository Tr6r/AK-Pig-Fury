#ifndef __PF_ENEMY_MANAGER_H__
#define __PF_ENEMY_MANAGER_H__

#include "pf_enemy.h"
#include "pf_wolf_basic.h"

#define PF_GAME_MAX_ENEMY 4
#define PF_GAME_MAX_WOLF_BASIC 4

enum pf_enemy_type : uint8_t {
	PF_ENEMY_TYPE_WOLF_BASIC = 0,
	PF_ENEMY_TYPE_COUNT
};

class pf_enemy_manager {
public:
	pf_enemy_manager() = default;
	~pf_enemy_manager() = default;

	void init();
	void update();
	void render();

	pf_enemy *spawn_random_enemy();
	void remove_enemy(uint8_t index);

	// Getters
	pf_enemy *get_enemy(uint8_t index) { return enemies_[index]; }
	uint8_t get_enemy_count() const { return enemy_count_; }

private:
	pf_wolf_basic *spawn_wolf_basic();
	pf_wolf_basic wolves_[PF_GAME_MAX_WOLF_BASIC];
	pf_enemy *enemies_[PF_GAME_MAX_ENEMY];
	uint8_t enemy_count_;
};

#endif // __PF_ENEMY_MANAGER_H__