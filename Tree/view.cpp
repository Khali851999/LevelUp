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

//====================================Vertical Order Sum==========================================================================
void VerticalOrderSum(Node *root)
{
    if (root == nullptr)
        return;

    int left = 1e7, right = -1e7;
    width(root, 0, left, right);

    int view[right - left + 1] = {};

    queue<pair<Node *, int>> q;
    q.push({root, -left});
    while (q.size())
    {
        int size = q.size();
        while (size--)
        {
            auto p = q.front();
            q.pop();
            Node *val = p.first;
            int x = p.second;

            view[x] += val->val;

            if (val->left != nullptr)
                q.push({val->left, x - 1});
            if (val->right != nullptr)
                q.push({val->right, x + 1});
        }
    }
}

//====================================Bottom View==========================================================================
//last element of each vertical level
void width(Node *root, int x, int &left, int &right)
{
    if (root == nullptr)
        return;

    right = max(right, x);
    left = min(left, x);

    width(root->left, x - 1, left, right);
    width(root->right, x + 1, left, right);
}
void BottomView(Node *root)
{
    if (root == nullptr)
        return;

    int left = 1e7, right = -1e7;
    width(root, 0, left, right);

    int view[right - left + 1] = {};

    queue<pair<Node *, int>> q;
    q.push({root, -left});
    while (q.size())
    {
        int size = q.size();
        while (size--)
        {
            auto p = q.front();
            q.pop();
            Node *val = p.first;
            int x = p.second;

            view[x] = val->val;

            if (val->left != nullptr)
                q.push({val->left, x - 1});
            if (val->right != nullptr)
                q.push({val->right, x + 1});
        }
    }

    for (auto y : view)
        cout << y << " ";
    cout << endl;
}

//====================================Top View==========================================================================
//first element of each vertical level
void BottomView(Node *root)
{
    if (root == nullptr)
        return;

    int left = 1e7, right = -1e7;
    width(root, 0, left, right);

    vector<int> view(right - left + 1, 1e7);

    queue<pair<Node *, int>> q;
    q.push({root, -left});
    while (q.size())
    {
        int size = q.size();
        while (size--)
        {
            auto p = q.front();
            q.pop();
            Node *val = p.first;
            int x = p.second;

            if (view[x] == 1e7)
                view[x] = val->val;

            if (val->left != nullptr)
                q.push({val->left, x - 1});
            if (val->right != nullptr)
                q.push({val->right, x + 1});
        }
    }
    for (auto y : view)
        cout << y << " ";
    cout << endl;
}

//=========================================Main Diagonal Traversal (\)===================================================================
//left jaate hue x-1 krro right jaate hue same rhne do ( its part of same diagonal)
void mainDiagonalWidth(Node *root, int x, int &left)
{
    if (root == nullptr)
        return;

    left = min(left, x);

    mainDiagonalWidth(root->left, x - 1, left);
    mainDiagonalWidth(root->right, x, left);
}

void MainDiagonalTraversal(Node *root)
{
    if (root == nullptr)
        return;

    int left = 1e7;
    mainDiagonalWidth(root, 0, left);

    vector<vector<int>> view(-left + 1, vector<int>());

    queue<pair<Node *, int>> q;
    q.push({root, -left});
    while (q.size())
    {
        int size = q.size();
        while (size--)
        {
            auto p = q.front();
            q.pop();
            Node *val = p.first;
            int x = p.second;

            view[x].push_back(val->val);

            if (val->left != nullptr)
                q.push({val->left, x - 1});
            if (val->right != nullptr)
                q.push({val->right, x});
        }
    }
    for (auto x : view)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    cout << endl;
}

//=========================================Secondary Diagonal View (/)===================================================================
void secondaryDiagonalWidth(Node *root, int x, int &right)
{
    if (root == nullptr)
        return;

    right = max(right, x);

    secondaryDiagonalWidth(root->left, x, right);
    secondaryDiagonalWidth(root->right, x + 1, right);
}

void SecondayDiagonalTraversal(Node *root)
{
    if (root == nullptr)
        return;

    int right = -1e7;
    secondaryDiagonalWidth(root, 0, right);

    vector<vector<int>> view(right + 1, vector<int>());

    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (q.size())
    {
        int s = q.size();
        while (s--)
        {
            auto p = q.front();
            q.pop();
            Node *val = p.first;
            int x = p.second;

            view[x].push_back(val->val);

            if (val->left != nullptr)
                q.push({val->left, x});
            if (val->right != nullptr)
                q.push({val->right, x + 1});
        }
    }

    for (auto x : view)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
}

//======================================Binary Tree as Doubly Linked List=========================================================
Node *head = nullptr;
Node *tail = nullptr;
void dll(Node *root)
{
    if (root == nullptr)
        return;

    dll(root->left);
    if (tail == nullptr)
    {
        head = root;
    }
    else
    {
        tail->right = root;
        root->left = tail;
    }
    tail = root;
    dll(root->right);
    
}
void bToDLL(Node *root, Node **head_ref)
{
    head = nullptr;
    tail = nullptr;
    dll(root);
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->right;
    }
    cout << endl;
    while (tail != nullptr)
    {
        cout << tail->val << " ";
        tail = tail->left;
    }
}