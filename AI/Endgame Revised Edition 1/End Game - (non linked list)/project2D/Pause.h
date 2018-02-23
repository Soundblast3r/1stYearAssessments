#pragma once
#include "Application.h"
#include "Renderer2D.h"


//pre-declaration
class Application2D;

class Pause
{
public:
	Pause();
	~Pause();

	bool startup(Application2D* a_app);
	void shutdown();

	void update(float deltaTime);
	void draw(aie::Renderer2D& a_renderer);



protected:
	aie::Font*			m_font;
	float m_timer;
	aie::Texture*		m_texture;
	Application2D*			application;
};