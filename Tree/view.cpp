#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int val)
    {
        this->val = val;
    }
};

//================================================LEFT VIEW========================================================
//first element of each level will give left view
void LeftView(Node *node)
{
    queue<Node *> q;
    q.push(node);
    vector<int> leftView;
    while (q.size())
    {
        int size = q.size();
        leftView.push_back(q.front()->val);
        while (size--)
        {
            Node *value = q.front();
            q.pop();

            //first left call then right
            if (value->left != nullptr)
                q.push(value->left);
            if (value->right != nullptr)
                q.push(value->right);
        }
    }

    for (auto x : leftView)
        cout << x << endl;
}
//==============================================RIGHT VIEW=========================================================
//first element of each level will give right view if call are made 1. right 2. left
void RightView_1(Node *node)
{
    queue<Node *> q;
    q.push(node);
    vector<int> rightView;
    while (q.size())
    {
        int size = q.size();
        rightView.push_back(q.front()->val);
        while (size--)
        {
            Node *value = q.front();
            q.pop();
            if (value->right != nullptr)
                q.push(value->right);
            if (value->left != nullptr)
                q.push(value->left);
        }
    }

    for (auto x : rightView)
        cout << x << endl;
}

//last element of each level will give right view if call are made 1. left 2. right
void RightView_2(Node *node)
{
    queue<Node *> q;
    q.push(node);
    vector<int> rightView;
    while (q.size())
    {
        int size = q.size();
        int last_ele = 0;
        while (size--)
        {
            Node *value = q.front();
            q.pop();

            last_ele = value->val;

            if (value->left != nullptr)
                q.push(value->left);
            if (value->right != nullptr)
                q.push(value->right);
        }
        rightView.push_back(last_ele);
    }

    for (auto x : rightView)
        cout << x << endl;
}
//==============================================VERTICAL VIEW=========================================================
void verticalTraversal(Node *root)
{
    if (root == nullptr)
        return;

    //ordered map
    map<int, vector<int>> omap;
    queue<pair<Node *, int>> q;

    q.push({root, 0});
    while (q.size())
    {
        int size = q.size();
        while (size--)
        {
            auto p = q.front();
            q.pop();
            Node *value = p.first;
            int x = p.second;

            omap[x].push_back(value->val);

            if (value->left != nullptr)
                q.push({value->left, x - 1});
            if (value->right != nullptr)
                q.push({value->right, x + 1});
        }
    }

    vector<vector<int>> res;
    for (auto x : omap)
    {
        for (auto y : x.second)
            cout << y << " ";
        cout << endl;
    }
}
