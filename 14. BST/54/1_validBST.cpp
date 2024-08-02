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

bool solve(Node *root, int lowerBound, int upperBound)
{
    // 1. Base Case
    if (root == NULL)
    {
        return true;
    }

    // 2. check on the position you are standing and then recursively check for left and right
    if (root->data > lowerBound && root->data < upperBound)
    {
        bool leftAns = solve(root->left, lowerBound, root->data);
        bool rightAns = solve(root->right, root->data, upperBound);
        return leftAns && rightAns;
    }

    // if (root->data > lowerBound && root->data < upperBound && solve(root->left, lowerBound, root->data) && solve(root->right, root->data, upperBound))
    // {
    //     return true;
    // }
    else
    {
        return false;
    }
}

// bool solve(Node *root, int lowerBound, int upperBound)
// {
//     // 1. Base Case
//     if(root == NULL){
//         return true;
//     }

//     // 2. Left mein chota hoga root se or right mein bada hoga root se
//     if(root->data > lowerBound && root->data < upperBound && solve(root->left , lowerBound , root->data) && solve(root->right , root->data , upperBound)){
//         return true;
//     }
//     return false;
// }

bool isValid(Node *root)
{
    int lowerBound = INT_MIN;
    int upperBound = INT_MAX;

    bool ans = solve(root, lowerBound, upperBound);
    return ans;
}

int main()
{
    Node *root = NULL;

    cout << "enter the data for node : " << endl;
    takeInput(root);

    cout << "Tree comes out to be : " << endl;
    levelOrderTraversalLineWise(root);

    cout << endl;
    cout << endl;

    cout << isValid(root);
    return 0;
}