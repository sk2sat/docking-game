#include <stdio.h>
#include <DxLib.h>

#define ISS_3DMODEL	"ISSComplete1.mv1"

#define DR	0.1

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
	
	VECTOR pos;
	pos.x = 0.0;
	pos.y = 0.0;
	pos.z = 300.0;
	
	SetCameraPositionAndTarget_UpVecY(pos, VGet(0.0, 0.0, 0.0));
	
	while(ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0){
		
		ClearDrawScreen();
		
		if(CheckHitKey(KEY_INPUT_UP)) pos.y += DR;
		if(CheckHitKey(KEY_INPUT_DOWN)) pos.y -= DR;
		if(CheckHitKey(KEY_INPUT_LEFT)) pos.x -= DR;
		if(CheckHitKey(KEY_INPUT_RIGHT)) pos.x += DR;
		if(CheckHitKey(KEY_INPUT_SPACE)) pos.z -= DR;
		if(CheckHitKey(KEY_INPUT_RETURN)) pos.z += DR;
		
		SetCameraPositionAndTarget_UpVecY(pos, VGet(pos.x, pos.y, pos.z-100));
		MV1SetPosition(ISS, VGet(0.0, 0.0, 0.0));
		MV1DrawModel(ISS);
		
		clsDx();
		printfDx("x=%f y=%f z=%f", pos.x, pos.y, pos.z);
		
		ScreenFlip();
	}
	
	DxLib_End();
	
	return 0;
}


