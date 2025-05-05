#include "point.hpp"
#include "shapes/square.hpp"
#include <math.h>
#include <vector>
#include "draw.hpp"

Square::Square(Point P, Point R) : A(P), C(R) {};

Point Square::middle(Point P, Point Q) {
    return Point((A.x+C.x)/2, (A.y+C.y)/2);
}

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
    // Calcul du milieu de la diagonale
    Point M = middle(A, C);

    // Calcule du vecteur de la diagonale
    double vx = C.x - A.x;
    double vy = C.y - A.y;

    // Calcul des coordonnées du point B et du point D
    double bx = M.x - vy / 2;
    double by = M.y + vx / 2;
    double dx = M.x + vy / 2;
    double dy = M.y - vx / 2;
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

void Square::translate(Point T) {
    A.x += T.x;
    A.y += T.y;
    C.x += T.x;
    C.y += T.y;
    draw();
}

void Square::resize(double ratio) {
    Point M = middle(A, C);
    A.x = M.x - ratio * side() / 2;
    A.y = M.y - ratio * side() / 2;
    C.x = M.x + ratio * side() / 2;
    C.y = M.y + ratio * side() / 2;
    draw();
}

void Square::rotate(double angle) {
    double x = A.x;
    double y = A.y;
    A.x = x * cos(angle) - y * sin(angle);
    A.y = x * sin(angle) + y * cos(angle);
    x = C.x;
    y = C.y;
    C.x = x * cos(angle) - y * sin(angle);
    C.y = x * sin(angle) + y * cos(angle);
    draw();
}

bool Square::equals(Square square) {
    Point B, D, B_square, D_square;
    find_other_corner(A, C, B, D);
    find_other_corner(square.A, square.C, B_square, D_square);
    return (A.x == square.A.x && A.y == square.A.y && C.x == square.C.x && C.y == square.C.y) && (B.x == B_square.x && B.y == B_square.y && D.x == D_square.x && D.y == D_square.y);
}