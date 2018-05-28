#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 500
#define DX 0.0002 //change in x
#define DY 0.0002
#define T 0.0000009 //stability condition
#define ALPHA 0.01

int main(){
	double tempArray[SIZE][SIZE];
	double prevArray[SIZE][SIZE];
	
	//Initialise the temperature arrays
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			if(i >= 150 && i <= 350 && j >= 150 && j <= 350){
				tempArray[i][j] = 50.0;
				prevArray[i][j] = 50.0;
			}
			else{		
				tempArray[i][j] = 20.0;
				prevArray[i][j] = 20.0;
			}
		}
	}

	

	double xPos = 0.0;
	double yPos = 0.0;
	FILE *output;
	output = fopen("heat.dat", "w");
	
	for(int i = 0; i < SIZE; i++){
		xPos = 0.0;
		for(int j = 0; j < SIZE; j++){
			fprintf(output, "%f %f %f \n", xPos, yPos, tempArray[i][j]);	
			xPos += DX;		
		}
		yPos += DY;
	}
	fclose(output);

	return 0;
}
