//Problem2: Array
//Find the min and max element in the given array
//Using Divide and Conquer technique.
//Time complexity is : O(n), but average comparison are reduced:(3n/2 - 1)
//Date: 28/10/2020

#include<iostream>
#include<vector>
using namespace std;


struct val  //to store the minimum and maximum value
{
  int min;
  int max;
};

struct val find_min_max(vector<int>&v, int i, int j) //finds the min and maximum value recursively
{
  if(i == j - 1) //only two elments are there, so just compare them and return min, max accordingly
  {
    struct val ans; //declared a variable to hold two values
    if(v[i] >= v[j])
    {
        ans.min = v[j];
        ans.max = v[i];
    }
    else
    {
        ans.min = v[i];
        ans.max = v[j];
    }
    return ans;
  }
  if(i == j) //only one element is there, so just assign the same value in both var and return 
  {
     struct val ans;
     ans.min = v[i];
     ans.max = v[j];
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
  }
  else 
  {
    res.min = ans1.min;
  }

  //one comparison to find the max value among ans and ans1
  if(ans.max < ans1.max)
  {
    res.max = ans1.max;
  }
  else 
  {
    res.max = ans.max;
  }

  return res;

}

int main()
{
  vector<int>v;
  int i, n, data;
  int min,max;
  struct val ans;

  cout << "Enter size for the array: ";
  cin >> n;
  cout << "Enter data in the array:";
  for(i = 0; i < n; i++)
  {
      cin >> data;
      v.push_back(data);
  }

  ans = find_min_max(v,0,n-1); //0 and n-1 are indices of first and last element
  min = ans.min;
  max = ans.max;

  cout << "\nMaximum element in the array is: " << max << "\n";
  cout << "Minimum element in the array is: " << min << "\n";
}

