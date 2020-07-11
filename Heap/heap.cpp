#include <bits/stdc++.h>
using namespace std;
class Heap
{
public:
    vector<int> arr;
    Heap(vector<int> arr)
    {
        this->arr = arr;
    }
    int top()
    {
        if (arr.size() == 0)
            return -1;

        return arr[0];
    }
    int push(int ele)
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
        int lci = 2 * pi + 1;
        int rci = 2 * pi + 2;

        int maxIdx = pi;

        if (arr[lci] > arr[pi])
            maxIdx = lci;

        if (arr[rci] > arr[pi])
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
}