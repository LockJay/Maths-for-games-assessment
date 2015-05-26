#include "Game1.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Object.h"
#include "CollisionManager.h"
#include "Vector2.h"
#include <iostream>

Game1::Game1(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title) : Application(windowWidth, windowHeight, fullscreen, title)
{
	m_spritebatch = SpriteBatch::Factory::Create(this, SpriteBatch::GL3);

	//background and box
	m_background = new Texture("./Images/Background.png");
	box.objectSprite = new Texture("./Images/tinybox.png");
	box.position.x = 120.0f;
	box.position.y = 200.0f;
	box.height = box.objectSprite->GetHeight();
	box.width = box.objectSprite->GetWidth();
	box.SetBorders();

	//player
	sanic.objectSprite = new Texture("./Images/sanicSpriteSheet.png");
	sanic.position.x = 320.0f;
	sanic.position.y = 240.0f;
	sanic.height = 72;//sanic.objectSprite->GetHeight();
	sanic.width = 74;//sanic.objectSprite->GetWidth();
	sanic.SetBorders();
	sanic.direction.x = 900.0f;
	sanic.direction.y = 900.0f;

	m_animation = 0.25f;
	m_timer = 0;
}

Game1::~Game1()
{
	SpriteBatch::Factory::Destroy(m_spritebatch);
	delete m_background;
}


void Game1::Update(float deltaTime)
{
	collisionDetected = false;

	////// KEY INPUTS ////////
	if (GetInput()->IsKeyDown(GLFW_KEY_W) || GetInput()->IsKeyDown(GLFW_KEY_UP))
	{
		collisionDetected = collision.DetectCollision(sanic, box, 'W');
		
		if (collisionDetected == true)
		{
			sanic.position.y = box.bBorder + (sanic.height / 2);
		}
		else
		{
			sanic.position.y -= sanic.direction.y * deltaTime;
		}
		sanic.UpdateBorders();
	}
	if (GetInput()->IsKeyDown(GLFW_KEY_A) || GetInput()->IsKeyDown(GLFW_KEY_LEFT))
	{
		collisionDetected = collision.DetectCollision(sanic, box, 'A');

		if (collisionDetected == true)
		{
			sanic.position.x = box.rBorder + (sanic.width / 2);
		}
		else
		{
			sanic.position.x -= sanic.direction.x * deltaTime;
		}
		sanic.UpdateBorders();
	}
	if (GetInput()->IsKeyDown(GLFW_KEY_S) || GetInput()->IsKeyDown(GLFW_KEY_DOWN))
	{
		collisionDetected = collision.DetectCollision(sanic, box, 'S');

		if (collisionDetected == true)
		{
			sanic.position.y = box.tBorder - (sanic.height / 2);
		}
		else
		{
			sanic.position.y += sanic.direction.y * deltaTime;
		}
		sanic.UpdateBorders();
	}
	if (GetInput()->IsKeyDown(GLFW_KEY_D) || GetInput()->IsKeyDown(GLFW_KEY_RIGHT))
	{
		if (collision.DetectCollision(sanic.tBorder, sanic.bBorder, sanic.lBorder, sanic.rBorder, box.tBorder, box.bBorder, box.lBorder, box.rBorder, 'D') == true)
		{
			sanic.position.x = box.lBorder - (sanic.width / 2);
		}
		else
		{
			sanic.position.x += sanic.direction.x * deltaTime;
		}
		sanic.UpdateBorders();
	}
	if (GetInput()->WasKeyPressed(GLFW_KEY_R))
	{
		sanic.position.x = 320.0f;
		sanic.position.y = 240.0f;
	}




	////// ANIMATION ///////
	if (m_animation == 1.0f)
	{
		m_animation = 0.0f;
	}
	if (m_timer > 5.0f)
	{
		m_animation += 0.25f;
		m_timer = 0;
	}
	m_timer++;

}

void Game1::Draw()
{
	// clear the back buffer
	ClearScreen();

	m_spritebatch->Begin();

	// TODO: draw stuff.
	m_spritebatch->SetUVRect(0, 0, 1, 1);
	m_spritebatch->DrawSprite(m_background, 320, 240, 640, 480);

	m_spritebatch->DrawSprite(box.objectSprite, box.position.x, box.position.y, 50, 50);


	//use an array of textures instead of the UVRect?


	m_spritebatch->SetUVRect(m_animation, 0, 0.25, 1);
	m_spritebatch->DrawSprite(sanic.objectSprite, sanic.position.x, sanic.position.y, 74, 72);

	//std::cout << this->GetFPS() << std::endl;


	m_spritebatch->End();

}