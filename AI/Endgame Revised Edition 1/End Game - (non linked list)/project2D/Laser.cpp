#include "Laser.h"
#include <iostream>
#include "Matrix3.h"


Laser::Laser()
{
	LaserPosition.x;
	LaserPosition.y;

	Direction = Vector2(0, 0);
	Velocity = Vector2(0, 0);
	Speed = 0.0f;
	isActive = false;

	//we don't need to initialise our matrix because it will be the identity matrix
}


Laser::~Laser()
{
}

void Laser::SetTexture(aie::Texture* a_texture)
{
	m_texture = a_texture;
}

void Laser::SetRenderer(aie::Renderer2D* a_renderer)
{
	m_2dRenderer = a_renderer;
}

void Laser::update(float deltaTime)
{
	m_timer += deltaTime;
	LaserPosition += Direction * Speed * deltaTime;
	
	//put the laserposition into the matrix (transformMatrix) - use setTranslate
	TransformMatrix.setTranslate(LaserPosition.x, LaserPosition.y);
	TransformMatrix.setRotateZ(0);

}

void Laser::draw()
{
	if(isActive == true)
	{
		// demonstrate animation
		//m_2dRenderer->drawSprite(m_texture, LaserPosition.x, LaserPosition.y, 100, 100);
		m_2dRenderer->drawSpriteTransformed3x3(m_texture, (float*)TransformMatrix);
	}

}

void Laser::shutdown()
{
	Velocity = Vector2(0, 0);
	Direction = Vector2(0, 0);
}