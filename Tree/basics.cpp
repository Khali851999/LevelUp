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
vector<Node*> NodetoRootpath(Node* node, int data)
{
    if(node==nullptr)return vector<Node*>();
    vector<Node*> l=NodetoRootpath(node->left,data);
    vector<Node*> r=NodetoRootpath(node->right,data);
}
int main()
{
    return 0;
}