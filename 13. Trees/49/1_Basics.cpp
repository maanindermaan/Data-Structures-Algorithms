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

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;

    // initially
    q.push(root);

    while (!q.empty())
    {
        // 1.
        Node *temp = q.front();

        // 2.
        q.pop();

        // 3. Print
        cout << temp->data << " ";

        // 4. Insert Child
        if (temp->left)
        {
            q.push(temp->left);
        }

        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}

void levelOrderTraversalLineWise(Node *root)
{
    queue<Node *> q;

    // initially
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        // 1.
        Node *temp = q.front();

        // 2.
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {

            // 3. Print
            cout <<"The data is : "<<temp->data << " ";

            // 4. Insert Child
            if (temp->left)
            {

                q.push(temp->left);
            }
            if (temp->right)
            {

                q.push(temp->right);
            }
        }
    }
}

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

int maxDepth(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);

    int maxHeight = max(leftHeight, rightHeight) + 1;

    return maxHeight;
}

int diamterOfBinaryTree(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return 0;
    }

    int ans1 = diamterOfBinaryTree(root->left);
    int ans2 = diamterOfBinaryTree(root->right);
    int ans3 = maxDepth(root->left) + maxDepth(root->right);

    int finalAns = max(ans1, max(ans2, ans3));

    return finalAns;
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

    levelOrderTraversal(root);

    // cout << "Levelorder Traversal" << endl;
    // levelOrderTraversalLineWise(root);
    // cout << endl;

    // cout << "Inorder Traversal" << endl;
    // inorderTraversal(root);
    // cout << endl;

    // cout << "Preorder Traversal" << endl;
    // preorderTraversal(root);
    // cout << endl;

    // cout << "Postorder Traversal" << endl;
    // postorderTraversal(root);
    // cout << endl;

    // cout << maxDepth(root);
    // cout << endl;
    // cout << endl;
    // cout << diamterOfBinaryTree(root);

    return 0;
}