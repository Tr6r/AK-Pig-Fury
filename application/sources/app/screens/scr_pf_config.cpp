#include "scr_pf_config.h"

static void view_scr_pf_config();

view_dynamic_t dyn_view_pf_config = {
	{
		.item_type = ITEM_TYPE_DYNAMIC,
	},
	view_scr_pf_config
};

view_screen_t scr_pf_config = {
	&dyn_view_pf_config,
	ITEM_NULL,
	ITEM_NULL,
	.focus_item = 0,
};

void view_scr_pf_config() {
	// pf_menu_render();
    view_render.clear();
    view_render.setCursor(0, 0);
    view_render.setTextSize(1);
    view_render.setTextColor(WHITE);
    view_render.println("config");
}

void scr_pf_config_handle(ak_msg_t *msg) {
	switch (msg->sig) {
		case SCREEN_ENTRY: {
			timer_set(AC_TASK_DISPLAY_ID,AC_DISPLAY_MENU_UPDATE,AC_DISPLAY_GAMEPLAY_UPDATE_INTERVAL_MS,TIMER_PERIODIC);
			break;
		}
		case AC_DISPLAY_MENU_UPDATE: {
			scr_mng_invalidate();
			// pf_menu_update();
			break;
		}
		case AC_DISPLAY_BUTON_UP_PRESSED: {
			break;
		}
		case AC_DISPLAY_BUTON_DOWN_PRESSED: {
			break;
		}
		case AC_DISPLAY_BUTON_MODE_PRESSED: {
			break;
		}
		default:
			break;
	}
}
