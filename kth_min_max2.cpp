//Problem 3: Array
//Finding the kth maximum and kth minimum from an array.
//Date : 29/10/2020
//Data structure used min_heap and max_heap.
//extra space : O(n);

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int Left(int i)              //returns the index of left child
{
   return (2 * i + 1);
}

int Right(int i)            //returns the index of the right child
{
  return (2 * i + 2);
}

void swap(int *a, int *b)   //function to swap two elements
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void min_heapify(vector<int> &v, int i)  //function to min heapify a given array
{
    int left_child = Left(i);            //find the index of left child of the current element v[i]
    int right_child = Right(i);          //find the index of right child of the current element v[i]
    int smallest = i;                    //consider the current element v[i] to be smallest till now.
    if(left_child < v.size() && v[left_child] < v[smallest])smallest = left_child;     //if left child is smaller than current 
    if(right_child < v.size() && v[right_child] < v[smallest])smallest = right_child;  //if right child is smaller than current
    
    if(smallest != i)                    //if the current element v[i] is indeed not smaller then , it will be true
    {
        swap(v[i], v[smallest]);         //swap the smaller element with current element v[i]
        min_heapify(v, smallest);        //min heapify the heap, from the new smallest element
    }
}

int extract_min(vector<int> &v)         //finds the minimum element and save it in min variable, and deletes it from the heap
{ 
    int min = v[0];                     //min element will surely be on root in min heap
    swap(v[0], v[v.size() - 1]);        //swap the min element with the last element in heap
    v.erase(v.begin() + v.size() - 1);  //delete the last element
    min_heapify(v, 0);                  //min heapify from root
    
    return min;                         //return the saved min element
}


void build_min_heap(vector<int> &v)      //builds the heap by calling min heapify
{
    for(int i = v.size()/2; i >= 0 ; i--)  //start from the first non leaf
    {
        min_heapify(v, i);
    }
}
  
void max_heapify(vector<int> &w, int i)   //max heapify the given heap
{
    int left_child = Left(i);             //finds the index of the left child
    int right_child = Right(i);           //finds the index of the right child
    int largest = i;                      //assume that current element v[i] is the largest element

    if(left_child < w.size() && w[left_child] > w[largest])largest = left_child;       //if the left child is larger than parent
    if(right_child < w.size() && w[right_child] > w[largest])largest = right_child;    //if right child is learger than parent

    if(largest != i)                 //if any of the child of the parent is larger than it, then it will be true
    {
        swap(w[i], w[largest]);      //swap the larger child with the parent w[i]
        max_heapify(w, largest);     //max heapify the heap from the largest child index
    }
}

int extract_max(vector <int> &w) //extracts the max element from heap.
{
    int max = w[0];              //max element will be at the root of the max heap, store it in var max
    swap(w[0], w[w.size() -1]);  //swap the max element with the last element
    w.erase(w.begin() + w.size() - 1); //erasing the max element from the heap.
    max_heapify(w, 0);            //max heapify again from root
 
    return max;                  //return the max element
}

void build_max_heap(vector<int> &w)  //builds the max heap
{
    for(int i = w.size()/2; i >= 0; i--)    //start from the first non leave from end
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
