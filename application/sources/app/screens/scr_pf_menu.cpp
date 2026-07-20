#include "pf_game.h"
#include "scr_pf_menu.h"

static void view_scr_pf_menu();

view_dynamic_t dyn_view_pf_menu = {
	{
		.item_type = ITEM_TYPE_DYNAMIC,
	},
	view_scr_pf_menu
};

view_screen_t scr_pf_menu = {
	&dyn_view_pf_menu,
	ITEM_NULL,
	ITEM_NULL,
	.focus_item = 0,
};

void view_scr_pf_menu() {
	pf_menu_render();
}

void scr_pf_menu_handle(ak_msg_t *msg) {
	switch (msg->sig) {
		case SCREEN_ENTRY: {
			task_post_pure_msg(AC_TASK_PF_GAME_ID, AC_PF_GAME_INIT);
			timer_set(AC_TASK_DISPLAY_ID,AC_DISPLAY_MENU_UPDATE,AC_DISPLAY_GAMEPLAY_UPDATE_INTERVAL_MS,TIMER_PERIODIC);
			break;
		}
		case AC_DISPLAY_MENU_UPDATE: {
			scr_mng_invalidate();
			pf_menu_update();
			break;
		}
		case AC_DISPLAY_BUTON_UP_PRESSED: {
			pf_menu_anim_dir dir = PF_MENU_ANIM_RIGHT;
			task_post_common_msg(AC_TASK_PF_GAME_ID, AC_PF_MENU_NEXT_ITEM, (uint8_t*)&dir, sizeof(dir));
			break;
		}
		case AC_DISPLAY_BUTON_DOWN_PRESSED: {
			pf_menu_anim_dir dir = PF_MENU_ANIM_LEFT;
			task_post_common_msg(AC_TASK_PF_GAME_ID, AC_PF_MENU_NEXT_ITEM, (uint8_t*)&dir, sizeof(dir));
			break;
		}
		case AC_DISPLAY_BUTON_MODE_PRESSED: {
			pf_menu_item_st st = pf_get_menu_st();
			switch (st)
			{
				case PF_MENU_GAMEPLAY:
					SCREEN_TRAN(scr_pf_gameplay_handle, &scr_pf_gameplay);
					break;
				case PF_MENU_CONFIG:
					SCREEN_TRAN(scr_pf_config_handle, &scr_pf_config);
					break;
				default:
					break;
			}
			
			break;
		}
		default:
			break;
	}
}
