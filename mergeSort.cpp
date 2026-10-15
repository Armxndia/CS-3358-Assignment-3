#include <iostream>
using namespace std;
  
// Merges two sorted subarrays of A[]. 
// First sorted subarray is A[l..m].
// Second sorted subarray is A[m+1..r].
// You might want to call this function in function mergeSort().
void merge(int A[], int l, int m, int r) 
{ 
	int n1 = m - l + 1; //Size of left array
    int n2 = r - m; //Size of right array

	int* L = new int[n1]; //L is an array of size n1
	int* R = new int[n2]; //R is an array of size n2

	//Stores l->m in L and m+1->r in R
	for (int i = 0; i < n1; i++)
        L[i] = A[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[m + 1 + j];

	//pointer variables to traverse array
	int i = 0, j = 0, k = l;

	//Main Merge Portion
	//Compares starting at the index 0 of two halves of the split array then will store the correct value back into the main array
	while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    //Copy remaining to L if needed
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    //Copy remaining to R if needed
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }

	//Important :)
	delete[] L;
	delete[] R;
} 

// using mergeSort to sort sub-array A[l..r]  
// l is for left index and r is right index of the 
// sub-array of A[] to be sorted
void mergeSort(int A[], int l, int r) 
{ 
	//Base Case
	if (l >= r) return;

	//Mid Variable
	int m = ( l + (r-1) ) / 2;

	//Recursion
	mergeSort(A, l, m);
	mergeSort(A, m+1, r);

	//Convergence
	merge(A, l, m, r);
} 
  

int main() 
{ 
    cout << "Please enter the length (number of elements) of the input array: ";
	int n;
	cin >> n;
	
	if(n <= 0) {
		cout << "Illegal input array length!" << endl;
		return 0;
	}
	
	int* A = new int [n];
	
	cout << "Please enter each element in the array" << endl; 
	cout << "(each element must be an integer within the range of int type)." << endl;
	for(int i=0; i<n; i++) {
		cout << "A[" << i << "] = ";
		cin >> A[i];
	}
  
    cout << "Given array A[] is: "; 
	for(int i=0; i<n-1; i++)
		cout << A[i] << ",";
	cout << A[n-1] << endl;
	
  
    mergeSort(A, 0, n-1); 
  
    cout << "After mergeSort, sorted array A[] is: "; 
	for(int i=0; i<n-1; i++)
		cout << A[i] << ",";
	cout << A[n-1] << endl;
	
	
	delete [] A;
    return 0; 
} 