#include "point.hpp"
#include "shapes/circle.hpp"
#include <cmath>

Circle::Circle(double r, Point c) : radius(r), center(c) {};

double Circle::circumference(){
    return 2*M_PI*radius.distance(center);
}

double Circle::area(){
    return M_PI*radius.distance(center)*radius.distance(center)
}

void Circle::draw(){
    
}