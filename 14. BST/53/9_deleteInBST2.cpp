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

Node *searchingInBST(Node *root, int target)
{
    // Base Case
    if (root == NULL)
    {
        return NULL;
    }

    // 1. Jis node pe khade ho usi se puch lo kya tum tagret ke equal ho
    if (root->data == target)
    {
        return root;
    }

    if (target > root->data)
    {
        // 2. right subtree mein dekhlo
        return searchingInBST(root->right, target);
    }

    else
    {
        // 3. left subtree mein dekhlo
        return searchingInBST(root->left, target);
    }
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

int minValue(Node* root){
    Node* temp = root; 
    if(temp == NULL){
        return -1;
    }

    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;

}


Node* deletingNodeInBST(Node* root , int target){
    // 1. Base Case
    if(root == NULL){
        return NULL;
    }

    // 2. Root = target
    if(root->data == target){
        // case 1 : Leaf Node
        if(root->left == NULL && root->right == NULL){
            return NULL;
        }

        // case 2 : Left Node
        else if(root->left != NULL && root->right == NULL){
            Node* child = root->left;
            delete root;
            return child;
        }

        // case 3 : Right Node
        else if(root->left == NULL && root->right != NULL){
            Node* child = root->right;
            delete root;
            return child;
        }

        // case 4 : Non null nodes
        else{
            // inorder Successor ko find kro ( Right tree -> Minimum Value )
            int inorderSuccessor = minValue(root->right);

            // iski value daldo jis node ko aap delete krna chahte ho usme
            root->data = inorderSuccessor;

            // Ab Jha pe tumhara successor pada tha uss position ko delete krdo by recursion
            root->right = deletingNodeInBST(root->right , inorderSuccessor);

            return root;
        }
    }

    // 3. target chota hai root se to goto left and perform same task
    else if(target < root->data){
        root->left = deletingNodeInBST(root->left , target);
    }

    // 4. target bada hai root se to goto right and perform same task
    else if(target > root->data){
        root->right = deletingNodeInBST(root->right , target);
    }
    return root;
}

int main()
{
    Node *root = NULL;

    cout << "enter the data for node : " << endl;
    takeInput(root);

    cout << "Before deleting : " << endl;
    levelOrderTraversalLineWise(root);

    cout << endl;
    cout << endl;

    int target;
    cout << "Enter the value of target : ";
    cin >> target;

    deletingNodeInBST(root, target);

    cout << endl;
    cout << endl;
    cout << "After deleting : " << endl;
    levelOrderTraversalLineWise(root);
    return 0;
}