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

    Node()
    {
    }

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

    if (root->data > data)
    {
        // insert in left
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
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

Node *insert(Node *&root, int val, int &successor)
{
    if (root == NULL)
    {
        return new Node(val);
    }

    if (val >= root->data)
    {
        // right side
        root->right = insert(root->right, val, successor);
    }
    else
    {
        // left
        successor = root->data; // Update the successor before going to the left subtree
        root->left = insert(root->left, val, successor);
    }
    return root;
}

vector<int> findLeastGreater(vector<int> &arr, int n)
{
    vector<int> ans(arr.size(), -1);
    Node *root = NULL; // Initialize the local root pointer

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        int successor = -1;
        root = insert(root, arr[i], successor);
        ans[i] = successor; // Store the successor value in the ans vector
    }

    return ans;
}

int main()
{
    cout << "Enter the data for node : " << endl;
    Node *root = NULL;
    takeInput(root);
    cout << endl;
    cout << endl;
    cout << endl;

    cout << "Printing Level Order Traversal" << endl;

    levelOrderTraversalLineWise(root);

    cout << endl;
    cout << endl;
    cout << "Replacing Elements with its least greater element to its right : " << endl;

    vector<int> arr{8, 58, 71, 18, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};

    int n = arr.size();

    vector<int> ans = findLeastGreater(arr, n);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}