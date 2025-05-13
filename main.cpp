#include "draw.hpp"
#include "point.hpp"
#include "shapes.hpp"
#include <vector>
#include <assert.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;

bool equals(double a, double b) {
	if (a*0.99999 < b && a*1.00001 > b && b*0.99999 < a && b*1.00001 > a) { return true; }
	else { return false; }
}
int main() {
	
	// Define points in a vector
	std::vector<Point> points = {
		Point(0, 0),
		Point(100, 0),
		Point(100, 100),
		Point(0, 100),
		Point(0, 0)
		
	};
	
	////////////////////////////// Tests /////////////////////////////////
	// Tests distance
	assert(points.at(0).distance(points.at(1)) == 100);
	assert(points.at(1).distance(points.at(2)) == 100);
	assert( equals( points.at(0).distance(points.at(2)), sqrt(100*100 + 100*100) ) );
	
	// Tests square 
	Square square(points.at(0), points.at(3));
	assert( equals( square.side(), sqrt(50*50+50*50) ) );
	assert( equals( square.perimeter(), 4*sqrt(50*50+50*50) ) );
	assert( equals( square.area(), 50*50+50*50) );
	assert(square.center().x == 0);
	assert(square.center().y == 50);
	square.translate(Point(100, 0));
	assert(square.center().x == 100);
	assert(square.center().y == 50);
	assert(square.equals(square));

	Square square2(points.at(0), points.at(2));
	assert( equals( square2.side(), 100) ) ;
	assert( equals( square2.perimeter(), 4*100 ) );
	assert( equals( square2.area(), 100*100) );
	assert(square2.center().x == 50);
	assert(square2.center().y == 50);
	square2.resize(0.5);

	assert(square2.center().x == 50 && square2.center().y == 50);
	assert( equals( square2.perimeter(), 2*100 ) );
	assert( equals( square2.area(), 50*50) );
	square2.resize(2);
	square2.rotate(M_PI/2);
	assert( equals( square2.side(), 100) ) ;
	assert( equals( square2.perimeter(), 4*100 ) );
	assert( equals( square2.area(), 100*100) );
	assert(square2.center().x == 50 && square2.center().y == 50);
	assert( square2.A.x == 100 && square2.A.y == 0);
	assert( square2.C.x == 0 && square2.C.y == 100);

	Circle in_circle = square2.inscribedCircle();
	assert(in_circle.radius == 50);
	assert(in_circle.center.x == 50 && in_circle.center.y == 50);

	Square square3 = Square(Point(0, 0), Point(100, 100));
	Circle out_circle = square2.circumscribedCircle();
	assert(out_circle.radius == 50*sqrt(2));
	assert(out_circle.center.x == 50 && in_circle.center.y == 50);
	cout << "All square tests passed!" << endl;

	// Tests Circle
    Circle circle(50, Point(10, 10));
    assert(equals(circle.radius, 50));
    assert(equals(circle.circumference(), 2*M_PI*50));
    assert(equals(circle.area(), M_PI*50*50));
    assert(circle.center.x == 10);
    assert(circle.center.y == 10);

    // Test circle translation
    circle.translate(Point(10, 10));
    assert(circle.center.x == 20);
    assert(circle.center.y == 20);
    assert(equals(circle.radius, 50));
    assert(equals(circle.circumference(), 2*M_PI*50));
    assert(equals(circle.area(), M_PI*50*50));

    // Test circle resize
    circle.resize(2);
    assert(equals(circle.radius, 100));
    assert(equals(circle.area(), M_PI*100*100));
    assert(equals(circle.circumference(), 2*M_PI*100));
    assert(circle.center.x == 20); // Center should remain the same
    assert(circle.center.y == 20);

    // Test circle equals
    Circle circle2(100, Point(20, 20));
    assert(circle.equals(circle2));
    Circle circle3(90, Point(10, 20));
    assert(!circle.equals(circle3));

    circle.draw();
	cout << "All circle tests passed!" << endl;

	/*
	// Tests Triangle
    Triangle triangle(Point(0, 0), Point(100, 0), Point(50, 100));
    assert(equals(triangle.perimeter(), 100 + 2 * sqrt(50*50 + 100*100)));
    assert(equals(triangle.area(), 0.5 * 100 * 100));

    // Test triangle center
    Point center = triangle.center();
    assert(equals(center.x, 50));
    assert(equals(center.y, 100/3.0));

	Triangle triangle2(Point(0, 0), Point(0, 100), Point(-50, 50));
	assert(equals(triangle.perimeter(), 100 + 2 * sqrt(2*50*50)));
    assert(equals(triangle.area(), 0.5 * 100 * 100));

    // Test triangle translation
    triangle.translate(Point(10, 10));
    assert(equals(triangle.A.x, 10));
    assert(equals(triangle.A.y, 10));
    assert(equals(triangle.B.x, 110));
    assert(equals(triangle.B.y, 10));
    assert(equals(triangle.C.x, 60));
    assert(equals(triangle.C.y, 110));

    // Test triangle resize
    Triangle triangle2(Point(0, 0), Point(100, 0), Point(50, 100));
    Point originalCenter = triangle2.center();
    triangle2.resize(0.5);
    assert(equals(triangle2.area(), 0.5 * 0.5 * 0.5 * 100 * 100));
    Point newCenter = triangle2.center();
    assert(equals(originalCenter.x, newCenter.x));
    assert(equals(originalCenter.y, newCenter.y));

    // Test triangle rotation
    Triangle triangle3(Point(0, 0), Point(100, 0), Point(50, 100));
    Point centerBefore = triangle3.center();
    triangle3.rotate(M_PI/2); // 90 degrees
    Point centerAfter = triangle3.center();
    assert(equals(centerBefore.x, centerAfter.x));
    assert(equals(centerBefore.y, centerAfter.y));

    // Test triangle equals
    Triangle triangle4(Point(0, 0), Point(100, 0), Point(50, 100));
    assert(triangle4.equals(triangle4));
    Triangle triangle5(Point(0, 0), Point(100, 0), Point(50, 90));
    assert(!triangle4.equals(triangle5));

    // Test triangle properties
    Triangle rightTriangle(Point(0, 0), Point(100, 0), Point(0, 100));
    assert(rightTriangle.isRightAngled());
    assert(!rightTriangle.isEquilateral());
    assert(!rightTriangle.isIsoceles());

    Triangle equilateralTriangle(Point(0, 0), Point(100, 0), Point(50, 50*sqrt(3)));
    assert(!equilateralTriangle.isRightAngled());
    assert(equilateralTriangle.isEquilateral());
    assert(equilateralTriangle.isIsoceles());

    Triangle isoscelesTriangle(Point(0, 0), Point(100, 0), Point(50, 100));
    assert(!isoscelesTriangle.isRightAngled());
    assert(!isoscelesTriangle.isEquilateral());
    assert(isoscelesTriangle.isIsoceles());
	*/

	// Draw the picture by connecting the points
	// draw_picture(points);
	cout << "All tests passed!" << endl;
	
	return 0;
}
