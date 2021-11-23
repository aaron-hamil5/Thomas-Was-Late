#include "Engine.h"

void Engine::input()
{
	Event event;

	while (m_Window.pollEvent(event)) {
		if (event.type == Event::KeyPressed) {
			/*Quit*/
			if (Keyboard::isKeyPressed(Keyboard::Escape)) {
				m_Window.close();
			}

			/*Start Game*/
			if (Keyboard::isKeyPressed(Keyboard::Return)) {
				m_isPlaying = true;
			}

			/*Switch Charater*/
			if (Keyboard::isKeyPressed(Keyboard::Q)) {
				m_Charater1 = !m_Charater1;
			}

			/*Change view*/
			if (Keyboard::isKeyPressed(Keyboard::E)) {
				m_SplitScreen = !m_SplitScreen;
			}
		}
	}
}
