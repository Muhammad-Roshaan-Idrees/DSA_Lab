
#include <iostream>
#include <vector>

using namespace std;

// Merge function to combine two sorted halves
void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1; // Size of left half
    int n2 = right - mid;    // Size of right half

    // Create temporary arrays for left and right halves
    vector<int> L(n1);
    vector<int> R(n2);

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0;    // Initial index of first subarray
    int j = 0;    // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L if any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R if any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to display array content
void displayArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

// Function to test Merge Sort on various arrays
void testMergeSort()
{
    vector<vector<int>> testArrays = {
        {38, 27, 43, 3, 9, 82, 10},
        {12, 11, 13, 5, 6, 7},
        {5, 1, 4, 2, 8},
        {10, 3, 8, 9, 4, 6, 7},
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1},
        {1, 3, 2, 5, 4},
        {}};

    for (auto &array : testArrays)
    {
        vector<int> arrCopy = array; // Create a copy for sorting
        mergeSort(arrCopy, 0, arrCopy.size() - 1);
        cout << "Sorted array: ";
        displayArray(arrCopy);
    }
}

int main()
{
    testMergeSort();
    return 0;
}