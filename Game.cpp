#include <math.h>
#include "Game.h"

VECTOR d_port = VGet(-6.0, 0.0, 45.0);

Game::Game(){
	clear_flg = FALSE;
	ISS = MV1LoadModel(ISS_3DMODEL);
        if(ISS == -1){
                printf("error:\n\tcan't load 3D model.");
                throw "can't open";
        }
        MV1SetPosition(ISS, VGet(0.0, 0.0, 0.0));
        MV1SetScale(ISS, VGet(20.0, 20.0, 2.0));
	cpos = VGet(0.0,-150.0,300.0);
	cvel = VGet(0.5,-0.2,0.3);
	SetCameraPositionAndTarget_UpVecY(cpos, VGet(0.0, 0.0, 0.0));
	cons = new Console(SCRNX-CONS_XSIZ, 0, SCRNX, SCRNY);
}

Game::~Game(){
	delete cons;
}

void Game::update(){
	VECTOR tmp;

	tmp = cvel;

	if(clear_flg) return;

	if(CheckHitKey(KEY_INPUT_UP))		tmp.y -= DV;
	if(CheckHitKey(KEY_INPUT_DOWN))		tmp.y += DV;
	if(CheckHitKey(KEY_INPUT_LEFT))		tmp.x -= DV;
	if(CheckHitKey(KEY_INPUT_RIGHT))	tmp.x += DV;
	if(CheckHitKey(KEY_INPUT_SPACE))	tmp.z -= DV;
	if(CheckHitKey(KEY_INPUT_RETURN))	tmp.z += DV;

	cvel = tmp;
	cpos.x	+= cvel.x * DT;
	cpos.y	+= cvel.y * DT;
	cpos.z	+= cvel.z * DT;

	if(fabsf(cpos.x - d_port.x) <= DOCKING_DISTANCE){
	if(fabsf(cpos.y - d_port.y) <= DOCKING_DISTANCE){
	if(fabsf(cpos.z - d_port.z) <= DOCKING_DISTANCE){
		cons->puts(GetColor(0xff,0x00,0x00),"Conglatulation!");
		clear_flg = TRUE;
		SCENE_MODE = ENDING;
	}}}

	SetCameraPositionAndTarget_UpVecY(cpos, VGet(cpos.x, cpos.y, cpos.z-100));
}

void Game::draw(){
	clsDx();
	DrawBox(0,0,SCRNX,SCRNY,GetColor(0x00,0x00,0x00),TRUE);
	MV1DrawModel(ISS);
	DrawBox(SCRNX-CONS_XSIZ, 0, SCRNX, SCRNY, GetColor(0xff,0xff,0xff), TRUE);
	DrawLine(0, SCRNY/2, SCRNX, SCRNY/2, GetColor(0xff,0xff,0xff));
	DrawLine((SCRNX-CONS_XSIZ)/2, 0, (SCRNX-CONS_XSIZ)/2, SCRNY, GetColor(0xff,0xff,0xff));

	cons->draw();
	printfDx("x=%f y=%f z=%f", cpos.x, cpos.y, cpos.z);
}

void Game::ending(){
	DrawString(SCRNX/2, SCRNY/2, "GAME CLEAR!", GetColor(0xff,0x00,0x00));
	Sleep(1000);
}


