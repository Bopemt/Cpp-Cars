#ifndef CAR_HYBRID
#define CAR_HYBRID

#include "carElectro.h"
#include "carGasEngine.h"

class CarHybrid : public CarElectro, CarGasEngine {
private:
	bool change = false;
public:
	CarHybrid(
		sRect _rect, eDirection _dir, 
		float _speed, int _id, float _fuel = 100.f, float _charge = 100.f
	) 
		: Car(_rect, _dir, _speed, _id), CarElectro(_rect, _dir, _speed, _id), 
				CarGasEngine(_rect, _dir, _speed, _id) {}

	virtual float getFuel() override;
	virtual void refill(float count) override;
	virtual void move(float elapsedTime) override;
};

#endif // !CAR_HYBRID
