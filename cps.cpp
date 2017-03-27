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

Circle::Circle(double r): radius(r) {}

double Circle::getWidth() const {
	return 2*radius;
}

double Circle::getHeigth() const {
	return 2*radius;
}

string Circle::generatePostScript() const {

}