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

Node *searchingInBST(Node *root, int target)
{
    // Base Case
    if (root == NULL)
    {
        return NULL;
    }

    // 1. Jis node pe khade ho usi se puch lo kya tum tagret ke equal ho
    if (root->data == target)
    {
        return root;
    }

    if (target > root->data)
    {
        // 2. right subtree mein dekhlo
        return searchingInBST(root->right, target);
    }

    else
    {
        // 3. left subtree mein dekhlo
        return searchingInBST(root->left, target);
    }
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

int maxValue(Node *root)
{
    Node *temp = root;
    if (temp == NULL)
    {
        return -1;
    }

    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

// Node* deleteNodeInBST(Node* root , int target){
//     // Base Case
//     if(root == NULL){
//         return NULL;
//     }

//     // step 1 : search target
//     // temp is the node to be deleted
//     Node* temp = searchingInBST(root , target);

//     // step 2 : delete temp
//     // case 1 : Leaf node
//     if(temp->left == NULL && temp->right == NULL){
//         delete temp;
//         return NULL;
//     }

//     // case 2 : Left node
//     else if(temp->left != NULL && temp->right == NULL){
//         Node* child = temp->left;
//         delete temp;
//         return child;
//     }

//     // case 3 : Right node
//     else if(temp->right != NULL && temp->left == NULL){
//         Node* child = temp->right;
//         delete temp;
//         return child;
//     }

//     // case 4 : Both child exisiting
//     // we calculate inorder predecessor of left subtree -> left subtree mein maximum value nikalni hai
//     else{
//         //  we are replacing temp with inorderPre
//         int inorderPredecessor = maxValue(temp->left);
//         temp->data = inorderPredecessor;
//         // delete the initial value of inorderPre using recursion
//         temp->left = deleteNodeInBST(temp->left , inorderPredecessor);
//         return root;
//     }
// }

Node *deleteNodeInBST(Node *root, int target)
{
    // Base Case
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == target)
    {
        // isi ko delete krna hai
        // 4 cases to delete it
        // case 1 : Leaf node
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // case 2 : Left node
        else if (root->left != NULL && root->right == NULL)
        {
            Node *child = root->left;
            delete root;
            return child;
        }

        // case 3 : Right node
        else if (root->right != NULL && root->left == NULL)
        {
            Node *child = root->right;
            delete root;
            return child;
        }

        // case 4 : Both child exisiting
        // we calculate inorder predecessor of left subtree -> left subtree mein maximum value nikalni hai
        else
        {
            //  we are replacing root with inorderPre
            int inorderPredecessor = maxValue(root->left);
            root->data = inorderPredecessor;
            // delete the initial value of inorderPre using recursion
            root->left = deleteNodeInBST(root->left, inorderPredecessor);
            return root;
        }
    }

    else if (target > root->data)
    {
        // right part
        root->right = deleteNodeInBST(root->right, target);
    }

    else if (target < root->data)
    {
        // left part
        root->left = deleteNodeInBST(root->left, target);
    }
    return root;
}


int main()
{
    Node *root = NULL;

    cout << "enter the data for node : " << endl;
    takeInput(root);

    cout << "Before deleting : " << endl;
    levelOrderTraversalLineWise(root);

    cout << endl;
    cout << endl;

    int target;
    cout << "Enter the value of target : ";
    cin >> target;

    deleteNodeInBST(root, target);

    cout << endl;
    cout << endl;
    cout << "After deleting : " << endl;
    levelOrderTraversalLineWise(root);
    return 0;
}