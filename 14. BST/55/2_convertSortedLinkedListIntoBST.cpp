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

void printLinkedList(Node* head){
    Node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->right;   // next ptr is right ptr
    }
    cout<<endl;
}

Node *sortedLinkedListIntoBST(Node* &head, int n)
{
    // 1. Base Case
    if (n <= 0 || head == NULL)
    {
        return NULL;
    }

    // 2. Left Subtree
    Node *leftSubtree = sortedLinkedListIntoBST(head, n - 1 - (n/2));

    // 3. Mid
    //    Now head is at mid node you have to create a root
    Node* root = head;

    // 4. Root ko left subtree se connect krdo
    root->left = leftSubtree;

    // 5. Update head
    head = head->right;

    // 6. Right Subtree and Attach mid to right as well
    root->right = sortedLinkedListIntoBST(head , n/2);

    return root;
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
    // convertIntoSortedDLL(root , head);
    
    // cout << endl;
    // cout << endl;

    // printLinkedList(head);

    Node* root1 = NULL;
    root1 = sortedLinkedListIntoBST(head , 9);
    cout << endl;
    cout << endl;

    cout << "Tree comes out to be : " << endl;
    levelOrderTraversalLineWise(root1);

    cout << endl;
    cout << endl;
    return 0;
}