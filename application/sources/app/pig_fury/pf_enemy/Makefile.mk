CFLAGS		+= -I./sources/app/pig_fury/pf_enemy
CPPFLAGS	+= -I./sources/app/pig_fury/pf_enemy

VPATH += sources/app/pig_fury/pf_enemy

DIR = sources/app/pig_fury/pf_enemy
# CPP source files
SOURCES_CPP +=	$(DIR)/pf_wolf_basic.cpp	\
