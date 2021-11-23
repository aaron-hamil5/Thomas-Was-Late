#include "Engine.h"

void Engine::draw() {
	/*Clear the screen and set to white*/
	m_Window.clear(Color::White);

	if (!m_SplitScreen) {
		m_Window.setView(m_BGMainView);

		m_Window.draw(m_BackgroundSprite);
		m_Window.setView(m_MainView);
	}
	else {
		m_Window.setView(m_BGLeftView);
		m_Window.draw(m_BackgroundSprite);
		m_Window.setView(m_BGRightView);

		/*Draw the background*/
		m_Window.draw(m_BackgroundSprite);
		m_Window.setView(m_RightView);
	}

	/*Draw HUD*/
	m_Window.setView(m_HUDView);

	m_Window.display();
}