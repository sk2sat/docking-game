#ifndef SCENE_H_
#define SCENE_H_

#include "DxLib.h"

#define MENU_MODE	0
#define GAME_MODE	1
#define CONFIG_MODE	2
#define ENDING		3

extern int SCRNX,SCRNY,SCENE_MODE;

class Scene {
public:
	virtual void update()	{};
	virtual void draw()	{};
};

#endif
