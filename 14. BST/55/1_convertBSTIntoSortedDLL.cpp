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



void convertIntoSortedDLL(Node* root, Node* &head){
    // 1. base case
    if(root == NULL){
        return;
    }

    // 2. Converting right subtree into Linked List
    convertIntoSortedDLL(root->right , head);

    // 3. Attach root node to this right part
    root->right = head;

    if(head != NULL){
        head->left = root;
    }

    // 4. Update head
    head = root;

    // 2. Converting left subtree into Linked List
    convertIntoSortedDLL(root->left , head);
}


// void convertIntoSortedDLL(Node* root, Node* &head){
//     // 1. base case
//     if(root == NULL){
//         return;
//     }

//     // RNL
//     convertIntoSortedDLL(root->right , head);

//     root->right = head;

//     if(head != NULL){
//         head->left = root;
//     }

//     head = root;

//     convertIntoSortedDLL(root->left , head);

// }


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



void printLinkedList(Node* head){
    Node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->right;   // next ptr is right ptr
    }
    cout<<endl;
}

int main()
{
    Node *root = NULL;

    cout << "enter the data for node : " << endl;
    takeInput(root);

    cout << endl;
    cout << endl;

    cout << "Tree comes out to be : " << endl;
    levelOrderTraversalLineWise(root);

    cout << endl;
    cout << endl;

    // 5 2 7 1 3 6 8 4 9 -1
    Node* head = NULL;
    convertIntoSortedDLL(root , head);
    
    cout << endl;
    cout << endl;

    printLinkedList(head);
    return 0;
}