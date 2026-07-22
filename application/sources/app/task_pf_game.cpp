#include "fsm.h"
#include "message.h"
#include "port.h"

#include "sys_ctrl.h"
#include "sys_dbg.h"

#include "app.h"
#include "app_dbg.h"

#include "task_list.h"
#include "task_pf_game.h"

void task_pf_game(ak_msg_t *msg) {
	switch (msg->sig) {
		case AC_PF_GAME_INIT: {
			pf_game_init();
			break;
		}
		case AC_PF_MENU_NEXT_ITEM: {
			pf_menu_anim_dir dir = *(pf_menu_anim_dir*)get_data_common_msg(msg);
			pf_menu_move_next_item(dir);
			break;
		}
		case AC_PF_GAMEPLAY_INIT: {
			pf_gameplay_init();
			break;
		}
		case AC_PF_PIG_ATK: {
			pf_char_dir dir = *(pf_char_dir*)get_data_common_msg(msg);
			if (pf_pig_try_pickup_weapon(dir))
				break;
			pf_pig_atk(dir);
			break;
		}
		case AC_PF_PIG_JUMP: {
			pf_pig_jump();
			break;
		}
		default:
			break;
	}
}
