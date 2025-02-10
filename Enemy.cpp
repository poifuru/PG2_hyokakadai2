#include "Enemy.h"
#include <Novice.h>
#include "Player.h"
#include "Function.h"

Enemy::Enemy() {
	pos_ = { 1000.0f, 360.0f };
	radius_ = { 50, 50 };
	velocity_ = { 0.0f, 5.0f };
	color_ = RED;
	HP_ = 10;
	isAlive_ = true;
	respawnTimer_ = 60;
	killedCount_ = 0;
}

Enemy::~Enemy() {

}

void Enemy::SetHP(int damage)
{
	HP_ -= damage;
}

void Enemy::SetKilledCount(int num)
{
	killedCount_ += num;
}

void Enemy::Update(const char* keys [[maybe_unused]] ) {
	//縦に移動させる
	if (isAlive_) {
		pos_.y += velocity_.y;

		//壁に当たったら反射
		if (pos_.y + radius_.y >= kScreenHeightMax || pos_.y - radius_.y <= kScreenHeightMin) {
			velocity_.y *= -1;
		}
	}

	if (HP_ <= 0) {
		isAlive_ = false;
	}

	if (!isAlive_) {
		respawnTimer_--;

		if (respawnTimer_ <= 0) {
			respawnTimer_ = 60;
			HP_ = 10;
			isAlive_ = true;
		}
	}
}
