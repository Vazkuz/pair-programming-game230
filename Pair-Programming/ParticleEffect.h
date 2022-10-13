#pragma once
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

