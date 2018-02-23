#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "Size.h"



//pre-declaration
class Application2D;

class MainMenu
{
public:
	MainMenu();
	~MainMenu();

	bool startup(Application2D* a_app);
	void shutdown();

	void update(float deltaTime);
	void draw(aie::Renderer2D& a_renderer);



protected:

	
	aie::Font*			m_font;
	float m_timer;
	aie::Texture*		m_texture;
	Application2D*		application;

	Size GameMouseButton;
};