// ------------------ Declaring and initializing an array of  first 10 natural numbers ---------------------

##include<iostream>
using namespace std;
int main()
{
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    for(int i = 0; i < 9; i++)
    {
        cout << array[i] << " ";
    }
    
    return 0;
}