// ------------------ Checking whether the number is a palindrome or not ---------------------

#include<iostream>
using namespace std;
int main()
{
  int num[6];
  
  cout << "Enter 6 integers: " << endl;
  for(int i =0; i<6; i++)
  { 
    cin >> num[i];
  }
  
  bool palindrome = false;
  for(int i=0; i<3; i++)
  {
    if(num[i] == num[5-i])
    {
      palindrome = true;  
      break;
      }
      else
      {
        palindrome = false;
      }
  }
  
  if (palindrome)
  {
   cout << "The array is a palindrome" << endl;
  }
  else
  {
   cout << "The array is not a palindrome" << endl;
  }
  
  return 0;
}