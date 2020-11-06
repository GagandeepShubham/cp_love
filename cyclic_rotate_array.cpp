//Array Problem: 7
//Cyclically rotate an array by one.
//Date: 06/11/2020

#include<iostream>
using namespace std;

int main()
{
  int n, i;
  cout << "Enter size for array: ";
  cin >> n;
  int a[n];

  cout << "Enter elements in array: ";
  for(i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  //Rotation part
  int temp1 = a[0] , temp2;
  for(i = 1; i < n; i++)
  {
    if(i == n - 1)
    {
      a[0] = a[i];
    }
    temp2 = a[i];
    a[i] = temp1;
    temp1 = temp2;
  }

  cout << "After rotating the array: ";
  for(i = 0; i < n; i++)cout << a[i] << " ";
  
  cout << "\n";
}
