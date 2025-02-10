#pragma once
#include "Circle.h"
#include "struct.h"
#include "Bullet.h"
#include "constant.h"

class Player : public Circle {
private:
	//メンバ変数
	int shotCoolTime_;

public:
	Bullet* bullet_[kBulletNum];

	//コンストラクタ,デストラクタ
	Player();
	~Player() override;

	//メンバ関数
	//アクセッサー--
	Vector2<float> GetPos() { return pos_; };
	Vector2<int> GetRadius() { return radius_; };
	void SetPos(float x, float y);
	//------------

	/// <summary>
	/// アップデート
	/// </summary>
	/// <param name="keys">現在押されているキー</param>
	/// <param name="preKeys">1フレーム前に押されていたキー</param>
	void Update(const char* keys) override;

	void DrawBullet();
};

