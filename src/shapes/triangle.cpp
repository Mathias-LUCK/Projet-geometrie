#include "point.hpp"
#include "shapes/triangle.hpp"
#include <vector>
#include "draw.hpp"
#include <cmath>
#include <iostream>
using namespace std;

Triangle::Triangle(Point P, Point Q, Point R) : A(P), B(Q), C(R) {}

double Triangle::perimeter(){
    return A.distance(B)+ B.distance(C)+ C.distance(A); 
}

double Triangle::area(){
    double p = perimeter()/2;
    return sqrt(p*(p-A.distance(B))*(p-B.distance(C))*(p-C.distance(A)));
}

Point Triangle::center(){
    Point G;
    G.x = (A.x+B.x+C.x)/3; //formule de xG
    G.y = (A.y+B.y+C.y)/3; //formule de yG
    return G;
}

void Triangle::draw(){
    std::vector<Point> points = {A,B,C,A};
    draw_picture(points);
}

void Triangle::translate(Point T){
    A.x += T.x;
    A.y += T.y;
    B.x += T.x;
    B.y += T.y;
    C.x += T.x;
    C.y += T.y;
}

void Triangle::resize(double ratio) {
  Point M = center();
  auto scalePt = [&](Point& P){
    P.x = M.x + ratio * (P.x - M.x);
    P.y = M.y + ratio * (P.y - M.y);
  };
  scalePt(A);
  scalePt(B);
  scalePt(C);
}

void Triangle::rotate(double angle) {
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
  rotatePt(B);
  rotatePt(C);
}

bool Triangle::isEquilateral(){
    if (A.distance(B) == B.distance(C) and A.distance(B) == C.distance(A)){
        return true;
    }
    return false;
}

bool Triangle::isRightAngled(){
    if (A.distance(B) * A.distance(B) + B.distance(C) * B.distance(C) == C.distance(A) * C.distance(A)){
        return true;
    }
    if (A.distance(B) * A.distance(B) + C.distance(A) * C.distance(A) == B.distance(C) * B.distance(C)){
        return true;
    }
    if (B.distance(C) * B.distance(C) + C.distance(A) * C.distance(A) == A.distance(B) * A.distance(B)){
        return true;
    }
    return false;
}

bool Triangle::equals(Triangle triangle){
    return A.x == triangle.A.x && A.y == triangle.A.y && B.x == triangle.B.x && B.y == triangle.B.y && C.x == triangle.C.x && C.y == triangle.C.y;
}

Circle Triangle::inscribedCircle(){
    double rayon = area() / perimeter();
    Point centerPoint = center();
    return Circle(rayon, centerPoint);
}

Circle Triangle::circumscribedCircle(){
    double s = perimeter() / 2;
    double rayon = A.distance(B) * B.distance(C) * C.distance(A) / (4 * area());
    Point centerPoint;
    centerPoint.x = (B.distance(C) * B.distance(C) + C.distance(A) * C.distance(A) - A.distance(B) * A.distance(B)) / 2 * B.distance(C);
    centerPoint.y = (A.distance(B) * A.distance(B) + C.distance(A) * C.distance(A) - B.distance(C) * B.distance(C)) / 2 * A.distance(B);
    return Circle(rayon, centerPoint);
}