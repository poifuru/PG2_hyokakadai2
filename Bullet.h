#pragma once
#include "Circle.h"
#include "constant.h"

class Bullet : public Circle{
public:
	//メンバ変数
	int damage_;
	bool isShot_;

	//コンストラクタ,デストラクタ
	Bullet();
	~Bullet() override;

	//メンバ関数
	//アクセッサー--
	Vector2<float> GetPos() { return pos_; };
	Vector2<int> GetRadius() { return radius_; }
	void SetPos(float x, float y);
	//------------

	/// <summary>
	/// アップデート関数
	/// </summary>
	/// <param name="keys">今押されているキー</param>
	void Update(const char* keys [[maybe_unused]]) override;
};

