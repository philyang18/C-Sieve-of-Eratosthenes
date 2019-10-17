// ITP 365 Spring 2018
// HW1 - Sieve of Eratosthenes
// Name: Phillip
// Email: yangphil@usc.edu
// Platform: Mac

#include <iostream>
#include <string>
#include "sieve.hpp"
#include "gwindow.h"
#include "vector.h"
#include "strlib.h"

int main(int argc, char** argv)
{
    // Create a 500x500 window
    GWindow gw(500, 500);
    
    //creates two vectors of type int and enum- NumberType
    Vector<int> intVector;
    Vector<NumberType> typeVector;
    
    //calls the initVectors function
    initVectors(intVector, typeVector);
    
    //this creates the white squares with the black outlines and numbers
    drawGrid(gw, intVector, typeVector);
    

    //calls the drawGrid function for each index of the vectors
    for(int i = 2; i < 2 + intVector.size(); i++)
    {
        while(calcNextPrime(intVector, typeVector, i) != -1)
        {
            drawGrid(gw, intVector, typeVector);
            
            //slows down the animation
            pause(1000.0);
        }
    }
    return 0;
}
