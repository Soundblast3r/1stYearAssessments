#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <iostream>
#include "Application2D.h"
#include "Game.h"
#include "Size.h"
#include "Enemyship.h"
#include "PathingAgent.h"

Game::Game()
{
}


Game::~Game()
{
}

bool Game::startup(Application2D * a_app)
{
	application = a_app;
	
	m_2dRenderer = new aie::Renderer2D();
	
	//create graph here
	graphAddress = new Graph();

	//pass the address of our renderer into our graph
	graphAddress->SetRendererAddress(m_2dRenderer);

	m_texture = new aie::Texture("./textures/numbered_grid.tga");

	m_shipTexture = new aie::Texture("./textures/ship.png");
	m_EnemyShipTexture = new aie::Texture("./textures/EnemyShip.png");
	m_PathingAgentTexture = new aie::Texture("./textures/PathingAgent.png");
	m_LaserTexture = new aie::Texture("./textures/Laser.png");
	m_ShieldTexture = new aie::Texture("./textures/Shield.png");

	Debugmode = false;
	AIInMovement = false;

	m_playerShip = new Ship;
	m_playerShip -> SetTexture(m_shipTexture);
	m_playerShip -> SetRenderer(m_2dRenderer);

	m_Laser = new Laser;
	m_Laser->SetTexture(m_LaserTexture);
	m_Laser->SetRenderer(m_2dRenderer);

	m_Shield = new Shield;
	m_Shield->SetTexture(m_ShieldTexture);
	m_Shield->SetRenderer(m_2dRenderer);

	//set the ship's laser pointer to this laser
	m_playerShip->laser = m_Laser;
	m_playerShip->shield = m_Shield;
	m_Shield->ship = m_playerShip;

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_timer = 0;
	m_cameraX = 10.0f;
	m_cameraY = 10.0f;

	aie::Input* input = aie::Input::getInstance();
	int mouseX = input->getMouseX();
	int mouseY = input->getMouseY();

	/// put this in game
	{
		int m_nodes[MAP_WD][MAP_HT] = {
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		};

		for (int i = 0; i < MAP_HT; i++)
		{
			for (int j = 0; j < MAP_WD; j++)
			{
				if (i > 5 && i < 9 && j > 4 && j < 10)
				{
					continue;
				}
				graphAddress->AddNode(Vector2((i+1)*50.0f, (j+1)*50.0f));
			}
		}



		for (int i = 0; i < graphAddress->m_nodes.size(); i++)
		{

			for (int j = 0; j < graphAddress->m_nodes.size(); j++)
			{
				//if it's the same node, move to next node
				if (i == j)
					continue;

				//add an edge between the nodes that need edges added
				float dist = (graphAddress->m_nodes[i]->data - graphAddress->m_nodes[j]->data).Magnitude();
				if (dist < 100)
				{
					graphAddress->AddEdge(*(graphAddress->m_nodes[i]), *graphAddress->m_nodes[j], 1.0f);
				}

			}
		}
	}

	m_EnemyShip = new EnemyShip;
	m_EnemyShip->AI_Graph = graphAddress;
	m_EnemyShip->SetTexture(m_EnemyShipTexture);
	m_EnemyShip->SetRenderer(m_2dRenderer);
	m_EnemyShip->SetAIPos();
	m_EnemyShip->Player = m_playerShip;


	m_PathingAgent = new PathingAgent;
	m_PathingAgent->SetTexture(m_PathingAgentTexture);

	m_PathingAgent->SetRenderer(m_2dRenderer);
	m_PathingAgent->Player = m_playerShip;
	return true;

}

void Game::shutdown()
{
	delete m_shipTexture;
	delete m_EnemyShipTexture;
	delete m_2dRenderer;
	delete m_font;
	delete m_playerShip;
	delete m_Shield;
	delete m_texture;
	delete m_PathingAgent;

}

