	#include <Novice.h>
	#include "Scene.h"

	const char kWindowTitle[] = "LC1B_23_マスヤゴウ_PG2評価課題";

	// Windowsアプリでのエントリーポイント(main関数)
	int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

		// ライブラリの初期化
		Novice::Initialize(kWindowTitle, 1280, 720);

		//インスタンス生成
		SceneManager manager;

		//シーンの登録
		manager.AddScene(0, new Title(&manager));
		manager.AddScene(1, new Game(&manager));
		manager.AddScene(2, new GameOver(&manager));
		manager.AddScene(3, new Clear(&manager));

		// キー入力結果を受け取る箱
		char keys[256] = {0};
		char preKeys[256] = {0};

		// ウィンドウの×ボタンが押されるまでループ
		while (Novice::ProcessMessage() == 0) {
			// フレームの開始
			Novice::BeginFrame();

			// キー入力を受け取る
			memcpy(preKeys, keys, 256);
			Novice::GetHitKeyStateAll(keys);

			//メインループ
			manager.Update(keys, preKeys);
			manager.Draw();

	#ifdef _DEBUG

			Novice::ScreenPrintf(100, 20, "currentScene:%d", manager.GetScene());

	#endif

			// フレームの終了
			Novice::EndFrame();

			// ESCキーが押されたらループを抜ける
			if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
				break;
			}
		}

		// ライブラリの終了
		Novice::Finalize();
		return 0;
	}
