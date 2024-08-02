// Time Complexity -> O(1)
#include <iostream>
#include <queue>
#include <map>
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
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTreeFromInOrderPostOrderTraversal(int inOrder[], int postOrder[], int size, int &postIndex, int inOrderStart, int inOrderEnd , unordered_map<int,int>&mapping)
{

    // step A : Base Case
    if (postIndex < 0 || inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    // step B : find root node
    int element = postOrder[postIndex--]; 
    Node *root = new Node(element);

    // step C : Finding indexes in inorder array using map
    int i = mapping[element];

    // Step D : recursive call right
    root->right = buildTreeFromInOrderPostOrderTraversal(inOrder, postOrder, size, postIndex, i + 1, inOrderEnd , mapping); // inorder end is size-1

    // Step E : recursive call left
    root->left = buildTreeFromInOrderPostOrderTraversal(inOrder, postOrder, size, postIndex, inOrderStart, i - 1, mapping); // inorder start is 0 intially

    return root;
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

void createMapping(unordered_map<int,int> &mapping , int inOrder[] , int size){
    for(int i=0 ; i<size ; i++){
        mapping[inOrder[i]] = i; // value ke corresponding index store krliya 1->2
    }
}

int main()
{
    int inOrder[] = {40, 20, 50, 10, 60, 30, 70};
    int postOrder[] = {40, 50, 20, 60, 70, 30, 10};
    int size = 7;
    int postIndex = size - 1;
    int inOrderStart = 0;
    int inOrderEnd = size - 1;

    unordered_map<int,int> mapping;

    createMapping(mapping , inOrder , size);

    Node *root = buildTreeFromInOrderPostOrderTraversal(inOrder, postOrder, size, postIndex, inOrderStart, inOrderEnd , mapping);

    cout << "Printing Level Order Traversal" << endl;
    levelOrderTraversalLineWise(root);
    return 0;
}
