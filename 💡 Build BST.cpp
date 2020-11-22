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



node* build(int a[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    node* root = new node(a[mid]);
    root->left = build(a, start, mid - 1);
    root->right = build(a, mid + 1, end);
    return root;
}
void preorder(node* root)
{
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);

    preorder(root->right);
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

int main()
{
#ifndef ONLINE_jUDGE
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        //node* root=NULL;
        node* root = build(a, 0, n - 1);
        preorder(root) ;
        cout << endl;
    }
    //bfs(root) ;
}
