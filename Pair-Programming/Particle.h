//TEAM: Daniel M., Rohit P., Gabriel O.
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>

using namespace sf;

enum ParticleShape
{
    Circle,
    Triangle,

    Square


};

class Particle
{

private:
    ParticleShape shape;
    CircleShape body;

    float size;
    Vector2f position;
    Vector2f velocity;
    bool alive = false;

public:
    int ageOfParticle = 0;
    float lifespan;

    Particle(Vector2f position, float size, float lifespan = 60.f);
    ~Particle();

    void Update();


    void Render(RenderWindow& window);

    void SetVelocity(Vector2f velocity);

    
};

