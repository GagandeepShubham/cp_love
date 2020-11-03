//Problem 6: Array
//Find Union and intersection of two sorted arrays.
//Date : 02/11/2020
#include<iostream>
#include<vector>
using namespace std;

int main()
{
  int i,j,n,m;
  int data;
  vector<int>a, b, res;
  cout << "Enter size for the array a: ";
  cin >>n;
  cout << "Enter the data in the array: ";
  for(i = 0; i < n; i++)
  {
    cin >> data;
    a.push_back(data);
  }

  cout << "\nEnter size for the array b: ";
  cin >> m;
  cout << "Enter the data in the array: ";
  for(j = 0; j < m; j++)
  {
    cin >> data;
    b.push_back(data);
  }
  

  //Merge the arrays:
  i = 0, j = 0;
  while(true)
  {
       if(i == a.size())break;
       if(j == b.size())break;

       if(a[i] < b[j])
       {
            res.push_back(a[i]);
            i++;
       }
       else if(a[i] > b[j])
       {
            res.push_back(b[j]);
            j++;
        }
       else if(a[i] == b[j])
       {
            res.push_back(a[i]);
            res.push_back(b[j]);
            i++;
            j++;
        }
    }



    while(i < a.size())
    {
        res.push_back(a[i]);
        i++;
    }

    while(j < b.size())
    {
        res.push_back(b[j]);
        j++;
    }

    cout << "\nUnion of the arrays: ";
    for(int x: res)cout << x << " ";
    cout << "\n";


    //Merge procedure for intersecting the arrays:
    res.clear();
    i = 0; j = 0;
    while(true)
    {
      if(i == a.size())break;
      if(j == b.size())break;

      if(a[i] == res[res.size() - 1])i++;
      if(b[j] == res[res.size() - 1])j++;
      if(a[i] < b[j]) 
      {
        res.push_back(a[i]);
        i++;
      }
      else if(a[i] > b[j]) 
      {
        res.push_back(b[j]);
        j++;
      }
      else if(a[i] == b[j])
      {
        res.push_back(a[i]);
        i++;
        j++;
      }
    }

    while(i < a.size())
    {
      res.push_back(a[i]);
      i++;
    }

    while(j < b.size())
    {
      res.push_back(b[j]);
      j++;
    }

    cout << "\nIntersection of the arrays: ";
    for(int x: res)cout << x << " ";
    cout << "\n";

}

