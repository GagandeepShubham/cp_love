//Problem 3: Array
//Finding the kth maximum and kth minimum from an array.
//Date : 29/10/2020
//Data structure used min_heap and max_heap.
//extra space : O(n);

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int Left(int i)
{
   return (2 * i + 1);
}

int Right(int i)
{
  return (2 * i + 2);
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void min_heapify(vector<int> &v, int i)
{
    int left_child = Left(i);
    int right_child = Right(i);
    int smallest = i;
    if(left_child < v.size() && v[left_child] < v[smallest])smallest = left_child;
    if(right_child < v.size() && v[right_child] < v[smallest])smallest = right_child;
    
    if(smallest != i)
    {
        swap(v[i], v[smallest]);
        min_heapify(v, smallest);
    }
}

int extract_min(vector<int> &v)
{
    int min = v[0];
    swap(v[0], v[v.size() - 1]);
    v.erase(v.begin() + v.size() - 1);
    min_heapify(v, 0);
    
    return min;
}


void build_min_heap(vector<int> &v)
{
    for(int i = v.size()/2; i >= 0 ; i--)
    {
        min_heapify(v, i);
    }
}
  
void max_heapify(vector<int> &w, int i)
{
    int left_child = Left(i);
    int right_child = Right(i);
    int largest = i;

    if(left_child < w.size() && w[left_child] > w[largest])largest = left_child;
    if(right_child < w.size() && w[right_child] > w[largest])largest = right_child;

    if(largest != i)
    {
        swap(w[i], w[largest]);
        max_heapify(w, largest);
    }
}

int extract_max(vector <int> &w) //extracts the max element from heap.
{
    int max = w[0];
    swap(w[0], w[w.size() -1]);
    w.erase(w.begin() + w.size() - 1); //erasing the max element from the heap.
    max_heapify(w, 0);
 
    return max;
}

void build_max_heap(vector<int> &w)
{
    for(int i = w.size()/2; i >= 0; i--)
    {
        max_heapify(w, i);
    }
}

int main()
{
    vector<int> v, w;
    int i, n , data;
    cout << "Enter size for the array: ";
    cin >> n;
    cout << "Enter data in the array: ";
    for(i = 0; i < n; i++)
    { 
        cin >> data;
        v.push_back(data);
        w.push_back(data);
    }

    build_min_heap(v); //building minheap from the array elements.

    int k;
    cout << "Enter k: ";
    cin >> k;

    int count = 1, min;
    while(count <= k)
    {
        min = extract_min(v);  //extracting the minimum element k times
        count++;
    }

    build_max_heap(w); //building maxheap from the array elements.

    count = 1;
    int max;
    while(count <= k)
    {
        max = extract_max(w); //extracting the maximum element k times
        count++;
    }

    cout << "The " << k << "th minimum element is: " << min << "\n"; 
    cout << "The " << k << "th maximum element is: " << max << "\n";
    
}    
