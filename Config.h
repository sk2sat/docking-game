#ifndef CONFIG_H_
#define CONFIG_H_

#include "Scene.h"

class Config : public Scene {
public:
	Config();
	~Config();

	void update();
	void draw();
};

#endif
