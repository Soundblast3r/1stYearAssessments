#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "Ship.h"
#include "EnemyShip.h"
#include "Laser.h"
#include "Shield.h"
#include "Graph.h"
#include "PathingAgent.h"

//pre-declaration
class Application2D;

class Game
{
public:
	Game();
	~Game();

	bool startup(Application2D* a_app);
	void shutdown();

	void update(float deltaTime);
	void draw(aie::Renderer2D& a_renderer);
	Laser* m_Laser;
	Shield* m_Shield;
	bool Debugmode;
	bool AIInMovement;
	GraphNode nodePosition;

protected:
	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_shipTexture;
	aie::Texture*		m_LaserTexture;
	aie::Texture*		m_ShieldTexture;
	aie::Texture*		m_EnemyShipTexture;
	aie::Texture*		m_PathingAgentTexture;
	aie::Font*			m_font;
	float m_timer;
	aie::Texture*		m_texture;
	PathingAgent*		m_PathingAgent;

	Ship *m_playerShip; //put this on the heap
	EnemyShip* m_EnemyShip;
	float m_cameraX, m_cameraY;

	Graph* graphAddress;


	Application2D*		application;
};