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
#define TIMESTEPS 10000

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

	//Compute time steps
	for(int i = 0; i < TIMESTEPS; i++){
		#pragma omp parallel default(none) shared(tempArray, prevArray) private(j, k)
		for(int j = 1; j < SIZE-1; j++){
			for(int k = 1; k < SIZE-1 ; k++){
				tempArray[j][k] = prevArray[j][k] + T * ALPHA * (prevArray[j+1][k] + prevArray[j-1][k] - 4*prevArray[j][k] + prevArray[j][k+1] + prevArray[j][k-1])/0.00000004;
			}
		}
		#pragma omp parallel default(none) shared(tempArray, prevArray) private(j, k)
		for(int j = 1; j < SIZE-1; j++){
			for(int k = 1; k < SIZE-1 ; k++){
				prevArray [j][k] = tempArray[j][k];
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
