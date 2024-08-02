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

// building tree from inorder and postorder traversal
// postIndex should be passed byreference because it is being updated in code each time
Node *buildTreeFromInOrderPostOrderTraversal(int inOrder[], int postOrder[], int size, int &postIndex, int inOrderStart, int inOrderEnd)
{

    // step A : Base Case
    // Post wala index array se bhar na nikal jaye
    // if startIndex > EndIndex i.e. invalid array
    if (postIndex < 0 || inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    // step B : find root node
    int element = postOrder[postIndex--]; // kyunki recursive call hogi na. Har baar aage badta jayega. Har baar first index of preorder hi root node hogi
    Node *root = new Node(element);

    // step C : Finding indexes in inorder array
    int i = findPosition(inOrder, size, element);

    // Step D : recursive call right
    root->right = buildTreeFromInOrderPostOrderTraversal(inOrder, postOrder, size, postIndex, i + 1, inOrderEnd); // inorder end is size-1

    // Step E : recursive call left
    root->left = buildTreeFromInOrderPostOrderTraversal(inOrder, postOrder, size, postIndex, inOrderStart, i - 1); // inorder start is 0 intially

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
    int postOrder[] = {40, 50, 20, 60, 70, 30, 10};
    int size = 7;
    int postIndex = size - 1;
    int inOrderStart = 0;
    int inOrderEnd = size - 1;

    Node *root = buildTreeFromInOrderPostOrderTraversal(inOrder, postOrder, size, postIndex, inOrderStart, inOrderEnd);

    cout << "Printing Level Order Traversal" << endl;
    levelOrderTraversalLineWise(root);
    return 0;
}