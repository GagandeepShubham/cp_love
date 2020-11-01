//Problem 3: Array
//Find the kth minimum and kth maximum from an array
//Date : 29/10/2020
#include<iostream>
#include<vector>
using namespace std;

struct val
{
  int min;
  int max;
  int index_min = 0;
  int index_max = 0;
};

struct val find_min_max(vector<int>&v, int i, int j) //finds the min and maximum value recursively
{
  if(i == j - 1) //only two elments are there, so just compare them and return min, max accordingly
  {
    struct val ans; //declared a variable to hold two values
    if(v[i] >= v[j])
    {
        ans.min = v[j];
        ans.index_min = j;
        ans.max = v[i];
        ans.index_max = i;
    }
    else
    {
        ans.min = v[i];
        ans.index_min = i;
        ans.max = v[j];
        ans.index_max = j;
    }
    return ans;
  }
  if(i == j) //only one element is there, so just assign the same value in both var and return 
  {
     struct val ans;
     ans.min = v[i];
     ans.max = v[j];
     ans.index_max = j;
     ans.index_min = i;
     return ans;
  }
   
  //else more than 2 elements are there
  int mid = (i + j)/2; //find the middle index
  
  struct val ans = find_min_max(v,i, mid); //find the min and max in range [i to mid]
  struct val ans1 = find_min_max(v,mid + 1, j);//find the min and max in range [mid+1 to j]

  struct val res;  //new struct value to hold two numbers

  //one comparison to find the min value among ans and ans1
  if(ans.min < ans1.min)
  {
    res.min = ans.min;
    res.index_min = ans.index_min;
  }
  else 
  {
    res.min = ans1.min;
    res.index_min = ans1.index_min;
  }

  //one comparison to find the max value among ans and ans1
  //one comparison to find the max value among ans and ans1
  if(ans.max < ans1.max)
  {
    res.max = ans1.max;
    res.index_max = ans1.index_max;
  }
  else 
  {
    res.max = ans.max;
    res.index_max = ans.index_max;
  }

  return res;

}


int main()
{
  vector<int> v;                       //to store array element
  int i, data, k, n, count = 1;
  int min, max;                        //to store min and max value
  int index_min, index_max;            //to store min and max vlaue index
  struct val ans;                      //structure having min and max values and their indices

  cout << "Enter size of array: ";
  cin >> n;
  cout << "Enter data in array: ";
  for(i = 0; i < n; i++)
  {
      cin >> data;
      v.push_back(data);
  }

  cout << "\nEnter the value for k: ";
  cin >> k;

  while(count < k)
  {
     ans = find_min_max(v, 0, v.size() - 1);
     min = ans.min;
     max = ans.max;
     index_min = ans.index_min;
     index_max = ans.index_max;
     auto it1 = v.begin() + index_min;
     auto it2 = v.begin() + index_max;
     if(it1 != v.end()) v.erase(it1); //erasing the min from the vector
     if(it2 != v.end()) v.erase(it2); //erasing the max from the vector
     count++;
   }

  //the above while loop will call the find_min_max function -> k - 1 times.
  //so to find the kth min and max we will have to call the find_min_max function 1 more time
  ans = find_min_max(v, 0, v.size() - 1);
  min = ans.min;
  max = ans.max;
  
  cout << "The " << k << "th minimum element is: " << min << "\n";
  cout << "The " << k << "th maximum element is: " << max << "\n";

  v.clear();
}

