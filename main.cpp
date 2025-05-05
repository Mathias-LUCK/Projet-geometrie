#include "draw.hpp"
#include "point.hpp"
#include "shapes.hpp"
#include <vector>
#include <assert.h>
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

	Square square2(points.at(0), points.at(2));
	assert( equals( square2.side(), sqrt(100) ) );
	assert( equals( square2.perimeter(), 4*sqrt(100) ) );
	assert( equals( square2.area(), 100*100) );
	assert(square2.center().x == 50);
	assert(square2.center().y == 50);

	
	// Tests triangle
	Triangle triangle(points.at(0), points.at(1), points.at(2));
	assert(triangle.perimeter() == 300);
	assert(triangle.area() == 10000);
	assert(triangle.center().x == 50);
	assert(triangle.center().y == 50);

	// Draw the picture by connecting the points
	// draw_picture(points);
	cout << "All tests passed!" << endl;
	
	return 0;
}
