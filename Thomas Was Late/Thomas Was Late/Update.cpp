#include "Engine.h"

#include <SFML/Graphics.hpp>

#include <sstream>

using namespace sf;
void Engine::update(float dtAsSec) {
	if (m_isPlaying) {
		/*Time Left*/
		m_TimeRemaining -= dtAsSec;

		/*Out Of Time*/
		if (m_TimeRemaining) {
			m_NewLevel = true;
		}
	}
}