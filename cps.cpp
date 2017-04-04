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
using std::move;

/***** String to Postscript file *****/
void stringToPostscriptFile(const string & postscript, const string & filename)
{
	ofstream postscriptFile;
	try
	{
		postscriptFile.open(filename);
		postscriptFile << postscript << " showpage";
		postscriptFile.close();
	}
	catch (std::exception & e)
	{
		cout << e.what() << endl;
	}
}

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
	string radius = to_string(getWidth()/2);
	string postscript = 
	"gsave newpath 0 0 " + radius + " 0 360 arc closepath stroke grestore ";
	return postscript;
}

/***** POLYGON *****/

Polygon::Polygon(int numSides, double sideLength):_sides(numSides), _sideLength(sideLength) {
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
	int angleSum = (_sides - 2 ) * 180;
	int angle =  angleSum / _sides;
	string postscript = "gsave ";
	
	int sX, sY, eX, eY = 0;
	postscript += "0 0 moveto ";
	for(int c = 0; c < _sides ; c++) {
		//Find the new end
		eX = sX + (cos((M_PI / 180) * ((180 - angle) * c)) * _sideLength);
		eY = sY + (sin((M_PI / 180) * ((180 - angle) * c)) * _sideLength);
		//Move the start to the end of the previous line
		sX = eX;
		sY = eY;
		postscript += to_string(eX) + " " + to_string(eY) + " lineto ";
	}
	postscript += "stroke grestore ";
	return postscript;
}

/***** RECTANGLE *****/

Rectangle::Rectangle(double height, double width) {
	setWidth(width);
	setHeight(height);
}

string Rectangle::generatePostScript() const {
	string width = to_string(getWidth());
	string height = to_string(getHeight());
	string halfWidth = to_string(getWidth()/2);
	string halfHeight = to_string(getHeight()/2);

	string postscript = "gsave newpath " + halfWidth + " " + halfHeight + " moveto ";
	postscript += "0 -" + height + " rlineto "; 
	postscript += "-" + width + " 0 rlineto ";
	postscript += "0 " + height + " rlineto closepath stroke grestore "; 
	return postscript;
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

/***** RotatedShape *****/

RotatedShape::RotatedShape(shared_ptr<Shape> shape, int rotationAngle):_shape(shape), _rotation(rotationAngle) {
	double width = shape->getWidth();
	double height = shape->getHeight();
	if(rotationAngle == 0 || rotationAngle == 180) {
		setWidth(width);
		setHeight(height);
	}
	else {
		setWidth(height);
		setHeight(width);
	}
}

string RotatedShape::generatePostScript() const {
	string postscript = "gsave ";
	postscript += to_string(_rotation) + " rotate ";
	postscript += _shape->generatePostScript();
	postscript += "grestore ";
	return postscript;
}

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
	string postscript = "gsave ";
	for (auto const shape : _shapes)
	{
		postscript += shape->generatePostScript();
	}
	postscript += "grestore ";
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
	string postscript = "gsave ";
	for (auto const shape : _shapes)
	{
		postscript += shape->generatePostScript();
		postscript += "0 " + to_string(shape->getHeight()/2) + " translate ";
	}
	postscript += "grestore ";
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
	string postscript = "gsave ";
	for (auto const shape : _shapes)
	{
		postscript += shape->generatePostScript();
		postscript += to_string(shape->getWidth()/2) + " 0 translate ";
	}
	postscript += "grestore ";
	return postscript;
}
