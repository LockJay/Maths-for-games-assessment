#include "Object.h"

Object::Object()
{

}

Object::~Object()
{
	delete objectSprite;
}

void Object::SetBorders()
{
	tBorder = position.y - (height / 2);
	bBorder = position.y + (height / 2);
	lBorder = position.x - (width / 2);
	rBorder = position.x + (width / 2);
}

void Object::UpdateBorders()
{
	tBorder = position.y - (height / 2);
	bBorder = position.y + (height / 2);
	lBorder = position.x - (width / 2);
	rBorder = position.x + (width / 2);
}

//used for testing
void Object::UpdateYBorders()
{
	tBorder = position.y - (height / 2);
	bBorder = position.y + (height / 2);
}
void Object::UpdateXBorders()
{
	lBorder = position.x - (width / 2);
	rBorder = position.x + (width / 2);
}