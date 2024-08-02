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

int successor = 0;

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


// WITH RECURSION
// void inorderSuccessor(Node* root , int target){
//     // Base Case
//     if(root == NULL){
//         return;
//     }

//     if(root->data > target){
//         successor = root->data;
//         inorderSuccessor(root->left , target);
//     }

//     else if(root->data <= target){
//         inorderSuccessor(root->right , target);
        
//     }
// }

// WITHOUT RECURSION
void inorderSuccessor(Node *root, int target)
{
    Node *curr = root;
    while (curr)
    {
        if (curr->data > target)
        {
            successor = curr->data;
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
}

int main()
{
    Node *root = NULL;

    cout << "enter the data for node : " << endl;
    takeInput(root);

    cout << "Printing Tree : " << endl;
    levelOrderTraversalLineWise(root);

    int target = 5;

    inorderSuccessor(root, target);

    cout << successor;
}