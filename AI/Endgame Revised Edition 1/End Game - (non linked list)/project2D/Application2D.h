#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <iostream>
#include "MainMenu.h"
#include "Pause.h"
#include "Game.h"
#include "Matrix2.h"
#include "Matrix3.h"
#include "Matrix4.h"



#define MAP_WD 14
#define MAP_HT 25

enum class Scene
{
	NONE,
	MAINMENU,
	GAME,
	PAUSE
};

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	Scene currentScene = Scene::NONE;
	void SwitchScene(Scene nextScene);

	void OpenSceneInFront(Scene nextScene);
	void ResumeScene(Scene nextScene);
	MainMenu MainMenu;
	Game Game;
	Pause Pause;
	Ship Ship;
	//Graph graph;

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;

	float m_cameraX, m_cameraY;
	float m_timer;
};

