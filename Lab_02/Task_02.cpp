// ------------------ Searching a number in a specific array ---------------------

#include<iostream>
using namespace std;
int main()
{
	int searchValue;
	cout<<"Enter Search Value: " <<endl;
	cin>>searchValue;
	bool found = false;
	int array[10] = {12,14,10,15,17,53,97,64,43,24};
	int i;
	for (i=0; i<9; i++)
	{
	 if (array[i] == searchValue)
	  {
		found = true;
		break;
	  }
	 else 
	 { 
		found = false;
	 }
	}
	if(found)
	{
	   cout << "Search Found: " << i << endl;    
	}
	else
	{
		cout << "The number was not found" << endl;
	}

	system("pause");
	return 0;
}