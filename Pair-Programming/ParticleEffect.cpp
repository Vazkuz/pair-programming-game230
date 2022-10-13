#include "ParticleEffect.h"
#include "Particle.h"
using namespace sf;

// Global Variables
const int ARRAY_LENGTH = 20;
Particle* particleArray[ARRAY_LENGTH];



ParticleEffect::ParticleEffect(Vector2f position)
{
    this->position = position;

    for (int i = 0; i < ARRAY_LENGTH; i++) {
        *(particleArray + i) = nullptr;
    }
}


ParticleEffect::~ParticleEffect() {
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        delete (particleArray + i);
        *(particleArray + i) = nullptr;
    }
    delete[] particleArray;
}

void ParticleEffect::Update() {
    particlesAlive = 0;
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        if (particleArray[i]) {
            particleArray[i]->Update();
            particlesAlive++;
            if (particleArray[i]->ageOfParticle > particleArray[i]->lifespan) {
                particleArray[i]->~Particle();
                particleArray[i] = nullptr;
                particlesAlive--;
            }
        }
    }
}

void ParticleEffect::Render(RenderWindow& window) {
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        if (particleArray[i]) {
            particleArray[i]->Render(window);
        }
    }
}

//creates a new particle for every element of the particles array
void ParticleEffect::Emit() {
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        particleArray[i] = new Particle(this->position);
        int randX = rand() % 10 - 5;
        int randY = rand() % 10 - 5;
        sf::Vector2f randomVelocity = sf::Vector2f(randX, randY);
        particleArray[i]->SetVelocity(randomVelocity);
    }
}

// adds a new particle at the specified index in the particles 
// array (it should also randomize the particle velocity in some way)
void ParticleEffect::AddParticle(int index) {
    if (particleArray[index] != nullptr) {
        delete particleArray[index];
    }
    particleArray[index] = new Particle(this->position);
    int randX = rand() % 200 + 1;
    int randY = rand() % 200 + 1;
    sf::Vector2f randomVelocity = sf::Vector2f(randX, randY);
    particleArray[index]->SetVelocity(randomVelocity);
}