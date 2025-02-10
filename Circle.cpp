#include "Circle.h"
#include <Novice.h>

Circle::Circle() {
	pos_ = {};
	radius_ = {};
	velocity_ = {};
	color_ = WHITE;
}

Circle::~Circle() {
}

void Circle::Update(const char* keys[[maybe_unused]]) {
}

void Circle::Draw() {
	Novice::DrawEllipse(
		static_cast<int>(pos_.x), static_cast<int>(pos_.y),
		radius_.x, radius_.y, 0.0f, color_, kFillModeSolid
	);
}
