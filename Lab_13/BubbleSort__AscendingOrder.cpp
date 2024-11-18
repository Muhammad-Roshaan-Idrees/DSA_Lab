#include <iostream>
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
// Function to print the array
void printArray(int arr[], int n){
for(int i=0; i<n; i++){
cout<<arr[i]<<" ";
}
cout<<endl;
}
int main(){
int n;
cout << "Enter the number of registration numbers: ";
cin >> n;
int arr[n];
cout << "Enter the registration numbers: ";
for (int i = 0; i < n; i++) {
cin >> arr[i];
}
bubbleSort(arr, n);
cout << "Sorted registration numbers in ascending order: ";
printArray(arr, n);
return 0;
}
