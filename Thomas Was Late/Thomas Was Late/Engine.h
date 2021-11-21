#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include "TextureHolder.h"

using namespace sf;

class Engine {
private:
#pragma region Vaiables;

	//Creating the textures
	TextureHolder texHol;
	const int TILE_SIZE = 50;
	const int Verts_In_Quad = 4;

	// Creating the gravity to keep the player down
	const int GRAVITY = 300;

	RenderWindow m_Window;

	//Main Views
	View m_MainView;
	View m_LeftView;
	View m_RightView;

	//Required View for the Background
	View m_BGMainView;
	View m_BGLeftView;
	View m_BGRightView;
	View m_HUDView;

	//Declaring Sprites and Textures
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

	//Is the game playing?
	bool m_isPlaying = false;

	//Which player is in focus
	bool m_Charater1 = true;

	//Start split screen mode?
	bool m_SplitScreen = false;

	//Seconds left in game
	float m_TimeRemaining = 10;
	Time m_GameTimeTotal;

	//In need of a new level
	bool m_NewLevel = true;

	//Internal Variable
	void input();
	void update(float dtAsSec);
	void draw();
	#pragma endregion

public:
	Engine();
	void run();

};
#endif ENGINE_H