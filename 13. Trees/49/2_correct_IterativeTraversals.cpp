#include <iostream>
#include <algorithm>
#include <stack>
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


void preorderTraversal(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    // NLR
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void preorderTraversalIterative(Node *root)
{
    // check if root is null or not
    stack<Node*>st;
    if(root == NULL){
        return;
    }

    st.push(root);

    while(!st.empty()){
        root = st.top();
        st.pop();

        cout<<root->data<<" ";

        if(root->right){
            st.push(root->right);
        }

        if(root->left){
            st.push(root->left);
        }
    }
}

void inorderTraversal(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    // LNR
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void inorderTraversalIterative(Node *root)
{
    if(root == NULL){
        return;
    }

    Node* node = root;
    stack<Node*>st;

    while(true){
        if(node != NULL){
            st.push(node);
            node = node->left;
        }
        else{
            if(st.empty()){
                return;
            }
            node = st.top();
            st.pop();
            cout<<node->data<<" ";
            node = node->right;
        }
    }
}

void postorderTraversal(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    // LRN
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}


// using 2 stack
void postorderTraversalIterative2(Node *root)
{
    if(root == NULL){
        return;
    }
    stack<Node*>st1 , st2;
    st1.push(root);

    while(true){
        if(st1.empty()){
            break;
        }
        root = st1.top();
        st1.pop();

        st2.push(root);

        if(root ->left){
            st1.push(root->left);
        }

        if(root ->right){
            st1.push(root->right);
        }
    }

    while(!st2.empty()){
        root = st2.top();
        st2.pop();

        cout<<root->data<<" ";
    }
}

// using single stack
void postorderTraversalIterative1(Node *root)
{
    stack<Node*> st;
    Node* curr = root;

    while(curr != NULL || !st.empty()){
        if(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        else{
            Node* temp = st.top()->right;
            if(temp == NULL){
                temp = st.top();
                st.pop();
                cout<<temp->data<<" ";

                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    cout<<temp->data<<" ";
                }
            }   
            else{
                curr = temp;
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

    cout << "Preorder Traversal" << endl;
    preorderTraversal(root);
    cout << endl;
    cout << endl;

    cout << "Preorder Traversal Iterative" << endl;
    preorderTraversalIterative(root);
    cout << endl;
    cout << endl;

    cout << "Inorder Traversal" << endl;
    inorderTraversal(root);
    cout << endl;
    cout << endl;

    cout << "Inorder Traversal Iterative" << endl;
    inorderTraversalIterative(root);
    cout << endl;
    cout << endl;

    cout << "Postorder Traversal" << endl;
    postorderTraversal(root);
    cout << endl;
    cout << endl;

    cout << "Postorder Traversal Iterative" << endl;
    postorderTraversalIterative1(root);
    cout << endl;
    cout << endl;
    return 0;
}

// 1 2 3 -1 -1 4 5 -1 -1 6 -1 -1 7 -1 -1