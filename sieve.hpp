#pragma once
#include "gwindow.h"
#include "vector.h"

enum NumberType
{
    UNKNOWN,
    PRIME,
    COMPOSITE
};

//Function: drawSquare
//Parameters: Gwindow by ref, an integer, value of NumberType (enum), and two doubles to represent x and y coordinates
//Purpose: draws individual squares of size 50x50
//Output: outputs nothing and draws a square
void drawSquare(GWindow& gw, int number, NumberType nm, double x, double y);

//Function: initVectors
//Parameters: two vectors
//Purpose: initializes the two vectors by filling them with integers from 2-101 and UNKNOWN for the enum vector
//Output: nothing
void initVectors(Vector<int>& iv, Vector<NumberType>& tv);

//Function: drawSquare
//Parameters: Gwindow by ref, an integer, value of NumberType (enum), and two doubles to represent x and y coordinates
//Purpose: draws individual squares of size 50x50
//Output: outputs nothing and draws a square
void drawGrid(GWindow& gw, Vector<int>& iv, Vector<NumberType>& tv);

//Function: calcNextPrime
//Parameters: two vectors and an integer
//Purpose: Finds prime numbers and multiplies the number to determine all of the multiples of the prime numbers between the range 2-101. Composite numbers are turned red while prime numbers are green
//Output: an integer which is either the prime number or -1 when all numbers are read
int calcNextPrime(Vector<int>& iv, Vector<NumberType>& tv, int startAt);
