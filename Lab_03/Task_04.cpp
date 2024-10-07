//------------------ Phone Contact Application --------------------
          //------------------ Searching Contact through Linear and Binary searching algorithms--------------------

#include <iostream>
#include <string>
using namespace std;
struct Contact
{
    string name;
    string phoneNo;
};

int linearSearch(Contact contacts[], int n, string target)
{
    for (int i = 0; i < n; i++)
    {
        if (contacts[i].name == target)
        {
            return i;
        }
    }
    return -1;
}

void sortingContacts(Contact contacts[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (contacts[j].name > contacts[j + 1].name)
            {
                Contact temp = contacts[j];
                contacts[j] = contacts[j + 1];
                contacts[j + 1] = temp;
            }
        }
    }
}

int binarySearch(Contact contacts[], int low, int high, string target)
{
    if (low > high)
    {
        return -1; // Not found
    }
    int mid = (low + high) / 2;
    if (contacts[mid].name == target)
    {
        return mid;
    }
    else if (contacts[mid].name > target)
    {
        return binarySearch(contacts, low, mid - 1, target);
    }
    else
    {
        return binarySearch(contacts, mid + 1, high, target);
    }
}

int main()
{
    int n;

    cout << "Enter the number of contacts: ";
    cin >> n;

    Contact contacts[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter name for contact " << i + 1 << ": ";
        cin >> contacts[i].name;
        cout << "Enter phone number for contact " << i + 1 << ": ";
        cin >> contacts[i].phoneNo;
    }

    string target;
    cout << "Enter the name to search for: ";
    cin >> target;

    int result1 = linearSearch(contacts, n, target);
    if (result1 != -1)
    {
        cout << "Found using Linear Search at index " << result1
             << " with phone number: " << contacts[result1].phoneNo << endl;
    }
    else
    {
        cout << "Not found using Linear Search." << endl;
    }

    sortingContacts(contacts, n);
   

    int result2 = binarySearch(contacts, 0, n - 1, target);
    if ( result2 != -1)
    {
        cout << "Found using Binary Search at index " << result2
             << " with phone number: " << contacts[result2].phoneNo << endl;
    }
    else
    {
        cout << "Not found using Binary Search." << endl;
    }

    return 0;
}
