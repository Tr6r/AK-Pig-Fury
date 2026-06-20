#include "scr_pf_gameplay.h"
#include "pf_game.h"

static void view_scr_pf_gameplay();

view_dynamic_t dyn_view_pf_gameplay = {
	{
		.item_type = ITEM_TYPE_DYNAMIC,
	},
	view_scr_pf_gameplay
};

view_screen_t scr_pf_gameplay = {
	&dyn_view_pf_gameplay,
	ITEM_NULL,
	ITEM_NULL,
	.focus_item = 0,
};

void view_scr_pf_gameplay() {
	pf_game_render();
}

void scr_pf_gameplay_handle(ak_msg_t *msg) {
	switch (msg->sig) {
		case SCREEN_ENTRY: {
			APP_DBG_SIG("PF_GAMEPLAY\n");
			task_post_pure_msg(AC_TASK_PF_GAME_ID, AC_PF_GAME_INIT);
			timer_set(AC_TASK_DISPLAY_ID,AC_DISPLAY_GAMEPLAY_UPDATE,AC_DISPLAY_GAMEPLAY_UPDATE_INTERVAL_MS,TIMER_PERIODIC);
			break;
		}
		case AC_DISPLAY_GAMEPLAY_UPDATE: {
			scr_mng_invalidate();
			pf_game_update();
			break;
		}
		case AC_DISPLAY_BUTON_UP_PRESSED: {
			pf_char_dir dir = RIGHT;
			task_post_common_msg(AC_TASK_PF_GAME_ID, AC_PF_PIG_ATK, (uint8_t*)&dir, sizeof(dir));
			break;
		}
		case AC_DISPLAY_BUTON_DOWN_PRESSED: {
			pf_char_dir dir = LEFT;
			task_post_common_msg(AC_TASK_PF_GAME_ID, AC_PF_PIG_ATK, (uint8_t*)&dir, sizeof(dir));
			break;
		}
		default:
			break;
	}
}