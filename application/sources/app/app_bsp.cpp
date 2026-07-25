#include "button.h"

#include "app.h"
#include "app_bsp.h"

#include "task_list.h"
#include "timer.h"

button_t btn_mode;
button_t btn_up;
button_t btn_down;

void btn_mode_callback(void* b) {
	button_t* me_b = (button_t*)b;
	switch (me_b->state) {
	case BUTTON_SW_STATE_PRESSED: {
		task_post_pure_msg(AC_TASK_DISPLAY_ID, AC_DISPLAY_BUTON_MODE_PRESSED);
	}
		break;

	case BUTTON_SW_STATE_LONG_PRESSED:
		break;

	default:
		break;
	}
}

void btn_up_callback(void* b) {
	button_t* me_b = (button_t*)b;
	switch (me_b->state) {
	case BUTTON_SW_STATE_PRESSED: {
		task_post_pure_msg(AC_TASK_DISPLAY_ID, AC_DISPLAY_BUTON_UP_PRESSED);
	}
		break;

	case BUTTON_SW_STATE_LONG_PRESSED:
		break;

	default:
		break;
	}
}

void btn_down_callback(void* b) {
	button_t* me_b = (button_t*)b;
	switch (me_b->state) {
	case BUTTON_SW_STATE_PRESSED: {
		task_post_pure_msg(AC_TASK_DISPLAY_ID, AC_DISPLAY_BUTON_DOWN_PRESSED);
	}
		break;

	case BUTTON_SW_STATE_LONG_PRESSED:
		break;

	default:
		break;
	}
}
