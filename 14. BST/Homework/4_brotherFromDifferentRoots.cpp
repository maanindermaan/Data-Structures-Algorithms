#include <iostream>
#include <queue>
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

Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        // This is the first node we have to create
        root = new Node(data);
        return root;
    }

    if (root->data > data)
    {
        // insert in left
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
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

void levelOrderTraversalLineWise(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int levelNodes = q.size();
        while (levelNodes--)
        {
            Node *temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        cout << endl;
    }
}

int countPairs(Node* root1 , Node* root2 , int x){
    int ans = 0;
    stack<Node*> s1 , s2;

    Node* a = root1;
    Node* b = root2;

    while(1){
        while(a){
            // inorder
            s1.push(a);
            a = a->left;
        } 

        while(b){
            // reverse inorder
            s2.push(b);
            b = b->right;
        }

        // both stacks are empty it means that inorder is complete
        if(s1.empty() || s2.empty()){
            break;
        }

        // top elements nikallo
        Node* atop = s1.top();
        Node* btop = s2.top();

        int sum = atop->data + btop->data;

        if(sum == x){
            ++ans;
            s1.pop();
            s2.pop();

            // right walo ko bhi daldo
            a = atop->right;

            // left walo ko bhi daldo
            b = btop->left;
        }

        else if(sum < x){
            s1.pop();
            // BST1 ke pointer ko successor pe lejao, BST1->aage
            a = atop->right;
        }

        else{
            s2.pop();
            // BST1 ke pointer ko successor pe lejao, BST1->aage
            b = btop->left;
        }
    }
    return ans;
}

int main()
{
    Node *root1 = NULL;
    Node *root2 = NULL;

    cout << "Enter the data for node 1 (-1 to stop input): " << endl;
    takeInput(root1);
    cout << "Printing Tree 1: " << endl;
    levelOrderTraversalLineWise(root1);
    cout << endl;

    cout << "Enter the data for node 2 (-1 to stop input): " << endl;
    takeInput(root2);
    cout << "Printing Tree 2: " << endl;
    levelOrderTraversalLineWise(root2);
    cout << endl;

    int x = 16;
    int result = countPairs(root1, root2, x);
    cout << "Number of pairs with sum " << x << " in the two BSTs: " << result << endl;

    return 0;
}
