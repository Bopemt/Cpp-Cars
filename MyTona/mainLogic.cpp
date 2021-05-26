#include "mainLogic.h"

template<typename T>
void MainLogic::pop_front(std::vector<T>& vec) {
    vec.erase(vec.begin());
}

bool MainLogic::carIsOut(Car& car)
{
    return (car.getX() + car.getW() < 0 || car.getX() > Constants::screen_width || car.getY() + car.getH() < 0 || car.getY() > Constants::screen_height);
}

bool MainLogic::isFirstCarsNear() {
    auto firstCars = spawner.getFirstCars();
    for (auto car : spawner.getFirstCars()) {
        if (car->rangeToRect(Constants::crossRoadRect) > Constants::carSizeX * 2)
            return false;
    }
    return true;
}

void MainLogic::checkCarsCountAndSpawn()
{
    if (spawner.vCarsTop.size() + spawner.vCarsBot.size() + spawner.vCarsLeft.size() + spawner.vCarsRight.size() + 
        spawner.vPassedCars.size() + spawner.vCrossedCars.size() < Constants::maxCarsCount)
        spawner.spawnCar();
}

void MainLogic::moveStartCars(float elapsedTime, std::vector<std::shared_ptr<Car>>& vCars)
{
    if (vCars.size() > 0) {
        if (vCars[0]->rangeToRect(Constants::crossRoadRect) > 0)
            vCars[0]->move(elapsedTime);
        else {
            auto firstCars = spawner.getFirstCars();
            auto dir = vCars[0]->getDir();
            if (firstCars.size() == 4 && isFirstCarsNear()) {
                switch (dir) {
                case eDirection::UP:
                case eDirection::DOWN:
                    if (!horizontal) {
                        vCars[0]->move(elapsedTime);
                        spawner.vCrossedCars.push_back(std::move(vCars[0]));
                        pop_front(vCars);
                        vertical = true;
                    }
                    break;
                case eDirection::LEFT:
                case eDirection::RIGHT:
                    if (!vertical) {
                        vCars[0]->move(elapsedTime);
                        spawner.vCrossedCars.push_back(std::move(vCars[0]));
                        pop_front(vCars);
                        horizontal = true;
                    }
                    break;
                }
            }
            else if (firstCars.size() > 0) {
                switch (dir) {
                case eDirection::UP:
                    if (!horizontal && (spawner.vCarsRight.size() == 0 ||
                        !(vCars[0]->needPassOtherCar(*spawner.vCarsRight[0], Constants::crossRoadRect)))) {
                        vCars[0]->move(elapsedTime);
                        spawner.vCrossedCars.push_back(std::move(vCars[0]));
                        pop_front(vCars);
                        vertical = true;
                    }
                    break;
                case eDirection::DOWN:
                    if (!horizontal && (spawner.vCarsLeft.size() == 0 ||
                        !(vCars[0]->needPassOtherCar(*spawner.vCarsLeft[0], Constants::crossRoadRect)))) {
                        vCars[0]->move(elapsedTime);
                        spawner.vCrossedCars.push_back(std::move(vCars[0]));
                        pop_front(vCars);
                        vertical = true;
                    }
                    break;
                case eDirection::LEFT:
                    if (!vertical && (spawner.vCarsTop.size() == 0 ||
                        !(vCars[0]->needPassOtherCar(*spawner.vCarsTop[0], Constants::crossRoadRect)))) {
                        vCars[0]->move(elapsedTime);
                        spawner.vCrossedCars.push_back(std::move(vCars[0]));
                        pop_front(vCars);
                        horizontal = true;
                    }
                    break;
                case eDirection::RIGHT:
                    if (!vertical && (spawner.vCarsBot.size() == 0 ||
                        !(vCars[0]->needPassOtherCar(*spawner.vCarsBot[0], Constants::crossRoadRect)))) {
                        vCars[0]->move(elapsedTime);
                        spawner.vCrossedCars.push_back(std::move(vCars[0]));
                        pop_front(vCars);
                        horizontal = true;
                    }
                    break;
                }
            }
        }
        if (vCars.size() >= 2) {
            for (auto car = vCars.begin() + 1; car < vCars.end(); car++) {
                if ((*car)->rangeToRect((*(car - 1))->getRect()) > Constants::offSet) {
                    (*car)->move(elapsedTime);
                }
            }
        }
    }
}
void MainLogic::moveCrossedCars(float elapsedTime) {
    auto cars = spawner.vCrossedCars;

    if (cars.size() > 0) {
        for (auto car = cars.begin(); car < cars.end(); car++) {
            (*car)->move(elapsedTime);
            if (!(*car)->isIntersects(Constants::crossRoadRect)) {
                if (cars.size() == 1)
                    switch ((*car)->getDir()) {
                    case eDirection::UP:
                    case eDirection::DOWN:
                        vertical = false;
                        break;
                    case eDirection::LEFT:
                    case eDirection::RIGHT:
                        horizontal = false;
                        break;
                    }
                spawner.vPassedCars.push_back(std::move(*car));
                pop_front(spawner.vCrossedCars);
            }
        }
    }
}

void MainLogic::movePassedCars(float elapsedTime) {
    auto cars = spawner.vPassedCars;
    for (auto car = cars.begin(); car < cars.end(); car++) {
        (*car)->move(elapsedTime);
        if (carIsOut(**car)) {
            pop_front(spawner.vPassedCars);
        }
    }
}

MainLogic::MainLogic()
{
    for (int _ = 0; _ < Constants::maxInitCarsCount; _++) {
        spawner.spawnCar();
    }
}

void MainLogic::moveCars(float elapsedTime)
{
    moveStartCars(elapsedTime, spawner.vCarsTop);
    moveStartCars(elapsedTime, spawner.vCarsBot);
    moveStartCars(elapsedTime, spawner.vCarsLeft);
    moveStartCars(elapsedTime, spawner.vCarsRight);
    moveCrossedCars(elapsedTime);
    movePassedCars(elapsedTime);
}

std::vector<std::shared_ptr<Car>>& MainLogic::getTopCars()
{
    return spawner.vCarsTop;
}

std::vector<std::shared_ptr<Car>>& MainLogic::getBotCars()
{
    return spawner.vCarsBot;
}

std::vector<std::shared_ptr<Car>>& MainLogic::getLeftCars()
{
    return spawner.vCarsLeft;
}

std::vector<std::shared_ptr<Car>>& MainLogic::getRightCars()
{
    return spawner.vCarsRight;
}

std::vector<std::shared_ptr<Car>>& MainLogic::getCrossedCars()
{
    return spawner.vCrossedCars;
}

std::vector<std::shared_ptr<Car>>& MainLogic::getPassedCars()
{
    return spawner.vPassedCars;
}
