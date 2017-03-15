#include <stdio.h>
#include <math.h>
#include <DxLib.h>

//#define DEBUG

#define ISS_3DMODEL	"ISSComplete1.mv1"

#define DV	0.1
#define DT	0.01

#define SCRNX	640
#define SCRNY	480

#define MENU_MODE	0
#define GAME_MODE	1
#define CONFIG_MODE	2

#define CONS_XSIZ	128
#define DOCKING_DISTANCE	1.0

VECTOR d_port = VGet(-6.0, 0.0, 45.0);

int SCENE_MODE;

class Scene {
public:
	Scene();
	~Scene();
	void Draw();
};

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	if(DxLib_Init() < 0) return -1;
	SetDrawScreen(DX_SCREEN_BACK);
	
	while(ProcessMessage()==0){
		switch(SCENE_MODE){
		case MENU_MODE:
			break;
		case GAME_MODE:
			break;
		case CONFIG_MODE:
			break;
		default:
			return -1;
			break;
		}
	}
	
	DxLib_End();
	return 0;
}

namespace motomoto {
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	int ISS;
	
	if(DxLib_Init() < 0){
		return -1;
	}
	
	ISS = MV1LoadModel(ISS_3DMODEL);
	if(ISS == -1){
		printf("error:\n\tcan't load 3D model.");
		return -1;
	}
	MV1SetPosition(ISS, VGet(0.0, 0.0, 0.0));
	MV1SetScale(ISS, VGet(20.0, 20.0, 2.0));
	
	SetDrawScreen(DX_SCREEN_BACK);
	
	VECTOR pos, vel;
	pos.x = 0.0;
	pos.y = -150.0;
	pos.z = 300.0;
	vel = VGet(0.0, 0.0, 0.0);
	
	SetCameraPositionAndTarget_UpVecY(pos, VGet(0.0, 0.0, 0.0));
	
	while(ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0){
		clsDx();
		ClearDrawScreen();

		VECTOR tmp;
		tmp = vel;
#ifdef DEBUG
		tmp = pos;
#endif
		if(CheckHitKey(KEY_INPUT_UP))		tmp.y -= DV;
		if(CheckHitKey(KEY_INPUT_DOWN))		tmp.y += DV;
		if(CheckHitKey(KEY_INPUT_LEFT))		tmp.x -= DV;
		if(CheckHitKey(KEY_INPUT_RIGHT))	tmp.x += DV;
		if(CheckHitKey(KEY_INPUT_SPACE))	tmp.z -= DV;
		if(CheckHitKey(KEY_INPUT_RETURN))	tmp.z += DV;
#ifndef DEBUG
		vel = tmp;
		pos.x	+= vel.x * DT;
		pos.y	+= vel.y * DT;
		pos.z	+= vel.z * DT;
#else
		pos = tmp;
#endif

		if(fabsf(pos.x - d_port.x) <= DOCKING_DISTANCE){
		if(fabsf(pos.y - d_port.y) <= DOCKING_DISTANCE){
		if(fabsf(pos.z - d_port.z) <= DOCKING_DISTANCE){
			printfDx("conglatulations!");
		}}}

		SetCameraPositionAndTarget_UpVecY(pos, VGet(pos.x, pos.y, pos.z-100));
		MV1SetPosition(ISS, VGet(0.0, 0.0, 0.0));
		MV1DrawModel(ISS);
		
		DrawBox(SCRNX-CONS_XSIZ, 0, SCRNX, SCRNY, GetColor(0xff, 0xff, 0xff), TRUE);
		DrawLine(0, SCRNY/2, SCRNX, SCRNY/2, GetColor(0xff, 0xff, 0xff));
		DrawLine((SCRNX-CONS_XSIZ)/2, 0, (SCRNX-CONS_XSIZ)/2, SCRNY, GetColor(0xff,0xff,0xff));
		DrawFormatString(SCRNX-CONS_XSIZ, 0, GetColor(0,0,0), "aaa");
		
		printfDx("x=%f y=%f z=%f", pos.x, pos.y, pos.z);
		
		ScreenFlip();
	}
	
	DxLib_End();
	
	return 0;
}

};
