#ifndef ENGINE_H
#define ENGINE_H

#include "mainLogic.h"

#include <SFML/Graphics.hpp>

class Engine {
private:
	sf::RenderWindow window;
	MainLogic mainLogic;

	void update(float dtAsSeconds);
	void drawCars(std::vector<std::shared_ptr<Car>> &vCars);
	void draw();

public:
	Engine();
	void start();
};

#endif // !ENGINE_H
