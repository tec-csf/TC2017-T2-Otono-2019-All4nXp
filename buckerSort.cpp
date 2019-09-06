#include <bits/stdc++.h>
#include <iostream>
#include<time.h>
#include <ctime> 
using namespace std; 


// BucketSort.cpp : Defines the entry point for the console application.
// Coded By : Sibtain Raza Jamali
//  Computer Scientist
//Obtenido de: https://gist.github.com/SibtainRazaJamali/5f70bb184d2a29cc223885f2af7c3c6c#file-bucket-sort-L30


struct node{
	int data;
	node* next;
};
int hashing(int element, int size, int max)
{
	int hash = (element*size) / (max + 1);
	return hash;
}

void bucketSort(int arr[], int n)
{
	int largest = 0;
	for (int i = 0; i<n; i++){
		if (arr[i]>largest){
			largest = arr[i];
		}
	}

	node **bucket = new node*[n];
	for (int i = 0; i<n; i++){
		bucket[i] = NULL;
	}

	for (int i = 0; i<n; i++){
		int index = hashing(arr[i], n, largest);
		node* newNode = new node;
		newNode->data = arr[i];
		if (bucket[index] == NULL || arr[i]<bucket[index]->data) {
			newNode->next = bucket[index];
			bucket[index] = newNode;
		}
		else if (arr[i] >= bucket[index]->data){
			node* current = bucket[index];
			node* parent = current;
			while (current && arr[i] >= current->data){
				parent = current;
				current = current->next;
			}

			if (parent->next==NULL){
				
				newNode->next = NULL;
				parent->next= newNode;
			}
			else if (arr[i] <= current->data){
				newNode->next = parent->next;
				parent->next = newNode;
			}

		}

	}

	for (int i = 0, j = 0; i<n; i++){
		node* current = bucket[i];
		while (current){
			arr[j++] = current->data;
			current = current->next;
		}
	}

}

/* Driver program to test above funtion */
int main() 
{ 

#define MAX_NUMEROS 500000

int arr[MAX_NUMEROS] = { 0 };

for(int a=0;a<MAX_NUMEROS;a++)
	{
  // generamos un numero
	int M = (rand() % 793);
    arr[a] = M;
	}
	
	int n = sizeof(arr)/sizeof(arr[0]);
	
	unsigned t0, t1;
	t0=clock();    //Corre tiempo
	bucketSort(arr, n); 
	t1 = clock();  //Termina de ejecutarse
	
	double time = (double(t1-t0)/CLOCKS_PER_SEC); //Se calcula el tiempo
	
	//printf("Sorted array: \n");  //Imrpimimos arras solo para corroborar
	//printArray(arr, n); 
	std::cout << "\nExecution Time: " << time << std::endl; //Imprimimos tiempo de ejecucion
	return 0; 
} 


