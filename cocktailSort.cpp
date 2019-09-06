// C++ implementation of Cocktail Sort 
// Obtenido de: https://www.geeksforgeeks.org/cocktail-sort/

#include <stdio.h>
#include <iostream>
#include<stdlib.h>
#include<time.h>
#include <ctime>
using namespace std; 

// Sorts arrar a[0..n-1] using Cocktail sort 
void CocktailSort(int a[], int n) 
{ 
	bool swapped = true; 
	int start = 0; 
	int end = n - 1; 

	while (swapped) { 
		// reset the swapped flag on entering 
		// the loop, because it might be true from 
		// a previous iteration. 
		swapped = false; 

		// loop from left to right same as 
		// the bubble sort 
		for (int i = start; i < end; ++i) { 
			if (a[i] > a[i + 1]) { 
				swap(a[i], a[i + 1]); 
				swapped = true; 
			} 
		} 

		// if nothing moved, then array is sorted. 
		if (!swapped) 
			break; 

		// otherwise, reset the swapped flag so that it 
		// can be used in the next stage 
		swapped = false; 

		// move the end point back by one, because 
		// item at the end is in its rightful spot 
		--end; 

		// from right to left, doing the 
		// same comparison as in the previous stage 
		for (int i = end - 1; i >= start; --i) { 
			if (a[i] > a[i + 1]) { 
				swap(a[i], a[i + 1]); 
				swapped = true; 
			} 
		} 

		// increase the starting point, because 
		// the last stage would have moved the next 
		// smallest number to its rightful spot. 
		++start; 
	} 
} 

/* Prints the array */
void printArray(int a[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		printf("%d ", a[i]); 
	printf("\n"); 
} 

// Driver code 
int main() 
{ 
#define MAX_NUMEROS 500000

int arr[MAX_NUMEROS] = { 0 };

for(int a=0;a<MAX_NUMEROS;a++)
	{
  // generamos un numero
	int M = (rand() % 109856) + 50;
    arr[a] = M;
	}
	
	int n = sizeof(arr)/sizeof(arr[0]);
	
	unsigned t0, t1;
	t0=clock();    //Corre tiempo
	CocktailSort(arr, n); 
	t1 = clock();  //Termina de ejecutarse
	
	double time = (double(t1-t0)/CLOCKS_PER_SEC); //Se calcula el tiempo
	
	//printf("Sorted array: \n");  //Imrpimimos arras solo para corroborar
	//printArray(arr, n); 
	std::cout << "\nExecution Time: " << time << std::endl; //Imprimimos tiempo de ejecucion
	return 0; 
} 

