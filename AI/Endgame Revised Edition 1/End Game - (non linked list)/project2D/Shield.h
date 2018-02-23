#pragma once
#include "Renderer2D.h"
#include "Texture.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix2.h"
#include "Matrix3.h"
#include "Matrix4.h"

class Ship;

class Shield
{
public:
	Shield();
	~Shield();

	virtual void update(float deltaTime);
	virtual void draw();
	virtual void shutdown();

	Ship* ship;

	void SetTexture(aie::Texture* a_texture);
	void SetRenderer(aie::Renderer2D* a_renderer);

	Vector2 ShieldPosition; // has x and y
	float rotation;


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