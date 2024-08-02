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


bool checkMirror(Node* p , Node* q){
    if(p == NULL && q == NULL){
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

    if(p->data == q->data && checkMirror(p->left , q->right) && checkMirror(p->right , q->left)){
        return true;
    }
    return false;
}

bool isMirror(Node *root)
{
    if(root == NULL){
        return true;
    }

    Node* p = root->left;
    Node* q = root->right;

    return checkMirror(p,q);
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
    Node *root = NULL;

    root = buildTrees();

    cout << "Levelorder Traversal for root ->" << endl;
    levelOrderTraversalLineWise(root);
    cout << endl;
    cout << endl;
    cout << endl;

    if (isMirror(root))
    {
        cout << "Yes trees are mirror";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}
