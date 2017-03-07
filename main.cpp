#include <stdio.h>
#include <DxLib.h>

#define ISS_3DMODEL	"ISSComplete1.mv1"

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
	MV1SetScale(ISS, VGet(1.0, 2.0, 2.0));
	
	SetDrawScreen(DX_SCREEN_BACK);
	
	VECTOR pos;
	pos.x = 0.0;
	pos.y = 0.0;
	pos.z = 0.0;
	
	SetCameraPositionAndTarget_UpVecY(pos, VGet(0.0, 0.0, 0.0));
	
	while(ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0){
		
		ClearDrawScreen();
		clsDx();
		
		if(CheckHitKey(KEY_INPUT_UP)) pos.y += 5.0;
		if(CheckHitKey(KEY_INPUT_DOWN)) pos.y -= 5.0;
		if(CheckHitKey(KEY_INPUT_LEFT)) pos.x -= 5.0;
		if(CheckHitKey(KEY_INPUT_RIGHT)) pos.x += 5.0;
		if(CheckHitKey(KEY_INPUT_SPACE)) pos.z += 5.0;
		
		MV1SetPosition(ISS, VGet(0.0, 0.0, 0.0));
		
		SetCameraPositionAndAngle(pos, 0.0, 0.0, 0.0);
		printfDx("x=%f y=%f z=%f", pos.x, pos.y, pos.z);
		
		MV1DrawModel(ISS);
		ScreenFlip();
		
	}
	
	DxLib_End();
	
	return 0;
}


