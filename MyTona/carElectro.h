#ifndef CAR_ELECTRO_H
#define CAR_ELECTRO_H

#include "car.h"

class CarElectro : virtual public Car {
protected:
	float charge;
public:
	CarElectro(sRect _rect, eDirection _dir, float _speed, int _id, float _charge = 100.f)
		: Car(_rect, _dir, _speed, _id), charge(_charge) {}
	virtual ~CarElectro() {}
	virtual float getFuel() override;
	virtual void refill(float count) override;
	virtual void move(float elapsedTime) override;
};

#endif // !CAR_ELECTRO_H
