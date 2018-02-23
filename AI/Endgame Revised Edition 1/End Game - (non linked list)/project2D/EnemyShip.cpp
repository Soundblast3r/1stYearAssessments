#include "EnemyShip.h"
#include "Vector2.h"
#include <iostream>
#include "Graph.h"
#include "Ship.h"
#include "Input.h"


EnemyShip::EnemyShip()
{
	position.x = 100;
	position.y = 600;
	Direction = Vector2(0, 0);
	Velocity = Vector2(0, 0);
	Speed = 10.0f;
	Mass = 5.0f;
	Drag = 0.99f;
	currentState = FSMAgent2::AgentState2::NONE;
}


EnemyShip::~EnemyShip()
{
}

void EnemyShip::SetTexture(aie::Texture* a_texture)
{
	m_texture = a_texture;
}

void EnemyShip::SetRenderer(aie::Renderer2D* a_renderer)
{
	m_2dRenderer = a_renderer;
}

void EnemyShip::SetMousePos(Vector2 a_mousePos)
{
	CurrentMousePos = a_mousePos;
}

void EnemyShip::update(float deltaTime)
{
	

	std::cout << "EnemyShip Can not go any further Upwards" << "\n";
	//CurrentMousePos

	if (position.x <= 49.9f)
	{
		position.x = 50;
		Velocity.x = 0.0f;
		std::cout << "EnemyShip Can not go any further to the left" << "\n";
	}

	///Right
	if (position.x >= 1250.1)
	{
		position.x = 1250;
		Velocity.x = 0.0f;
		std::cout << "EnemyShip Can not go any further to the right" << "\n";
	}

	///Up
	if (position.y <= 49.9)
	{
		position.y = 50;
		Velocity.y = 0.0f;
		std::cout << "EnemyShip Can not go any further Downwards" << "\n";
	}

	///Down
	if (position.y >= 700.1f)
	{
		position.y = 700;
		Velocity.y = 0.0f;
		std::cout << "EnemyShip Can not go any further Upwards" << "\n";
	}

	Vector2 vecBetween = Player->ShipPosition - position;
	int Dist = vecBetween.Magnitude();
	std::cout << "Distance between EnemyShip and player is:" << Dist << "\n";
	int playerspeed = Player->Velocity.Magnitude();

	//AI movement
	if (currentState == FSMAgent2::AgentState2::NONE)
	{
		std::cout << "AgentState2 is NONE" << "\n";
		std::cout << "AgentState2 assumed startup" << "\n";
		std::cout << "AgentState2 setting to Wander" << "\n";
		currentState = FSMAgent2::AgentState2::WANDER;
	}
//change from here
	else if (currentState == FSMAgent2::AgentState2::SEEK)
	{
		if (playerspeed > 100 || Dist < 200)
		{
				vecBetween.Normalize();
				Direction = vecBetween;
				m_timer += deltaTime; m_timer += deltaTime;
				Vector2 ForceSum = Direction * Speed;
				Vector2 Acceleration = ForceSum * (1.0f / Mass);
				Vector2 Dampening = (Velocity * Drag) * -1;
				Velocity += Acceleration + Dampening * deltaTime;
				position += Velocity * deltaTime;
		}
		else if (playerspeed < 99)
		{
			currentState = FSMAgent2::AgentState2::WANDER;
		}
	}

	else if (currentState == FSMAgent2::AgentState2::WANDER)
	{
		if (playerspeed > 500 || Dist < 200)
		{
			std::cout << "Player is moving to fast, moving to them" << Dist << "\n";
			currentState = FSMAgent2::AgentState2::SEEK;
		}
	}
}

void EnemyShip::draw()
{
	if (currentState == FSMAgent2::AgentState2::WANDER)
	{
		m_2dRenderer->drawCircle(position.x, position.y, 100, 100);
	}
	else
	{
		m_2dRenderer->drawSprite(m_texture, position.x, position.y, 100, 100);
	}
}

void EnemyShip::shutdown()
{
	Velocity = Vector2(0, 0);
	Direction = Vector2(0, 0);
}

void EnemyShip::SetAIPos()
{
	nodePosition = AI_Graph->GetNodeAtPosition(position);
	position.x = nodePosition->data.x;
	position.y = nodePosition->data.y;
}