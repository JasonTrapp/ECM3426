#include <math.h>
#include <stdio.h>
#include <omp.h>

#define SIZE 500
#define DX 0.0002 //change in x
#define DY 0.0002
#define T 0.0000009 //stability condition
#define ALPHA 0.01

int main(){
	double tempArray[SIZE][SIZE];
	double prevArray[SIZE][SIZE];

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

	return 0;
}
