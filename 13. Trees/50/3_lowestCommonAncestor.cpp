#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    // Base Case
    if (root == NULL)
    {
        return 0;
    }

    // check for p and q
    if (root->data == p->data)
    {
        return p;
    }

    if (root->data == q->data)
    {
        return q;
    }

    Node *leftAns = lowestCommonAncestor(root->left, p, q);
    Node *rightAns = lowestCommonAncestor(root->right, p, q);

    if (leftAns == NULL && rightAns == NULL)
    {
        return NULL;
    }
    else if (leftAns != NULL && rightAns == NULL)
    {
        return leftAns;
    }
    else if (leftAns == NULL && rightAns != NULL)
    {
        return rightAns;
    }
    else
    {
        return root;
    }
}

Node *buildTrees()
{
    int data;
    cout << "Enter the data : ";
    cin >> data;

    // Base Case
    if (data == -1)
    {
        return NULL;
    }

    // Step A , B and C
    Node *root = new Node(data);

    cout << "Enter data for left part of " << data << " node" << endl;
    root->left = buildTrees();

    cout << "Enter data for right part of " << data << " node" << endl;
    root->right = buildTrees();

    return root;
}

int main()
{
    Node *root = NULL;

    root = buildTrees();

    int p_val, q_val;
    cout << "Enter the value of node p: ";
    cin >> p_val;

    cout << "Enter the value of node q: ";
    cin >> q_val;

    Node *p = new Node(p_val);
    Node *q = new Node(q_val);

    Node *ans = lowestCommonAncestor(root, p, q);
    cout << ans->data;

    return 0;
}

