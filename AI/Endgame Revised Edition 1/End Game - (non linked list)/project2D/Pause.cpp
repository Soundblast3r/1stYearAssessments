#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <iostream>
#include "Pause.h"
#include "Application2D.h"
#include "Size.h"


Pause::Pause()
{
}


Pause::~Pause()
{
}

bool Pause::startup(Application2D* a_app)
{
	application = a_app;
	m_font = new aie::Font("./font/consolas.ttf", 32);
	return true;
}

void Pause::shutdown()
{
	delete m_font;
}

void Pause::update(float deltaTime)
{
	m_timer += deltaTime;

	aie::Input* input = aie::Input::getInstance();

	float mouseX = input->getMouseX();
	float mouseY = input->getMouseY();


	bool ButtonCheck(Size button, int mouseX, int mouseY);
	bool MainMenuButton_stateCheck = false;
	bool GameButton_stateCheck = false;
	bool PauseButton_stateCheck = false;

	if (input->wasKeyReleased(aie::INPUT_KEY_BACKSPACE))
	{
		MainMenuButton_stateCheck = true;
	}

	if (input->wasKeyReleased(aie::INPUT_KEY_ENTER))
	{
		GameButton_stateCheck = true;
	}

	if (MainMenuButton_stateCheck == true)
	{
		//change to MainMenu scene
		system("cls");
		std::cout << "MainMenu Selected" << "\n";
		application->SwitchScene(Scene::MAINMENU);
		return;
	}

	if (GameButton_stateCheck == true)
	{
		//change to Game scene
		system("cls");
		std::cout << "Game selected" << "\n";
		application->ResumeScene(Scene::GAME);
		return;
	}


}

void Pause::draw(aie::Renderer2D& a_renderer) {

	a_renderer.drawText(m_font, "Your Game is Paused", 510, 350);
}