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
	
	assert(points.at(0).distance(points.at(1)) == 100);
	assert(points.at(1).distance(points.at(2)) == 100);
	assert( equals( points.at(0).distance(points.at(2)), sqrt(100*100 + 100*100) ) );

	// Draw the picture by connecting the points
	// draw_picture(points);
	cout << "All tests passed!" << endl;
	
	return 0;
}
