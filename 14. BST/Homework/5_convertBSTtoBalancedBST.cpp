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

void inorderTraversal(Node *root, vector<int> &inorder)
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

Node *buildTree(vector<int> &inorder, int s, int e)
{
    if (s > e)
    {
        return NULL;
    }

    int mid = (s + e) / 2;

    int element = inorder[mid];

    Node *root = new Node(element);

    root->left = buildTree(inorder, s, mid - 1);
    root->right = buildTree(inorder, mid + 1, e);

    return root;
}

Node *BSTtoBalancedBST(Node *root)
{
    vector<int> inorder;

    inorderTraversal(root, inorder);

    // Build balanced BST using inorder Traversals

    return buildTree(inorder, 0, inorder.size() - 1);
}

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

    Node *ans = BSTtoBalancedBST(root);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Printing Tree : " << endl;
    levelOrderTraversalLineWise(ans);
}






// Approach 2
class Solution{
public:
    void inorderFinder(vector<int>& inorder , Node* root){
        if(root == NULL){
            return;
        }
        
        inorderFinder(inorder , root->left);
        inorder.push_back(root->data);
        inorderFinder(inorder , root->right);
    }
    
    Node* bst_convertor(vector<int>& inorder , int s , int e){
        if(s > e){
            return NULL;
        }
        
        int mid = s + (e - s) / 2;
        Node* root = new Node(inorder[mid]);
        
        root->left = bst_convertor(inorder, s, mid - 1);
        root->right = bst_convertor(inorder, mid + 1, e);
        
        return root;
    }
    
    Node* buildBalancedTree(Node* root)
    {
        vector<int> inorder;
        inorderFinder(inorder , root);
        
        return bst_convertor(inorder , 0 , inorder.size()-1);
    }
};