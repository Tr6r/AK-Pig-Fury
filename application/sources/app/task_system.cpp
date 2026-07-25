#include "fsm.h"
#include "port.h"
#include "message.h"

#include "sys_ctrl.h"
#include "sys_dbg.h"

#include "app.h"
#include "app_dbg.h"

#include "task_list.h"
#include "task_system.h"

void task_system(ak_msg_t* msg) {
	switch (msg->sig) {
	default:
		break;
	}
}
