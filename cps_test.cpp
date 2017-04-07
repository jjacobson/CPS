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
        REQUIRE( pol1.getHeight() == 5*(1+cos(PI/3))/(2*sin(PI/3)) );
        REQUIRE( pol2.getHeight() == 13*(cos(PI/6))/(sin(PI/6)));
        REQUIRE( pol3.getHeight() == 0.9*(cos(PI/8))/(sin(PI/8)) );
    }

        SECTION( "Width" )
    {
        REQUIRE( pol1.getWidth() == (5*sin(PI*(3-1)/(2*3)))/(sin(PI/3)));
        REQUIRE( pol2.getWidth() == 13/(sin(PI/6)) );
        REQUIRE( pol3.getWidth() == (0.9*sin(PI/8))/(sin(PI/8)));
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
        REQUIRE( square1.getHeight() == 1*(cos(PI/4))/(sin(PI/4)) );
        REQUIRE( square2.getHeight() == 15*(cos(PI/4))/(sin(PI/4)) );
        REQUIRE( square3.getHeight() == 0.5*(cos(PI/4))/(sin(PI/4)) );
        REQUIRE( square4.getHeight() == 200*(cos(PI/4))/(sin(PI/4)) );
    }

        SECTION( "Width" )
    {
        REQUIRE( square1.getWidth() == (1*sin(PI/4))/(sin(PI/4)) );
        REQUIRE( square2.getWidth() == (15*sin(PI/4))/(sin(PI/4)) );
        REQUIRE( square3.getWidth() == (0.5*sin(PI/4))/(sin(PI/4)) );
        REQUIRE( square4.getWidth() == (200*sin(PI/4))/(sin(PI/4)) );
    }
}

TEST_CASE( "Triangle" )
{
    Triangle tri1(5);
    Triangle tri2(13.0);
    Triangle tri3(0.9);


    SECTION( "Heigth" )
    {
        REQUIRE( tri1.getHeight() == 5*(1+cos(PI/3))/(2*sin(PI/3)) );
        REQUIRE( tri2.getHeight() == 13*(1+cos(PI/3))/(2*sin(PI/3)) );
        REQUIRE( tri3.getHeight() == 0.9*(1+cos(PI/3))/(2*sin(PI/3)) );
    }

        SECTION( "Width" )
    {
        REQUIRE( tri1.getWidth() == (5*sin(PI*(3-1)/(2*3)))/(sin(PI/3)) );
        REQUIRE( tri2.getWidth() == (13*sin(PI*(3-1)/(2*3)))/(sin(PI/3)) );
        REQUIRE( tri3.getWidth() == (0.9*sin(PI*(3-1)/(2*3)))/(sin(PI/3)) );
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

TEST_CASE( "Scaled Shape" )
{
    Triangle triangle(3.0);
    Circle circle(3.5);
    Square square(4.0);
    Rectangle rectangle(2.0,8.0);
    Polygon polygon(6,1.0);

    ScaledShape striangle(make_shared<Triangle>(triangle),0.5,1.5);
    ScaledShape scircle(make_shared<Circle>(circle),2,0.75);
    ScaledShape srectangle(make_shared<Rectangle>(rectangle),3.2,0.25);

    SECTION("Height")
    {
        REQUIRE(striangle.getHeight() == triangle.getHeight()*1.5);
        REQUIRE(scircle.getHeight() == circle.getHeight()*0.75);
        REQUIRE(srectangle.getHeight() == rectangle.getHeight()*0.25);
    }
    SECTION("Width")
    {
        REQUIRE(striangle.getWidth() == triangle.getWidth()*0.5);
        REQUIRE(scircle.getWidth() == circle.getWidth()*2);
        REQUIRE(srectangle.getWidth() == rectangle.getWidth()*3.2);
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

TEST_CASE( "PostScript: Basic Shapes" )
{   
    const string filename = "basic_shapes.ps";
    string postscript = "";

    // Basic Shapes
    Rectangle rect(36,72);
    Square square(36);
    Circle circ(36);
    Triangle triangle(36);
    Polygon hexagon(6,18);
    Polygon septagon(7,18);
    // Shapes drawn at bottom left corner to test if centered properly
    postscript += hexagon.generatePostScript() + showpage();
    postscript += septagon.generatePostScript()+ showpage();
    postscript += rect.generatePostScript() + showpage();
    postscript += circ.generatePostScript() + showpage();
    postscript += square.generatePostScript() + showpage();
    postscript += triangle.generatePostScript() + showpage();
    // Shapes drawn all on one page
    postscript += translate(144, 144);
    postscript += hexagon.generatePostScript() + translate(0, 72);
    postscript += septagon.generatePostScript()+ translate(0, 72);
    postscript += rect.generatePostScript() + translate(0, 72);
    postscript += circ.generatePostScript() + translate(0, 72);
    postscript += square.generatePostScript() + translate(0, 72);
    postscript += triangle.generatePostScript(); 

    stringToPostscriptFile(postscript,filename);
}

TEST_CASE( "PostScript: Compound Shapes" )
{
    const string filename = "compound_shapes.ps";
    string postscript = "";

    // Basic shapes used for compound shapes
    Rectangle rect(36,72);
    Square square(36);
    Circle circ(36);
    Triangle triangle(72);
    Polygon hexagon(6,36);
    Polygon septagon(7,36);

    // Vector of basic shapes
    vector<shared_ptr<Shape>> basic_shapes
    {
        make_shared<Rectangle>(rect), make_shared<Square>(square),
        make_shared<Circle>(circ), make_shared<Triangle>(triangle), 
        make_shared<Polygon>(hexagon), make_shared<Polygon>(septagon)
    };
    // Layered, Vertical, Horizontal shapes
    LayeredShape ls1(basic_shapes);
    VerticalShape vs1(basic_shapes);
    HorizontalShape hs1(basic_shapes);

    postscript += translate(144, 144);
    postscript += ls1.generatePostScript() + showpage() + translate(144, 144);
    postscript += vs1.generatePostScript() + showpage() + translate(144, 144);
    postscript += hs1.generatePostScript() + showpage() + translate(144, 144);
    // Scaled Basic Shapes
    ScaledShape s_rect(make_shared<Rectangle>(rect), 0.5, 0.5);
    ScaledShape s_square(make_shared<Square>(square), 1.5, 1.5);
    ScaledShape s_circ(make_shared<Circle>(circ), 2, 0.5);
    ScaledShape s_triangle(make_shared<Triangle>(triangle), 2, 0.5);
    ScaledShape s_hex(make_shared<Polygon>(hexagon), 1.5, 1.5);
    ScaledShape s_sept(make_shared<Polygon>(septagon), 0.5, 0.5);

    postscript += translate(144, 144) + rect.generatePostScript();
    postscript += translate(0, 216) + s_rect.generatePostScript() + showpage();
    postscript += translate(144, 144) + square.generatePostScript();
    postscript += translate(0, 216) + s_square.generatePostScript() + showpage();
    postscript += translate(144, 144) + circ.generatePostScript();
    postscript += translate(0, 216) + s_circ.generatePostScript() + showpage(); 
    postscript += translate(144, 144) + triangle.generatePostScript();
    postscript += translate(0, 216) + s_triangle.generatePostScript() + showpage();
    postscript += translate(144, 144) + hexagon.generatePostScript();
    postscript += translate(0, 216) + s_hex.generatePostScript() + showpage();
    postscript += translate(144, 144) + septagon.generatePostScript();
    postscript += translate(0, 216) + s_sept.generatePostScript();
        
    stringToPostscriptFile(postscript,filename);
}
