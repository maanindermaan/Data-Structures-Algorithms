#include <iostream>
#include <algorithm>
#include <stack>
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

void inorderTraversal(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    // LNR
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void inorderTraversalIterative(Node *root)
{
    stack<Node *> st;
    Node *current = root;

    while (current != NULL || !st.empty())
    {
        // Reach the leftmost node of the current subtree
        while (current != NULL)
        {
            st.push(current);
            current = current->left;
        }

        // Current is now NULL, so pop a node and print its data
        current = st.top();
        st.pop();
        cout << current->data << " ";

        // Move to the right subtree
        current = current->right;
    }
}

void preorderTraversal(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    // NLR
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void preorderTraversalIterative(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    stack<Node *> st;
    Node *current = root;

    while (!st.empty() || current != NULL)
    {
        while (current != NULL)
        {
            // Print the current node's data
            cout << current->data << " ";

            // Push the current node to stack
            st.push(current);

            // Move to the left node
            current = current->left;
        }

        // Pop the top node and move to its right node
        current = st.top();
        st.pop();

        current = current->right;
    }
}


void postorderTraversal(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    // LRN
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

void postorderTraversalIterative(Node *root)
{
    stack<Node *> st;
    Node *current = root;

    while (current != NULL || !st.empty())
    {
        // Reach the leftmost node of the current subtree
        while (current != NULL)
        {
            st.push(current);
            current = current->left;
        }
        // Move to the right subtree
        current = current->right;

        // Current is now NULL, so pop a node and print its data
        current = st.top();
        st.pop();
        cout << current->data << " ";
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

    cout << "Inorder Traversal" << endl;
    inorderTraversal(root);
    cout << endl;
    cout << endl;

    cout << "Inorder Traversal Iterative" << endl;
    inorderTraversalIterative(root);
    cout << endl;
    cout << endl;

    cout << "Preorder Traversal" << endl;
    preorderTraversal(root);
    cout << endl;
    cout << endl;

    cout << "Preorder Traversal Iterative" << endl;
    preorderTraversalIterative(root);
    cout << endl;
    cout << endl;

    cout << "Postorder Traversal" << endl;
    postorderTraversal(root);
    cout << endl;
    cout << endl;

    cout << "Postorder Traversal Iterative" << endl;
    postorderTraversalIterative(root);
    cout << endl;
    cout << endl;
    return 0;
}

// 20 30 50 -1 60 -1 -1 40 -1 -1 100 -1 -1