// C++ Program for counting sort 
//Obtenido de: https://www.geeksforgeeks.org/counting-sort/
#include <bits/stdc++.h>
#include<time.h>
#include <ctime> 

//Counting sort which takes negative numbers as well 
#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 
  
void countSort(vector <int>& arr) 
{ 
    int max = *max_element(arr.begin(), arr.end()); 
    int min = *min_element(arr.begin(), arr.end()); 
    int range = max - min + 1; 
      
    vector<int> count(range), output(arr.size()); 
    for(int i = 0; i < arr.size(); i++) 
        count[arr[i]-min]++; 
          
    for(int i = 1; i < count.size(); i++) 
           count[i] += count[i-1]; 
    
    for(int i = arr.size()-1; i >= 0; i--) 
    {  
         output[ count[arr[i]-min] -1 ] = arr[i];  
              count[arr[i]-min]--;  
    } 
      
    for(int i=0; i < arr.size(); i++) 
            arr[i] = output[i]; 
} 
  
void printArray(vector <int> & arr)  
{  
    for (int i=0; i < arr.size(); i++)  
        cout << arr[i] << " ";  
    cout << "\n";  
} 


// Driver code 
int main() 
{ 

#define MAX_NUMEROS 1000000000

vector<int> arr;

for(int a=0;a<MAX_NUMEROS;a++)
	{
  // generamos un numero
	int M = (rand() % 79365);
    arr.push_back(M);
	}
	
	int n = sizeof(arr)/sizeof(arr[0]);
	
	unsigned t0, t1;
	t0=clock();    //Corre tiempo
	countSort(arr); 
	t1 = clock();  //Termina de ejecutarse
	
	double time = (double(t1-t0)/CLOCKS_PER_SEC); //Se calcula el tiempo
	
	//printf("Sorted array: \n");  //Imrpimimos arras solo para corroborar
	//printArray(arr, n); 
	std::cout << "\nExecution Time: " << time << std::endl; //Imprimimos tiempo de ejecucion
	return 0; 
}

// This code is contributed by rathbhupendra 

