#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H
#include "Object.h"
#include "Vector2.h"

class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();

	bool DetectCollision(Object &a, Object &b, char direction);
	bool DetectCollision(float obj1T, float obj1B, float obj1L, float obj1R, float obj2T, float obj2B, float obj2L, float obj2R, char direction) const;

};




#endif