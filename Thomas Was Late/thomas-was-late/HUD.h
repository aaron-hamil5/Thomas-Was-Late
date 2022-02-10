#ifndef  HUD_H
#define HUD_H

#include<SFML/Graphics.hpp>

using namespace sf;

class HUD
{
public:
	HUD();
	Text getMessage();
	Text getLevel();
	Text getTime();
	Text setLevel(String text);
	Text setTime(String text);


private:
	Font m_Font;
	Text m_StartText;
	Text m_TimeText;
	Text m_LevelText;
};


#endif // ! HUD_H
