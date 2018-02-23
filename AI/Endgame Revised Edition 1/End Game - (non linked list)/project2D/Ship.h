#pragma once

#include "Renderer2D.h"
#include "Texture.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix2.h"
#include "Matrix3.h"
#include "Matrix4.h"

class Laser;
class Shield; //forward declare

class Ship
{
public:

	
	Ship();
	~Ship();
	virtual void update(float deltaTime);
	virtual void draw();
	virtual void shutdown();

	void SetTexture(aie::Texture* a_texture);
	void SetRenderer(aie::Renderer2D* a_renderer);

	Vector2 ShipPosition; // has x and y

	Laser* laser;
	Shield* shield;
	Matrix3 TransformMatrix;
	float Rotation;

	Vector2 Direction;
	Vector2 Velocity;

	

	float Speed;
	float Mass;
	float Drag;
	float m_timer;
	//change the above to a Vector called position. (anywhere you see m_ShipX should be pos.x)
protected:
	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	Ship*				m_shipTexture;
	



};

