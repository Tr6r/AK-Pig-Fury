#include "scr_pf_gameplay.h"

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
	view_render.clear();
	view_render.setTextSize(1);
	view_render.setTextColor(WHITE);
	view_render.print("pf_gameplay");
}

void scr_pf_gameplay_handle(ak_msg_t *msg) {
	switch (msg->sig) {
	case SCREEN_ENTRY: {
		APP_DBG_SIG("PF_GAMEPLAY\n");
	} break;
	default:
		break;
	}
}