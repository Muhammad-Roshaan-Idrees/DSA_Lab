#include <iostream>
#include <vector>
using namespace std;
int main() 
{
    int size, key;
    cout << "Enter the size of the array: ";
    cin >> size;

    if (size < 1) 
    {
        cout << "Invalid size. The array size should be at least 1." << endl;
        return 1;
    }

    vector<int> array(size);

    cout << "Enter " << size << " integers: " << endl;
    for (int i = 0; i < size; ++i)
    {
        cin >> array[i];
    }
    cout << "Enter the key to search for: ";
    cin >> key;

    bool found = false;
    for (int i = 0; i < size; ++i)
    {
        if (array[i] == key)
        {
            cout << "Key " << key << " found at position " << i+1 << "." << endl;
            found = true;
            break;
        }
    }

    if (!found) 
    {
        cout << "Key " << key << " not found in the array." << endl;
    }

    return 0;
}