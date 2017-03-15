#ifndef GAME_H_
#define GAME_H_

#include "Scene.h"

#define ISS_3DMODEL     "ISSComplete1.mv1"

class Game : public Scene {
public:
	Game();
	~Game();
	void update();
	void draw();
	void ending();
	
private:
	int ISS;
	VECTOR campos, pos;
};

#endif
