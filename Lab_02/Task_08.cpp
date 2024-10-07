// ------------------ Inserting an element at a specific index in a 4 * 4 matrix ---------------------

#include<iostream>
using namespace std;
int main()
{
    int arr[4][4];
    int val;
    bool found = false;
    cout<<"Enter the elements of 4*4 matrix :"<<endl;
    for(int i=0 ; i<4 ; i++)
    {
        for (int j=0 ; j<4 ; j++)
        {
            cout<<"Enter elements at position "<<"("<<i<<","<<j<<"):"<<endl;
            cin>>arr[i][j];
        }
    }
    cout<<"Enter value to search:";
    cin>>val;
    for(int i=0 ; i<4 ; i++)
    {
        for (int j=0 ; j<4 ; j++)
        {
            if(arr[i][j] == val)
            {
                cout<<"Value"<<val<<"found at position"<<"("<<i<<","<<j<<"):"<<endl;
                found = true;
                break;
            }
        }
      if(found)
      {
         break;
      }
    }
    if(!found)
    {
       cout<<"Value not found at any position"<<endl;
    }
    return 0;
}