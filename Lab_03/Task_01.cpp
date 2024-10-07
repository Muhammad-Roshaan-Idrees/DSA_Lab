//------------------ Linear Search of an array element--------------------

#include<iostream>
using namespace std;

int linearSearch(int arr[], int size, int target)
{
    // Traverse the array element by element
    for(int i=1; i<=size; i++)
    {
        if(arr[i] == target)
        {
             return i; // Return the index if target is found
        }
    }
    return -1; // Return -1 if target is not found
}
int main()
{
    int arr[10];
    int size;
    cout<<"Enter the size of array: "<<endl;
    cin>>size;
    for(int i=1; i<=size; i++)
    {
        cout<<"\n Enter the array element at index: "<< i <<" is: "<<"\t";
        cin>>arr[i];
    }
    
    size=sizeof (arr) / sizeof (arr[0]);
    int target;
    cout<<"\nEnter the value to be search: "<<"\t";
    cin>>target;

    int result = linearSearch(arr, size, target);

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