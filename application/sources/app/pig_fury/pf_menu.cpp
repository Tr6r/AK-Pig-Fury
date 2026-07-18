#include "pf_menu.h"

void pf_menu::init() {
	pos_x_ = PF_MENU_INIT_POS_X;
	pos_y_ = PF_MENU_INIT_POS_Y;
	cur_menu_item_ = PF_MENU_GAMEPLAY;
}

void pf_menu::render() {
	switch (cur_menu_item_)
	{
	case PF_MENU_GAMEPLAY: {
		view_render.drawBitmap(pos_x_, pos_y_, menu_gameplay_bitmap,PF_MENU_ICON_W, PF_MENU_ICON_H, WHITE);
		break;
	}
	case PF_MENU_CONFIG: {
		view_render.drawBitmap(pos_x_, pos_y_, menu_config_bitmap,PF_MENU_ICON_W, PF_MENU_ICON_H, WHITE);
		break;
	}
	default:
		break;
	}
}