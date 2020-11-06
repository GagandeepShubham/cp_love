//Program for union of two sorted arrays:

#include<iostream>
#include<vector>
using namespace std;

int main()
{
  int n, m, i, j;
  cout << "enter size for array A: ";
  cin >> n;
  int a[n];
  
  cout << "Enter elements in array: ";
  for(i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  cout << "Enter size for array B: ";
  cin >> m;
  int b[m];
  cout << "Enter elements in array: ";
  for(i = 0; i < m; i++)
  {
    cin >> b[i];
  }

  i = 0, j = 0;
  vector<int> res;
  while(true)
  {
    if(i == n)break;
    if(j == n)break;
    if(!res.empty())
    {
      if(a[i] == res[res.size() - 1])i++;
      if(b[j] == res[res.size() - 1])j++;
    }
    if(a[i] == b[j])
    {
        res.push_back(a[i]);
        i++;
        j++;
    }
    else
    {
        if(a[i] < b[j])
        {
          res.push_back(a[i]);
          i++;
        }
        else if(b[j] < a[i])
        {
          res.push_back(b[j]);
          j++;
        }
        else
        {
          res.push_back(a[i]);
          res.push_back(b[j]);
          i++;
          j++;
        }
    }
  }

  while(i < n)             //pushing the remaining elements of a in res if any.
  {
    res.push_back(a[i]);
    i++;
  }

  while(j < m)             //pushing the remaining elements of b in res if any.
  {
    res.push_back(b[j]);
    j++;
  }

  cout << "Union of two arrays: ";
  for(int x: res)cout << x << " ";
  cout << "\n";

}
