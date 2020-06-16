#include <bits/stdc++.h>
using namespace std;
void nextGreaterLR(vector<int> &a)
{

    stack<int> st;
    vector<int> ans(a.size(), -1);

    for (int i = 0; i < a.size(); i++)
    {
        while (!st.empty() && a[st.top()] < a[i])
        {
            ans[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }

    for (auto x : ans)
        cout << x << " ";
    cout << endl;
}

void nextSmallerLR(vector<int> &a)
{

    stack<int> st;
    vector<int> ans(a.size(), -1);

    for (int i = 0; i < a.size(); i++)
    {
        while (!st.empty() && a[st.top()] > a[i])
        {
            ans[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }

    for (auto x : ans)
        cout << x << " ";
    cout << endl;
}

void nextGreaterRL(vector<int> &a)
{

    stack<int> st;
    vector<int> ans(a.size(), -1);

    for (int i = a.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && a[st.top()] < a[i])
        {
            ans[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }

    for (auto x : ans)
        cout << x << " ";
    cout << endl;
}

void nextSmallerRL(vector<int> &a)
{

    stack<int> st;
    vector<int> ans(a.size(), -1);

    for (int i = a.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && a[st.top()] > a[i])
        {
            ans[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }

    for (auto x : ans)
        cout << x << " ";
    cout << endl;
}
int main()
{
    vector<int> arr = {5, 8, 9, -1, 6, 2, 3, 7};
    nextGreaterLR(arr);
    nextSmallerLR(arr);
    nextGreaterRL(arr);
    nextSmallerRL(arr);
}