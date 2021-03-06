#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <SFML/Audio.hpp>

using namespace sf;

class SoundManager {
private:
	SoundBuffer m_FireBuffer;
	SoundBuffer m_FallInFireBuffer;
	SoundBuffer m_FallInWaterBuffer;

	SoundBuffer m_JumpBuffer;

	SoundBuffer m_ReachGoalBuffer;


	Sound m_Fire1Sound;
	Sound m_Fire2Sound;
	Sound m_Fire3Sound;

	Sound m_FallInFireSound;
	Sound m_FallInWaterSound;

	Sound m_JumpSound;
	Sound m_ReachGoalSound;

	int m_NextSound = 1;

public:
	SoundManager();
	void PlayFire(Vector2f emitterLocation, Vector2f listenerLocation);
	void PlayFallInFire();
	void PlayFallInWater();
	void PlayJump();
	void PlayReachGoal();
};

#endif