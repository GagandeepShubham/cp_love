/**
 * Problem 8: Arrays
 * Find largest sum in a contiguous subarray.
 * Date: 07/11/2020
 * Time complexity: O(n)
 * Kadane's Algorithm
**/

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

  //a[] = {2, -3, 4, 1, -5}  , ans = 5.
  //a[] = {-1, -2, -3, -4}  , ans = -1.

  int sum = 0, max = a[0];  //let say the maximum contig. subarray sum we got is a[0].
  for(i = 0; i < n; i++)
  {
    sum += a[i];  //add the value of current element in sum
    if(sum > max)max = sum; //if the sum until now is greater than previous max then assign it to max
    if (sum < 0) sum = 0;  
  }
  
  cout << "\nThe max contiguous subarray sum: " << max << "\n";
}
