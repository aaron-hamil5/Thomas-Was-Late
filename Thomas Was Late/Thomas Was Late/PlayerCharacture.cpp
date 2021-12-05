#include "PlayableCharacter.h"

void PlayableCharacter::Spawn(Vector2f startPosition, float gravity){
//Place the player at the starting point
m_Position.x = startPosition.x;
m_Position.y = startPosition.y;

m_Gravity = gravity;

m_Sprite.setPosition(m_Position);
}

if (m_RightPressed){
    m_Position.x += m_Speed * elapsedTime;
}

if (m_LeftPressed){
    m_Position.y -= m_Speed * elapsedTime;
}

//Handle Jumping
if (m_IsJumping){
//Update Length of time of the Jumping
m_TimeThisJump += elapsedTime;

//is the jump upwards
    if (m_TimeThisJump < m_JumpDuration)
    {
        //move up 2x the gravity
        m_Position.y -= m_Gravity * 2 * elapsedTime;
    }
    else{
    m_IsJumping = false;
    m_IsFalling = true;
    }
    
    //Creating gravity
    if (m_IsFalling)
    {
        m_Position.y += m_Gravity* elapsedTime;
    }
    //Update all FloatRect on all body parts
    FloatRect r = getPosition();
    
    //Feet
    m_Feet.left = r.left + 3;
    m_Feet.top = r.top + r.height -1;
    m_Feet.width = r.width - 6;
    m_Feet.height = 1;
    
    //Head
    m_Head.left = r.left;
    m_Head.top = r.top + (r.height * .3)
    m_Head.width = r.width;
    m_Head.height = 1;
    
    //Right
    m_Right.left = r.left + r.width - 2;
    m_Right.top = r.top + (r.height * .35);
    m_Right.width = 1;
    m_Right.height = r.height * .3;
    
    //Updating the position
    m_Sprite.setPosition(m_Position);
    
    FloatRect PlayableCharacter::getPosition(){
        return m_Sprite.getGlobalBounds();
    }
    
    Vector2f PlayableCharacter::getCenter(){
    return Vector2f(
    m_Position.x + m_Sprite.getGlobalBounds().width / 2,
    m_Position.y + m_Sprite.getGlobalBounds().height / 2);
    }
    
    FloatRect PlayableCharacter::getFeet(){
    return m_Feet;
    }
    
    FloatRect PlayableCharacter::getHead(){
        return m_Head;
        }
        
    FloatRect PlayableCharacter::getLeft(){
        return m_Left;
        }
            
    FloatRect PlayableCharacter::getRight(){
        return m_Right;
        }
        
    Sprite PlayableCharacter::getSprite(){
    return m_Sprite;
    }
    
    
    void PlayableCharacter::stopFalling(float position){
        m_Position.y = position - getPosition().height;
        m_Sprite.setPosition(m_Position);
        m_IsFalling = false;
    }
    void PlayableCharacter::stopRight(float position){
    m_Position.x = position - m_Sprite.getGlobalBounds().width;
    m_Sprite.setPosition(m_Position);
    }
    
    void PlayableCharacter::stopLeft(float position){
    m_Position.x = position = m_Sprite.getGlobalBounds().width;
    m_Sprite.setPosition(m_Position);
    }
    
    void PlayableCharacter::stopJump(){}
    m_IsJumping = false;
    m_IsFalling= true;
    }
    
}