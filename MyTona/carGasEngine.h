#ifndef CAR_GAS_ENGINE_H
#define CAR_GAS_ENGINE_H

#include "car.h"

class CarGasEngine : virtual public Car {
protected:
	float fuel;
public:
	CarGasEngine(sRect _rect, eDirection _dir, float _speed, int _id,float _fuel = 100.f)
		: Car(_rect, _dir, _speed, _id), fuel(_fuel) {}
	virtual ~CarGasEngine() {}
	virtual float getFuel() override;
	virtual void refill(float count) override;
	virtual void move(float elapsedTime) override;
};

#endif // !CAR_GAS_ENGINE_H