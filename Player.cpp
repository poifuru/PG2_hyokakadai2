#include "Player.h"
#include <Novice.h>

Player::Player() {
	pos_ = { 100.0f, 360.0f };
	radius_ = { 25, 25 };
	velocity_ = { 5.0f, 5.0f };
	color_ = WHITE;
	shotCoolTime_ = 6;

	for (int i = 0; i < kBulletNum; i++) {
		bullet_[i] = new Bullet();
	}
}

Player::~Player() {
	for (int i = 0; i < kBulletNum; i++) {
		delete bullet_[i];
	}
}

void Player::SetPos(float x, float y) {
	pos_.x = x;
	pos_.y = y;
}

void Player::Update(const char* keys) {
	//入力処理
	if (keys[DIK_W] && pos_.y - radius_.y > 0) {
		pos_.y -= velocity_.y;
	}
	if (keys[DIK_S] && pos_.y - radius_.y < 720) {
		pos_.y += velocity_.y;
	}
	if (keys[DIK_A] && pos_.x - radius_.x > 0) {
		pos_.x -= velocity_.x;
	}
	if (keys[DIK_D] && pos_.x - radius_.x < 1280) {
		pos_.x += velocity_.x;
	}

	//連射のクールタイムの処理
	if (shotCoolTime_ <= 0 && keys[DIK_SPACE]) {
		for (int i = 0; i < kBulletNum; i++) {
			if (!bullet_[i]->isShot_) {
				bullet_[i]->isShot_ = true;
				bullet_[i]->SetPos(pos_.x, pos_.y);
				i = (i + 1) % kBulletNum;
				break;
			}
		}
		shotCoolTime_ = 6;
	}
	else if (keys[DIK_SPACE]) {
		shotCoolTime_--;
	}
	else {
		shotCoolTime_ = 1;
	}

	//連射弾の処理
	for (int i = 0; i < kBulletNum; i++) {
		if (!bullet_[i]->isShot_) {
			bullet_[i]->SetPos(pos_.x, pos_.y);
		}
		else if (bullet_[i]->isShot_) {
			bullet_[i]->Update(keys);
		}
	}
}

void Player::DrawBullet() {
	for (int i = 0; i < kBulletNum; i++) {
		if (bullet_[i]->isShot_) {
			bullet_[i]->Draw();
		}
	}
}
