#include "Game.h"

Game::Game(){
	ISS = MV1LoadModel(ISS_3DMODEL);
        if(ISS == -1){
                printf("error:\n\tcan't load 3D model.");
                throw "can't open";
        }
        MV1SetPosition(ISS, VGet(0.0, 0.0, 0.0));
        MV1SetScale(ISS, VGet(20.0, 20.0, 2.0));
	SetCameraPositionAndTarget_UpVecY(pos, VGet(0.0, 0.0, 0.0));
}

Game::~Game(){
	
}

void Game::update(){
	
}

void Game::draw(){
	
	MV1DrawModel(ISS);
}

void Game::ending(){
	
}


