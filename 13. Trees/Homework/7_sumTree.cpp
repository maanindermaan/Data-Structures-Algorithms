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

int toSumTree(Node* root){
    // 1. Base Case
    if(root == NULL){
        return 0;
    }

    // 2. If leaf Node
    if(root->left == NULL && root->right == NULL){
        // 2.1 Orignal data save krlo
        int temp = root->data;

        // 2.2 Or uss Node ke data ko NULL mark krdiya
        root->data = 0;

        // 2.3 Or uper wali node ke liye is rrot node ka data return krdo
        return temp;
    }

    // 3. Recursively Call mardo
    int lsum = toSumTree(root->left);
    int rsum = toSumTree(root->right);

    // 4. Agar leaf node ni hai to same uss orignal node ke data ko lsum + rsum se replace krdo store krke orgnl ko
    int temp = root->data;

    root->data = lsum + rsum;
    
    return temp + root->data;
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

    cout << "Levelorder Traversal" << endl;
    levelOrderTraversalLineWise(root);
    cout << endl;

    int ans = toSumTree(root);

    cout << endl;
    cout << endl;
    cout << "Levelorder Traversal" << endl;
    levelOrderTraversalLineWise(root);
    cout << endl;
    cout << endl;
    return 0;
}