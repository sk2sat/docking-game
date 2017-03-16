#ifndef GAME_H_
#define GAME_H_

#include "Scene.h"

#define ISS_3DMODEL     "ISSComplete1.mv1"

#define CONS_XSIZ	128
#define DT	0.01
#define DV	0.1

class Game : public Scene {
public:
	Game();
	~Game();
	void update();
	void draw();
	void ending();
	
private:
	int ISS;
	VECTOR cpos, pos, cvel;
};

#endif
