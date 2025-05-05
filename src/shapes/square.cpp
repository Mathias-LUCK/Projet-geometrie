#include "point.hpp"
#include "shapes/square.hpp"
#include <math.h>

Square::Square(Point P, Point R) : A(P), C(R) {};

double Square::side() {
    return (1/sqrt(2))*A.distance(C);
}