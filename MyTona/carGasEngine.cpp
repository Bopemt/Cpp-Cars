#include "carGasEngine.h"

float CarGasEngine::getFuel() { return fuel; }
void CarGasEngine::refill(float count) { fuel += count; }
void CarGasEngine::move(float elapsedTime) {
	fuel--;
	Car::move(elapsedTime);
}