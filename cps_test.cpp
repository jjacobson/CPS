// cps_test.cpp
// 3-26-2017
//
// created by
// Frank Cline  (fmcline@alaska.edu)
// Alexander Eckert (aeckert@alaska.edu)
// Jeremiah Jacobson (jjjacobson2@alaska.edu)
// Rohan Weeden (reweeden@alaska.edu)
//
// Test program for class cps
// Project 2 for CS372 Spring 2017 at UAF
// Professor Dr. Hartman
//
// Uses the "Catch" unit-testing framework
// Requires catch.hpp, cps.h, cps.cpp

#include "cps.h"          // For class Team
#include "cps.h"          // Double inclusion test

#define CATCH_CONFIG_MAIN  // We want Catch to write function main
#include "catch.hpp"       // For the "Catch" unit-testing framework

// Additional includes for this test program
#define _USE_MATH_DEFINES
#include <math.h> // for M_PI
#include <cmath>
using std::sin;
using std::cos;
using std::abs;
using std::sqrt;
#include <vector>
using std::vector;
#include <memory>
using std::shared_ptr;
using std::make_shared;

TEST_CASE( "Circle" )
{
    Circle cir1(1);
    Circle cir2(15.0);
    Circle cir3(0.5);
    Circle cir4(200);
    Circle cir5(72);

    SECTION( "Heigth" )
    {
        REQUIRE( cir1.getHeight() == 2.0 );
        REQUIRE( cir2.getHeight() == 30.0 );
        REQUIRE( cir3.getHeight() == 1.0 );
        REQUIRE( cir4.getHeight() == 400.0 );
    }

    SECTION( "Width" )
    {
        REQUIRE( cir1.getWidth() == 2.0 );
        REQUIRE( cir2.getWidth() == 30.0 );
        REQUIRE( cir3.getWidth() == 1.0 );
        REQUIRE( cir4.getWidth() == 400.0 );
    }
}

TEST_CASE( "Polygon" )
{
    Polygon pol1(3, 5);
    Polygon pol2(6, 13.0);
    Polygon pol3(8, 0.9);

    SECTION( "Heigth" )
    {
        REQUIRE( pol1.getHeight() == 5*(1+cos(M_PI/3))/(2*sin(M_PI/3)) );
        REQUIRE( pol2.getHeight() == 13*(cos(M_PI/6))/(sin(M_PI/6)));
        REQUIRE( pol3.getHeight() == 0.9*(cos(M_PI/8))/(sin(M_PI/8)) );
    }

        SECTION( "Width" )
    {
        REQUIRE( pol1.getWidth() == (5*sin(M_PI*(3-1)/2*3))/(sin(M_PI/3)));
        REQUIRE( pol2.getWidth() == 13/(sin(M_PI/6)) );
        REQUIRE( pol3.getWidth() == (0.9*sin(M_PI/8))/(sin(M_PI/8)));
    }
}

TEST_CASE( "Rectangle" )
{
    Rectangle rec1(1, 5);
    Rectangle rec2(15.0, 13.0);
    Rectangle rec3(0.5, 0.9);
    Rectangle rec4(200, 400);


    SECTION( "Heigth" )
    {
        REQUIRE( rec1.getHeight() == 1.0 );
        REQUIRE( rec2.getHeight() == 15.0 );
        REQUIRE( rec3.getHeight() == 0.5 );
        REQUIRE( rec4.getHeight() == 200.0 );
    }

    SECTION( "Width" )
    {
        REQUIRE( rec1.getWidth() == 5.0 );
        REQUIRE( rec2.getWidth() == 13.0 );
        REQUIRE( rec3.getWidth() == 0.9 );
        REQUIRE( rec4.getWidth() == 400.0 );
    }
}

TEST_CASE( "Spacer" )
{
    Spacer spacer1(1, 5);
    Spacer spacer2(15.0, 13.0);
    Spacer spacer3(0.5, 0.9);
    Spacer spacer4(200, 400);


    SECTION( "Heigth" )
    {
        REQUIRE( spacer1.getHeight() == 1.0 );
        REQUIRE( spacer2.getHeight() == 15.0 );
        REQUIRE( spacer3.getHeight() == 0.5 );
        REQUIRE( spacer4.getHeight() == 200.0 );
    }

        SECTION( "Width" )
    {
        REQUIRE( spacer1.getWidth() == 5.0 );
        REQUIRE( spacer2.getWidth() == 13.0 );
        REQUIRE( spacer3.getWidth() == 0.9 );
        REQUIRE( spacer4.getWidth() == 400.0 );
    }
}

