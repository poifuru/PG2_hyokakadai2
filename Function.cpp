#include "Function.h"
#include <math.h>

bool CollisionEllipse(Vector2<float> pos1, Vector2<int> radius1, Vector2<float> pos2, Vector2<int> radius2) {
	float distance = sqrtf(powf(pos2.x - pos1.x, 2) + powf(pos2.y - pos1.y, 2));
	float maxDistance = static_cast<float>(radius1.x + radius2.x);

	if (distance <= maxDistance) {
		return true;
	}
	return false;
}