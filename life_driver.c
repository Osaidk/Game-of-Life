//life_driver.c
//
//Life Driver program
//Roger Priebe 9/5/2018
//EE 312


/* Student information for project:
 *
 * Replace <Osaid Kadim> with your name.
 *
 * On my honor, <Osaid Kadim>, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Osaid Kadim
 * email address: osaid.k@utexas.edu
 * UTEID: omk226
 * Section 5 digit ID:
 *
 */

//This file is a driver program for the life.c module.
//This program must work with your implementations life.h and life.c
//Do not change the function definitions for populateWorld, showWorld or
//iterateGeneration.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "life.h"


//int argc, char *argv[]
int main() {
    char fName[strlen (argv[1])];
    strcpy( fName, argv[1]);

    const int numGenerations = *argv[2]; //set to a smaller number for debugging

    const int MAX_ROWS = 80; //we want the world to fit on one screen
    char *world[MAX_ROWS];
    int numRows=0;
    int numCols=0;
    populateWorld(fName, world, &numRows, &numCols);

    showWorld(world, numRows, numCols);

    for (int iteration = 0; iteration < numGenerations; iteration++) {

       // system("clear"); //Linux only
        iterateGeneration(world, numRows, numCols);

        showWorld(world, numRows, numCols);

    }

    return 0;
}



