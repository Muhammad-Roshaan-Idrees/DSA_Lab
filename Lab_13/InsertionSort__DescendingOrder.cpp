#include<iostream>
using namespace std;
void insertionSort(int arr[], int n) {
for (int i = 0; i < n - 1; i++) {
for (int j = 0; j < n - i - 1; j++) {
if (arr[j] < arr[j + 1]) {
// Swap arr[j] and arr[j+1]
int temp = arr[j];
arr[j] = arr[j + 1];
arr[j + 1] = temp;
}
}
}
}
// Function to display the sorted array
void displayArray(int arr[], int n) {
for (int i = 0; i < n; i++) {
cout << arr[i] << " ";
}
cout << endl;
}
int main() {
int n;
cout << "Enter the number of registration numbers: ";
cin >> n;
int arr[n];
cout << "Enter the registration numbers: ";
for (int i = 0; i < n; i++) {
cin >> arr[i];
}
insertionSort(arr, n);
cout << "Sorted registration numbers in descending order: ";
displayArray(arr, n);
return 0;
}
