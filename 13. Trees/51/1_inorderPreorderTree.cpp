#include <iostream>
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
        this->left = NULL;
        this->right = NULL;
    }
};

int findPosition(int inOrder[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (inOrder[i] == element)
        {
            return i;
        }
    }
    return -1;
}

// building tree from inorder and preorder traversal 
// preIndex should be passed byreference because it is being updated in code each time
Node *buildTreeFromInOrderPreOrderTraversal(int inOrder[], int preOrder[], int size, int &preIndex, int inOrderStart, int inOrderEnd)
{

    // step A : Base Case
    // Pre wala index array se bhar na nikal jaye
    // if startIndex > EndIndex i.e. invalid array
    if (preIndex >= size || inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    // step B : find root node
    int element = preOrder[preIndex++]; // kyunki recursive call hogi na. Har baar aage badta jayega. Har baar first index of preorder hi root node hogi
    Node *root = new Node(element);

    // step C : Finding indexes in inorder array
    int i = findPosition(inOrder, size, element);

    // Step D : recursive call left
    root->left = buildTreeFromInOrderPreOrderTraversal(inOrder, preOrder, size, preIndex, inOrderStart, i - 1); // inorder start is 0 intially

    // Step E : recursive call right
    root->right = buildTreeFromInOrderPreOrderTraversal(inOrder, preOrder, size, preIndex, i + 1, inOrderEnd); // inorder end is size-1

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
int main()
{
    int inOrder[] = {40, 20, 50, 10, 60, 30, 70};
    int preOrder[] = {10, 20, 40, 50, 30, 60, 70};
    int size = 7;
    int preIndex = 0;
    int inOrderStart = 0;
    int inOrderEnd = size - 1;

    Node *root = buildTreeFromInOrderPreOrderTraversal(inOrder, preOrder, size, preIndex, inOrderStart, inOrderEnd);

    cout<<"Printing Level Order Traversal"<<endl;
    levelOrderTraversalLineWise(root);
    return 0;
}