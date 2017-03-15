#include "Menu.h"

#define TITLE_YSIZ	(SCRNY/6)
#define BUTTON_NUM	2
#define BUTTON_XSIZ	(SCRNX/3)
#define BUTTON_YSIZ	(SCRNY/7)

Menu::Menu(){
	now_button = 0;
}

Menu::~Menu(){
	
}

void Menu::update(){
	if(CheckHitKey(KEY_INPUT_UP))	now_button--;
	if(CheckHitKey(KEY_INPUT_DOWN))	now_button++;
	if(now_button<0)		now_button++;
	if(now_button>=BUTTON_NUM)	now_button--;
}

void Menu::draw(){
	DrawBox(0,0,SCRNX,SCRNY,GetColor(0x00,0x00,0xcc), TRUE);
	
	int xc = SCRNX/2;
	int x0 = xc - (BUTTON_XSIZ/2);
	int x1 = xc + (BUTTON_XSIZ/2);
	for(int i=0;i<BUTTON_NUM;i++){
		int yc = ((SCRNY-TITLE_YSIZ)/(BUTTON_NUM*2))*(i+1) + TITLE_YSIZ;
		int y0 = yc - (BUTTON_YSIZ/2);
		int y1 = yc + (BUTTON_YSIZ/2);
		DrawBox(x0,y0,x1,y1,GetColor(0x00,0xcc,0x00),TRUE);
		if(i==now_button){
			DrawBox(x0,y0,x1,y1,GetColor(0xff,0x00,0x00),FALSE);
		}
		char *bname;
		if(i==0) bname = (char*)"start";
		if(i==1) bname = (char*)"config";
		DrawFormatString(x0,y0,GetColor(0xff,0x00,0x00),bname);
	}
}


