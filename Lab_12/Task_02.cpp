
#include <iostream>
#include <vector>
#include <ctime>    // For time()

using namespace std;

// Quick Sort with last element as pivot (original method)
void quickSortLastPivot(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high]; // pivot element (last element)
        int i = low - 1;       // index of smaller element

        for (int j = low; j < high; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quickSortLastPivot(arr, low, pi - 1);
        quickSortLastPivot(arr, pi + 1, high);
    }
}

// Quick Sort with random element as pivot
void quickSortRandomPivot(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        // Select a random pivot and swap it with the last element
        int randomIndex = low + rand() % (high - low + 1);
        swap(arr[randomIndex], arr[high]);

        // Print selected random pivot index and value
        cout << "Random pivot selected: index " << randomIndex 
             << " (value " << arr[high] << ")" << endl;

        int pivot = arr[high]; // pivot element (randomly selected and swapped to the end)
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quickSortRandomPivot(arr, low, pi - 1);
        quickSortRandomPivot(arr, pi + 1, high);
    }
}

int main()
{
    // Initialize random seed
    srand(time(0));

    // Create an array to sort
    vector<int> arr = {33, 12, 52, 3, 75, 29, 41, 6, 19};
    vector<int> arrCopy = arr; // Copy for second method

    // Sort with last element as pivot
    quickSortLastPivot(arr, 0, arr.size() - 1);
    cout << "Sorted array (Last Element as Pivot): ";
    for (int i : arr) cout << i << " ";
    cout << endl;

    // Sort with random element as pivot
    quickSortRandomPivot(arrCopy, 0, arrCopy.size() - 1);
    cout << "Sorted array (Random Element as Pivot): ";
    for (int i : arrCopy) cout << i << " ";
    cout << endl;

    return 0;
}