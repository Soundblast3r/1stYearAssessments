#pragma once
#include "Renderer2D.h"
#include "Texture.h"
#include "Matrix2.h"
#include "Matrix3.h"
#include "Matrix4.h"


class Laser
{
public:
	Laser();
	~Laser();

	virtual void update(float deltaTime);
	virtual void draw();
	virtual void shutdown();

	void SetTexture(aie::Texture* a_texture);
	void SetRenderer(aie::Renderer2D* a_renderer);

	Vector2 LaserPosition; // has x and y
	Vector2 Direction;
	Vector2 Velocity;
	float Speed;

	bool isActive;

	Matrix3 TransformMatrix;

protected:
	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	float m_timer;
};