#include "point.hpp"
#include "shapes/circle.hpp"
#define _USE_MATH_DEFINES
#include <cmath>

Circle::Circle(double r, Point c) : radius(r), center(c) {};

double Circle::circumference(){
    return 2*M_PI*radius;
}

double Circle::area(){
    return M_PI*radius*radius;
}

/*void Circle::draw(){
    for (size_t i = 1; i < 360 ; ++i) {
		t.setposition(points[i].x, points[i].y);
	}
}*/