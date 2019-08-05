
#include <bits/stdc++.h> 
using namespace std; 

void swap(int *xp, int *yp) 
{ 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
} 

void bubbleSort(int arr[], int n) 
{ 
    // Base case 
    if (n == 1) 
        return; 
  
    // One pass of bubble sort. After 
    // this pass, the largest element 
    // is moved (or bubbled) to end. 
    for (int i=0; i<n-1; i++) 
        if (arr[i] > arr[i+1]) 
            swap(arr[i], arr[i+1]); 
  
    // Largest element is fixed, 
    // recur for remaining array 
    bubbleSort(arr, n-1); 
} 

void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 


int main() 
{ 
	int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int arr[n];
        for(int i = 0; i<n; i++)
        {
            cin >> arr[i];
        } 
        bubbleSort(arr, n);
	    printArray(arr, n);    
    }
    
	return 0; 
} 

