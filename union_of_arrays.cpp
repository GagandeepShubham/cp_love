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
    if(i == n)break;      //checking whether we reached the end of the array
    if(j == n)break;      
    if(!res.empty())
    {
      if(a[i] == res[res.size() - 1])i++;  //if the current element of array a is the last element in res array then skip the a's element
      if(b[j] == res[res.size() - 1])j++;  //if the current element of array b is the last element in res array then skip the b's element
    }
    if(a[i] == b[j])                       //if both current element of a and current element of b are equal then push only one 
    {
        res.push_back(a[i]);               
        i++;                               //increment index of a to consider next element from a
        j++;                               //increment index of b to consider next element from b
    }
    else
    {
        if(a[i] < b[j])                    //if current element of a is smaller than current element of b.
        {
          res.push_back(a[i]);             //then push the current element of a
          i++;                             //and move ahead.
        }
        else if(b[j] < a[i])               //if current element of b is smaller than current element of a.
        {
          res.push_back(b[j]);             //then push the current element of b.
          j++;                             //and move ahead
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
