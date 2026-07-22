#include "eeprom.h"

#include "task_display.h"
#include "app_eeprom.h"

#include "pf_config.h"

void pf_config::init() {
	load_config();
	cur_item_ = PF_CONFIG_GAME_MODE;
	is_visible_ = true;
	anim_duration_ticks = PF_CONFIG_ITEM_FRAME;
}

void pf_config::move_down() {
	cur_item_ = (pf_config_item)((cur_item_ + 1) % PF_CONFIG_ITEM_COUNT);
}

void pf_config::move_up() {
	cur_item_ = (pf_config_item)((cur_item_ + PF_CONFIG_ITEM_COUNT - 1) % PF_CONFIG_ITEM_COUNT);
}

void pf_config::change_config()
{
	switch (cur_item_)
	{
		case PF_CONFIG_GAME_MODE: {
			data_.game_mode = (data_.game_mode == PF_GAME_MODE_NORMAL) ? PF_GAME_MODE_HARD : PF_GAME_MODE_NORMAL;
			anim_duration_ticks = PF_CONFIG_ITEM_FRAME;
			is_visible_ = true;
			break;
		}
		case PF_CONFIG_GAME_SOUND: {
			data_.sound = !data_.sound;
			anim_duration_ticks = PF_CONFIG_ITEM_FRAME;
			is_visible_ = true;
			break;
		}
		case PF_CONFIG_EXIT: {
			save_config();
			break;
		}
		default:
			break;
	}
}

void pf_config::update() {
	if (anim_duration_ticks > 0)
		anim_duration_ticks--;
	if (anim_duration_ticks == 0) {
		is_visible_ = !is_visible_;
		anim_duration_ticks = PF_CONFIG_ITEM_FRAME;
	}
}

void pf_config::render() {
	const uint8_t *bitmap;
	view_render.drawLine(33,0,33, LCD_HEIGHT, WHITE);
	uint8_t pos_y = PF_CONFIG_ITEM_BORDER_POS_Y;
	for (int i = 0;i<PF_CONFIG_ITEM_COUNT;i++) {
		bitmap = (i == cur_item_) ? white_bitmap[i] : black_bitmap[i];
		view_render.drawBitmap(PF_CONFIG_ITEM_BORDER_POS_X + PF_CONFIG_ITEM_OFFSET_X, pos_y + PF_CONFIG_ITEM_OFFSET_Y, bitmap, PF_CONFIG_ITEM_WIDTH, PF_CONFIG_ITEM_HEIGHT, WHITE);
		view_render.drawRect(PF_CONFIG_ITEM_BORDER_POS_X, pos_y, PF_CONFIG_ITEM_BORDER_WIDTH, PF_CONFIG_ITEM_BORDER_HEIGHT, WHITE);
		pos_y += PF_CONFIG_ITEM_BORDER_HEIGHT + PF_CONFIG_ITEM_BORDER_GAP;
	}
	switch (cur_item_)
	{
		case PF_CONFIG_GAME_MODE: {
			uint8_t text_pos_x = 40 + (LCD_WIDTH - 40 - PF_CONFIG_ITEM_GAMEMODE_WIDTH) / 2;
			view_render.drawBitmap(text_pos_x, 20, config_gamemode_bitmap, PF_CONFIG_ITEM_GAMEMODE_WIDTH, PF_CONFIG_ITEM_GAMEMODE_HEIGHT, WHITE);
			uint8_t mode_pos_x = 40 + (LCD_WIDTH - 40 - (data_.game_mode == PF_GAME_MODE_NORMAL ? PF_CONFIG_ITEM_GAMEMODE_NORMAL_WIDTH : PF_CONFIG_ITEM_GAMEMODE_HARD_WIDTH)) / 2;
			if (!is_visible_) break;
			if (data_.game_mode == PF_GAME_MODE_NORMAL)
				view_render.drawBitmap(mode_pos_x, 35, config_gamemode_normal_bitmap, PF_CONFIG_ITEM_GAMEMODE_NORMAL_WIDTH, PF_CONFIG_ITEM_GAMEMODE_NORMAL_HEIGHT, WHITE);
			else 
				view_render.drawBitmap(mode_pos_x, 35, config_gamemode_hard_bitmap, PF_CONFIG_ITEM_GAMEMODE_HARD_WIDTH, PF_CONFIG_ITEM_GAMEMODE_HARD_HEIGHT, WHITE);
			break;
		}
		case PF_CONFIG_GAME_SOUND: {
			uint8_t text_pos_x = 40 + (LCD_WIDTH - 40 - PF_CONFIG_ITEM_GAMESOUND_WIDTH) / 2;
			view_render.drawBitmap(text_pos_x, 20, config_gamesound_bitmap, PF_CONFIG_ITEM_GAMESOUND_WIDTH, PF_CONFIG_ITEM_GAMESOUND_HEIGHT, WHITE);
			uint8_t mode_pos_x = 40 + (LCD_WIDTH - 40 - (data_.sound? PF_CONFIG_ITEM_GAMESOUND_ON_WIDTH : PF_CONFIG_ITEM_GAMESOUND_OFF_WIDTH)) / 2;
			if (!is_visible_) break;
			if (data_.sound)
				view_render.drawBitmap(mode_pos_x, 35, config_gamesound_on_bitmap, PF_CONFIG_ITEM_GAMESOUND_ON_WIDTH, PF_CONFIG_ITEM_GAMESOUND_ON_HEIGHT, WHITE);
			else 
				view_render.drawBitmap(mode_pos_x, 35, config_gamesound_off_bitmap, PF_CONFIG_ITEM_GAMESOUND_OFF_WIDTH, PF_CONFIG_ITEM_GAMESOUND_OFF_HEIGHT, WHITE);
			break;
		}
		case PF_CONFIG_EXIT: {
			uint8_t text_pos_x = 40 + (LCD_WIDTH - 40 - PF_CONFIG_ITEM_EXIT_WIDTH) / 2;
			view_render.drawBitmap(text_pos_x, 30, config_exit_bitmap, PF_CONFIG_ITEM_EXIT_WIDTH, PF_CONFIG_ITEM_EXIT_HEIGHT, WHITE);
			break;
		}
		default:
			break;
	}
}

void pf_config::save_config()
{
	eeprom_erase(EEPROM_START_ADDR, sizeof(data_));
	eeprom_write(
		EEPROM_START_ADDR,
		(uint8_t *)&data_,
		sizeof(data_));
}

void pf_config::load_config()
{
	eeprom_read(
		EEPROM_START_ADDR,
		(uint8_t *)&data_,
		sizeof(data_));
}