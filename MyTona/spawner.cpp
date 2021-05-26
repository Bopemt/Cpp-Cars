#include "spawner.h"

int generateID()
{
    static int s_id = 0;
    return ++s_id;
}

void Spawner::spawnCar() {
    if (rand() % 4 == 1) spawnCarFromBot();
    else if (rand() % 4 == 2) spawnCarFromTop();
    else if (rand() % 4 == 3) spawnCarFromRight();
    else SpawnCarFromLeft();
}

std::shared_ptr<Car> Spawner::getRandomEngine(const sRect& _rect, const eDirection _dir) {
    int carType = rand();
    if (carType % 3 == 0) {
        return std::make_shared<CarGasEngine>(_rect, _dir, Constants::carSpeed, generateID());
    }
    else if (carType % 3 == 1) {
        return std::make_shared<CarElectro>(_rect, _dir, Constants::carSpeed, generateID());
    }
    else {
        return std::make_shared<CarHybrid>(_rect, _dir, Constants::carSpeed, generateID());
    }
}

void Spawner::spawnCarFromTop() {
    if (vCarsTop.size() == 0 || !(vCarsTop.back()->isIntersects(Constants::topPos))) {
        vCarsTop.push_back(std::move(getRandomEngine(Constants::topPos, eDirection::DOWN)));
    }
}

void Spawner::spawnCarFromBot() {
    if (vCarsBot.size() == 0 || !(vCarsBot.back()->isIntersects(Constants::botPos))) {
        vCarsBot.push_back(std::move(getRandomEngine(Constants::botPos, eDirection::UP)));
    }
}

void Spawner::SpawnCarFromLeft() {
    if (vCarsLeft.size() == 0 || !(vCarsLeft.back()->isIntersects(Constants::leftPos))) {
        vCarsLeft.push_back(std::move(getRandomEngine(Constants::leftPos, eDirection::RIGHT)));
    }
}

void Spawner::spawnCarFromRight() {
    if (vCarsRight.size() == 0 || !(vCarsRight.back()->isIntersects(Constants::rightPos))) {
        vCarsRight.push_back(std::move(getRandomEngine(Constants::rightPos, eDirection::LEFT)));
    }
}

std::vector<std::shared_ptr<Car>>& Spawner::getFirstCars()
{
    vFirstCars.clear();
    if (vCarsTop.size()) vFirstCars.push_back(vCarsTop[0]);
    if (vCarsBot.size()) vFirstCars.push_back(vCarsBot[0]);
    if (vCarsLeft.size()) vFirstCars.push_back(vCarsLeft[0]);
    if (vCarsRight.size()) vFirstCars.push_back(vCarsRight[0]);
    return vFirstCars;
}
