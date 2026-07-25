CFLAGS		+= -I./sources/app/screens
CPPFLAGS	+= -I./sources/app/screens

VPATH += sources/app/screens

# CPP source files
SOURCES_CPP += sources/app/screens/scr_startup.cpp
SOURCES_CPP += sources/app/screens/scr_pf_gameplay.cpp
SOURCES_CPP += sources/app/screens/scr_pf_menu.cpp
SOURCES_CPP += sources/app/screens/scr_pf_config.cpp
SOURCES_CPP += sources/app/screens/scr_pf_gameover.cpp
SOURCES_CPP += sources/app/screens/scr_pf_welcome.cpp
