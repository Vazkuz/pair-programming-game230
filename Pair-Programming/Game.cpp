#include "Game.h"
using namespace std;
using namespace gm;
using namespace sf;

class GameObject {
private:
	Shape* shape;
	ParticleEffect* pEffect;

public:
	GameObject(const Vector2f& position, float size) {
		shape = new CircleShape(size);
		shape->setPosition(position);
	}
	~GameObject() {
		delete shape;
		shape = nullptr;
	}

	void update(RenderWindow& window) {
		window.draw(*shape);
	}

	void render(RenderWindow& window) {
		window.clear();
		window.display();
	}

	ParticleEffect(const Vector2f& position) {
		pEffect = new ParticleEffect;
		pEffect->setPosition(position)
	}
};

Game::Game() {

}

Game::~Game() {

}

void Game::handleInput(sf::RenderWindow& window) {
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) {
			window.close();
		}

		if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
			cout << "Here goes the particle effect" << endl;
		}
	}
}

void Game::update(sf::RenderWindow& window) {
}

void Game::render(sf::RenderWindow& window) {
	window.clear();
	window.display();
}