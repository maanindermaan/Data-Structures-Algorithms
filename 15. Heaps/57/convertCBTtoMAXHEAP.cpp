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
    // LNR
    if (root == NULL)
    {
        return;
    }

    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}

void postorderInsert(Node* root, vector<int>& inorder, int& index) {
    if (root == NULL) {
        return;
    }

    // LRN
    postorderInsert(root->left, inorder, index);
    postorderInsert(root->right, inorder, index);

    root->data = inorder[index];
    index++;
}


void convertToMaxHeap(Node* root) {
    vector<int> inorder;
    inorderTraversal(root, inorder);

    int index = 0;
    postorderInsert(root, inorder, index);
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
    cout << endl;

    convertToMaxHeap(root);

    cout << endl;
    cout << endl;

    cout << "Tree comes out to be : " << endl;
    levelOrderTraversalLineWise(root);


}