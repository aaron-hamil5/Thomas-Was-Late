#include "Engine.h"

void Engine::draw()
{
	m_Window.clear(sf::Color::White);

	if (!m_IsSplitScreen)
	{
		m_Window.setView(m_BGMainView);
		m_Window.draw(m_BackgroundSprite);
		m_Window.setView(m_MainView);
		
		m_Window.draw(m_VALevel, &m_TextureFiles);

		m_Window.draw(m_Thomas.getSprite());
		m_Window.draw(m_Bob.getSprite());
	}
	else
	{
		m_Window.setView(m_BGLeftView);
		m_Window.draw(m_BackgroundSprite);
		m_Window.setView(m_LeftView);
		
		m_Window.draw(m_VALevel, &m_TextureFiles);

		m_Window.draw(m_Bob.getSprite());
		m_Window.draw(m_Thomas.getSprite());
				
		m_Window.setView(m_BGRightView);
		m_Window.draw(m_BackgroundSprite);
		m_Window.setView(m_RightView);
		
		m_Window.draw(m_VALevel, &m_TextureFiles);

		m_Window.draw(m_Thomas.getSprite());
		m_Window.draw(m_Bob.getSprite());
	}

	m_Window.setView(m_HUDView);

	m_Window.draw(m_HUD.getLevel());
	m_Window.draw(m_HUD.getTime());
	if (!m_IsPlaying) {
		m_Window.draw(m_HUD.getMessage());
	}

	m_Window.display();
}