#include <bits/stdc++.h>
using namespace std;
void next_greater_on_right(vector<int> &a)
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

void next_smaller_on_right(vector<int> &a)
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

void next_greater_on_left(vector<int> &a)
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

void next_smaller_on_left(vector<int> &a)
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
    vector<int> arr = {2, -1, 8, 6, 9, 4, 3, 5};
    next_greater_on_right(arr);
    next_smaller_on_right(arr);
    next_greater_on_left(arr);
    next_smaller_on_left(arr);
}