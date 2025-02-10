#pragma once
#include "struct.h"

/// <summary>
/// 円同士の当たり判定を取る関数
/// </summary>
bool CollisionEllipse(Vector2<float> pos1, Vector2<int> radius1, Vector2<float> pos2, Vector2<int> radius2);