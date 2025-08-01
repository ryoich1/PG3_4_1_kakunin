#include "ClearScene.h"
#include <Novice.h>
#include <Windows.h>

void ClearScene::Initialize() {}

void ClearScene::Update(char* keys, char* preKeys) {

	// スペースで次のシーンへ
	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) {
		sceneNo =TITLE;
	}
}

void ClearScene::Draw() {

	SetConsoleOutputCP(65001);

	Novice::ScreenPrintf(580, 345, "Clear!!!");
	Novice::ScreenPrintf(500, 375, "Push Space : Title Scene");
}
