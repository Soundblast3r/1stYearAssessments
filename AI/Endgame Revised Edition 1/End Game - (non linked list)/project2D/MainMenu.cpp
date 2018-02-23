#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <iostream>
#include "MainMenu.h"
#include "Application2D.h"
#include "Size.h"
#include "Vector2.h"

bool ButtonCheck(Size button, int mouseX, int mouseY);
bool MainMenuButton_stateCheck = false;
bool GameKeyButton_stateCheck = false;
bool GameMouseButton_stateCheck = false;
bool PauseButton_stateCheck = false;

MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{

}

bool MainMenu::startup(Application2D* a_app)
{
	application = a_app;

	m_font = new aie::Font("./font/consolas.ttf", 32);

	GameMouseButton.width = 176;
	GameMouseButton.height = 28;
	GameMouseButton.x = 623;
	GameMouseButton.y = 279;

	return true;
}

void MainMenu::shutdown()
{
		delete m_font;
}

void MainMenu::update(float deltaTime)
{
	m_timer += deltaTime;

	aie::Input* input = aie::Input::getInstance();

	float mouseX = input->getMouseX();
	float mouseY = input->getMouseY();


	GameMouseButton_stateCheck = ButtonCheck(GameMouseButton, mouseX, mouseY);
	

	if (input->wasKeyReleased(aie::INPUT_KEY_ENTER))
	{
		GameKeyButton_stateCheck = true;
	}

	if (GameKeyButton_stateCheck == true)
	{
		//change to ontrols scene
		std::cout << "Game selected" << "\n";
		application->SwitchScene(Scene::GAME);
		return;
	}

	if (GameMouseButton_stateCheck == true)
	{
		//change to ontrols scene
		std::cout << "Game selected" << "\n";
		application->SwitchScene(Scene::GAME);
		return;
	}
}

void MainMenu::draw(aie::Renderer2D& a_renderer) {

	a_renderer.drawLine(535, 296, 711, 296, 0, 0);
	a_renderer.drawLine(535, 263, 711, 263, 0, 0);

	char MainMenu[32];
	sprintf_s(MainMenu, 32, "");

	a_renderer.drawBox(GameMouseButton.x, GameMouseButton.y, GameMouseButton.width, GameMouseButton.height);
	a_renderer.drawText(m_font, "Play Game", 545, 300 - 32);
}

bool ButtonCheck(Size button, int mouseX, int mouseY)
{
	aie::Input* input = aie::Input::getInstance();

	if (mouseY <= (button.y - button.height) + (button.height + button.height / 2) && mouseY >= (button.y - button.height) + (button.height - button.height / 2)
		&&
		mouseX <= (button.x - button.width) + (button.width + button.width / 2) && mouseX >= (button.x - button.width) + (button.width - button.width / 2))
	{
		if (input->isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_LEFT))
		{
			return true;
		}
	}
}