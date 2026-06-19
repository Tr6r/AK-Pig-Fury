#include "fsm.h"
#include "port.h"
#include "message.h"

#include "sys_ctrl.h"
#include "sys_dbg.h"

#include "app.h"
#include "app_dbg.h"

#include "task_list.h"
#include "task_pf_game.h"

void task_pf_game(ak_msg_t* msg) {
	switch (msg->sig) {
	case AC_PF_GAME_INIT:
		pf_game_init();
	default:
		break;
	}
}
