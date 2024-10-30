
#include<iostream>
using namespace std;
// Function to implement Bubble Sort
void bubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        // Last i elements are already sorted
        for(int j=0; j<n-i-1; j++){
            // Swap if current element is greater than the next element
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
// Function to print the  array

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[]={12,13,14,15,16};
    int arr2[]={12,13,15,2,7,4};
    int arr3[]={15,2,7,4,1,9};
    int n= sizeof(arr)/sizeof(arr[0]);
    int n1= sizeof(arr2)/sizeof(arr2[0]);
    int n2= sizeof(arr3)/sizeof(arr3[0]);

    cout<<"Original Array: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout<<"Sorted Array: ";
    printArray(arr, n);

    cout<<"Original Array: ";
    printArray(arr2, n);

    bubbleSort(arr2, n);

    cout<<"Nested Array: ";
    printArray(arr2, n);

    cout<<"Original Array: ";
    printArray(arr3, n);

    bubbleSort(arr3, n);

    cout<<"Reversed Array: ";
    printArray(arr3, n);

    return 0;
}

// Time Complexities:

// 1. Best Case:      O(n)
// 2. Average Case:   O(n^2)
// 3. Worst Case:     O(n^2)

