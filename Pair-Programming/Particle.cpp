
#include "Particle.h"
using namespace std;


Particle::Particle(Vector2f position, float lifespan)
{
	shape = ParticleShape::Circle;
    size = 5.f;
    this->position = position;
    velocity = Vector2f(0, 1);
    this->lifespan = lifespan;
    alive = true;
    if (shape == ParticleShape::Circle) {
        body = CircleShape(size);
    }
    body.setRadius(size);

}

Particle::~Particle()
{
    cout << "Dead" << endl;
}

void Particle::Update()
{
    ageOfParticle++;
    position += velocity;
    body.setPosition(position);

}

void Particle::Render(RenderWindow& window)
{
    window.draw(body);
    cout << position.x << ", " << position.y << endl;
}


void Particle::SetVelocity(Vector2f velocity)
{
    this->velocity = velocity;
}


