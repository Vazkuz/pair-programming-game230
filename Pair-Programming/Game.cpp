#include "Game.h"
using namespace gm;
using namespace sf;

class GameObject {
private:
	Shape* shape;
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
	}
}

void Game::update(sf::RenderWindow& window) {
	std::cout << "update" << std::endl;
}

void Game::render(sf::RenderWindow& window) {
	window.clear();
	window.display();
}