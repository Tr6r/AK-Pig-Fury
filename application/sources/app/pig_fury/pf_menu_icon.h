#ifndef __PF_MENU_ICON_H__
#define __PF_MENU_ICON_H__

#include "stdint.h"

class pf_menu_icon {
public:
	pf_menu_icon() = default;
	virtual ~pf_menu_icon() = default;
	virtual void init() = 0;
	virtual void update() = 0;
	virtual void render(int16_t x, int16_t y) = 0;
};

class pf_gameplay_icon : public pf_menu_icon {
public:
	void update() override;
	void render(int16_t x, int16_t y) override;
};

class pf_config_icon : public pf_menu_icon {
public:
	void update() override;
	void render(int16_t x, int16_t y) override;
};

#endif //__PF_MENU_ICON_H__
