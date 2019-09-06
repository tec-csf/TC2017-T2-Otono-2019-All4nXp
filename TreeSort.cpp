// C++ program to implement Tree Sort 
//Obtenido de: 
#include<bits/stdc++.h> 
#include <iostream>
#include<time.h>
#include <ctime> 

using namespace std; 

struct Node 
{ 
	int key; 
	struct Node *left, *right; 
}; 

// A utility function to create a new BST Node 
struct Node *newNode(int item) 
{ 
	struct Node *temp = new Node; 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// Stores inoder traversal of the BST 
// in arr[] 
void storeSorted(Node *root, int arr[], int &i) 
{ 
	if (root != NULL) 
	{ 
		storeSorted(root->left, arr, i); 
		arr[i++] = root->key; 
		storeSorted(root->right, arr, i); 
	} 
} 

/* A utility function to insert a new 
Node with given key in BST */
Node* insert(Node* node, int key) 
{ 
	/* If the tree is empty, return a new Node */
	if (node == NULL) return newNode(key); 

	/* Otherwise, recur down the tree */
	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 

	/* return the (unchanged) Node pointer */
	return node; 
} 

// This function sorts arr[0..n-1] using Tree Sort 
void treeSort(int arr[], int n) 
{ 
	struct Node *root = NULL; 

	// Construct the BST 
	root = insert(root, arr[0]); 
	for (int i=1; i<n; i++) 
		insert(root, arr[i]); 

	// Store inoder traversal of the BST 
	// in arr[] 
	int i = 0; 
	storeSorted(root, arr, i); 
} 

// Driver Program to test above functions 
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
	treeSort(arr, n); 
	t1 = clock();  //Termina de ejecutarse
	
	double time = (double(t1-t0)/CLOCKS_PER_SEC); //Se calcula el tiempo
	
	//printf("Sorted array: \n");  //Imrpimimos arras solo para corroborar
	//printArray(arr, n); 
	std::cout << "\nExecution Time: " << time << std::endl; //Imprimimos tiempo de ejecucion
	return 0; 

} 

