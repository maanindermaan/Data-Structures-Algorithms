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
}

Node *insertIntoBST(Node *root, int data)
{

    if (root == NULL)
    {
        // This is the first node we have to create
        root = new Node(data);
        return root;
    }

    // Not the first node

    if (root->data > data)
    {
        // insert in left
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
        // if(root->data < data)
        // insert into right
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void inorderTraversal(Node *root, vector<float> &inorder)
{
    if (root == NULL)
    {
        return;
    }

    // LNR
    inorderTraversal(root->left, inorder);

    inorder.push_back(root->data);

    inorderTraversal(root->right, inorder);
}

float findMedian(Node *root)
{
    vector<float> inorder;

    inorderTraversal(root, inorder);

    int size = inorder.size();
    float median = 0;

    if (size % 2 == 0)
{
    // even case
    median = (inorder[size / 2] + inorder[(size / 2) - 1]) / 2.0;
}

    else
    {
        // odd case
        median = inorder[size / 2];
    }
    return median;
}

// float findMedian(Node *root)
// {
//     vector<float> inorder;

//     inorderTraversal(root, inorder);

//     int size = inorder.size();
//     float median = 0;

//     if (size % 2 == 0)
//     {
//         // even case
//         median = (inorder[size / 2 - 1] + inorder[size / 2]) / 2.0;
//     }
//     else
//     {
//         // odd case
//         median = inorder[size / 2];
//     }
//     return median;
// }


int main()
{
    Node *root = NULL;

    cout << "enter the data for node : " << endl;
    takeInput(root);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Printing Tree : " << endl;
    levelOrderTraversalLineWise(root);

    float ans = findMedian(root);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Median is : " << endl;
    cout << ans;
}
