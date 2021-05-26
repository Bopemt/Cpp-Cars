#include "carHybrid.h"

float CarHybrid::getFuel()
{
	return 0;
}

void CarHybrid::refill(float count)
{
	charge += count / 2;
	fuel += count / 2;
}

void CarHybrid::move(float elapsedTime)
{
    if (change)
        CarElectro::move(elapsedTime);
    else
        CarGasEngine::move(elapsedTime);
    change = !change;
}
