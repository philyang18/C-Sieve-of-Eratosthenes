#include "sieve.hpp"
#include "gwindow.h"
#include "vector.h"
#include "strlib.h"

void drawSquare(GWindow& gw, int number, NumberType nm, double x, double y)
{
    //uses Stanford library function to convert an int to a string
    std::string numString = integerToString(number);
    
    //compares nm value to values of the NumberType enum
    if(nm == COMPOSITE)
    {
        gw.setColor("red");
    }
    else if(nm == PRIME)
    {
        gw.setColor("green");
    }
    else if (nm == UNKNOWN)
    {
        gw.setColor("white");
    }
    
    //sets the colors and display of the square
    gw.fillRect(x,y,50,50);
    gw.setColor("black");
    gw.drawRect(x,y,50,50);
    gw.setColor("black");
    gw.drawLabel(numString, x+25, y+25);
}

void initVectors(Vector<int>& iv, Vector<NumberType>& tv)
{
    for(int i = 0; i < 100; i++)
    {
        iv.add(i + 2);
        tv.add(UNKNOWN);
    }
}

void drawGrid(GWindow& gw, Vector<int>& iv, Vector<NumberType>& tv)
{
    //variables
    int index = -1;
    int y = 0;

    for(int x = 0; x < 11; x++)
    {
        //counts the index even though the x is reset every 10 loops
        index += 1;
        
        //x = 10, the x-coord will be 500 so we reset the value of the x multiplier
        if (x == 10)
        {
            x = 0;
            //adds 50 to the y-coordinate
            y += 50;
        }
        //ends the loops once the y-coordinate value goes beyond 450
        if (y > 450)
        {
            break;
        }
        //calls the drawSquare function continuously to complete the grid
        drawSquare(gw, iv[index], tv[index], x * 50, y);
    }
}

int calcNextPrime(Vector<int>& iv, Vector<NumberType>& tv, int startAt)
{
    int returnNum = 0;
    
    //compares the values of the enum vector to determine if the value is unknown/prime
    if(tv[startAt-2] == UNKNOWN)
    {
        //relabels the value of the number as prime, thus changing its color
        tv[startAt-2] = PRIME;
        
        //variable
        int compNum = 0;
        
        //determines all multiples of the prime number between 2-101
        for(int j = 2; j < 52; j++)
        {
            compNum = startAt * j;
            
            if(compNum < 2 + iv.size())
            {
                //relabels the value as composite and thus changing it to a red color
                tv[compNum - 2] = COMPOSITE;
            }
            else
            {
                break;
            }
        }
        //returns the prime number
        returnNum = startAt;
    }
    //once all the numbers are read, the function returns -1
    else
    {
        returnNum = -1;
    }
    return returnNum;
}
