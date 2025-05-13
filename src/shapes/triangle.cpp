#include "point.hpp"
#include "shapes/triangle.hpp"
#include <iostream>
using namespace std;

Triangle::Triangle(Point P, Point Q, Point R) : A(P), B(Q), C(R) {}

double Triangle::perimeter(){
    return A.distance(B)+ B.distance(C)+ C.distance(A); 
}

double Triangle::area(){
    return 1/2*(A.x*(B.y-C.y)+B.x*(C.y-A.y)+C.x*(A.y-B.y));
}

Point Triangle:: center(){
    Point G;
    G.x = (A.x+B.x+C.x)/3; //formule de xG
    G.y = (A.y+B.y+C.y)/3; //formule de yG
    return G;
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

bool Triangle::isEquilateral(){
    if (A.distance(B) == B.distance(C) and A.distance(B) == C.distance(A)){
        return true;
    }
    return false;
}


