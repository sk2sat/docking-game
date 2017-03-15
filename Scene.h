#ifndef SCENE_H_
#define SCENE_H_

#include "DxLib.h"

extern int SCRNX,SCRNY;

class Scene {
public:
	virtual void update()	{};
	virtual void draw()	{};
};

#endif
