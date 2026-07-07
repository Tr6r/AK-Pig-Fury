include sources/app/pig_fury/pf_enemy/Makefile.mk
include sources/app/pig_fury/pf_weapon/Makefile.mk

# Game
CFLAGS		+= -I./sources/app/pig_fury
CPPFLAGS	+= -I./sources/app/pig_fury

VPATH += sources/app/pig_fury
DIR = sources/app/pig_fury
# CPP source files
SOURCES_CPP +=	$(DIR)/pf_game.cpp	\
				$(DIR)/pf_char.cpp	\
				$(DIR)/pf_pig.cpp	\
				$(DIR)/pf_enemy_manager.cpp	\
				$(DIR)/pf_weapon_manager.cpp	\
