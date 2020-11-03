//Problem 4: Array
//Sort an array containing only 2, 0, 1.
//Time Complexity: O(n)
//Date: 30/10/2020

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v;
    int i, data, count_0 = 0, count_1 = 0, count_2 = 0;
    int n;
    cout << "Enter size for the array: ";
    cin >> n;
    cout << "Enter data in the array: ";
    for(i = 0; i < n; i++)
    {
        cin >> data;
        v.push_back(data);
        if(data == 0)count_0++;    //get the count of all the 0 elements
        if(data == 1)count_1++;    //get the count of all the 1 elements
        if(data == 2)count_2++;    //get the count of all the 2 elements
    }

    cout << "Array: ";
    for(int x: v)cout << x << " ";

    v.clear();
    
    for(i = 0; i < n; i++)
    {
        if(count_0 > 0)        //push all the 0 elements in the array first
        {
            v.push_back(0);
            count_0--;
            continue;
        } 
        if(count_1 > 0)        //push all the 1 elements in the array next.
        {
            v.push_back(1);
            count_1--;
            continue;
        }
        if(count_2 > 0)v.push_back(2);  //push all the 2 elements in the array last.
        count_2--;
    }

    cout << "\nAfter sorting, the array is: ";   //printing the array
    for(int x: v)cout << x << " ";

    cout << "\n";
}
