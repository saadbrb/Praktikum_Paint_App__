#include <iostream>
#include <cmath>
#include "point.h"

std::ostream& operator<<(std::ostream& os, const Point& pnt) {
    os << "( " << pnt.getX() << ", " << pnt.getY() << ")";
    return os;
}

float Point::length() const {
    return sqrt(x * x + y * y);
}

Point& Point::operator+=(const Point& other) {
    x += other.x;
    y += other.y;
    return *this;
}

Point& Point::operator-=(const Point& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Point Point::operator+(const Point& other) const {
    Point pnt(*this);
    pnt.x += other.x;
    pnt.y += other.y;
    return pnt;
}

Point Point::operator-(const Point& other) const {
    Point pnt(*this);
    pnt.x -= other.x;
    pnt.y -= other.y;
    return pnt;
}

bool Point::operator==(const Point& other) const {
    return (x == other.x) && (y == other.y);
}

//bool Point::operator!=(const Point& other) const {
//    return !(*this  ==  other);
//}
