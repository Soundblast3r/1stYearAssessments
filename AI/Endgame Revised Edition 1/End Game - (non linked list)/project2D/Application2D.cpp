#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "MainMenu.h"
#include "Size.h"

// https://aie.instructure.com/courses/39/pages/linked-lists
// https://trello.com/c/gNIqE6CL/59-linear-motion
 
Application2D::Application2D()
{

}

Application2D::~Application2D() {

}


bool Application2D::startup() {
	//renderer is created in Application2d.
	m_2dRenderer = new aie::Renderer2D();

	aie::Input* input = aie::Input::getInstance();

	float mouseX = input->getMouseX();
	float mouseY = input->getMouseY();

	m_cameraX = mouseX;
	m_cameraY = mouseY;
	m_timer = 0;

	SwitchScene(Scene::MAINMENU);
	return true;
}

void Application2D::shutdown() {

	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	if (currentScene == Scene::MAINMENU)
	{
		MainMenu.update(deltaTime);

	}
	else if (currentScene == Scene::GAME)
	{
		Game.update(deltaTime);
	}
	else if (currentScene == Scene::PAUSE)
	{
		Pause.update(deltaTime);
	}
	m_timer += deltaTime;

	aie::Input* input = aie::Input::getInstance();
}

void Application2D::draw() {


	clearScreen();
	m_2dRenderer->begin();

	if (currentScene == Scene::MAINMENU)
	{
		MainMenu.draw(*m_2dRenderer);
	}
	else if (currentScene == Scene::GAME)
	{
		Game.draw(*m_2dRenderer);
	}
	else if (currentScene == Scene::PAUSE)
	{
		Pause.draw(*m_2dRenderer);
	}

	

	m_2dRenderer->end();
}

//switch scene
void Application2D::SwitchScene(Scene nextScene)
{

	////shutdown old scene if there is one
	if (currentScene != Scene::NONE)
	{
		//shutdown old one
		if (currentScene == Scene::MAINMENU)
		{
			MainMenu.shutdown();
		}
		else if (currentScene == Scene::GAME)
		{
			Game.shutdown();
		}
		else if (currentScene == Scene::PAUSE)
		{
			Pause.shutdown();
			Ship.shutdown();
		}
	}

	//startup new scene
	if (nextScene == Scene::MAINMENU)
	{
		MainMenu.startup(this);
	}
	else if (nextScene == Scene::GAME)
	{
		Game.startup(this);
	}
	else if (nextScene == Scene::PAUSE)
	{
		Pause.startup(this);
	}

	//set currentScene to nextScene
	currentScene = nextScene;
}

//begin new scene without shutting down old scene
void Application2D::OpenSceneInFront(Scene nextScene)
{
	currentScene = nextScene;

	//startup new scene
	if (nextScene == Scene::MAINMENU)
	{
		MainMenu.startup(this);
	}
	else if (nextScene == Scene::GAME)
	{
		Game.startup(this);
	}
	else if (nextScene == Scene::PAUSE)
	{
		Pause.startup(this);
	}
}

void Application2D::ResumeScene(Scene nextScene)
{

	////shutdown old scene if there is one
	if (currentScene != Scene::NONE)
	{
		//shutdown old one
		if (currentScene == Scene::MAINMENU)
		{
			MainMenu.shutdown();
		}
		else if (currentScene == Scene::GAME)
		{
			Game.shutdown();
		}
		else if (currentScene == Scene::PAUSE)
		{
			Pause.shutdown();
		}
	}

	currentScene = nextScene;
}


