#include <iostream>
#include <algorithm>
#include <map>
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

void printLeftBoundary(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    // If you're at leaf node
    if (root->left == NULL && root->right == NULL)
    {
        return; // because we are taking care of leaf Nodes separtely
    }

    cout << root->data << " ";
    if (root->left)
    {
        printLeftBoundary(root->left);
    }
    else
    {
        printLeftBoundary(root->right);
    }
}

void printLeafBoundary(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    // If you're at leaf node
    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data<<" ";
    }

    printLeafBoundary(root->left);
    printLeafBoundary(root->right);
}

void printRightBoundary(Node* root){
    // Base Case
    if (root == NULL)
    {
        return;
    }

    // If you're at leaf node
    if (root->left == NULL && root->right == NULL)
    {
        return; // because we are taking care of leaf Nodes separtely
    }

    if(root->right){
        printRightBoundary(root->right);
    }
    else{
        printRightBoundary(root->left);
    }

    // Vapis jaate hue print krna hai becuase hume yeah reverse order mein chiye
    cout<<root->data<<" ";
}


void boundaryTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data<<" ";

    // 1. Left Part
    printLeftBoundary(root->left);

    // 2. Leaf Nodes
    printLeafBoundary(root);

    // 3. Right Part
    printRightBoundary(root->right);
}

int main()
{
    Node *root = buildTrees();
    boundaryTraversal(root);
    return 0;
}





// Approach COmbined 
class Solution {
public:
    void leftBoundary(Node* root, vector<int>& result) {
        if(root == NULL){
            return;
        }
        
        if(root->left || root->right){
            result.push_back(root->data);
        }
        
        if(root->left){
            rightBoundary(root->left , result);
        }
        else{
            rightBoundary(root->right , result);
        }
    }

    void leafNodes(Node* root, vector<int>& result) {
        if (root == NULL){
            return;
        } 
        if (root->left == NULL && root->right == NULL) {
            result.push_back(root->data);
            return;
        }
        
        leafNodes(root->left, result);
        leafNodes(root->right, result);
    }

    void rightBoundary(Node* root, vector<int>& result) {
        if(root == NULL){
            return;
        }
        if(root->right){
            rightBoundary(root->right , result);
        }
        else{
            rightBoundary(root->left , result);
        }
        
        if(root->left || root->right){
            result.push_back(root->data);
        }
    }

    vector<int> boundary(Node* root) {
        vector<int> result;
        if (!root){
            return result;
        } 

        result.push_back(root->data);

        leftBoundary(root->left, result);
        leafNodes(root->left, result);
        leafNodes(root->right, result);
        rightBoundary(root->right, result);

        return result;
    }
};