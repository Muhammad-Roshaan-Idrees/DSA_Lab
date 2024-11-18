
#include <iostream>
#include <vector>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For clock() and time()

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
        int randomIndex = low + rand() % (high - low + 1);
        swap(arr[randomIndex], arr[high]);

        int pivot = arr[high]; // pivot element
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

// Function to measure performance
void measurePerformance(int size)
{
    vector<int> arr(size);
    for (int &num : arr) {
        num = rand() % 10000; // Random values between 0 and 9999
    }

    vector<int> arrCopy = arr; // Copy for second sorting method

    cout << "\nArray Size: " << size << endl;

    // Measure time for Quick Sort with last element as pivot
    clock_t start = clock();
    quickSortLastPivot(arr, 0, arr.size() - 1);
    clock_t end = clock();
    double timeLastPivot = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time (Last Element as Pivot): " << timeLastPivot << " seconds" << endl;

    // Measure time for Quick Sort with random element as pivot
    start = clock();
    quickSortRandomPivot(arrCopy, 0, arrCopy.size() - 1);
    end = clock();
    double timeRandomPivot = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time (Random Element as Pivot): " << timeRandomPivot << " seconds" << endl;
}

int main()
{
    // Initialize random seed
    srand(time(0));

    // Measure performance for different array sizes
    measurePerformance(100);     // Small array
    measurePerformance(1000);    // Medium array
    measurePerformance(10000);   // Large array

    return 0;
}
