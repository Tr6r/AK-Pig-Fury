CFLAGS		+= -I./sources/app/pig_fury/pf_enemy
CPPFLAGS	+= -I./sources/app/pig_fury/pf_enemy

VPATH += sources/app/pig_fury/pf_enemy
PF_ENEMY_DIR := sources/app/pig_fury/pf_enemy
# CPP source files
SOURCES_CPP +=	$(PF_ENEMY_DIR)/pf_wolf_basic.cpp \
