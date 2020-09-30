#include <bits/stdc++.h>
using namespace std;
class Heap
{
public:
    vector<int> arr;
    bool isMaxHeap = true;

    Heap(vector<int> a, bool isMaxHeap)
    {
        this->arr = a;
        this->isMaxHeap = isMaxHeap;

        for (int i = arr.size() - 1; i >= 0; i--)
            downHeapify(i, arr.size()); //O(n)
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

    bool compare(int x, int y)
    {

        if (isMaxHeap)
            return x > y;
        else
            return x < y;

    }
    void downHeapify(int pi, int n) //O(log n)
    {
        //pi -> parentIdx

        int lci = 2 * pi + 1; //leftChildIdx
        int rci = 2 * pi + 2; //rightChildIdx

        int maxIdx = pi; //idx of maxElement

        if (lci < n && compare(arr[lci], arr[maxIdx]))
            maxIdx = lci;

        if (rci < n && compare(arr[rci], arr[maxIdx]))
            maxIdx = rci;

        // if (lci < n && arr[lci] > arr[maxIdx])
        //     maxIdx = lci;

        // if (rci < n && arr[rci] > arr[maxIdx])
        //     maxIdx = rci;

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

        if (pi >= 0 && compare(arr[minIdx], arr[pi]))
            minIdx = pi;

        // if (pi >= 0 && arr[pi] < arr[minIdx])
        //     minIdx = pi;

        if (minIdx != ci)
        {
            swap(arr[minIdx], arr[ci]);
            upHeapify(minIdx, arr.size());
        }
    }
};
int main()
{
    vector<int> arr = {10, 20, 30, -2, -3, -4, 5, 6, 7, 8, 9, 22, -9, 6, 11, 99};
    Heap heap(arr, 0);

    heap.push(18);
    heap.push(-5);
    heap.push(201);
    heap.push(116);
    heap.pop();

    while (!heap.empty()) //O(n log n)
    {
        cout << heap.top() << " ";
        heap.pop();
    }
}
