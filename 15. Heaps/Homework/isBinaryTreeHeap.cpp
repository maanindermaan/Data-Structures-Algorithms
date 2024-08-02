// #include <iostream>
// #include <queue>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *left;
//     Node *right;

//     Node(int data)
//     {
//         this->data = data;
//         left = NULL;
//         right = NULL;
//     }
// };

// void levelOrderTraversalLineWise(Node *root)
// {
//     queue<Node *> q;

//     // initially
//     q.push(root);
//     q.push(NULL);

//     while (!q.empty())
//     {
//         // 1.
//         Node *temp = q.front();

//         // 2.
//         q.pop();

//         if (temp == NULL)
//         {
//             cout << endl;
//             if (!q.empty())
//             {
//                 q.push(NULL);
//             }
//         }
//         else
//         {

//             // 3. Print
//             cout << temp->data << " ";

//             // 4. Insert Child
//             if (temp->left)
//             {

//                 q.push(temp->left);
//             }
//             if (temp->right)
//             {

//                 q.push(temp->right);
//             }
//         }
//     }
// }

// Node *insertIntoBST(Node *root, int data)
// {

//     if (root == NULL)
//     {
//         // This is the first node we have to create
//         root = new Node(data);
//         return root;
//     }

//     // Not the first node

//     if (root->data > data)
//     {
//         // insert in left
//         root->left = insertIntoBST(root->left, data);
//     }
//     else
//     {
//         // if(root->data < data)
//         // insert into right
//         root->right = insertIntoBST(root->right, data);
//     }
//     return root;
// }

// void takeInput(Node *&root)
// {
//     int data;
//     cin >> data;

//     while (data != -1)
//     {
//         root = insertIntoBST(root, data);
//         cin >> data;
//     }
// }

// int nodeCount(Node *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }

//     int left = nodeCount(root->left);
//     int right = nodeCount(root->right);

//     return 1 + left + right;
// }

// bool isCBT(Node *root, int i, int n)
// {
//     if (root == NULL)
//     {
//         return true;
//     }

//     if (i > n)
//     {
//         return false;
//     }

//     bool left = isCBT(root->left, 2 * i, n);

//     bool right = isCBT(root->right, 2 * i + 1, n);

//     return left && right;
// }

// bool isMaxOrder(Node *root)
// {
//     if (root == NULL)
//     {
//         return true;
//     }

//     int l = isMaxOrder(root->left);
//     int r = isMaxOrder(root->right);
//     bool ans = true;

//     if (root->left == NULL && root->right == NULL)
//     {
//         ans = true;
//     }

//     if (root->left != NULL && root->right == NULL)
//     {
//         ans = root->data > root->left->data;
//     }

//     if (root->left != NULL && root->right != NULL)
//     {
//         ans = root->data > root->left->data && root->data > root->right->data;
//     }
//     return ans && l && r;
// }

// bool isHeap(Node *root)
// {
//     int n = nodeCount(root);
//     int i = 1;
//     return isCBT(root, i, n) && isMaxOrder(root);
// }

// int main()
// {
//     Node *root = NULL;
//     cout << "Enter data : " << endl;
//     takeInput(root);

//     cout << endl;
//     cout << endl;

//     cout << "Printing using level order traversal : " << endl;

//     levelOrderTraversalLineWise(root);
//     cout << endl;
//     cout << endl;

//     if (isHeap(root))
//     {
//         cout << "Yes it is a heap" << endl;
//     }
//     else
//     {
//         cout << "No it is not a heap" << endl;
//     }

//     return 0;
// }



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
        left = NULL;
        right = NULL;
    }
};

void levelOrderTraversalLineWise(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
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
            cout << temp->data << " ";

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

Node *takeInput()
{
    int data;
    cout << "Enter root data (-1 for NULL): ";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *root = new Node(data);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        cout << "Enter left child of " << current->data << " (-1 for NULL): ";
        cin >> data;
        if (data != -1)
        {
            current->left = new Node(data);
            q.push(current->left);
        }

        cout << "Enter right child of " << current->data << " (-1 for NULL): ";
        cin >> data;
        if (data != -1)
        {
            current->right = new Node(data);
            q.push(current->right);
        }
    }

    return root;
}

int nodeCount(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = nodeCount(root->left);
    int right = nodeCount(root->right);

    return 1 + left + right;
}

bool isCBT(Node *root, int i, int n)
{
    if (root == NULL)
    {
        return true;
    }

    if (i > n)
    {
        return false;
    }

    bool left = isCBT(root->left, 2 * i, n);
    bool right = isCBT(root->right, 2 * i + 1, n);

    return left && right;
}

bool isMaxOrder(Node *root)
{
    if (root == NULL)
    {
        return true;
    }

    int l = isMaxOrder(root->left);
    int r = isMaxOrder(root->right);
    bool ans = true;

    if (root->left == NULL && root->right == NULL)
    {
        ans = true;
    }

    if (root->left != NULL && root->right == NULL)
    {
        ans = root->data > root->left->data;
    }

    if (root->left != NULL && root->right != NULL)
    {
        ans = root->data > root->left->data && root->data > root->right->data;
    }
    return ans && l && r;
}

bool isHeap(Node *root)
{
    int n = nodeCount(root);
    int i = 1;
    return isCBT(root, i, n) && isMaxOrder(root);
}

int main()
{
    Node *root = takeInput();

    cout << "Printing using level order traversal: " << endl;
    levelOrderTraversalLineWise(root);
    cout << endl;

    if (isHeap(root))
    {
        cout << "Yes, it is a max heap." << endl;
    }
    else
    {
        cout << "No, it is not a max heap." << endl;
    }

    return 0;
}
