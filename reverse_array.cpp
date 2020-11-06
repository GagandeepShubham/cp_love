//Array: Problem 1
//Program to reverse and Array/String
//Time complexity: O(n)
//Date: 27/10/2020

#include<iostream>
using namespace std;
#define nl cout << "\n"
#define deb(x) cout << #x << ":" << x << "\n";

int main()
{
  int i, n;
  cout << "Enter size for the array: ";
  cin >> n;
  int a[n];
  cout << "Enter data in the array: ";
  for(i = 0; i < n; i++)
  {
      cin >> a[i];
  }

  cout << "Original Array:";
  for(int x: a)cout << x << " ";
  cout << "\n";

  int temp; //to temporarily hold the value
  for(i = 0; i < n; i++)
  {
      if(i == (n / 2))break;   //if i reaches in the middles then break
      temp = a[i];             //else get the ith element and its opposite element and then swap them
      a[i] = a[n - i - 1];     
      a[n - i - 1] = temp;     
  }

  cout << "Reversed Array:";
  for(int x: a)cout << x << " ";
  cout << "\n";
}
