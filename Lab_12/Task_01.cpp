
#include <iostream>
#include <vector>
using namespace std;

// Quick Sort with last element as pivot
void quickSortLastPivot(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high]; // pivot element (last element)
        int i = low - 1;       // index of smaller element

        for (int j = low; j < high; j++)
        {
            // If current element is smaller than or equal to pivot
            if (arr[j] <= pivot)
            {
                i++; // increment index of smaller element
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        // Recursively sort elements before and after partition
        quickSortLastPivot(arr, low, pi - 1);
        quickSortLastPivot(arr, pi + 1, high);
    }
}

// Quick Sort with first element as pivot
void quickSortFirstPivot(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = arr[low]; // pivot element (first element)
        int i = high + 1;     // index of larger element

        for (int j = high; j > low; j--)
        {
            // If current element is larger than or equal to pivot
            if (arr[j] >= pivot)
            {
                i--; // decrement index of larger element
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i - 1], arr[low]);
        int pi = i - 1;

        // Recursively sort elements before and after partition
        quickSortFirstPivot(arr, low, pi - 1);
        quickSortFirstPivot(arr, pi + 1, high);
    }
}

int main()
{
    vector<int> arr1 = {33, 12, 52, 3, 75, 29, 41, 6, 19};
    vector<int> arr2 = arr1; // Copy of the original array

    cout << "Original array: ";
    for (int i : arr1) cout << i << " ";
    cout << endl;

    // Sort with last element as pivot
    quickSortLastPivot(arr1, 0, arr1.size() - 1);
    cout << "Sorted array (Last Element as Pivot): ";
    for (int i : arr1) cout << i << " ";
    cout << endl;

    // Sort with first element as pivot
    quickSortFirstPivot(arr2, 0, arr2.size() - 1);
    cout << "Sorted array (First Element as Pivot): ";
    for (int i : arr2) cout << i << " ";
    cout << endl;

    return 0;
}