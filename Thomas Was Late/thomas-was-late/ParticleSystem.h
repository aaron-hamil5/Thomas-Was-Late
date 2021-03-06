#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTE_H

#include "Particle.h"
using namespace sf;
using namespace std;

class ParticleSystem : public Drawable
{
private:
	vector<Particle> m_Particles;
	VertexArray m_Vertices;
	float m_Duration;
	bool m_IsRunning = false;
public:
	virtual void draw(RenderTarget& target, RenderStates states) const;

	void init(int numParticles);
	void emitParticles(Vector2f position);
	void update(float dt);
	bool running();
};

#endif