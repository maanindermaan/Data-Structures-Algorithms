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

int rangeSumBSTnodes(Node *root, int low, int high)
{
    if (root == NULL)
    {
        return 0; // Return 0 for an empty subtree
    }
    int ans = 0;
    bool inRange = false;

    if (root->data >= low && root->data <= high)
    {
        ans += root->data;
        // ans += 1; // for getCount
        inRange = true;
    }

    if (inRange)
    {
        ans += rangeSumBSTnodes(root->left, low, high) + rangeSumBSTnodes(root->right, low, high);
    }

    else if (root->data < low)
    {
        ans += rangeSumBSTnodes(root->right, low, high);
    }

    // If the current node's value is greater than high, explore the left subtree
    if (root->data > high)
    {
        ans += rangeSumBSTnodes(root->left, low, high);
    }

    return ans;
}






int main()
{
    Node *root = NULL;

    cout << "enter the data for node : " << endl;
    takeInput(root);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Printing Tree : " << endl;
    levelOrderTraversalLineWise(root);

    int low = 7;
    int high = 15;
    int ans = rangeSumBSTnodes(root, low, high);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Sum of nodes lying in range is : " << ans;
    cout << endl;
    cout << endl;
}
