//TEAM: Daniel M., Rohit P., Gabriel O.
#include "Particle.h"

using namespace std;


Particle::Particle(Vector2f position, float size,float lifespan)
{
	shape = ParticleShape::Circle;
    this->size = size;
    this->position = position;
    this->lifespan = lifespan;
    alive = true;
    if (shape == ParticleShape::Circle) {
        body = CircleShape(size);
    }

}

Particle::~Particle()
{
}

void Particle::Update()
{

    ageOfParticle++;
    position += velocity;
    body.setPosition(position);
    body.setRadius(size * (lifespan - ageOfParticle)/lifespan);

}

void Particle::Render(RenderWindow& window)
{
    window.draw(body);
}


void Particle::SetVelocity(Vector2f velocity)
{
    this->velocity = velocity;
}


