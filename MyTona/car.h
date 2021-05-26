#ifndef CAR_H
#define CAR_H

#include "sRect.h"

enum class eDirection {
    UP, LEFT, RIGHT, DOWN
};

class Car {
protected:
    sRect rect;
    const eDirection dir;
    float speed;
    int id;

public:
    Car(sRect _rect, eDirection _dir, float _speed, int _id = 0)
        : rect(_rect), dir(_dir),id(_id), speed(_speed) {}
    virtual ~Car() {}
    bool needPassOtherCar(const Car& otherCar, const sRect& crossRoad);
    float rangeToRect(const sRect& rect);
    bool isIntersects(const sRect& rect);
    virtual void move(const float elapsedTime);

    float getX() { return rect.pos.x; }
    float getY() { return rect.pos.y; }
    float getW() { return rect.size.width; }
    float getH() { return rect.size.height; }
    int getID() { return id; }
    eDirection getDir() { return dir; }
    sRect& getRect() { return rect; }

    virtual float getFuel() = 0;
    virtual void refill(float count) = 0;
};

#endif // !CAR_H
