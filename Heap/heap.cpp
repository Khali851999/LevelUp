#include <bits/stdc++.h>
using namespace std;
class Heap
{
public:
    vector<int> arr;
    Heap(vector<int> a)
    {
        this->arr = a;

        for (int i = arr.size() - 1; i >= 0; i--)
            downHeapify(i, arr.size());   //O(n)
    }
    int top() //O(1)
    {
        if (arr.size() == 0)
            return -1;

        return arr[0];
    }
    void push(int ele) //O(log n)
    {
        arr.push_back(ele);
        upHeapify(arr.size() - 1, arr.size());
    }
    void pop() //O(log n)
    {
        if (arr.size() == 0)
            return;

        swap(arr[0], arr[arr.size() - 1]);
        arr.erase(arr.end() - 1);

        downHeapify(0, arr.size());
    }
    bool empty() //O(1)
    {
        return arr.size() == 0;
    }
    int size() //O(1)
    {
        return arr.size();
    }
    void downHeapify(int pi, int n) //O(log n)
    {
        //pi -> parentIdx

        int lci = 2 * pi + 1; //leftChildIdx
        int rci = 2 * pi + 2; //rightChildIdx

        int maxIdx = pi; //idx of maxElement

        if (lci < n && arr[lci] > arr[maxIdx])
            maxIdx = lci;

        if (rci < n && arr[rci] > arr[maxIdx])
            maxIdx = rci;

        if (maxIdx != pi)
        {
            swap(arr[maxIdx], arr[pi]);
            downHeapify(maxIdx, n);
        }
    }

    void upHeapify(int ci, int n) //O(log n)
    {
        int pi = (ci - 1) / 2;

        int minIdx = ci;

        if (arr[pi] < arr[minIdx])
            minIdx = pi;

        if (minIdx != ci)
        {
            swap(arr[minIdx], arr[ci]);
            upHeapify(pi, arr.size());
        }
    }
};
int main()
{
    vector<int> arr = {10, 20, 30, -2, -3, -4, 5, 6, 7, 8, 9, 22, 11, 13};
    Heap heap(arr);

    heap.push(100);
    heap.push(5);

    while (!heap.empty()) //O(n log n)
    {
        cout << heap.top() << " ";
        heap.pop();
    }
}