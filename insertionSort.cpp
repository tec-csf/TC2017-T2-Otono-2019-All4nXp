// C++ program for insertion sort 
// This is code is contributed by rathbhupendra
//Obtenido de: https://www.geeksforgeeks.org/insertion-sort/

#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include<stdlib.h>
#include<time.h>
#include <ctime> 
using namespace std; 

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n) 
{ 
	int i, key, j; 
	for (i = 1; i < n; i++) 
	{ 
		key = arr[i]; 
		j = i - 1; 

		/* Move elements of arr[0..i-1], that are 
		greater than key, to one position ahead 
		of their current position */
		while (j >= 0 && arr[j] > key) 
		{ 
			arr[j + 1] = arr[j]; 
			j = j - 1; 
		} 
		arr[j + 1] = key; 
	} 
} 

// A utility function to print an array of size n 
void printArray(int arr[], int n) 
{ 
	int i; 
	for (i = 0; i < n; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

/* Driver code */
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
	insertionSort(arr, n); 
	t1 = clock();  //Termina de ejecutarse
	
	double time = (double(t1-t0)/CLOCKS_PER_SEC); //Se calcula el tiempo
	
	//printf("Sorted array: \n");  //Imrpimimos arras solo para corroborar
	//printArray(arr, n); 
	std::cout << "\nExecution Time: " << time << std::endl; //Imprimimos tiempo de ejecucion
	return 0; 
} 

 

