// cps.h
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

#ifndef CPS_H_INCLUDED
#define CPS_H_INCLUDED

#include <string>
using std::string;

/***** SHAPE *****/

class Shape {
public:
	virtual ~Shape()=default;
	virtual double getWidth() const=0;
	virtual double getHeight() const=0;

	virtual string generatePostScript() const=0;

protected:
	double _height;
	double _width;
	int _numSides;
	double _sideLength;
};

/***** CIRCLE *****/

class Circle : public Shape {
public:	
	Circle(double radius);
	double getWidth() const override;
	double getHeight() const override;

	string generatePostScript() const override;
};

/***** POLYGON *****/

class Polygon : public Shape
{
public:
	Polygon(int numSides, double sideLength);
	double getWidth() const override;
	double getHeight() const override;

	string generatePostScript() const override;
};

/***** RECTANGLE *****/

class Rectangle : public Shape
{
public:
	Rectangle(double height, double width);
	double getWidth() const override;
	double getHeight() const override;

	string generatePostScript() const override;
};

/***** SPACER *****/

class Spacer : public Shape
{
public:
	Spacer(double height, double width);
	double getWidth() const override;
	double getHeight() const override;

	string generatePostScript() const override;
};

/***** SQUARE *****/

class Square : public Polygon
{
public:
	Square(double sideLength);
};

/***** TRIANGLE *****/

class Triangle : public Polygon
{
public:
	Triangle(double sideLength);
};

#endif // CPS_H_INCLUDED