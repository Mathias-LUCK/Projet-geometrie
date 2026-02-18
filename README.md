# 2D Geometric Shapes Library in C++

## Description and Objective
This project is a simple C++ library for creating and manipulating basic 2D geometric shapes. It allows for the definition of points, circles, triangles, and squares, calculating their properties (area, perimeter, center, etc.), performing geometric transformations (translation, rotation, resizing), and checking some of their specific characteristics.

The main objective is to provide a set of clear and tested classes for common geometric operations.

## Main Data Structures

### Point
Represents a point in a 2D plane with `x` and `y` coordinates.
- `distance(Point p)`: Calculates the distance to another point.
- `equals(Point B)` : Verifies that the point is equal to Point B.

### Circle
Defined by a `radius` and a `Point center`.
- `circumference()`: Calculates the circumference.
- `area()`: Calculates the area.
- `translate(Point T)`: Moves the circle.
- `resize(double ratio)`: Modifies the circle's size while keeping the center fixed.
- `equals(Circle c)`: Compares with another circle.

### Triangle
Defined by three `Points` (A, B, C).
- `perimeter()`: Calculates the perimeter.
- `area()`: Calculates the area.
- `center()`: Calculates the center of gravity.
- `translate(Point T)`, `resize(double ratio)`, `rotate(double angle)`: Transformations.
- `isRightAngled()`, `isEquilateral()`, `isIsosceles()`: Checks properties.
- `inscribedCircle()`, `circumscribedCircle()`: Calculates the inscribed and circumscribed circles.

### Square
Defined by two opposite `Point`s (A, C).
- `side()`, `perimeter()`, `area()`: Calculates dimensions and area.
- `center()`: Calculates the center of the square.
- `translate(Point T)`, `resize(double ratio)`, `rotate(double angle)`: Transformations.
- `inscribedCircle()`, `circumscribedCircle()`: Calculates the inscribed and circumscribed circles.

## Project Structure
The project is organized with the following files:
- `point.hpp`, `point.cpp`: Definition and implementation of the `Point` structure.
- `circle.hpp`, `circle.cpp`: Definition and implementation of the `Circle` structure.
- `triangle.hpp`, `triangle.cpp`: Definition and implementation of the `Triangle` structure.
- `square.hpp`, `square.cpp`: Definition and implementation of the `Square` structure.
- `draw.hpp`, `draw.cpp`: Utility functions for drawing shapes.
- `shapes.hpp`: Main header file grouping all shapes for easy inclusion.
- `main.cpp`: Main program serving as an entry point, containing usage examples and unit tests.

## Dependencies
- Standard C++ library (`iostream`, `vector`, `cmath` for `sqrt` and `M_PI`, `assert.h`).
- No major external dependencies are required.

## Compilation and Execution

### Compile
To compile the project (and the tests included in `main.cpp`), use a g++ command similar to this one from the project root:
```bash
g++ -std=c++23 -Iinclude -o main src/*.cpp src/shapes/*.cpp main.cpp -lgdi32 -luser32
```
To execute :
```bash
./main
```


Projet créé en collaboration avec Elian HIRTH, Nathan NKENZI et Niriantsoa RAKOTOARISOA pour un cours d'informatique.
