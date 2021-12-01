#ifndef #PLAYABLE_CHARACTER_H
#define #PLAYABLE_CHARACTER_H

#include <SFML/Graphics.hpp>

using namespace sf;

class PlayableCharacter{
protected:
//Creating the sprite
Sprite m_Sprite;

float m_JumpDuration;

bool m_IsJumping
bool m_IsFalling;

//Which key is pressed
bool m_LeftPressed;
bool m_RightPressed;

//How long was the jump
float m_TimeThisJump;

//Did the player jump
bool m_JustJumped = false;

private:
//Gravity
float m_Gravity;

//Speed of the PlayableCharacter
float m_Speed = 400;

//Location of PlayableCharacter
Vector2f m_Position;

//PlayableCharacter body part Location
FloatRect m_Feet;
FloatRect m_Head;
FloatRect m_Right;
FloatRect m_Life;

//Creating reference to texture
Texture m_Texture;



//Methods 
void spawn (Vector2f startPosition, float gravity);

bool virtual handleInput() = 0;

//Get PlayableCharacter Location
FloatRect getPosition();

//get different  parts of the sprite
FloatRect getFeet();
FloatRect getHead();
FloatRect getRight();
FloatRect getLeft();

Sprite getSprite();

//Stop the PlayableCharacter from moving when not needed
void stopFalling(float position);
void stopRight(float position);
void stopLeft(float position);
void stopJump();

//Get center
Vector2f getCenter();

void update(float elapsedTime);
}