#ifndef Object_H
#define Object_H
#include "Texture.h"
#include "Vector2.h"

class Object
{
public:
	Object();
	~Object();

	void SetBorders();

	void UpdateBorders();

	//used for testing purposes
	void UpdateYBorders();
	void UpdateXBorders();

	float height;
	float width;
	
	float tBorder;
	float bBorder;
	float lBorder;
	float rBorder;
	
	Texture *objectSprite;
	Vector2 position;
	Vector2 direction;

};










#endif