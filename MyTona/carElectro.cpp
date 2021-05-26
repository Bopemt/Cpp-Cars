#include "carElectro.h"

float CarElectro::getFuel() { return charge; }
void CarElectro::refill(float count) { charge += count; }

void CarElectro::move(float elapsedTime) {
	charge--;
	Car::move(elapsedTime);
}
