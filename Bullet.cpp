#include "Bullet.h"
#include <Novice.h>

Bullet::Bullet() {
	pos_ = {0.0f, 0.0f};
	radius_ = { 5, 5 };
	velocity_ = { 15.0f,0.0f };
	color_ = WHITE;
	damage_ = 1;
	isShot_ = false;
}

Bullet::~Bullet() {
}

void Bullet::SetPos(float x, float y) {
	pos_.x = x;
	pos_.y = y;
}

void Bullet::Update(const char* keys [[maybe_unused]]){
	//isShotがtrueなら弾を動かす
	if (isShot_) {
		pos_.x += velocity_.x;
	}

	//画面外に出たらフラグを折る
	if (pos_.x + radius_.x >= kScreenWidthMax) {
		isShot_ = false;
	}
}
