#pragma once
#include "Matrix2.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include "Graph.h"
#include "Renderer2D.h"
#include "Texture.h"
#include <vector>
#include "Ship.h"

//FSM AGENT STUFF
class FSMAgent
{
public:
	enum AgentState
	{
		NONE,
		SEEK,
		FLEE,
		WANDER,
		STOPMOVING
	};

	//void SeekToPlayer();
	//void Flee();
	//void Wander();
	//void Destroyed();
};

class PathingAgent
{
public:
	int Health;
	bool IsAlive;
	PathingAgent();
	~PathingAgent();
	//override the update function
	void Update(float deltaTime);
	virtual void draw();
	//App2 calls this function and passes in the 
	//pathPoints array that was calculated using A*
	void SetPath(std::vector<Vector2> a_path);
	void SetTexture(aie::Texture* a_texture);
	void SetRenderer(aie::Renderer2D* a_renderer);
	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	Ship				*Player;

	Vector2 Direction;
	Vector2 Velocity;
	Vector2 position;
	Matrix3 TransformMatrix;
	float Rotation;

	float Speed;
	float Mass;
	float Drag;
	float m_timer;
	
	FSMAgent::AgentState currentState;
	int AIMode;
private:
	std::vector<Vector2> m_path;
};
