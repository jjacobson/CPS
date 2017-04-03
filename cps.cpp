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

/***** Shape *****/

double Shape::getWidth() const {
	return _width;
}

double Shape::getHeight() const {
	return _height;
}

void Shape::setWidth(double width) {
	_width = width;
}

void Shape::setHeight(double height) {
	_height = height;
}

void Shape::setNumSides(int numSides) {
	_numSides = numSides;
}

void Shape::setSideLength(double sideLength) {
	_sideLength = sideLength;
}

/***** CIRCLE *****/

Circle::Circle(double radius) {
	setWidth(2*radius);
	setHeight(2*radius);
}

string Circle::generatePostScript() const {
	return "Circle";
}

/***** POLYGON *****/

Polygon::Polygon(int numSides, double sideLength) {
	if(numSides%2!=0) {
		setHeight(sideLength*(1+cos(M_PI/numSides))/(2*sin(M_PI/numSides)));
		setWidth((sideLength*sin(M_PI*(numSides-1)/2*numSides))/(sin(M_PI/numSides)));
	}
	else if (numSides % 4 == 0)
	{
		setHeight(sideLength*(cos(M_PI/numSides))/(sin(M_PI/numSides)));
		setWidth((sideLength*sin(M_PI/numSides))/(sin(M_PI/numSides)));
	}
	else
	{
		setHeight(sideLength*(cos(M_PI/numSides))/(sin(M_PI/numSides)));
		setWidth(sideLength/(sin(M_PI/numSides)));
	}
}

string Polygon::generatePostScript() const {
	return "Polygon";
}

/***** RECTANGLE *****/

Rectangle::Rectangle(double height, double width) {
	setWidth(width);
	setHeight(height);
}

string Rectangle::generatePostScript() const {
	return "Rectangle";
}

/***** SPACER *****/

Spacer::Spacer(double height, double width) {
	setWidth(width);
	setHeight(height);
}

string Spacer::generatePostScript() const {
	return "Spacer";
}

/***** SQUARE *****/

Square::Square(double sideLength): Polygon(4, sideLength) {}

/***** TRIANGLE *****/

Triangle::Triangle(double sideLength): Polygon(3, sideLength) {}

/***** LayeredShape *****/

LayeredShape::LayeredShape(vector<shared_ptr<Shape>> shapes) {
	_shapes = shapes;
	double width = 0;
	double height = 0;
	for (auto const & shape : _shapes)
	{
		if (shape->getHeight() > height)
			height = shape->getHeight();
		if (shape->getWidth() > width)
			width = shape->getWidth();
	}
	setWidth(width);
	setHeight(height);
}

string LayeredShape::generatePostScript() const {
	string postscript = "gsave\n";
	for (auto const shape : _shapes)
	{
		postscript += shape->generatePostScript() + "\n";
	}
	postscript += "grestore";
	return postscript;
}

/***** VerticalShape *****/

VerticalShape::VerticalShape(vector<shared_ptr<Shape>> shapes) {
	_shapes = shapes;
	double width = 0;
	double height = 0;
	for (auto const & shape : _shapes)
	{
		height += shape->getHeight();
		if (shape->getWidth() > width)
			width = shape->getWidth();
	}
	setWidth(width);
	setHeight(height);
}

string VerticalShape::generatePostScript() const {
	string postscript = "gsave\n";
	for (auto const shape : _shapes)
	{
		postscript += shape->generatePostScript() + "\n";
		postscript += to_string(shape->getHeight()) + " translate\n";
	}
	postscript += "grestore";
	return postscript;
}

/***** HorizontalShape *****/

HorizontalShape::HorizontalShape(vector<shared_ptr<Shape>> shapes) {
	_shapes = shapes;
	double width = 0;
	double height = 0;
	for (auto const & shape : _shapes)
	{
		width += shape->getWidth();
		if (shape->getHeight() > height)
			height = shape->getHeight();
	}
	setWidth(width);
	setHeight(height);
}

string HorizontalShape::generatePostScript() const {
	string postscript = "gsave\n";
	for (auto const shape : _shapes)
	{
		postscript += shape->generatePostScript() + "\n";
		postscript += to_string(shape->getWidth()) + " translate\n";
	}
	postscript += "grestore";
	return postscript;
}
