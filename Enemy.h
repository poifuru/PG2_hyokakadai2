#pragma once
#include "Circle.h"
#include "constant.h"

//前方宣言
class Player;

class Enemy : public Circle {
private:
	//メンバ変数
	bool isAlive_;
	int respawnTimer_;
	int killedCount_;
	int HP_;
	Player* player_;

public:
	//コンストラクタ、デストラクタ
	Enemy();
	~Enemy();

	//アクセッサ--
	Vector2<float> GetPos() { return pos_; };
	Vector2<int> GetRadius() { return radius_; };
	bool GetIsAlive() { return isAlive_; };
	int GetKilledCount() { return killedCount_; };
	int GetHP() { return HP_; };
	void SetHP(int damage);
	void SetKilledCount(int num);
	//-----------

	//メンバ関数
	//
	void Update(const char* keys[[maybe_unused]]) override;
};

