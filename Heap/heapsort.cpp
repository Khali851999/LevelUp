#include <bits/stdc++.h>
using namespace std;
void downHeapify(vector<int> &arr, int pi, int n)
{

    int lci = 2 * pi + 1;
    int rci = 2 * pi + 2;

    int maxIdx = pi;
    if (lci < n && arr[lci] > arr[maxIdx])
        maxIdx = lci;

    if (rci < n && arr[rci] > arr[maxIdx])
        maxIdx = rci;

    if (maxIdx != pi)
    {
        swap(arr[maxIdx], arr[pi]);
        downHeapify(arr, maxIdx, n);
    }
}
void heapSort(vector<int> &arr)
{
    int n = arr.size();

    //1. create max heap
    for (int i = n - 1; i >= 0; i--)
        downHeapify(arr, i, n);

    //2. topmost elemet of the heap is max element to put that in last
    //3. heapify the heap again
    while (n--)
    {
        swap(arr[0], arr[n]);   //swap 0, n-1
        downHeapify(arr, 0, n); //heapify 0 til n -2
    }

    for (auto x : arr)
        cout << x << " ";
    cout << endl;
}
int main()
{
    vector<int> arr = {10, 20, 30, -2, -3, -4, 5, 6, 7, 8, 9, 22, 11, 13};

    heapSort(arr);
    
}