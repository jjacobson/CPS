// cps.h
//
// created by
// Frank Cline	(fmcline@alaska.edu)
// Alexander Eckert (aeckert@alaska.edu)
// Jeremiah Jacobson (jjjacobson2@alaska.edu)
// Rohan Weeden (reweeden@alaska.edu)
// 3-22-2017
// Project 2 for CS372 Spring 2017 at UAF
// Professor Dr. Hartman

#include <string>
using std::string;

class Shape {
public:
	virtual ~Shape()=default;
	virtual double getWidth() const=0;
	virtual double getHeigth() const=0;

	virtual string generate() const=0;	
};

class Circle : public Shape {
public:
	Circle(double r);
	double getWidth() const override;
	double getHeigth() const override;

	string generate() const override;

private:
	double radius;
};
