#include "point.hpp"
#include "shapes/square.hpp"
#include <math.h>
#include <vector>
#include "draw.hpp"

Square::Square(Point P, Point R) : A(P), C(R) {};

Point Square::middle(Point P, Point Q) {
  return Point((P.x + Q.x) / 2, (P.y + Q.y) / 2);
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
    Point M = middle(P, Q);

    // Calcule du vecteur de la diagonale
    double vx = Q.x - P.x;
    double vy = Q.y - P.y;

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
}

void Square::resize(double ratio) {
  Point M = center();
  auto scalePt = [&](Point& P){
    P.x = M.x + ratio * (P.x - M.x);
    P.y = M.y + ratio * (P.y - M.y);
  };
  scalePt(A);
  scalePt(C);
}

void Square::rotate(double angle) {
  Point M = center();
  double s = sin(angle), c = cos(angle);
  auto rotatePt = [&](Point& P){
    double dx = P.x - M.x, dy = P.y - M.y;
    double x_new = dx * c - dy * s;
    double y_new = dx * s + dy * c;
    P.x = M.x + x_new;
    P.y = M.y + y_new;
  };
  rotatePt(A);
  rotatePt(C);
}

bool Square::equals(Square square) {
  Point B, D, B_square, D_square;
  Square square90 = square;
  square90.rotate(90);
  Square square180 = square;
  square180.rotate(180);
  Square square270 = square;
  square270.rotate(270);
  // vérifie si les points définissant les diagonales sont identiques
  return (A.x == square.A.x && A.y == square.A.y && C.x == square.C.x && C.y == square.C.y) || (A.x == square90.A.x && A.y == square90.A.y && C.x == square90.C.x && C.y == square90.C.y) || (A.x == square180.A.x && A.y == square180.A.y && C.x == square180.C.x && C.y == square180.C.y) || (A.x == square270.A.x && A.y == square270.A.y && C.x == square270.C.x && C.y == square270.C.y);
}

Circle Square::inscribedCircle() {
    // Calcul du rayon (côté / 2)
    double r = side() / 2;
    Point centerPoint = center();
    return Circle(r, centerPoint);
}

Circle Square::circumscribedCircle() {
    // Calcul du rayon (diagonal / 2)
    double r = A.distance(C) / 2;
    Point centerPoint = center();
    return Circle(r, centerPoint);
}