// C++ implementation of Shell Sort 
//Obtenido de: https://www.geeksforgeeks.org/shellsort/
#include <iostream> 
using namespace std; 
#include <iostream>
#include<time.h>
#include <ctime> 
#include<bits/stdc++.h> 

/* function to sort arr using shellSort */
int shellSort(int arr[], int n) 
{ 
	// Start with a big gap, then reduce the gap 
	for (int gap = n/2; gap > 0; gap /= 2) 
	{ 
		// Do a gapped insertion sort for this gap size. 
		// The first gap elements a[0..gap-1] are already in gapped order 
		// keep adding one more element until the entire array is 
		// gap sorted 
		for (int i = gap; i < n; i += 1) 
		{ 
			// add a[i] to the elements that have been gap sorted 
			// save a[i] in temp and make a hole at position i 
			int temp = arr[i]; 

			// shift earlier gap-sorted elements up until the correct 
			// location for a[i] is found 
			int j;			 
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
				arr[j] = arr[j - gap]; 
			
			// put temp (the original a[i]) in its correct location 
			arr[j] = temp; 
		} 
	} 
	return 0; 
} 

void printArray(int arr[], int n) 
{ 
	for (int i=0; i<n; i++) 
		cout << arr[i] << " "; 
} 

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
	shellSort(arr, n); 
	t1 = clock();  //Termina de ejecutarse
	
	double time = (double(t1-t0)/CLOCKS_PER_SEC); //Se calcula el tiempo
	
	//printf("Sorted array: \n");  //Imrpimimos arras solo para corroborar
	//print(arr, n); 
	std::cout << "\nExecution Time: " << time << std::endl; //Imprimimos tiempo de ejecucion
	return 0; 
} 

