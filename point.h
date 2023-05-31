#ifndef POINT_H
#define POINT_H


// Forward declarations for the I/O lib
#include <iosfwd>

// Forward decl. of Point class
class Point;
// Forward declaration of operator<< function
std::ostream& operator<<(std::ostream&, const Point&);

///  Helper class for 2d points with some inlined methods
class Point {
private:
    int x, y;

public:
    Point(int px = 0, int py = 0) : x(px), y(py) {}

    void setValues(int px = 0, int py = 0) { x = px; y = py; }
    int setX(int px) { x = px; }
    int setY(int py) { y = py; }

    int getX() const { return x; }
    int getY() const { return y; }

    float length() const;

    Point& operator+=(const Point& other);
    Point& operator-=(const Point& other);
    Point operator+(const Point& other) const;
    Point operator-(const Point& other) const;
    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;
};

#endif // POINT_H
