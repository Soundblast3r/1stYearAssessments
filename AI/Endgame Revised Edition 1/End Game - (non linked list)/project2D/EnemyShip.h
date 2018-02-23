#pragma once
#include "Renderer2D.h"
#include "Texture.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Graph.h"
#include "ship.h"
#include "PathingAgent.h"

class FSMAgent2
{
public:
	enum AgentState2
	{
		NONE,
		SEEK,
		FLEE,
		WANDER,
		ATTACK,
		STOPMOVING
	};
};

class EnemyShip
{
public:
	EnemyShip();
	~EnemyShip();

	virtual void update(float deltaTime);
	virtual void draw();
	virtual void shutdown();

	Graph*				AI_Graph;
	Vector2 position; // has x and y
	void SetAIPos();
	void SetTexture(aie::Texture* a_texture);
	void SetRenderer(aie::Renderer2D* a_renderer);
	void SetMousePos(Vector2 a_mousePos);
	Ship*				Player;

	FSMAgent2::AgentState2 currentState;

protected:
	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	EnemyShip*			m_EnemyShipTexture;
	GraphNode*			nodePosition;

	Vector2 Direction;
	Vector2 Velocity;
	Vector2 CurrentMousePos;

	float Speed;
	float Mass;
	float Drag;
	float m_timer;
};

