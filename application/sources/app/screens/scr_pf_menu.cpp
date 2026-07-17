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
	view_render.clear();
	view_render.setTextSize(1);
	view_render.setTextColor(WHITE);
	view_render.setCursor(10,10);
	view_render.println("Menu");
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
		break;
	}
	default:
		break;
	}
}
