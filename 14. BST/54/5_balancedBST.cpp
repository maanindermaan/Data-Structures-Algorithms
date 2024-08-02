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

vector<Node *> ans;

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

void inorderTraversalStore(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // inorder LNR

    inorderTraversalStore(root->left);

    ans.push_back(root);

    inorderTraversalStore(root->right);
}

Node *BSTusingInorder(vector<Node *> inorder, int s, int e)
{
    // 1. Base Case
    if (s > e)
    {
        return NULL;
    }

    // 2. Mid nikal lo
    int mid = (s + e) / 2;

    // 3. Element nikal lo
    int element = inorder[mid]->data;

    // 4. Iss element ke liye node banado
    Node *root = new Node(element);

    // 5. Recursive Calls
    root->left = BSTusingInorder(inorder, s, mid - 1);
    root->right = BSTusingInorder(inorder, mid + 1, e);

    return root;
}

int main()
{
    Node *root = NULL;

    takeInput(root);
    cout << endl;
    cout << endl;

    cout << "Printing the unbalanced tree :" << endl;
    levelOrderTraversalLineWise(root);

    cout << endl;
    cout << endl;

    cout << "Printing the inorder traversal : " << endl;
    inorderTraversalStore(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i]->data << " ";
    }

    cout << endl;
    cout << endl;

    int s = 0;
    int e = ans.size() - 1;

    root = BSTusingInorder(ans, s, e);

    cout << "Printing the balanced tree :" << endl;
    levelOrderTraversalLineWise(root);

    cout << endl;
    cout << endl;
    return 0;
}