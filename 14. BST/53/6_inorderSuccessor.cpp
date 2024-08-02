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

int minValue(Node* root){
    Node* temp = root; 
    if(temp == NULL){
        return -1;
    }

    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;
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

int inorderSuccessor(Node* root){ // right -> minimum value
    if(root == NULL){
        return -1;
    }
    int ip = minValue(root->right);
    return ip;
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

int main()
{
    Node *root = NULL;

    cout << "enter the data for node : " << endl;
    takeInput(root);

    levelOrderTraversalLineWise(root);

    cout<<endl;
    cout<<endl;

    cout<<"Printing In order traversal : "<<endl;
    inorderTraversal(root);
    cout<<endl;
    cout<<endl;

    Node* temp = root;
    int ans = inorderSuccessor(temp);

    cout<<endl;
    cout<<endl;
    cout<<"The inorder Successor is : "<<ans;
    return 0;
}
