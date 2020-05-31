#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left = nullptr;
    Node *right = nullptr;
    int height = 0;
    int balance = 0;
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
//==============================================Rotations==============================================================================
void UpdateHeightBalance(Node *root)
{
    int lh = -1, rh = -1;
    if (root->left)
        lh = root->left->height;
    if (root->right)
        rh = root->right->height;

    root->height = max(lh, rh) + 1;
    root->balance = lh - rh;
}
Node *ll(Node *A)
{
    Node *B = A->left;
    Node *Bright = B->right;
    B->right = A;
    A->left = Bright;

    UpdateHeightBalance(A);
    UpdateHeightBalance(B);
    return B;
}
Node *rr(Node *A)
{
    Node *B = A->right;
    Node *Bleft = B->left;
    B->left = A;
    A->right = Bleft;

    UpdateHeightBalance(A);
    UpdateHeightBalance(B);
    return B;
}
Node *rl(Node *A)
{
    Node *B = A->right;
    A->right = ll(B);
    return rr(A);
}
Node *rl(Node *A)
{
    Node *B = A->right;
    Node *C = B->left;
    Node *Cleft = C->left;
    Node *Cright = C->right;
    C->left = A;
    C->right = B;
    A->right = Cleft;
    B->left = Cright;

    UpdateHeightBalance(A);
    UpdateHeightBalance(B);
    UpdateHeightBalance(C);

    return C;
}
Node *lr(Node *A)
{
    Node *B = A->left;
    Node *C = B->right;
    Node *Cleft = C->left;
    Node *Cright = C->right;
    C->left = B;
    C->right = A;
    B->right = Cleft;
    A->left = Cright;

    UpdateHeightBalance(A);
    UpdateHeightBalance(B);
    UpdateHeightBalance(C);

    return C;
}
Node *addition(Node *root, int data)
{
    if (root == nullptr)
        return new Node(data);
    if (data > root->val)
    {
        root->right = addition(root->right, data);
    }
    else
    {
        root->left = addition(root->left, data);
    }

    return root;
}
void AVL(Node *root)
{
}
int main()
{
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120};
    Node *root = createBST(arr, 0, arr.size() - 1);
    displayTree(root);
    AVL(root);
}