#ifndef SPAWNER_H
#define SPAWNER_H

#include <vector>
#include <memory>

#include "carHybrid.h"
#include "constants.h"

class Spawner {
private:
	std::shared_ptr<Car> getRandomEngine(const sRect& _rect, const eDirection _dir);
	void spawnCarFromTop();
	void spawnCarFromRight();
	void spawnCarFromBot();
	void SpawnCarFromLeft();

public:
	std::vector<std::shared_ptr<Car>> vCarsTop, vCarsBot, vCarsLeft, vCarsRight, vPassedCars, vFirstCars, vCrossedCars;
	void spawnCar();

	std::vector<std::shared_ptr<Car>>& getFirstCars();
};

#endif // !SPAWNER_H
