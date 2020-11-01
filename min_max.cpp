//Problem2 :Array
//Finding minimum and maximum from an Array
//Date: 27/10/2020
#include<iostream>
#include<climits>
using namespace std;
#define nl cout << "\n"
#define deb(x) cout << #x << ":" << x << "\n";

int main()
{
  int i, n , min = INT_MAX, max = INT_MIN;
  cout << "Enter size for the array: ";
  cin >> n;
  int a[n];
  cout << "Enter data in array: ";
  for(i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  for(i = 0; i < n; i++)
  {
    if(a[i] < min)min = a[i];
    if(a[i] > max)max = a[i];
  }
  
  cout << "Minimum element is: " << min << "\n";
  cout << "Maximum element is: " << max << "\n";

}
