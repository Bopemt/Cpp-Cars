#include "constants.h"
namespace Constants
{
    extern const int screen_width = 1024;
    extern const int screen_height = 768;
    extern const float carSizeX = 100;
    extern const float carSizeY = 100;
    extern const float carSpeed = 60.f;
    extern const int maxCarsCount = 8;
    extern const int maxInitCarsCount = 4;
    extern const float offSet = 10;
    extern const sRect topPos(screen_width / 2 - carSizeX - offSet, 0, carSizeX, carSizeY);
    extern const sRect botPos(screen_width / 2 + offSet, screen_height - carSizeY, carSizeX, carSizeY);
    extern const sRect leftPos(0, screen_height / 2 + offSet, carSizeX, carSizeY);
    extern const sRect rightPos(screen_width - carSizeX, screen_height / 2 - carSizeY - offSet, carSizeX, carSizeY);
    extern const sRect crossRoadRect(screen_width / 2 - carSizeX - 2 * offSet, screen_height / 2 - carSizeY - 2 * offSet, 2 * carSizeX + 4 * offSet, 2 * carSizeY + 4 * offSet);
}
