#include "Scene.h"
#include <Novice.h>

//基底クラス
void Scene::Update(const char* keys [[maybe_unused]], const char* preKeys [[maybe_unused]] ){
}

#pragma region シーンマネージャークラスの関数定義
SceneManager::SceneManager() {
	for (int i = 0; i < MaxScene; i++) {
		scenes_[i] = { nullptr };
		currentScene_ = 0;
	}
}

SceneManager::~SceneManager() {
	//登録されているシーンを全て解放する
	for (int i = 0; i < MaxScene; i++) {
		delete scenes_[i];
		scenes_[i] = nullptr;
	}
}

void SceneManager::AddScene(int index, Scene* scene) {
	if (index >= 0 && index < MaxScene) {
		scenes_[index] = scene;
	}
}

void SceneManager::ChangeScene(int index) {
	if (index >= 0 && index < MaxScene && scenes_[index]) {
		if (currentScene_ != -1) {
			scenes_[currentScene_]->Exit();
		}
		currentScene_ = index;
		scenes_[currentScene_]->Init();
	}
}

void SceneManager::Update(const char* keys, const char* preKeys) {
	if (currentScene_ != -1) {
		scenes_[currentScene_]->Update(keys, preKeys);
	}

}

void SceneManager::Draw() {
	if (currentScene_ != -1) {
		scenes_[currentScene_]->Draw();
	}
}
#pragma endregion

#pragma region タイトルクラス
void Title::Init() {
}

void Title::Update(const char* keys, const char* preKeys) {
	if (keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0) {
		sceneManager_->ChangeScene(1);
	}
}

void Title::Draw() {
	Novice::ScreenPrintf(540, 300, "Shooting Game!!");
	Novice::ScreenPrintf(540, 500, "start to SPACE!!");
}

void Title::Exit() {
}
#pragma endregion

#pragma region ゲームクラス
void Game::Init() {
	player_ = new Player();
	enemy_ = new Enemy();
}

void Game::Update(const char* keys, const char* preKeys[[maybe_unused]] ) {
	player_->Update(keys);
	enemy_->Update(keys);
}

void Game::Draw() {
	player_->Draw();
	player_->DrawBullet();
	if (enemy_->GetIsAlive() == true) {
		enemy_->Draw();
	}
	for (int i = 0; i < kBulletNum; i++) {
		if (player_->bullet_[i]->isShot_) {
			if (CollisionEllipse(
				player_->bullet_[i]->GetPos(), player_->bullet_[i]->GetRadius(), enemy_->GetPos(), enemy_->GetRadius()) == true &&
				enemy_->GetIsAlive()) {
				player_->bullet_[i]->isShot_ = false;
				enemy_->SetHP(player_->bullet_[i]->damage_);

				if (enemy_->GetHP() == 1) {
					enemy_->SetKilledCount(1);
				}
				break;
			}
		}
	}

	if ((CollisionEllipse(
		player_->GetPos(), player_->GetRadius(), enemy_->GetPos(), enemy_->GetRadius()) == true)) {
		sceneManager_->ChangeScene(2);
	}

	if (enemy_->GetKilledCount() == 3) {
		sceneManager_->ChangeScene(3);
	}

	Novice::ScreenPrintf(10, 0, "killedCount:%d", enemy_->GetKilledCount());
}

void Game::Exit() {
	delete player_;
	delete enemy_;
}
#pragma endregion

#pragma region ゲームオーバークラス
void GameOver::Init(){
}

void GameOver::Update(const char* keys, const char* preKeys){
	if (keys[DIK_1] && !preKeys[DIK_1]) {
		sceneManager_->ChangeScene(1);
	}
	else if (keys[DIK_2] && !preKeys[DIK_2]) {
		sceneManager_->ChangeScene(0);
	}
}

void GameOver::Draw(){
	Novice::ScreenPrintf(540, 200, "GameOver...");
	Novice::ScreenPrintf(300, 500, "restart to 1 key");
	Novice::ScreenPrintf(880, 500, "title to 2 key");
}
	
void GameOver::Exit(){
}
#pragma endregion

#pragma region クリアクラス
void Clear::Init() {
}

void Clear::Update(const char* keys, const char* preKeys){
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		sceneManager_->ChangeScene(0);
	}
}

void Clear::Draw(){
	Novice::ScreenPrintf(540, 200, "GameClear!!!!!");
	Novice::ScreenPrintf(540, 500, "title to SPACE key");
}

void Clear::Exit(){
}
#pragma endregion