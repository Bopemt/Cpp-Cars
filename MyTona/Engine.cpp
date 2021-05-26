#include "Engine.h"

Engine::Engine()
{
    window.create(sf::VideoMode(Constants::screen_width, Constants::screen_height), "SFML Works!");
}

void Engine::update(float dtAsSeconds)
{
    mainLogic.moveCars(dtAsSeconds);
    mainLogic.checkCarsCountAndSpawn();
}

void Engine::drawCars(std::vector<std::shared_ptr<Car>> &vCars) {
    for (auto& car : vCars) {

        sf::RectangleShape rectangle(sf::Vector2f(car->getW(), car->getH()));
        rectangle.move(car->getX(), car->getY());

        rectangle.setFillColor(sf::Color(175, 180, 240));

        window.draw(rectangle);
    }
}

void Engine::draw()
{
    window.clear(sf::Color::White);

    drawCars(mainLogic.getTopCars());
    drawCars(mainLogic.getBotCars());
    drawCars(mainLogic.getLeftCars());
    drawCars(mainLogic.getRightCars());
    drawCars(mainLogic.getCrossedCars());
    drawCars(mainLogic.getPassedCars());

    window.display();
}

void Engine::start()
{
    sf::Clock clock;
    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Time dt = clock.restart();

        float dtAsSeconds = dt.asSeconds();

        update(dtAsSeconds);
        draw();
    }
}
