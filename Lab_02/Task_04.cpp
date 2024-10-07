// ------------------ Deleting an element at a specific position ---------------------

#include<iostream>
using namespace std;

int main()
{
    int arr[10],n,index,x;
    cout<<"Enter size of array: "<<endl;
    cin>>n;
    cout<<"Enter array elements: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the index you want to delete: " <<endl;
    cin>>index;

    arr[index-1]=0;
    n++;

    for(int i=0; i<n-1; i++)
    {
        cout<<arr[i];
    }
    return 0;
}