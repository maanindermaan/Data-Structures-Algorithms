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



Node* lowestCommonAncestor(Node* root , Node* p , Node* q){
    // 1. Base Case
    if(root == NULL){
        return NULL;
    }

    // 2. Four cases
    // case 1 : p and q dono ka data chota hai root->data se. Dono left mein honge
    if(p->data < root->data && q->data < root->data){
       return lowestCommonAncestor(root->left , p , q);
    }

    // case 2 : p and q dono ka data bada hai root->data se. Dono right mein honge
    else if(p->data > root->data && q->data > root->data){
       return lowestCommonAncestor(root->right , p , q);
    }

    // case 3 : p left mein hai or q right mein hai
    else if(p->data < root->data && q->data > root->data){
       return root;
    }

    // case 4 : p right mein hai or q left mein hai
    else if(p->data > root->data && q->data < root->data){
       return root;
    }

    // case 3 and 4 se hi miljega agar ans hoga toh yeah toh formality ke liye likha hai
    return root;
}





// Node* lowestCommonAncestor(Node* root , Node* p , Node* q){
//     // 1. Base Case
//     if(root == NULL){
//         return NULL;
//     }

//     // 2. Four cases
//     // case 1 : p and q dono ka data chota hai root->data se. Dono left mein honge
//     if(p->data < root->data && q->data < root->data){
//         return lowestCommonAncestor(root->left , p , q);
//     }

//     // case 2 : p and q dono ka data bada hai root->data se. Dono right mein honge
//     if(p->data < root->data && q->data < root->data){
//         return lowestCommonAncestor(root->right , p , q);
//     }

//     // case 3 : p is small and q is big so the node you are standing is the data
//     if(p->data < root->data && q->data > root->data){
//         return root;
//     }
//     // case 2 : p is big and q is small so the node you are standing is the data
//     if(p->data > root->data && q->data < root->data){
//         return root;
//     }

//     return root;
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
    int pVal , qVal;

    cout<<"Enter the values of p and q : ";

    cin>>pVal>>qVal;

    Node* p = new Node(pVal);
    Node* q = new Node(qVal);

    Node* ans = lowestCommonAncestor(root , p , q);
    cout<<ans->data;
    return 0;
}