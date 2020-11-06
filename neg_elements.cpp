//Problem 5: Array
//Move all the negative elements to the one side of the array
//Time complexity: O(n)
//Date: 01/11/2020

#include<iostream>
using namespace std;

int main()
{
    int i, n;
    cout << "Enter size for the array: ";
    cin >> n;
    int a[n];

    cout << "Enter data in the array: ";
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    //Check whether the array is already in the required format.
    
    int streak_neg = 0, streak_pos = 0, streak_neg_end = 0, streak_pos_end = 0;
    int ans = 1; //to indicate that array is already in required format
    for(i = 1; i < n; i++)
    {
        if((a[i] >= 0 && streak_neg == 0) || (a[i] >= 0 && streak_neg_end == 1))streak_pos++;
        else if((a[i] < 0 && streak_pos == 0) || (a[i] < 0 && streak_pos_end == 1))streak_neg++;
        if(a[i] < 0 && a[i - 1] >= 0)streak_pos_end = 1;
        if(a[i] >= 0 && a[i - 1] < 0)streak_neg_end = 1;
        if(a[i] < 0 && streak_neg_end == 1)
        {
            ans = 0;
            break;
        }
        else if(a[i] >= 0 && streak_pos_end == 1)
        {
            ans = 0;
            break;
        }
    }
    
    if(ans == 0) // if the array is not in required format then only do this.
    {
      int j = 0, temp;
      i = -1;
      while(j < n)
      {
        if(a[j] < 0)
        {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        j++;
      }
    }

    if(ans == 1)cout << "Array already in required format!!\n";
    else cout << "Array after moving all the negative elements to one side: \n";
    for(i = 0; i < n; i++)cout << a[i] << " ";

    cout << "\n";

}