TEST_CASE( "Square" )
{
    Square square1(1);
    Square square2(15.0);
    Square square3(0.5);
    Square square4(200);


    SECTION( "Heigth" )
    {
        REQUIRE( square1.getHeight() == 1*(cos(M_PI/4))/(sin(M_PI/4)) );
        REQUIRE( square2.getHeight() == 15*(cos(M_PI/4))/(sin(M_PI/4)) );
        REQUIRE( square3.getHeight() == 0.5*(cos(M_PI/4))/(sin(M_PI/4)) );
        REQUIRE( square4.getHeight() == 200*(cos(M_PI/4))/(sin(M_PI/4)) );
    }

        SECTION( "Width" )
    {
        REQUIRE( square1.getWidth() == (1*sin(M_PI/4))/(sin(M_PI/4)) );
        REQUIRE( square2.getWidth() == (15*sin(M_PI/4))/(sin(M_PI/4)) );
        REQUIRE( square3.getWidth() == (0.5*sin(M_PI/4))/(sin(M_PI/4)) );
        REQUIRE( square4.getWidth() == (200*sin(M_PI/4))/(sin(M_PI/4)) );
    }
}

TEST_CASE( "Triangle" )
{
    Triangle tri1(5);
    Triangle tri2(13.0);
    Triangle tri3(0.9);


    SECTION( "Heigth" )
    {
        REQUIRE( tri1.getHeight() == 5*(1+cos(M_PI/3))/(2*sin(M_PI/3)) );
        REQUIRE( tri2.getHeight() == 13*(1+cos(M_PI/3))/(2*sin(M_PI/3)) );
        REQUIRE( tri3.getHeight() == 0.9*(1+cos(M_PI/3))/(2*sin(M_PI/3)) );
    }

        SECTION( "Width" )
    {
        REQUIRE( tri1.getWidth() == (5*sin(M_PI*(3-1)/2*3))/(sin(M_PI/3)) );
        REQUIRE( tri2.getWidth() == (13*sin(M_PI*(3-1)/2*3))/(sin(M_PI/3)) );
        REQUIRE( tri3.getWidth() == (0.9*sin(M_PI*(3-1)/2*3))/(sin(M_PI/3)) );
    }
}

double getHeightOfShapes(const vector<shared_ptr<Shape>> & shapes)
{
	double height = 0;
	for (auto const & shape : shapes)
	{
		height += shape->getHeight();
	}
	return height;
}

double getWidthOfShapes(const vector<shared_ptr<Shape>> & shapes)
{
	double width = 0;
	for (auto const & shape : shapes)
	{
		width += shape->getWidth();
	}
	return width;
}

TEST_CASE( "Compound Shapes" )
{
	Triangle triangle(3.0);
	Circle circle(3.5);
	Square square(4.0);
	Rectangle rectangle(2.0,8.0);
	Polygon polygon(6,1.0);
	
	SECTION( "RotatedShape" )
    {
    	RotatedShape rs1(make_shared<Square>(square), 0);
    	RotatedShape rs2(make_shared<Square>(square), 90);
    	RotatedShape rs3(make_shared<Square>(square), 180);
    	RotatedShape rs4(make_shared<Square>(square), 270);
		
		RotatedShape rs5(make_shared<Circle>(circle), 0);
		RotatedShape rs6(make_shared<Circle>(circle), 90);
		RotatedShape rs7(make_shared<Circle>(circle), 180);
		RotatedShape rs8(make_shared<Circle>(circle), 270);
		
    	RotatedShape rs9(make_shared<Rectangle>(rectangle), 0);
    	RotatedShape rs10(make_shared<Rectangle>(rectangle), 90);
    	RotatedShape rs11(make_shared<Rectangle>(rectangle), 180);
    	RotatedShape rs12(make_shared<Rectangle>(rectangle), 270);
		
    	// Height
        REQUIRE( rs1.getHeight() == square.getHeight());
        REQUIRE( rs2.getHeight() == square.getWidth());
        REQUIRE( rs3.getHeight() == square.getHeight());
        REQUIRE( rs4.getHeight() == square.getWidth());
		
        REQUIRE( rs5.getHeight() == circle.getHeight());
        REQUIRE( rs6.getHeight() == circle.getWidth());
        REQUIRE( rs7.getHeight() == circle.getHeight());
        REQUIRE( rs8.getHeight() == circle.getWidth());
		
        REQUIRE( rs9.getHeight() == rectangle.getHeight());
        REQUIRE( rs10.getHeight() == rectangle.getWidth());
        REQUIRE( rs11.getHeight() == rectangle.getHeight());
        REQUIRE( rs12.getHeight() == rectangle.getWidth());
        // Width
        REQUIRE( rs1.getWidth() == square.getWidth());
        REQUIRE( rs2.getWidth() == square.getHeight());
        REQUIRE( rs3.getWidth() == square.getWidth());
        REQUIRE( rs4.getWidth() == square.getHeight());
		
        REQUIRE( rs5.getWidth() == circle.getWidth());
        REQUIRE( rs6.getWidth() == circle.getHeight());
        REQUIRE( rs7.getWidth() == circle.getWidth());
        REQUIRE( rs8.getWidth() == circle.getHeight());
		
        REQUIRE( rs9.getWidth() == rectangle.getWidth());
        REQUIRE( rs10.getWidth() == rectangle.getHeight());
        REQUIRE( rs11.getWidth() == rectangle.getWidth());
        REQUIRE( rs12.getWidth() == rectangle.getHeight());
    }
}

