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

bool balancedBinaryTree(Node* root){
    // Base Case
    if(root == NULL){
        return true;
    }

    // 1 case solve krdo
    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);
    int diff = abs(leftHeight - rightHeight);

    bool ans1 = (diff<=1);

    // Recursive Call
    bool leftAns = balancedBinaryTree(root->left);
    bool rightAns = balancedBinaryTree(root->right);

    if(ans1 && leftAns && rightAns){
        return true;
    }
    else{
        return false;
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

    if(balancedBinaryTree(root)){
        cout<<"YES it is balanced";
    }
    else{
        cout<<"NO it is not balanced";
    }

    return 0;
}