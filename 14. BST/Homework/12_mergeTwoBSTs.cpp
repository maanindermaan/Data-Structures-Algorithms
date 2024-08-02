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

vector<int> mergeTwoBST(Node* root1 , Node* root2){
    vector<int> ans; // stores sorted elements of both the trees
    stack<Node*> s1 , s2;

    Node* a = root1;
    Node* b = root2;

    while(a || b || !s1.empty() || !s2.empty()){
        while(a){
            // inorder
            s1.push(a);
            a = a->left;
        } 

        while(b){
            // inorder
            s2.push(b);
            b = b->left;
        }

        if(s2.empty() || (!s1.empty() && s1.top()->data <= s2.top()->data)){
            Node* atop = s1.top();
            s1.pop();
            ans.push_back(atop->data);
            a = atop->right;
        }

        else{
            Node* btop = s2.top();
            s2.pop();
            ans.push_back(btop->data);
            b = btop->right;
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

    vector<int> ans = mergeTwoBST(root1 , root2);
    for(int i=0 ; i<ans.size() ; i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}
