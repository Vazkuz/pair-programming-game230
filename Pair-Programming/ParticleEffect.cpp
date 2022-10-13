#include "ParticleEffect.h"
using namespace sf;

enum ParticleShape
{
    Circle,
    Triangle,
    Squar
};

class Particle
{
private:
    ParticleShape shape;
    sf::CircleShape body;
    int size;
    sf::Vector2f position;
    sf::Vector2f velocity;
    short lifespan;
    bool alive = false;
public:
    Particle()
    {
        shape = ParticleShape::Circle;
        size = 40;
        position = sf::Vector2f(400, 0);
        velocity = sf::Vector2f(0, 1);
        lifespan = 200;
        alive = true;
        body.setRadius(size);
        body.setPosition(position);
    }
    void update()
    {
    }
    void render(RenderWindow& window)
    {
        //body.
    }
    void SetVelocity(sf::Vector2f newVelocity) {
        velocity = newVelocity;
    }
};

// Global Variables
const int ARRAY_LENGTH = 10;
Particle* particleArray[ARRAY_LENGTH];

ParticleEffect::ParticleEffect() {
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        *(particleArray + i) = nullptr;
    }
}

ParticleEffect::~ParticleEffect() {
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        delete *(particleArray + i);
        *(particleArray + i) = nullptr;
    }
    delete[] particleArray;
}

void ParticleEffect::Update() {
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        particleArray[i]->update();
    }
}

void ParticleEffect::Render(RenderWindow& window) {
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        particleArray[i]->render(window);
    }
}

//creates a new particle for every element of the particles array
void ParticleEffect::Emit() {
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        *(particleArray + i) = new Particle();
    }
}

// adds a new particle at the specified index in the particles 
// array (it should also randomize the particle velocity in some way)
void ParticleEffect::AddParticle(int index) {
    if (particleArray[index] != nullptr) {
        delete particleArray[index];
    }
    particleArray[index] = new Particle();
    int randX = rand() % 200 + 1;
    int randY = rand() % 200 + 1;
    sf::Vector2f randomVelocity = sf::Vector2f(randX, randY);
    particleArray[index]->SetVelocity(randomVelocity);
}