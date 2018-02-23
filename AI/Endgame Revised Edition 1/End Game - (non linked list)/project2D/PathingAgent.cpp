#include "PathingAgent.h"
#include <iostream>
#include <windows.h>
#include "Input.h"


PathingAgent::PathingAgent()
{
	position.x = 100;
	position.y = 600;
	Direction = Vector2(0, 0);
	Velocity = Vector2(0, 0);
	Speed = 10.0f;
	Mass = 5.0f;
	Drag = 0.99f;
	currentState = FSMAgent::AgentState::NONE;
	// AIMode 0 is off
	// AIMode 1 is distance travel
	// AIMode 2 is Node pathfinding travel
	AIMode = 0;

}


PathingAgent::~PathingAgent()
{
}

void PathingAgent::Update(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();
	//key controls
	if (input->wasKeyPressed(aie::INPUT_KEY_T))
	{
		//toggles AIMode
		if (AIMode == 0)
		{
			AIMode = 1;
		}
		else if (AIMode == 1)
		{
			AIMode = 2;
		}

		else if (AIMode == 2)
		{
			AIMode = 0;
		}
	}


	// movement stuff
	if (position.x <= 49.9f)
	{
		position.x = 50;
		Velocity.x = 0.0f;
		std::cout << "PathingAgent Can not go any further to the left" << "\n";
	}

	///Right
	if (position.x >= 1250.1)
	{
		position.x = 1250;
		Velocity.x = 0.0f;
		std::cout << "PathingAgent Can not go any further to the right" << "\n";
	}

	///Up
	if (position.y <= 49.9)
	{
		position.y = 50;
		Velocity.y = 0.0f;
		std::cout << "PathingAgent Can not go any further Downwards" << "\n";
	}

	///Down
	if (position.y >= 700.1f)
	{
		position.y = 700;
		Velocity.y = 0.0f;
		std::cout << "PathingAgent Can not go any further Upwards" << "\n";
	}
	
	Vector2 vecBetween = Player->ShipPosition - position;
	//normalize the vecBetween (to get the direction to our path point)

	//Add a force to our agent in that direction.
	int Dist = vecBetween.Magnitude();
	std::cout << "Distance between pathing agent and player is:" << Dist << "\n";
	if (AIMode == 0)
	{
		std::cout << "PathingAgent (yellow ship) is turned off" << Dist << "\n";
	}
	
	//if AIMode is set to distance movement
	if (AIMode == 1)
	{
		if (currentState == FSMAgent::AgentState::NONE)
		{
			std::cout << "AgentState is NONE" << "\n";
			std::cout << "AgentState assumed startup" << "\n";
			std::cout << "AgentState setting to Wander" << "\n";
			currentState = FSMAgent::AgentState::WANDER;
		}
		else if (currentState == FSMAgent::AgentState::SEEK)
		{
			if (Dist < 300)
			{
				if (Dist < 50)
				{
					//set case to STOPMOVING
					currentState = FSMAgent::AgentState::STOPMOVING;
				}
				else
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
			}

			else if (Dist > 301)
			{//set case to wander
				currentState = FSMAgent::AgentState::WANDER;
			}
		}

		else if (currentState == FSMAgent::AgentState::FLEE)
		{
			if (Dist <= 150)
			{
				std::cout << "AgentState is set to Flee" << "\n";
				std::cout << "Pathing agent is fleing to avoid collision" << "\n";
				vecBetween = position - Player->ShipPosition;
				vecBetween.Normalize();
				//		//Add a force to our agent in that direction.
				Direction = vecBetween;
				m_timer += deltaTime; m_timer += deltaTime;
				Vector2 ForceSum = Direction * Speed;
				Vector2 Acceleration = ForceSum * (1.0f / Mass);
				Vector2 Dampening = (Velocity * Drag) * -1;
				Velocity += Acceleration + Dampening * deltaTime;
				position += Velocity * deltaTime;
			}
			else if (Dist > 150)
				currentState = FSMAgent::AgentState::SEEK;
		}

		else if (currentState == FSMAgent::AgentState::WANDER)
		{
			std::cout << "AgentState is set to Wander" << "\n";
			std::cout << "Pathingagent (the Yellow ship) should now be wandering" << "\n";
			if (Dist < 401)
			{//set case to wander
				std::cout << "AgentState setting to seek" << "\n";
				currentState = FSMAgent::AgentState::SEEK;
			}
		}

		else if (currentState == FSMAgent::AgentState::STOPMOVING)
		{
			std::cout << "Player is too close, pathing agent stop moving to avoid colision" << "\n";
			if (Dist > 51)
			{//set case to wander
				std::cout << "AgentState setting to seek" << "\n";
				currentState = FSMAgent::AgentState::SEEK;
			}

			if (Dist < 20)
			{//set case to wander
				std::cout << "AgentState setting to Flee" << "\n";
				currentState = FSMAgent::AgentState::FLEE;
			}
		}
	}

	//ekse if AIMode is set to Node based Pathfinding
	else if (AIMode == 2)
	{
		std::cout << "AIMode is set to Mode 2: Node Based Pathfinding mode" << "\n";
		vecBetween.Normalize();
		//		//Add a force to our agent in that direction.
		Direction = vecBetween;
		{
			//if we have points in our path
			if (m_path.size() != 0)
			{
				Vector2 nextNodePosition = m_path[0];

				//calculate the vecBetween our agent and the 1st point in the path
				Vector2 vecBetween = (nextNodePosition - position);
				Vector2 DistBetween = (nextNodePosition - position);
				//normalize the vecBetween (to get the direction to our path point)
				vecBetween.Normalize();
				//Add a force to our agent in that direction.
				Direction = vecBetween;
				//if the distance between our agent and the 1st point < threshold	
				if (DistBetween.Magnitude() < 30)
				{
					//remove the first node from our path.
					m_path.erase(m_path.begin());
				}
			}

			else if (m_path.size() == 0)
			{
				Direction = Vector2(0, 0);
				Velocity = Vector2(0, 0);
			}

			m_timer += deltaTime;
			Vector2 ForceSum = Direction * Speed;
			Vector2 Acceleration = ForceSum * (1.0f / Mass);
			Vector2 Dampening = (Velocity * Drag) * -1;
			Velocity += Acceleration + Dampening * deltaTime;
			position += Velocity * deltaTime;

			TransformMatrix.setTranslate(position.x, position.y);
			TransformMatrix.setRotateZ(Rotation);
			//anything else Agent's require in their Update
		}
	}
	
}

void PathingAgent::SetPath(std::vector<Vector2> a_path)
{
	m_path = a_path;
}



void PathingAgent::SetTexture(aie::Texture* a_texture)
{
	m_texture = a_texture;
}

void PathingAgent::SetRenderer(aie::Renderer2D* a_renderer)
{
	m_2dRenderer = a_renderer;
}

void PathingAgent::draw()
{
	// demonstrate animation
	if (currentState == FSMAgent::AgentState::SEEK || currentState == FSMAgent::AgentState::FLEE || AIMode == 0 || AIMode == 2)
	{
		m_2dRenderer->drawSprite(m_texture, position.x, position.y, 100, 100);
	}
	else if (currentState == FSMAgent::AgentState::WANDER)
	{
		m_2dRenderer->drawCircle(position.x, position.y, 100, 100);
	}
}