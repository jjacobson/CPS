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
using std::to_string;
#include <vector>
using std::vector;
#include <memory>
using std::shared_ptr;
#include <fstream>
using std::ofstream;
#include <iostream>
using std::cout;
using std::endl;

const double M_PI = 3.1415926535;

/***** String to Postscript file *****/
void stringToPostscriptFile(const string & postscript, const string & filename);

/***** SHAPE *****/

class Shape {
public:
	virtual ~Shape()=default;
	virtual double getWidth() const;
	virtual double getHeight() const;

	virtual string generatePostScript() const=0;

protected:
	virtual void setWidth(double width);
	virtual void setHeight(double height);
	virtual void setNumSides(int numSides);
	virtual void setSideLength(double sideLength);

private:
	double _height;
	double _width;
	int _numSides;
	double _sideLength;
};

/***** CIRCLE *****/

class Circle : public Shape {
public:	
	Circle(double radius);
	
	string generatePostScript() const override;
};

/***** POLYGON *****/

class Polygon : public Shape
{
public:
	Polygon(int numSides, double sideLength);

	string generatePostScript() const override;
};

/***** RECTANGLE *****/

class Rectangle : public Shape
{
public:
	Rectangle(double height, double width);

	string generatePostScript() const override;
};

/***** SPACER *****/

class Spacer : public Shape
{
public:
	Spacer(double height, double width);

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

/***** LayeredShape *****/

class LayeredShape : public Shape
{
public:
	LayeredShape(vector<shared_ptr<Shape>> shapes);
	string generatePostScript() const override;
private:
	vector<shared_ptr<Shape>> _shapes;
};

/***** VerticalShape *****/

class VerticalShape : public Shape
{
public:
	VerticalShape(vector<shared_ptr<Shape>> shapes);
	string generatePostScript() const override;
private:
	vector<shared_ptr<Shape>> _shapes;
};

/***** HorizontalShape *****/

class HorizontalShape : public Shape
{
public:
	HorizontalShape(vector<shared_ptr<Shape>> shapes);
	string generatePostScript() const override;
private:
	vector<shared_ptr<Shape>> _shapes;
};

#endif // CPS_H_INCLUDED