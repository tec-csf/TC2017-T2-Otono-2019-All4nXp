// Optimized implementation of Bubble sort 
// Obtenido de: https://www.geeksforgeeks.org/bubble-sort/

#include <stdio.h>
#include <iostream>
#include<stdlib.h>
#include<time.h>
#include <ctime> 

void swap(int *xp, int *yp) 
{ 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
} 

// An optimized version of Bubble Sort 
void bubbleSort(int arr[], int n) 
{ 
int i, j; 
bool swapped; 
for (i = 0; i < n-1; i++) 
{ 
	swapped = false; 
	for (j = 0; j < n-i-1; j++) 
	{ 
		if (arr[j] > arr[j+1]) 
		{ 
		swap(&arr[j], &arr[j+1]); 
		swapped = true; 
		} 
	} 

	// IF no two elements were swapped by inner loop, then break 
	if (swapped == false) 
		break; 
} 
} 

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("n"); 
} 

// Driver program to test above functions 
int main() 
{ 

#define MAX_NUMEROS 10

int arr[MAX_NUMEROS] = { 0 };

for(int a=0;a<MAX_NUMEROS;a++)
	{
  // generamos un numero
	int M = (rand() % 88) + 50;
    arr[a] = M;
	}
	
	int n = sizeof(arr)/sizeof(arr[0]);
	
	unsigned t0, t1;
	t0=clock();    //Corre tiempo
	bubbleSort(arr, n); 
	t1 = clock();  //Termina de ejecutarse
	
	double time = (double(t1-t0)/CLOCKS_PER_SEC); //Se calcula el tiempo
	
	printf("Sorted array: \n");  //Imrpimimos arras solo para corroborar
	printArray(arr, n); 
	std::cout << "\nExecution Time: " << time << std::endl; //Imprimimos tiempo de ejecucion
	return 0; 
} 

