#include "point.hpp"
#include "shapes/square.hpp"
#include <math.h>
#include <vector>
#include "draw.hpp"

Square::Square(Point P, Point R) : A(P), C(R) {};

double Square::side() {
    return (1/sqrt(2))*A.distance(C);
}

double Square::perimeter() {
    return 4*side();
}

double Square::area() {
    return side()*side();
}

Point Square::center() {
    return Point((A.x+C.x)/2, (A.y+C.y)/2);
}

void Square::find_other_corner(Point P, Point Q, Point &R, Point &S) {
    double mx = (A.x + C.x) / 2;
    double my = (A.y + C.y) / 2;

    double vx = C.x - A.x;
    double vy = C.y - A.y;

    double bx = mx - vy / 2;
    double by = my + vx / 2;

    double dx = mx + vy / 2;
    double dy = my - vx / 2;

    R = Point(bx, by);
    S = Point(dx, dy);
}

void Square::draw() {
    // Calcul des coordonnées des autres points
    Point B, D;
    find_other_corner(A, C, B, D);
    std::vector<Point> points = {A, B, C, D, A};
    draw_picture(points);
}