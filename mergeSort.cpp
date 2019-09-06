/* C program for Merge Sort */
//Obtenido de: https://www.geeksforgeeks.org/merge-sort/	
#include<stdlib.h> 
#include<stdio.h> 

#include <iostream>
#include<time.h>
#include <ctime> 


// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 

	/* create temp arrays */
	int L[n1], R[n2]; 

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1+ j]; 

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2) 
	{ 
		if (L[i] <= R[j]) 
		{ 
			arr[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	/* Copy the remaining elements of L[], if there 
	are any */
	while (i < n1) 
	{ 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 

	/* Copy the remaining elements of R[], if there 
	are any */
	while (j < n2) 
	{ 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 

/* l is for left index and r is right index of the 
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
	if (l < r) 
	{ 
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l+(r-l)/2; 

		// Sort first and second halves 
		mergeSort(arr, l, m); 
		mergeSort(arr, m+1, r); 

		merge(arr, l, m, r); 
	} 
} 

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", A[i]); 
	printf("\n"); 
} 

/* Driver program to test above functions */
int main() 
{ 
#define MAX_NUMEROS 250000

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
	mergeSort(arr, 0, n-1); 
	t1 = clock();  //Termina de ejecutarse
	
	double time = (double(t1-t0)/CLOCKS_PER_SEC); //Se calcula el tiempo
	
	//printf("Sorted array: \n");  //Imrpimimos arras solo para corroborar
	//printArray(arr, n); 
	std::cout << "\nExecution Time: " << time << std::endl; //Imprimimos tiempo de ejecucion
	return 0; 

} 

