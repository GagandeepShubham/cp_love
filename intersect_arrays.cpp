//Program to intersect two sorted arrays.
//Date: 06/11/2020
#include<iostream>
#include<vector>
using namespace std;

int main()
{
  int n, m, i, j;
  
  cout << "Enter size for array A: ";
  cin >> n;
  int a[n];

  cout << "Enter elements in array: ";
  for(i = 0; i < n; i++)cin >> a[i];


  cout << "Enter size for array B: ";
  cin >> m;
  int b[m];

  cout << "Enter elements in array: ";
  for(j = 0; j < m; j++)cin >> b[j];

  vector<int> res;
  i = 0, j = 0;

  while(true)
  {
    if(i == n)break;   //if i reaches end of the array of a then break
    if(j == n)break;   //if j reaches end of the array of b then break
    if(a[i] == b[j])
    {
      res.push_back(a[i]);
      i++;
      j++;
    }
    else
    {
      if(a[i] < b[j])i++;
      else j++;
    }
  }

  //printing the array
  cout << "\nIntersection of arrays: ";
  for(int x: res)cout << x << " ";
  cout << "\n";
}
