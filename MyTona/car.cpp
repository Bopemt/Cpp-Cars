#include "car.h"

void Car::move(const float elapsedTime) {
    switch (dir) {
    case eDirection::UP:
        rect.pos.y -= speed * elapsedTime;
        break;
    case eDirection::DOWN:
        rect.pos.y += speed * elapsedTime;
        break;
    case eDirection::RIGHT:
        rect.pos.x += speed * elapsedTime;
        break;
    case eDirection::LEFT:
        rect.pos.x -= speed * elapsedTime;
        break;
    }
}

bool Car::needPassOtherCar(const Car& otherCar, const sRect &crossRoad) {
    auto otherdir = otherCar.dir;
    switch (dir) {
    case eDirection::UP:
        if (otherdir == eDirection::LEFT && rangeToRect(crossRoad) < otherCar.rect.size.height)
            return true;
    case eDirection::DOWN:
        if (otherdir == eDirection::RIGHT && rangeToRect(crossRoad) < otherCar.rect.size.height)
            return true;
    case eDirection::RIGHT:
        if (otherdir == eDirection::UP && rangeToRect(crossRoad) < otherCar.rect.size.width)
            return true;
    case eDirection::LEFT:
        if (otherdir == eDirection::DOWN && rangeToRect(crossRoad) < otherCar.rect.size.width)
            return true;
    }
    return false;
}

float Car::rangeToRect(const sRect& rect)
{
    switch (dir) {
    case eDirection::UP:
        return getY() - rect.pos.y - rect.size.height;
    case eDirection::DOWN:
        return rect.pos.y - getY() - getW();
    case eDirection::RIGHT:
        return rect.pos.x - getX() - getH();
    case eDirection::LEFT:
        return getX() - rect.pos.x - rect.size.width;
    }
}

bool Car::isIntersects(const sRect& rect)
{
    return !((rect.pos.x + rect.size.width <= getX()) || (rect.pos.x >= getX() + getW()) ||
             (rect.pos.y + rect.size.height <= getY()) || (rect.pos.y >= getY() + getH()) );
}
