#include <Novice.h>
#include "GameManager.h"

const char kWindowTitle[] = "GC2C_11_モトハシ_リョウイチ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// 生成
	GameManager* gameManager = new GameManager();

	// ゲーム実行
	gameManager->Run();

	// 解放
	delete gameManager;

	// ライブラリの終了
	Novice::Finalize();

	return 0;
}
