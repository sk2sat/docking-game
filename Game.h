#ifndef GAME_H_
#define GAME_H_

#include "Scene.h"
#include "Console.h"

#define ISS_3DMODEL     "ISSComplete1.mv1"

#define DOCKING_DISTANCE	1.0
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
	int clear_flg;
	int ISS;
	VECTOR cpos, pos, cvel;
	Console *cons;
};

#endif
