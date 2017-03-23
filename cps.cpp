// cps.cpp
//
// created by
// Frank Cline	(fmcline@alaska.edu)
// Alexander Eckert (aeckert@alaska.edu)
// Jeremiah Jacobson (jjjacobson2@alaska.edu)
// Rohan Weeden (reweeden@alaska.edu)
// 3-22-2017
// Project 2 for CS372 Spring 2017 at UAF
// Professor Dr. Hartman

Circle::Circle(double r): radius(r) {}

double Circle::getWidth() const override {
	return 2*radius;
}

double Circle::getHeigth() const override {
	return 2*radius;
}

string Circle::generate() const override {

}