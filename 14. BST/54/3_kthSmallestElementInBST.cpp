// Using Inorder Predecessor
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

int kthSmallestElement(Node *root, int &k)
{
    // 1. Base case
    if (root == NULL)
    {
        return -1;
    }

    // Inorder

    int leftAns = kthSmallestElement(root->left, k);
    if(leftAns != -1){
        return leftAns;
    }
    k--;
    if (k == 0)
    {
        return root->data; 
    }
    int rightAns = kthSmallestElement(root->right, k);
    return rightAns;
}

int main()
{
    Node *root = NULL;

    cout << "enter the data for node : " << endl;
    takeInput(root);

    cout << endl;
    cout << endl;

    cout << "Tree comes out to be : " << endl;
    levelOrderTraversalLineWise(root);

    cout << endl;
    int k;

    cout << "Enter the values of k : ";
    cin >> k;

    cout << kthSmallestElement(root, k);
    return 0;
}


// 2.
// class Solution {
// public:
//     void recursiveHelper(TreeNode* root, vector<int>&arr){
//         if(root == NULL){
//             return;
//         }
//         recursiveHelper(root->left , arr);
//         arr.push_back(root->val);
//         recursiveHelper(root->right , arr);
//     }

//     int kthSmallest(TreeNode* root, int k) {
//         vector<int>arr;
//         recursiveHelper(root , arr);

//         return arr[k-1];
//     }
// };