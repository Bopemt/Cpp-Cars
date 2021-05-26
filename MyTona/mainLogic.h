#ifndef MAIN_LOGIC_H
#define MAIN_LOGIC_H

#include "spawner.h"

class MainLogic {
private:
	bool vertical = false;
	bool horizontal = false;
	Spawner spawner;

	template<typename T>
	void pop_front(std::vector<T>& vec);
	bool carIsOut(Car& car);
	bool isFirstCarsNear();

	void moveStartCars(float elapsedTime, std::vector<std::shared_ptr<Car>>& vCars);
	void moveCrossedCars(float elapsedTime);
	void movePassedCars(float elapsedTime);

public:
	MainLogic();
	void moveCars(float elapsedTime);
	void checkCarsCountAndSpawn();
	std::vector<std::shared_ptr<Car>>& getTopCars();
	std::vector<std::shared_ptr<Car>>& getBotCars();
	std::vector<std::shared_ptr<Car>>& getLeftCars();
	std::vector<std::shared_ptr<Car>>& getRightCars();
	std::vector<std::shared_ptr<Car>>& getCrossedCars();
	std::vector<std::shared_ptr<Car>>& getPassedCars();
};

#endif // !MAIN_LOGIC_H
