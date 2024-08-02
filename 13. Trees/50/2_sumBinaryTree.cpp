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

int sumBinaryTree(Node* root){
    // Base Case
    if(root == NULL){
        return 0;
    }

    // 1 case solve krdo
    int currVal = root->data;
    int leftVal = sumBinaryTree(root->left);
    int rightVal = sumBinaryTree(root->right);

    currVal = currVal + leftVal + rightVal;

    return currVal;
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

    int ans = sumBinaryTree(root);
    cout<<ans;

    return 0;
}