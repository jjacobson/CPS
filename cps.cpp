// cps.cpp
// 3-22-2017
//
// created by
// Frank Cline	(fmcline@alaska.edu)
// Alexander Eckert (aeckert@alaska.edu)
// Jeremiah Jacobson (jjjacobson2@alaska.edu)
// Rohan Weeden (reweeden@alaska.edu)
//
// Project 2 for CS372 Spring 2017 at UAF
// Professor Dr. Hartman

#include "cps.h"

#define _USE_MATH_DEFINES
#include <math.h> // for M_PI
#include <cmath>
using std::sin;
using std::cos;
using std::abs;

/***** CIRCLE *****/

Circle::Circle(double radius) {
	_width = 2*radius;
	_height = 2*radius;
}

double Circle::getWidth() const {
	return _width;
}

double Circle::getHeight() const {
	return _height;
}

string Circle::generatePostScript() const {
	return "Circle";
}

/***** POLYGON *****/

Polygon::Polygon(int numSides, double sideLength) {
	if(numSides%2!=0) {
		_height = sideLength*(1+cos(M_PI/numSides))/(2*sin(M_PI/numSides));
		_width = (sideLength*sin(M_PI*(numSides-1)/2*numSides))/(sin(M_PI/numSides));
	}
	else if (numSides % 4 == 0)
	{
		_height = sideLength*(cos(M_PI/numSides))/(sin(M_PI/numSides));
		_width = (sideLength*sin(M_PI/numSides))/(sin(M_PI/numSides));
	}
	else
	{
		_height = sideLength*(cos(M_PI/numSides))/(sin(M_PI/numSides));
		_width = sideLength/(sin(M_PI/numSides));
	}
}

double Polygon::getWidth() const {
	return _width;
}

double Polygon::getHeight() const {
	return _height;
}

string Polygon::generatePostScript() const {
	return "Polygon";
}

/***** RECTANGLE *****/

Rectangle::Rectangle(double height, double width) {
	_width = width;
	_height = height;
}

double Rectangle::getWidth() const {
	return _width;
}

double Rectangle::getHeight() const {
	return _height;
}

string Rectangle::generatePostScript() const {
	return "Rectangle";
}

/***** SPACER *****/

Spacer::Spacer(double height, double width) {
	_width = width;
	_height = height;
}

double Spacer::getWidth() const {
	return _width;
}

double Spacer::getHeight() const {
	return _height;
}

string Spacer::generatePostScript() const {
	return "Spacer";
}

/***** SQUARE *****/

Square::Square(double sideLength): Polygon(4, sideLength) {}

/***** TRIANGLE *****/

Triangle::Triangle(double sideLength): Polygon(3, sideLength) {}