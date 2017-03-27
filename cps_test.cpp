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
#include <string>
using std::string;

TEST_CASE( "Circle" )
{
    Circle cir1(1);
    Circle cir2(15.0);
    Circle cir3(0.5);
    Circle cir4(200);
    Circle cir5(20);

    SECTION( "Heigth" )
    {
        REQUIRE( cir1.getHeigth() == 2.0 );
        REQUIRE( cir2.getHeigth() == 30.0 );
        REQUIRE( cir3.getHeigth() == 1.0 );
        REQUIRE( cir4.getHeigth() == 400.0 );
    }

        SECTION( "Width" )
    {
        REQUIRE( cir1.getHeigth() == 2.0 );
        REQUIRE( cir2.getHeigth() == 30.0 );
        REQUIRE( cir3.getHeigth() == 1.0 );
        REQUIRE( cir4.getHeigth() == 400.0 );
    }
}