TEST_CASE( "Stacked Shapes" )
{
	Triangle triangle(3.0);
	Circle circle(3.5);
	Square square(4.0);
	Rectangle rectangle(2.0,8.0);
	Polygon polygon(6,1.0);

	vector<shared_ptr<Shape>> shapes1 {
		make_shared<Triangle>(triangle), make_shared<Circle>(circle),
		make_shared<Triangle>(triangle), make_shared<Rectangle>(rectangle)
	};

	vector<shared_ptr<Shape>> shapes2 { make_shared<Square>(square) };

	vector<shared_ptr<Shape>> shapes3 {
		make_shared<Polygon>(polygon), make_shared<Square>(square),
		make_shared<Circle>(circle), make_shared<Triangle>(triangle)
	};

    vector<shared_ptr<Shape>> shapes4 {
        make_shared<Rectangle>(rectangle), make_shared<Circle>(circle),
        make_shared<Circle>(circle), make_shared<Rectangle>(rectangle)
    };

    SECTION( "LayeredShape" )
    {
    	LayeredShape ls1(shapes1);
		LayeredShape ls2(shapes2);
		LayeredShape ls3(vector<shared_ptr<Shape>> {
			make_shared<Circle>(5), make_shared<Circle>(2), 
			make_shared<Rectangle>(1,2), make_shared<Triangle>(1)
		});
    	// Height
        REQUIRE( ls1.getHeight() == 7.0);
        REQUIRE( ls2.getHeight() == square.getHeight());
        REQUIRE( ls3.getHeight() == 10.0);
        // Width
        REQUIRE( ls1.getWidth() == 8);
        REQUIRE( ls2.getWidth() == square.getWidth());
        REQUIRE( ls3.getWidth() == 10);
    }

    SECTION( "VerticalShape" )
    {
    	VerticalShape vs1(shapes1);
    	VerticalShape vs2(shapes2);
    	VerticalShape vs3(shapes3);
    	double shape1Height = getHeightOfShapes(shapes1);
    	double shape2Height = getHeightOfShapes(shapes2);
    	double shape3Height = getHeightOfShapes(shapes3);
    	// Height
        REQUIRE( vs1.getHeight() == shape1Height);
        REQUIRE( vs2.getHeight() == shape2Height);
        REQUIRE( vs3.getHeight() == shape3Height);
        // Width
        REQUIRE( vs1.getWidth() == 8);
        REQUIRE( vs2.getWidth() == square.getWidth());
        REQUIRE( vs3.getWidth() == 7);
    }

    SECTION( "HorizontalShape" )
    {
    	HorizontalShape hs1(shapes1);
    	HorizontalShape hs2(shapes2);
    	HorizontalShape hs3(shapes3);
    	double shape1Width = getWidthOfShapes(shapes1);
    	double shape2Width = getWidthOfShapes(shapes2);
    	double shape3Width = getWidthOfShapes(shapes3);
    	// Height
        REQUIRE( hs1.getHeight() == 7);
        REQUIRE( hs2.getHeight() == square.getHeight());
        REQUIRE( hs3.getHeight() == 7);
        // Width
        REQUIRE( hs1.getWidth() == shape1Width);
        REQUIRE( hs2.getWidth() == shape2Width);
        REQUIRE( hs3.getWidth() == shape3Width);
    }
}

TEST_CASE( "Post Script" )
{
    const string filename = "test.ps";
    string postscript = "";
    
    Rectangle rect(72,72*2);
    Circle circ(72);

    postscript += rect.generatePostScript() + " showpage ";
    postscript += circ.generatePostScript();

    stringToPostscriptFile(postscript,filename);
}

