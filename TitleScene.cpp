#include "TitleScene.h"
#include <Novice.h>
#include <Windows.h>

void TitleScene::Initialize() {}

void TitleScene::Update(char* keys, char* preKeys) {

	// スペースキーで次のシーンへ
	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) {
		sceneNo = STAGE;
	}
}

void TitleScene::Draw() {

	SetConsoleOutputCP(65001);

	Novice::ScreenPrintf(580, 345, "Title");
	Novice::ScreenPrintf(500, 375, "Push Space : Stage Scene");
}
