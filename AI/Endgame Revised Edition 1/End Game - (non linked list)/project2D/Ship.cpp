#include "Ship.h"
#include "Input.h"
#include "Matrix3.h"
#include <iostream>
#include "Game.h"
#include "Shield.h"
#include "Laser.h"


Ship::Ship()
{
	ShipPosition.x = 100;
	ShipPosition.y = 100;

	Rotation = 0.0f;

	Direction = Vector2(0, 0);
	Velocity = Vector2(0, 0);
	Speed = 300.0f;
	Mass = 5.0f;
	Drag = 0.99f;
}


Ship::~Ship()
{
}


//function used to set the ship's texture
void Ship::SetTexture(aie::Texture* a_texture)
{
	m_texture = a_texture;
}

void Ship::SetRenderer(aie::Renderer2D* a_renderer)
{
	m_2dRenderer = a_renderer;
}



void Ship::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();
	Direction = Vector2(0, 0);
	// use arrow keys to move camera

	///lasers
	{
		if (input->wasKeyReleased(aie::INPUT_KEY_SPACE))
		{
			std::cout << "Player fires" << "\n";
			//set pos
			laser->LaserPosition.x = ShipPosition.x;
			laser->LaserPosition.y = ShipPosition.y;
			// set physics
			laser->Direction = Vector2(0, 1);
			laser->Speed = 600.0f;

			//set active = true
			laser->isActive = true;
		}
	}

	///ship movement
	{
		if (input->isKeyDown(aie::INPUT_KEY_Q))
		{
			std::cout << "move shield Left" << "\n";
			//set pos
			Rotation -= 0.2f;
			//TransformMatrix.setScale(0.5f);
			//set active = true
		}

		if (input->isKeyDown(aie::INPUT_KEY_E))
		{
			std::cout << "move shield Right" << "\n";
			//set pos
			Rotation += 0.2f;
			//TransformMatrix.setScale(0.5);
			//set active = true
		}

		if (input->isKeyDown(aie::INPUT_KEY_W))
		{
			std::cout << "Ship Up" << "\n";
			//position.y += 200.0f * deltaTime;
			Direction.y = 1.0f;
		}

		if (input->isKeyDown(aie::INPUT_KEY_S))
		{
			std::cout << "Ship Down" << "\n";
			//position.y -= 100.0f * deltaTime;
			Direction.y = -1.0f;
		}
 
		if (input->isKeyDown(aie::INPUT_KEY_D))
		{
			std::cout << "Ship Right" << "\n";
			//position.y -= 100.0f * deltaTime;
			Direction.x = 1.0f;
		}

		if (input->isKeyDown(aie::INPUT_KEY_A))
		{
			std::cout << "Ship Left" << "\n";
			//position.y += 200.0f * deltaTime;
			Direction.x = -1.0f;
		}
		///Bordering
		{
			///left
			if (ShipPosition.x <= 49.9f)
			{
				ShipPosition.x = 50;
				Velocity.x = 0.0f;
				std::cout << "Ship Can not go any further to the left" << "\n";
			}

			///Right
			if (ShipPosition.x >= 1250.1)
			{
				ShipPosition.x = 1250;
				Velocity.x = 0.0f;
				std::cout << "Ship Can not go any further to the right" << "\n";
			}

			///Up
			if (ShipPosition.y <= 49.9)
			{
				ShipPosition.y = 50;
				Velocity.y = 0.0f;
				std::cout << "Ship Can not go any further Downwards" << "\n";
			}

			///Down
			if (ShipPosition.y >= 700.1f)
			{
				ShipPosition.y = 700;
				Velocity.y = 0.0f;
				std::cout << "Ship Can not go any further Upwards" << "\n";
			}
		}

		Vector2 ForceSum = Direction * Speed;
		Vector2 Acceleration = ForceSum * (1.0f / Mass);
		Vector2 Dampening = (Velocity * Drag) * -1;
		Velocity += Acceleration + Dampening * deltaTime;
		ShipPosition += Velocity * deltaTime;

 		TransformMatrix.setTranslate(ShipPosition.x, ShipPosition.y);
		TransformMatrix.setRotateZ(Rotation);
	}
}


void Ship::draw() 
{
	// demonstrate animation
	//m_2dRenderer->drawSprite(m_texture, ShipPosition.x , ShipPosition.y, 100, 100);
	m_2dRenderer->drawSpriteTransformed3x3(m_texture, (float*)TransformMatrix);
}

void Ship::shutdown() 
{
	Velocity = Vector2(0, 0);
	Direction = Vector2(0, 0);
}