
/*-----------------------------------------------------------------------------
Author:			
Description:	
-----------------------------------------------------------------------------*/
#ifndef GAME1_H
#define GAME1_H

#include "Object.h"
#include "Vector2.h"
#include "CollisionManager.h"
#include "Application.h"


class SpriteBatch;

class Game1 : public Application
{
public:

	// assets loaded in constructor
	Game1(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title);

	// assets destroyed in destructor
	virtual ~Game1();

	// update / draw called each frame automaticly
	virtual void Update(float deltaTime);
	virtual void Draw();

protected:

	CollisionManager collision;
	SpriteBatch *m_spritebatch;
	Texture *m_background;

	Object box;
	Object sanic;
	Object screenBorders;
	bool collisionDetected;
	float m_animation;
	int m_timer;

private:
};

#endif