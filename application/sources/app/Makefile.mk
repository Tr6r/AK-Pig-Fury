include sources/app/screens/Makefile.mk
include sources/app/pig_fury/Makefile.mk

CFLAGS		+= -I./sources/app
CPPFLAGS	+= -I./sources/app

VPATH += sources/app

# CPP source files
SOURCES_CPP += sources/app/task_system.cpp
SOURCES_CPP += sources/app/app.cpp
SOURCES_CPP += sources/app/app_data.cpp
SOURCES_CPP += sources/app/app_non_clear_ram.cpp
SOURCES_CPP += sources/app/app_bsp.cpp
SOURCES_CPP += sources/app/app_modbus_pull.cpp

SOURCES_CPP += sources/app/task_life.cpp
SOURCES_CPP += sources/app/task_list.cpp
SOURCES_CPP += sources/app/task_display.cpp

SOURCES_CPP += sources/app/task_uart_if.cpp
SOURCES_CPP += sources/app/task_dbg.cpp

# task pf game
SOURCES_CPP += sources/app/task_pf_game.cpp
