#include "point.hpp"
#include "shapes/circle.hpp"
#include <cmath>
#include <vector>
#include "draw.hpp"

const double PI = 3.141592653589793;

Circle::Circle(double r, Point c) : radius(r), center(c) {};

double Circle::circumference(){
    return 2*PI*radius;
}

double Circle::area(){
    return PI*radius*radius;
}

void Circle::draw(){
    std::vector<Point> points;
    const int segments = 100; // nombre de points pour l'approximation du cercle

    for (size_t i = 0; i < segments; ++i) {
		double angle = 2 * PI * i / segments;
        double x = center.x + radius * std::cos(angle);
        double y = center.y + radius * std::sin(angle);
        points.emplace_back(x, y);
	}

    // On ferme le cerle en ajoutant le premier point à la fin
    points.push_back(points.front());

    draw_picture(points);
}

void Circle::translate(Point T){
    center.x += T.x;
    center.y += T.y;
}

void Circle::resize(double ratio){
    radius *= ratio;
}

bool Circle::equals(Circle circle){
    return radius == circle.radius && center.x == circle.center.x && center.y == circle.center.y;
}