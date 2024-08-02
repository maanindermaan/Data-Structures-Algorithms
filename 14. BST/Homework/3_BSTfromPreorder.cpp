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

Node* build(int &i , int min , int max , vector<int>&preorder){
    if(i >= preorder.size()){
        return NULL;
    }

    Node* root = NULL;
    if(preorder[i] > min && preorder[i] < max){
        root = new Node(preorder[i++]);
        root->left = build(i , min , root->data , preorder);
        root->right = build(i , root->data , max , preorder);
    }
    return root;
}

Node* BSTfromPreorder(vector<int> &preorder){
    int min = INT_MIN;
    int max = INT_MAX;
    int i = 0;
    return build(i , min , max , preorder);
}

int main()
{
    Node *root = NULL;

    cout << "enter the data for node : " << endl;
    takeInput(root);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout << "Printing Tree : " << endl;
    levelOrderTraversalLineWise(root);

    vector<int> preorder;
    preorder.push_back(8);
    preorder.push_back(5);
    preorder.push_back(1);
    preorder.push_back(7);
    preorder.push_back(10);
    preorder.push_back(12);

    Node* temp = BSTfromPreorder(preorder);

    cout<<endl;
    cout<<endl;
    cout<<endl;

    cout << "Printing Tree : " << endl;
    levelOrderTraversalLineWise(temp);
    return 0;
}
