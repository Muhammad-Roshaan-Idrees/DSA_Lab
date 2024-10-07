//------------------ Binary Search of an array element--------------------

#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;
   while(low <= high)
   {
      int mid = low + (high - low) / 2; // Calculate mid to avoid overflow
      // Check if the target is at mid
      if(arr[mid] == target)
      {
         return mid;
      }
     // If the target is smaller than the mid element, search in the left half
      else if(arr[mid] > target)
      { 
          high = mid - 1;
      }
     // If the target is greater than the mid element, search in the right half
      else
      {
          low = mid + 1;
      } 
   } 
  return -1; // Target not found
}

int main()
{
    //  sorted array
    int arr[6];
    for(int i=1; i<=7; i++)
    {
        cout<<"\n Enter the values of Array at index: "<< i <<" is: "<<"\t";
        cin>>arr[i];
    }
    int size= sizeof (arr) / sizeof (arr[0]);
    int target;
    cout<<"\nEnter the value to be searched: "<<"\t";
    cin>>target;
    int result = binarySearch(arr, size, target);
    // Call binary search
    if(result!=-1)
    { 
        cout<<"Index " << result <<endl;
    }
    else
    {
        cout<<"Not Found"<<endl;
    }
    return 0;
}