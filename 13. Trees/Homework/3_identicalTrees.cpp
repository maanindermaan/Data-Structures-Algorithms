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

// bool isSame(Node* p , Node* q){
//     // Check if both trees are NULL, return true
//     if (p == NULL && q == NULL) {
//         return true;
//     }

//     // Check if either of the trees is NULL, return false
//     if (p == NULL || q == NULL) {
//         return false;
//     }

//     // Check if data is different, return false
//     if (p->data != q->data) {
//         return false;
//     }

//     bool leftCheck = isSame(p->left, q->left);
//     bool rightCheck = isSame(p->right, q->right);

//     // Check left and right subtrees recursively
//     return  leftCheck || rightCheck;
// }

// bool isSame(Node* p , Node* q){
//     if(p == NULL && q == NULL){
//         return true;
//     }

//     if(p != NULL && q != NULL){
//         if(p->data == q->data && isSame(p->left , q->left) && isSame(p->right , q->right)){
//             return true;
//         }
//     }

//     return false;
// }

bool isSame(Node *p, Node *q)
{
    if (p == NULL && q == NULL)
    {
        return true;
    }

    if (p == NULL && q != NULL)
    {
        return false;
    }

    if (p != NULL && q == NULL)
    {
        return false;
    }

    if (p->data == q->data && isSame(p->left, q->left) && isSame(p->right, q->right))
    {
        return true;
    }
    return false;
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
    Node *p = NULL;
    Node *q = NULL;

    p = buildTrees();
    q = buildTrees();

    cout << "Levelorder Traversal for p ->" << endl;
    levelOrderTraversalLineWise(p);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Levelorder Traversal for q ->" << endl;
    levelOrderTraversalLineWise(q);

    if (isSame(p, q))
    {
        cout << "Yes trees are identical";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}
