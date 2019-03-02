//
// Created by Osaid K on 9/15/18.
//
#include<stdio.h>
#include<stdlib.h>
#include <string.h>


void populateWorld(char fName[], char *grid[], int *numRows, int *numCols) {

     char buf[BUFSIZ];       // A buffer to extract file data then dump it in the grid.
     FILE *fileptr;
     fileptr = fopen(fName, "r");
     while (fgets(buf, sizeof(buf), fileptr)) {
        grid[*numRows] = malloc (sizeof(buf));   // Allocating memory in the size of the buffer for each pointer.
        strcpy (grid[*numRows], buf);
         printf("%s", grid[*numRows]);
         (*numRows)++;
     }

     *numCols=strlen(grid[(*numRows)-1]);

     for ( int i=0; i<*numRows; i++){                       //
         for (  int j=0; j<*numCols;j++){                   //   These lines are to transform the grid Array from
             if (grid [i][j] == 49) { grid [i][j] ='*';}    //    0's, and 1's to .'s and *'s
             else { grid [i][j] ='.';}}}                    //
     printf ("\n");






}



void showWorld(char *grid[], int numRows, int numCols){
    printf ("\n");
    for ( int i=0; i<numRows; i++){
        for (  int j=0; j<numCols;j++){
            printf("%c", grid [i][j]);
        }
            printf ("\n");
        }
      //exit(-1);
}

void iterateGeneration(char *grid[], int numRows, int numCols){
    char duplicate [numRows][numCols];

    for ( int p=0; p< numRows; p++){
        for ( int c=0; c< numCols; c++) {
            duplicate[p][c]=grid[p][c];
        }}

    for ( int i =0; i< numRows; i++){             // This is to go through the whole array and check data.
        for ( int j=0; j<numCols; j++){
            int livecount=0;

            for (int k = -1; k <= 1; k++){      // Here, these loops make it possible to inspect the neighbors
                for (int f= -1; f <= 1; f++) {

            if((i+k <0)||(i+k > numRows-1)||(j+f <0)||(j+f > numCols-1))
             continue;
            if ( grid [i+k][j+f] == '*') { livecount++;} }}  // here, we count live neighbors.
            if ( grid[i][j]=='*') { livecount--;}           // we have to subtract self count if the cell is live since we through zero in the neighbor inspecting loops.
            if ((grid[i][j] == '*') && (livecount > 3 )) { duplicate[i][j]='.';}    //
            if ((grid[i][j] == '.') && (livecount ==3))  { duplicate[i][j] ='*';}   // Here we apply the rules of the game.
            if ((grid[i][j] =='*') && (livecount <2))    { duplicate[i][j]='.';}    //
            else { grid [i][j] = grid [i][j];}


        }}

    for ( int g=0; g < numRows; g++){

        for ( int h=0; h< numCols; h++){
            grid[g][h]=duplicate[g][h];     // here we move the duplicate array back into the actual grid.
        }
    }



}

