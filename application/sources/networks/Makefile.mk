ifeq ($(IF_LINK_OPTION),-DIF_LINK_UART_EN)
include sources/networks/net/link/Makefile.mk
endif

ifeq ($(TASK_ZIGBEE_OPTION),-DTASK_ZIGBEE_EN)
include sources/networks/ArduinoZigBee/Makefile.mk
endif
