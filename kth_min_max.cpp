//Problem 3: array
//Find kth min and max element from an array
//Time complexity: O(nlogn)

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
  vector<int> v;
  int i, n , data, k;
  cout << "Enter the size for array: ";
  cin >> n;
  cout << "Enter data in array: ";
  for(i = 0; i < n; i++)
  {
        cin >> data;
        v.push_back(data);
  }

  //sort the array
  sort(v.begin(), v.end());
  cout << "Enter the value for k: ";
  cin >> k;
 
  while(k > n)
  {
    if(k > n)cout << "\n\tInvalid k!, enter again.\n";
    cout << "\nEnter the value for k: ";
    cin >> k;
  }
  cout << "The " << k << "th minimum element in the array is: " << v[k - 1];
  cout << "\nThe " << k << "th maximum element in the arrya is: " << v[n - k];
  cout << "\n";
}
