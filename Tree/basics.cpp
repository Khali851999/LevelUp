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

//============================================create Tree from preorder======================================================
int pos = 0;
Node *createTree(vector<int> preOrder)
{
    if (pos == preOrder.size() || preOrder[pos] == -1)
    {
        if (preOrder[pos] == -1)
            pos++;
        return nullptr;
    }

    Node *root = new Node(preOrder[pos++]);
    root->left = createTree(preOrder);
    root->right = createTree(preOrder);
    return root;
}
void displayTree(Node *root)
{
    if (root == nullptr)
        return;
    cout << (root->left ? root->left->val : -1);
    cout << " <- " << root->val << " -> ";
    cout << (root->right ? root->right->val : -1) << endl;
    displayTree(root->left);
    displayTree(root->right);
}

//===========================================NodetoRootPath=====================================================================================
vector<Node *> NodetoRootpath(Node *root, int data)
{
    if (root == nullptr)
        return vector<Node *>();
    vector<Node *> l = NodetoRootpath(root->left, data);
    if (!l.empty())
    {
        l.push_back(root);
        return l;
    }
    vector<Node *> r = NodetoRootpath(root->right, data);
    if (!r.empty())
    {
        r.push_back(root);
        return r;
    }
    return {root};
}
int main()
{
    vector<int> preOrder = {11, 6, 4, -1, 5, -1, -1, 8, -1, 10, -1, -1, 19, 17, -1, -1, 43, 31, -1, -1, 49, -1, -1};
    Node *root = createTree(preOrder);
    displayTree(root);
    return 0;
}