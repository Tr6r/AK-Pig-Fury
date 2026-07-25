/**
 ******************************************************************************
 * @author: GaoKong
 * @date:   13/08/2016
 ******************************************************************************
**/

#ifndef __APP_H__
#define __APP_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "ak.h"

#include "app_eeprom.h"
#include "app_data.h"

/*****************************************************************************/
/*  LIFE task define
 */
/*****************************************************************************/
/* define timer */
#define AC_LIFE_TASK_TIMER_LED_LIFE_INTERVAL		(1000)

/* define signal */
enum {
	AC_LIFE_SYSTEM_CHECK = AK_USER_DEFINE_SIG,
};

/*****************************************************************************/
/* IF task define
 */
/*****************************************************************************/
/* define timer */
/* define signal */
enum {
	AC_IF_PURE_MSG_IN = AK_USER_DEFINE_SIG,
	AC_IF_PURE_MSG_OUT,
	AC_IF_COMMON_MSG_IN,
	AC_IF_COMMON_MSG_OUT,
	AC_IF_DYNAMIC_MSG_IN,
	AC_IF_DYNAMIC_MSG_OUT,
};

/*****************************************************************************/
/*  LIFE task define
 */
/*****************************************************************************/
/* define timer */
#define AC_DISPLAY_INITIAL_INTERVAL									(100)
#define AC_DISPLAY_STARTUP_INTERVAL									(1500)
#define AC_DISPLAY_LOGO_INTERVAL									(10000)
#define AC_DISPLAY_SHOW_IDLE_BALL_MOVING_UPDATE_INTERAL				(150)
#define AC_DISPLAY_SHOW_MERRY_CHRISTMAS_SNOW_MOVING_UPDATE_INTERAL	(150)
#define AC_DISPLAY_SHOW_MERRY_CHRISTMAS_SLEEP_INTERVAL				(15000)
#define AC_DISPLAY_SHOW_MODBUS_PULL_INTERVAL						(1500)
#define AC_DISPLAY_SHOW_MODBUS_PULL_SLEEP_INTERVAL					(30000)
#define AC_DISPLAY_MINIMUM_SCREEN_RENDER_INTERVAL_MS				(50) /* 50ms => Max 20 FPS */
#define AC_DISPLAY_IDLE_INTERVAL									(15000)
#define AC_DISPLAY_WELCOME_TEXT_ANIM_TICK_INTERVAL					(120)

/* define signal */
enum {
	AC_DISPLAY_RENDER_SCREEN = AK_SYS_DEFINE_SIG,
	AC_DISPLAY_INITIAL = AK_USER_DEFINE_SIG,
	AC_DISPLAY_BUTON_MODE_PRESSED,
	AC_DISPLAY_BUTON_UP_PRESSED,
	AC_DISPLAY_BUTON_DOWN_PRESSED,
	AC_DISPLAY_SHOW_LOGO,
	AC_DISPLAY_SHOW_IDLE,
	AC_DISPLAY_SHOW_IDLE_BALL_MOVING_UPDATE,
	AC_DISPLAY_WELCOME_TEXT_ANIM_TICK,
	AC_DISPLAY_SHOW_FW_UPDATE,
	AC_DISPLAY_SHOW_FW_UPDATE_ERR,
	AC_DISPLAY_SHOW_MERRY_CHRISTMAS_SNOW_MOVING_UPDATE,
	AC_DISPLAY_SHOW_MERRY_CHRISTMAS_SLEEP,
	AC_DISPLAY_SHOW_MODBUS_PULL_UPDATE,
	AC_DISPLAY_SHOW_MODBUS_PULL_SLEEP,
	// PF game
	AC_DISPLAY_WELCOME_UPDATE,
	AC_DISPLAY_MENU,
	AC_DISPLAY_MENU_UPDATE,
	AC_DISPLAY_CONFIG_UPDATE,
	AC_DISPLAY_GAMEPLAY_UPDATE,
	AC_DISPLAY_GAMEOVER_UPDATE,
	AC_DISPLAY_GAMEOVER_ALLOW_CHANGE_SCR,
};

/*****************************************************************************/
/* Pig fury game task define
 */
/*****************************************************************************/
/* define timer */
#define AC_DISPLAY_WELCOME_INTERVAL_MS											(1500)
#define AC_DISPLAY_MENU_UPDATE_INTERVAL_MS										(60)
#define AC_DISPLAY_CONFIG_UPDATE_INTERVAL_MS									(60)
#define AC_DISPLAY_GAMEPLAY_UPDATE_INTERVAL_MS									(60)
#define AC_DISPLAY_GAMEOVER_UPDATE_INTERVAL_MS									(60)
#define AC_DISPLAY_GAMEOVER_CHANGE_SCR_INTERVAL_MS								(1500)

/* define signal */
enum {
	AC_PF_GAME_INIT = AK_USER_DEFINE_SIG,
	AC_PF_GAMEPLAY_INIT,
	AC_PF_GAME_START,
	AC_PF_GAME_STOP,
	AC_PF_MENU_NEXT_ITEM,
	AC_PF_PIG_ATK,
	AC_PF_PIG_JUMP,
	AC_PF_PIG_SQUAT
};

/*****************************************************************************/
/*  app function declare
 */
/*****************************************************************************/
#define APP_MAGIC_NUMBER	0xAABBCCDD
#define APP_VER				{0, 0, 0, 3}

typedef struct {
	uint32_t magic_number;
	uint8_t version[4];
} app_info_t;

extern const app_info_t app_info;

extern void* app_get_boot_share_data();
extern int  main_app();

#ifdef __cplusplus
}
#endif

#endif //__APP_H__
