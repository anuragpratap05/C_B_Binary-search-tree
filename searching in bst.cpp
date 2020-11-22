# C_B_Binary-search-tree
#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node* left;
	node* right;
	node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* insert_at_BST(node* root, int d)
{
	if (root == NULL)
	{
		return new node(d);
	}
	if (d <= root->data)
	{
		root->left = insert_at_BST(root->left, d);
	}
	else
	{
		root->right = insert_at_BST(root->right, d);
	}
	return root;
}

node* build()
{
	int d;
	cin >> d;
	node* root = NULL;
	while (d != -1)
	{
		root = insert_at_BST(root, d);
		cin >> d;
	}
	return root;
}

void bfs(node *root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		node* f = q.front();
		if (f == NULL) {
			cout << endl;
			q.pop();
			if (!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			cout << f->data << ",";
			q.pop();

			if (f->left) {
				q.push(f->left);
			}
			if (f->right) {
				q.push(f->right);
			}
		}
	}
	return;
}

void inorder(node* root)
{

	// inorder print of BST always gives sorted output.
	if (root == NULL)
	{
		return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
bool search(node* root, int key)
{
	if (root == NULL)
	{
		return false;

	}

	if (root->data == key)
	{
		return true;
	}

	if (key <= root->data)
	{
		return search(root->left, key);
	}
	else
	{
		return search(root->right, key);
	}
}

int main()
{
#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	node* root = build();
	bfs(root);
	cout << endl;
	inorder(root);
	cout << endl;
	if (search(root, 10))
	{
		cout << "present" << endl;
	}
	else
	{
		cout << "absent" << endl;
	}
}
