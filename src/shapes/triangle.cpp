#include "point.hpp"
#include "shapes/triangle.hpp"
#include <iostream>
using namespace std;



Triangle::Triangle(Point P, Point Q, Point R) : A(P), B(Q), C(R) {}


double Triangle:: perimeter(){
    return A.distance(B)+ B.distance(C)+ C.distance(A); 
}

double Triangle:: area(){
    return 1/2*(A.x*(B.y-C.y)+B.x*(C.y-A.y)+C.x*(A.y-B.y));
}

Point Triangle:: center(){
    Point G;
    G.x = (A.x+B.x+C.x)/3; //formule de xG
    G.y = (A.y+B.y+C.y)/3; //formule de yG
    cout << "xG = " << G.x << " yG = " << G.y;
    //(brouillon) cout << "G( " << (A.x+B.x+C.x)/3 << "," << (A.y+B.y+C.y)/3 << ")";
    return G;
}




bool Triangle:: isEquilateral(){
    if (A.distance(B) == B.distance(C) and A.distance(B) == C.distance(A)){
        return true;
    }
    return false;
}


