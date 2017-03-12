#include <stdio.h>
#include <DxLib.h>

#define DEBUG

#define ISS_3DMODEL	"ISSComplete1.mv1"

#define DV	0.1
#define DT	0.01

#define SCRNX	640
#define SCRNY	480

#define CONS_XSIZ	128

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
		pos.x	+= vel.x * DT;
		pos.y	+= vel.y * DT;
		pos.z	+= vel.z * DT;
#else
		pos = tmp;
#endif

		SetCameraPositionAndTarget_UpVecY(pos, VGet(pos.x, pos.y, pos.z-100));
		MV1SetPosition(ISS, VGet(0.0, 0.0, 0.0));
		MV1DrawModel(ISS);
		
		DrawBox(SCRNX-CONS_XSIZ, 0, SCRNX, SCRNY, GetColor(0xff, 0xff, 0xff), TRUE);
		DrawLine(0, SCRNY/2, SCRNX, SCRNY/2, GetColor(0xff, 0xff, 0xff));
		DrawLine((SCRNX-CONS_XSIZ)/2, 0, (SCRNX-CONS_XSIZ)/2, SCRNY, GetColor(0xff,0xff,0xff));
		DrawFormatString(SCRNX-CONS_XSIZ, 0, GetColor(0,0,0), "aaa");
		
		clsDx();
		printfDx("x=%f y=%f z=%f", pos.x, pos.y, pos.z);
		
		ScreenFlip();
	}
	
	DxLib_End();
	
	return 0;
}


