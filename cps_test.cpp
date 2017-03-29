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


TEST_CASE( "Circle" )
{
    Circle cir1(1);
    Circle cir2(15.0);
    Circle cir3(0.5);
    Circle cir4(200);

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