// ------------------ Transpose of a 4 * 4 matrix ---------------------

#include<iostream>
using namespace std;
int main()
{
    int a[4][4],i,j;
    cout<<"Enter values for matrices: "<<endl;
    for(int i=0; i<4; i++)
    {
      for(int j=0; j<4; j++)
       {
           cin>>a[i][j];
        }
    }
    cout<<"Transpose is:";
    for(int i=0; i<4; i++)
    {
      for(int j=0; j<4; j++)
      {
          cout<<a[j][i]<<"  ";
      }
    cout<<endl;
    }
    return 0;
}