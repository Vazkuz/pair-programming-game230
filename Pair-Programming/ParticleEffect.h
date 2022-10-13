#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>

class ParticleEffect
{
public:
	ParticleEffect();
	~ParticleEffect();
	void Update();
	void Render();

	//creates a new particle for every element of the particles array
	void Emit();

	// adds a new particle at the specified index in the particles 
	// array (it should also randomize the particle velocity in some way)
	void AddParticle();
};

