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
Node *createBST(vector<int> &arr, int start, int end)
{
    if (start > end)
        return nullptr;

    int mid = (start + end) >> 1;
    Node *node = new Node(arr[mid]);
    node->left = createBST(arr, start, mid - 1);
    node->right = createBST(arr, mid + 1, end);
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
bool find(Node *root, int data)
{
    Node *curr = root;
    if (curr == nullptr)
        return 0;
    while (curr != nullptr)
    {
        if (curr->val == data)
            return 1;
        else if (curr->val > data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return 0;
}
int minimum(Node *root)
{
    if (root == nullptr)
        return 0;

    Node *curr = root;
    while (curr->left != nullptr)
        curr = curr->left;

    return curr->val;
}
int maximum(Node *root)
{
    if (root == nullptr)
        return 0;

    Node *curr = root;
    while (curr->right != nullptr)
        curr = curr->right;

    return curr->val;
}
int main()
{
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120};
    Node *root = createBST(arr, 0, arr.size() - 1);
    displayTree(root);
    cout << find(root, 90) << endl;
    cout << find(root, 150) << endl;
    cout << minimum(root) << endl;
    cout << maximum(root) << endl;
}