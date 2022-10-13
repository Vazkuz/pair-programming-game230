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
    Squar

};

class Particle
{

private:
    ParticleShape shape;
    CircleShape body;
    int size;
    Vector2f position;
    Vector2f velocity;
    short lifespan;
    bool alive = false;

    Particle();
    ~Particle();

    void Update();

    void render(RenderWindow& window);
    
};

