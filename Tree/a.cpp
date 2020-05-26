/* C++ program to find LCA of n1 and n2 using one traversal of Binary Tree.
It handles all cases even when n1 or n2 is not there in Binary Tree */
#include <iostream>
using namespace std;

// A Binary Tree Node
class Node {
	Node *left, *right;
	int key;
};

// Utility function to create a new tree Node
Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

// This function returns LCA of n1 and n2 only if both n1 and n2 are present
// in tree, otherwise returns NULL;
bool findLCA(Node* root, int n1, int n2, Node* ans)
{
	if (root == nullptr)
		return 0;

	// check if either value is present in left subtree
	bool left = findLCA(root->left, n1, n2,ans);
	if (ans != nullptr) // if left subtree has an answer return true
		return true;

	// check if either value is present in right subtree
	bool right = findLCA(root->right, n1, n2,ans);
	if (ans != nullptr) // if right subtree has an answer return true
		return true;

	// check if either value is present in the root
	bool curr = (root->key == n1 || root->key == n2);

	// if 2 out of 3 are true
	if (left + right + curr >= 2)
		ans = root;

	return (left || right || curr);
}

// Driver program to test above functions
int main()
{
	// Let us create binary tree given in the above example
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	Node *ans=nullptr;
	bool lca = findLCA(root, 4, 5, ans);
	if (lca)
		cout << "LCA(4, 5) = " << ans->key;
	else
		cout << "Keys are not present ";


	lca = findLCA(root, 4, 10, ans);
	if (lca)
		cout << "nLCA(4, 10) = " << ans->key;
	else
		cout << "nKeys are not present ";

	return 0;
}
