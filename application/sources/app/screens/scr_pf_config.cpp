#include "pf_game.h"
#include "scr_pf_config.h"
#include "pf_sound.h"

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
	pf_config_render();
}

void scr_pf_config_handle(ak_msg_t *msg) {
	switch (msg->sig) {
		case SCREEN_ENTRY: {
			timer_set(AC_TASK_DISPLAY_ID,AC_DISPLAY_CONFIG_UPDATE,AC_DISPLAY_CONFIG_UPDATE_INTERVAL_MS,TIMER_PERIODIC);
			break;
		}
		case AC_DISPLAY_CONFIG_UPDATE: {
			scr_mng_invalidate();
			pf_config_update();
			break;
		}
		case AC_DISPLAY_BUTON_UP_PRESSED: {
			game_sound.play(PF_SOUND_CONFIG_SCROLL);
			pf_config_move_next_item(PF_MENU_ANIM_RIGHT);
			break;
		}
		case AC_DISPLAY_BUTON_DOWN_PRESSED: {
			game_sound.play(PF_SOUND_CONFIG_SCROLL);
			pf_config_move_next_item(PF_MENU_ANIM_LEFT);
			break;
		}
		case AC_DISPLAY_BUTON_MODE_PRESSED: {
			game_sound.play(PF_SOUND_CONFIG_SELECT);
			pf_change_config();
			if (pf_get_cur_config_item() == PF_CONFIG_EXIT) {
				timer_remove_attr(AC_TASK_DISPLAY_ID,AC_DISPLAY_CONFIG_UPDATE);
				SCREEN_TRAN(scr_pf_menu_handle, &scr_pf_menu);
			}
			break;
		}
		default:
			break;
	}
}
