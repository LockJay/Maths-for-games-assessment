#include "CollisionManager.h"

CollisionManager::CollisionManager()
{

}

CollisionManager::~CollisionManager()
{

}

bool CollisionManager::DetectCollision(Object &a, Object &b, char direction)
{
	bool detected = DetectCollision(a.tBorder, a.bBorder, a.lBorder, a.rBorder, b.tBorder, b.bBorder, b.lBorder, b.rBorder, direction);

	return detected;
}

bool CollisionManager::DetectCollision(float obj1T, float obj1B, float obj1L, float obj1R, float obj2T, float obj2B, float obj2L, float obj2R, char direction) const
{
	if (direction == 'W')
	{
		//checks if obj1's top border is above/at obj2's bottom border
		if (obj1T <= obj2B)
		{
			//checks if obj1's bottom border is above/at obj2's bottom border
			if (obj1B <= obj2B)
			{
				//obj1 isn't going to hit obj2's bottom border
				return false;
			}
			else
			{
				//checks if obj1's left border is between obj2's left and right borders
				if (obj1L >= obj2L && obj1L < obj2R)
				{
					return true;
				}
				//checks the same except with the right border
				else if (obj1R <= obj2R && obj1R > obj2L)
				{
					return true;
				}

				else if (obj1L > obj2L && obj1L < obj2R)
				{
					return true;
				}

				else if (obj1L < obj2L && obj1R > obj2R)
				{
					return true;
				}
			}

		}
	}
	if (direction == 'S')
	{
		//checks if obj1's bottom border is above/at obj2's top border
		if (obj1B >= obj2T)
		{
			//checks if obj1's top border is above/at obj2's top border
			if (obj1T >= obj2T)
			{
				//obj1 isn't going to hit obj2's top border
				return false;
			}
			else
			{
				//checks if obj1's left border is between obj2's left and right borders
				if (obj1L >= obj2L && obj1L < obj2R)
				{
					return true;
				}
				//checks the same except with the right border
				else if (obj1R <= obj2R && obj1R > obj2L)
				{
					return true;
				}

				else if (obj1L > obj2L && obj1L < obj2R)
				{
					return true;
				}

				else if (obj1L < obj2L && obj1R > obj2R)
				{
					return true;
				}
			}

		}
	}
	if (direction == 'A')
	{
		//checks if obj1's left border is above/at obj2's right border
		if (obj1L <= obj2R)
		{
			//checks if obj1's right border is above/at obj2's right border
			if (obj1R <= obj2R)
			{
				//obj1 isn't going to hit obj2's right border
				return false;
			}
			else
			{
				//checks if obj1's bottom border is between obj2's bottom and top borders
				if (obj1B >= obj2B && obj1B < obj2T)
				{
					return true;
				}
				else if (obj1T >= obj2T && obj1T < obj2B)
				{
					return true;
				}
				else if (obj1B < obj2B && obj1B > obj2T)
				{
					return true;
				}
				else if (obj1B > obj2B && obj1T < obj2T)
				{
					return true;
				}
			}

		}
	}
	if (direction == 'D')
	{
		//checks if obj1's right border is above/at obj2's left border
		if (obj1R >= obj2L)
		{
			//checks if obj1's left border is above/at obj2's left border
			if (obj1L >= obj2L)
			{
				//obj1 isn't going to hit obj2's left border
				return false;
			}
			else
			{
				//checks if obj1's right border is between obj2's bottom and top borders
				if (obj1B >= obj2B && obj1B < obj2T)
				{
					return true;
				}
				else if (obj1T >= obj2T && obj1T < obj2B)
				{
					return true;
				}
				else if (obj1B < obj2B && obj1B > obj2T)
				{
					return true;
				}
				else if (obj1B > obj2B && obj1T < obj2T)
				{
					return true;
				}
			}

		}
	}
	
	return false;

}