void Game::update(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	
	int mouseX = input->getMouseX();
	int mouseY = input->getMouseY();

	m_EnemyShip->SetMousePos(Vector2(mouseX, mouseY));

	m_timer += deltaTime;
	///input stuff
	{

		bool MainMenuButton_stateCheck = false;
		bool GameButton_stateCheck = false;
		bool PauseButton_stateCheck = false;

		

		/// change to if game ended
		// if (input->wasKeyReleased(aie::INPUT_KEY_1))
		// {
		//		MainMenuButton_stateCheck = true;
		// }
		if (input->wasKeyPressed(aie::INPUT_KEY_F1))
		{
			if (AIInMovement == true)
			{
				std::cout << "AIInMovement Turned off" << "\n";
				AIInMovement = false;
			}

			else if (AIInMovement == false)
			{
				std::cout << "AIInMovement Turned on" << "\n";
				AIInMovement = true;
		
				GraphNode* startNode = graphAddress->GetNodeAtPosition( m_PathingAgent->position );
				GraphNode* endNode = graphAddress->GetNodeAtPosition( m_playerShip->ShipPosition );

				std::vector<Vector2> resultPath = graphAddress->CalculatePath(startNode, endNode);
				m_PathingAgent->SetPath(resultPath);
			}
		
		}

		if (input->wasKeyPressed(aie::INPUT_KEY_F2))
		{
			graphAddress->BreadthFirstSearch(*graphAddress->m_nodes[0]);
		}
		
		if (input->wasKeyPressed(aie::INPUT_KEY_F3))
		{
			if (Debugmode == true)
			{
				std::cout << "DebugMode Turned off" << "\n";
				Debugmode = false;
			}

			else if (Debugmode == false)
			{
				std::cout << "DebugMode Turned on" << "\n";
				Debugmode = true;
			}
		}

		if (input->wasKeyReleased(aie::INPUT_KEY_F5))
		{
			system("cls");
			std::cout << "Game Restarted" << "\n";
			application->SwitchScene(Scene::GAME);
		}
		if (input->wasKeyPressed(aie::INPUT_KEY_F))
		{
			graphAddress->BreadthFirstSearch(*graphAddress->m_nodes[0]);
		}


		if (input->wasKeyReleased(aie::INPUT_KEY_ESCAPE))
		{
			PauseButton_stateCheck = true;
		}


		if (MainMenuButton_stateCheck == true)
		{
			//change to new game scene
			system("cls");
			std::cout << "MainMenu Selected" << "\n";
			application->SwitchScene(Scene::MAINMENU);
			return;
		}

		if (PauseButton_stateCheck == true)
		{
			system("cls");
			std::cout << "Pause Selected" << "\n";
			application->OpenSceneInFront(Scene::PAUSE);
			return;
			//go to password page (to continue from a previous point or see walkthroughs (eliminates the need to alter menu on save-data)
		}
	}

	/// game stuff
	{
		m_playerShip->update(deltaTime);
		if (m_Laser->isActive == true)
		{
			m_Laser->update(deltaTime);
		}

		if (m_Shield->isActive == true)
		{
			m_Shield->update(deltaTime);
		}

		m_EnemyShip->update(deltaTime);

		m_PathingAgent->Update(deltaTime);
		if (AIInMovement == true)
		{
			std::cout << "current x position is: " << m_PathingAgent->position.x << std::endl;
			std::cout << "current y position is: " << m_PathingAgent->position.y << std::endl << std::endl;
		}
	}
	///debug stuff
	{
		if (Debugmode == true)
		{
			if (input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT))
			{
			
					nodePosition = *graphAddress->GetNodeAtPosition(Vector2( (float)mouseX, (float)mouseY));
					std::cout << "Current Node x: " << nodePosition.data.x << std::endl;
					std::cout << "Current Node y: " << nodePosition.data.y << std::endl;
					std::cout << std::endl;
			}
		}
	}
}

void Game::draw(aie::Renderer2D& a_renderer) 
{
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);
	m_2dRenderer->begin();
	
	if (Debugmode == true)
	{
		graphAddress->DrawGraph(*m_2dRenderer);
	}
	

	m_EnemyShip->draw();

	m_PathingAgent->draw();
	
	if (m_Shield->isActive == true)
	{
		m_Shield->draw();
	}

	if (m_Laser->isActive == true)
	{	
		m_Laser->draw();
	}

	m_playerShip->draw();

	

	m_2dRenderer->end();


	
	a_renderer.drawText(m_font, "Game Playing", m_cameraX, m_cameraY);
}

