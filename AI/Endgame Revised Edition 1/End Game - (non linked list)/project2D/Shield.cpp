#include <iostream>
#include "Shield.h"
#include "Matrix2.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include "Input.h"
#include "Ship.h"


Shield::Shield()
{
	ShieldPosition.x;
	ShieldPosition.y;


	Direction = Vector2(0, 0);
	Velocity = Vector2(0, 0);
	Speed = 0.0f;
	rotation = 0.0f;
	isActive = true;

	//we don't need to initialise our matrix because it will be the identity matrix
}


Shield::~Shield()
{ 
}

void Shield::SetTexture(aie::Texture* a_texture)
{
	m_texture = a_texture;
}

void Shield::SetRenderer(aie::Renderer2D* a_renderer)
{
	m_2dRenderer = a_renderer;
}

void Shield::update(float deltaTime)
{

	m_timer += deltaTime;
	ShieldPosition += Direction * Speed * deltaTime;

	aie::Input* input = aie::Input::getInstance();
	{
		//add ship pointer

		if (input->isKeyDown(aie::INPUT_KEY_UP))
		{
			std::cout << "move shield Right" << "\n";
			//set pos
			ShieldPosition.y += 500 * deltaTime;
			//TransformMatrix.setScale(0.5);
			//set active = true
		}

		if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		{
			std::cout << "move shield Right" << "\n";
			//set pos
			ShieldPosition.y -= 500 * deltaTime;
			//TransformMatrix.setScale(0.5);
			//set active = true
		}

		if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		{
			std::cout << "move shield Right" << "\n";
			//set pos
			ShieldPosition.x += 500 * deltaTime;
			//TransformMatrix.setScale(0.5);
			//set active = true
		}

		if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		{
			std::cout << "move shield Right" << "\n";
			//set pos
			ShieldPosition.x -= 500 * deltaTime;
			//TransformMatrix.setScale(0.5);
			//set active = true
		}

	}


	//UPDATE YOUR MATRIX
	TransformMatrix.setRotateZ(rotation);


	//put the laserposition into the matrix (transformMatrix) - use setTranslate
	TransformMatrix.setTranslate(ShieldPosition.x, ShieldPosition.y);


}

void Shield::draw()
{
	if (isActive == true)
	{
		// demonstrate animation
		Matrix3 resultMatrix = (ship->TransformMatrix * TransformMatrix);
		m_2dRenderer->drawSpriteTransformed3x3(m_texture, (float*)resultMatrix);
	}

}

void Shield::shutdown()
{
	Velocity = Vector2(0, 0);
	Direction = Vector2(0, 0);
}