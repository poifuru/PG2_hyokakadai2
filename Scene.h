#pragma once
#include "constant.h"
#include "Player.h"
#include "Enemy.h"
#include "Function.h"
#include "constant.h"

//シーンの基底クラス
class Scene {
public:
	//仮想デストラクタ
	virtual ~Scene() = default;

	/// <summary>
	/// シーンごとの初期化
	/// </summary>
	virtual void Init() {}

	/// <summary>
	/// アップデート関数
	/// </summary>
	/// <param name="keys">今押されているキー</param>
	/// <param name="preKeys">1フレーム前に押されていたキー</param>
	virtual void Update(const char* keys [[maybe_unused]], const char* preKeys [[maybe_unused]] );

	/// <summary>
	/// 描画関数
	/// </summary>
	virtual void Draw() = 0;

	/// <summary>
	/// シーンの終了処理を行う関数
	/// </summary>
	virtual void Exit() {}
};

//シーンマネージャークラス
class SceneManager {
private:
	Scene* scenes_[MaxScene];
	int currentScene_;

public:
	//アクセッサ--
	int GetScene() { return currentScene_; };
	//-----------

	//コンストラクタ,デストラクタ
	SceneManager();
	~SceneManager();

	//メンバ関数

	/// <summary>
	/// シーンを登録する関数
	/// </summary>
	void AddScene(int index, Scene* scene);

	/// <summary>
	/// シーンを切り替える関数
	/// </summary>
	void ChangeScene(int index);

	/// <summary>
	/// アップデート関数
	/// </summary>
	void Update(const char* keys, const char* preKeys);

	/// <summary>
	/// 描画関数
	/// </summary>
	void Draw();
};

class Title : public Scene {
private:
	SceneManager* sceneManager_;

public:
	Title(SceneManager* manager) : sceneManager_(manager) {}

	//メンバ関数
	void Init() override;
	void Update(const char* keys, const char* preKeys) override;
	void Draw() override;
	void Exit() override;
};

class Game : public Scene {
private:
	//メンバ変数
	Player* player_;
	Enemy* enemy_;
	SceneManager* sceneManager_;

public:
	//アクセッサ--
	//Vector2<float> GetPlayerPos() { return player_->GetPos(); };

	//-----------
	Game(SceneManager* manager) : sceneManager_(manager) {}

	//メンバ関数
	void Init() override;
	void Update(const char* keys, const char* preKeys) override;
	void Draw() override;
	void Exit() override;
};

class GameOver : public Scene {
private:
	//メンバ変数
	SceneManager* sceneManager_;

public:
	GameOver(SceneManager* manager) : sceneManager_(manager) {}

	//メンバ関数
	void Init() override;
	void Update(const char* keys, const char* preKeys) override;
	void Draw() override;
	void Exit() override;
};

class Clear : public Scene {
private:
	//メンバ変数
	SceneManager* sceneManager_;

public:
	Clear(SceneManager* manager) : sceneManager_(manager) {}

	//メンバ関数
	void Init() override;
	void Update(const char* keys, const char* preKeys) override;
	void Draw() override;
	void Exit() override;
};