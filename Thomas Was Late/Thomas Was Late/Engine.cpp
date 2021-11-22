#include "Engine.h"

Engine::Engine()
{
	#pragma region Creating Window

	/*Get the devices screen resolution*/
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	/*Create the window with the device’s resolution*/
	m_Window.create(VideoMode(resolution.x, resolution.y), "Thomas Was Late", Style::Fullscreen);

	#pragma endregion

	#pragma region Creating two different modes
	/*Creating the game space for the single player mode*/
	m_MainView.setSize(resolution);
	m_HUDView.reset(FloatRect(0, 0, resolution.x, resolution.y));

	/*Creating the game space for the two-player mode*/
	m_LeftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_RightView.setViewport(FloatRect(0.5f, 0.001f, 0.499f, 0.998f));
	//Viewports for the background
	m_BGLeftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_BGRightView.setViewport(FloatRect(0.5f, 0.001f, 0.499f, 0.998f));
	#pragma endregion

	#pragma region Creating Background
	/*Linking the background image to a Texture, then linking the texture to the sprite*/
	m_BackgroundTexture = TextureHolder::GetTexture("graphics/background.png");
	m_BackgroundSprite.setTexture(m_BackgroundTexture);
	#pragma endregion

}

void Engine::run()
{
	/*Creating Time*/
	Clock clock;

	while (m_Window.isOpen()) {
		/*Reset time to 0*/
		Time dt = clock.restart();

		/*Reset time to Game length*/
		m_GameTimeTotal += dt;

		/*Make time display as seconds*/
		float dtAsSec = dt.asSeconds();
	}
}

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
