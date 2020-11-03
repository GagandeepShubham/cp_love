//Problem 6: Array
//Find Union and intersection of two sorted arrays.
//I am using the merge procedure which we use in a mergesort algorithm to merge two sorted
//arrays.
//Time complexity: O(m+n), m and n size of the arrays.
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
  

  //Union of two arrays using the merge procedure
  i = 0, j = 0;
  while(true)
  {
       if(i == a.size())break; //if the i reaches to the end of first array then exit while loop
       if(j == b.size())break; //if the j reaches to the end of second array then exit while loop

       if(a[i] < b[j]) //if ith element of a is lesser then the jth element of b
       {
            res.push_back(a[i]); //push the smaller element in the res array
            i++;                 //increment the i index to consider the next element of array a
       }
       else if(a[i] > b[j]) //if the jth element of the b is smaller than the ith element of a
       {
            res.push_back(b[j]); //push the smaller element in the result array.
            j++;                 //increment the j index to consider the next element of array b
        }
       else if(a[i] == b[j]) //if the both elements are equal then push both of them (union)
       {
            res.push_back(a[i]);
            res.push_back(b[j]);
            i++;             //increment i to consider next element of a
            j++;             //increment j to consider next element of b
        }
    }



    //Only one of the following while loops will execute
    while(i < a.size())  // if some elements are still remaining in a then push all of them in res
    {
        res.push_back(a[i]);
        i++;
    }

    while(j < b.size()) //if some elements are still remaining in b then push all of them in res.
    {
        res.push_back(b[j]);
        j++;
    }

    cout << "\nUnion of the arrays: ";
    for(int x: res)cout << x << " "; //printing the result of union of the arrays.
    cout << "\n";


    //Merge procedure for intersecting the arrays:
    res.clear();  
    i = 0; j = 0;
    while(true)
    {
      if(i == a.size())break; //if i reaches end then break because all elements of a would've been compared.
      if(j == b.size())break; //if j reaches end then break because all elements of b would've been compared.

      if(a[i] == res[res.size() - 1])i++; //if the current element of a matches the last element in res then skip the a[i].
      if(b[j] == res[res.size() - 1])j++; //if the current element of b matches the last element in res then skip the b[i].
      if(a[i] < b[j])  //if the current element of a is smaller than the current element of b
      {
        res.push_back(a[i]); //push the smaller element in res
        i++;                 //increment i to consider next element of a.
      }
      else if(a[i] > b[j])  // if the current element of b is smaller than the current element of a.
      {
        res.push_back(b[j]); //push the smaller element in res.
        j++;                 //increment j to consider next element of b.
      }
      else if(a[i] == b[j]) //if both the current elements, a[i] and b[j] are equal then push only one of them.
      {
        res.push_back(a[i]); //push either a[i] or b[j], both are same.
        i++;                 //increment i to consider next element of a.
        j++;                 //increment j to consider next element of b.
      }
    }

    //only one of the while loop will execute.
    while(i < a.size()) //if some elements are still remaining in a then push them all in the res array.
    {
      res.push_back(a[i]);
      i++;
    }

    while(j < b.size()) //if some elements are still remaining in b then push them all in the res array.
    {
      res.push_back(b[j]);
      j++;
    }

    cout << "\nIntersection of the arrays: ";
    for(int x: res)cout << x << " ";                //printing the result of intersection.
    cout << "\n";

}

