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

bool searchingInBST(Node* root , int target){
    // Base Case
    if(root == NULL){
        return false;
    }

    // 1. Jis node pe khade ho usi se puch lo kya tum tagret ke equal ho
    if(root->data == target){
        return true;
    }

    if(target > root->data){
        // 2. right subtree mein dekhlo
        return searchingInBST(root->right , target);
    }

    else{
        // 2. left subtree mein dekhlo
        return searchingInBST(root->left , target);
    }

    return false;

}


// bool searchingInBST(Node* root , int target){
//     // Base Case
//     if(root == NULL){
//         return false;
//     }

//     // 1. Jis node pe khade ho usi se puch lo kya tum tagret ke equal ho
//     if(root->data == target){
//         return true;
//     }
//     bool leftAns = false;
//     bool rightAns = false;

//     if(target > root->data){
//         // right subtree
//         rightAns = searchingInBST(root->right , target);
//     }

//     else{
//         // Left subtree
//         leftAns =  searchingInBST(root->left , target);
//     }

//     return rightAns || leftAns;
// }


int main()
{
    Node *root = NULL;

    cout << "enter the data for node : " << endl;
    takeInput(root);

    levelOrderTraversalLineWise(root);

    cout<<endl;
    cout<<endl;
    int target;
    cout<<"Enter the value of target : ";
    cin>>target;

    bool ans = searchingInBST(root , target);
    if(ans){
        cout<<"Yes the given target "<<target<<" is present in BST.";
    }
    else{
        cout<<"No sorry";
    }
    return 0;
}