# Game
CFLAGS		+= -I./sources/app/pig_fury
CPPFLAGS	+= -I./sources/app/pig_fury

# Enemy
CFLAGS      += -I./sources/app/pig_fury/pf_enemy
CPPFLAGS    += -I./sources/app/pig_fury/pf_enemy

VPATH += sources/app/pig_fury

DIR = sources/app/pig_fury
# CPP source files
SOURCES_CPP +=	$(DIR)/pf_game.cpp	\
				$(DIR)/pf_char.cpp	\
				$(DIR)/pf_pig.cpp	\
