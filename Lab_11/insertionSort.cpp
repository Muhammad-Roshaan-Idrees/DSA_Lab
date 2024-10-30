#include<iostream>
using namespace std;
// program for insertion sort

void insertionSort(int arr[], int n)
{
    for(int i=0; i<n; i++){
        int key=arr[i];
        int j=i-1;
        int no_of_iterations=0;

        while(j>=0 && arr[j]>key){
        arr[j+1]=arr[j];
        j=j-1;
        }
        arr[j+1]=key;
    }
}

void printArray(int arr[], int n){
   for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";    
   } 
   cout<<endl;
}


int main(){
    int arr[]={12,13,14,15,16};
    int arr2[]={12,13,15,2,7,4};
    int arr3[]={15,9,7,4,2,1};

    int n= sizeof(arr)/sizeof(arr[0]);
    int n1= sizeof(arr2)/sizeof(arr2[0]);
    int n2= sizeof(arr3)/sizeof(arr3[0]);

    cout<<"Original Array: ";
    printArray(arr, n);

    insertionSort(arr, n);

    cout<<"Sorted Array: ";
    printArray(arr, n);

    cout<<"Original Array: ";
    printArray(arr2, n);

    insertionSort(arr2, n);

    cout<<"Nested Array: ";
    printArray(arr2, n);

    cout<<"Original Array: ";
    printArray(arr3, n);

    insertionSort(arr3, n);

    cout<<"Reverse Array: ";
    printArray(arr3, n);

    return 0;
}

// Time Complexities:

// 1. Best Case:   O(n)
// 2. Average Case:   O(n^2)
// 3. Worst Case:   O(n^2)

