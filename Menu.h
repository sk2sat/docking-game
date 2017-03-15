#ifndef MENU_H_
#define MENU_H_

#include "Scene.h"

class Menu : public Scene {
public:
	Menu();
	~Menu();
	
	void update();
	void draw();
private:
	int scene_trans_flg;
	int now_button;
};

#endif
