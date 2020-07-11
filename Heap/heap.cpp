#include <bits/stdc++.h>
using namespace std;
class Heap
{
public:
    vector<int> arr;
    Heap(vector<int> arr)
    {
        this->arr = arr;

        for (int i = arr.size() - 1; i >= 0; i--)
            downHeapify(i, arr.size());
            
    }
    int top()
    {
        if (arr.size() == 0)
            return -1;

        return arr[0];
    }
    void push(int ele)
    {
        arr.push_back(ele);
        upHeapify(arr.size() - 1, arr.size());
    }
    void pop()
    {
        if (arr.size() == 0)
            return;

        swap(arr[0], arr[arr.size() - 1]);
        arr.erase(arr.end() - 1);

        downHeapify(0, arr.size());
    }
    bool empty()
    {
        return arr.size() == 0;
    }
    int size()
    {
        return arr.size();
    }
    void downHeapify(int pi, int n)
    {
        //pi -> parentIdx

        int lci = 2 * pi + 1; //leftChildIdx
        int rci = 2 * pi + 2; //rightChildIdx

        int maxIdx = pi; //idx of maxElement

        if (lci < n && arr[lci] > arr[pi])
            maxIdx = lci;

        if (rci < n && arr[rci] > arr[pi])
            maxIdx = rci;

        if (maxIdx != pi)
        {
            swap(arr[maxIdx], arr[pi]);
            downHeapify(maxIdx, n);
        }
    }

    void upHeapify(int ci, int n)
    {
        int pi = (ci - 1) / 2;

        int minIdx = ci;

        if (arr[pi] < arr[ci])
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

    while (!heap.empty())
    {
        cout << heap.top() << " ";
        heap.pop();
    }
}