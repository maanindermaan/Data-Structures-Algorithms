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

pair<bool, int> solve(Node *root)
{
    // base case
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, INT_MIN);
        return p;
    }
    if (root->left == NULL && root->right == NULL)
    {
        // leaf node
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> leftAns = solve(root->left);
    pair<bool, int> rightAns = solve(root->right);

    if (leftAns.first == true &&
        rightAns.first == true &&
        root->data > leftAns.second &&
        root->data > rightAns.second)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    else
    {
        pair<bool, int> p = make_pair(false, root->data);
        return p;
    }
}

int main()
{
    Node *root;

    return 0;
}


























//{ Driver Code Starts
// #include <bits/stdc++.h>
// using namespace std;

// // Tree Node
// struct Node {
//     int data;
//     Node *left;
//     Node *right;

//     Node(int val) {
//         data = val;
//         left = right = NULL;
//     }
// };

// // Function to Build Tree
// Node *buildTree(string str) {
//     // Corner Case
//     if (str.length() == 0 || str[0] == 'N') return NULL;

//     // Creating vector of strings from input
//     // string after spliting by space
//     vector<string> ip;

//     istringstream iss(str);
//     for (string str; iss >> str;) ip.push_back(str);

//     // Create the root of the tree
//     Node *root = new Node(stoi(ip[0]));

//     // Push the root to the queue
//     queue<Node *> queue;
//     queue.push(root);

//     // Starting from the second element
//     int i = 1;
//     while (!queue.empty() && i < ip.size()) {

//         // Get and remove the front of the queue
//         Node *currNode = queue.front();
//         queue.pop();

//         // Get the current Node's value from the string
//         string currVal = ip[i];

//         // If the left child is not null
//         if (currVal != "N") {

//             // Create the left child for the current Node
//             currNode->left = new Node(stoi(currVal));

//             // Push it to the queue
//             queue.push(currNode->left);
//         }

//         // For the right child
//         i++;
//         if (i >= ip.size()) break;
//         currVal = ip[i];

//         // If the right child is not null
//         if (currVal != "N") {

//             // Create the right child for the current Node
//             currNode->right = new Node(stoi(currVal));

//             // Push it to the queue
//             queue.push(currNode->right);
//         }
//         i++;
//     }

//     return root;
// }







// } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

// class Solution {
//   public:
    

// pair<bool, int> solve(Node *root)
// {
//     // base case
//     if (root == NULL)
//     {
//         pair<bool, int> p = make_pair(true, INT_MIN);
//         return p;
//     }
//     if (root->left == NULL && root->right == NULL)
//     {
//         // leaf node
//         pair<bool, int> p = make_pair(true, root->data);
//         return p;
//     }

//     pair<bool, int> leftAns = solve(root->left);
//     pair<bool, int> rightAns = solve(root->right);

//     if (leftAns.first == true &&
//         rightAns.first == true &&
//         root->data > leftAns.second &&
//         root->data > rightAns.second)
//     {
//         pair<bool, int> p = make_pair(true, root->data);
//         return p;
//     }

//     else
//     {
//         pair<bool, int> p = make_pair(false, root->data);
//         return p;
//     }
// }

  
//     bool isHeap(struct Node* tree) {
//         // code here
//         pair<bool, int> ans = solve(tree);
        
//         return ans.first;
//     }
// };

// //{ Driver Code Starts.

// int main() {
//     int tc;
//     scanf("%d ", &tc);
//     while (tc--) {
//         string treeString;
//         getline(cin, treeString);
//         Solution ob;
//         Node *root = buildTree(treeString);
//         if (ob.isHeap(root))
//             cout << 1 << endl;
//         else
//             cout << 0 << endl;
//     }

//     return 0;
// }
// // } Driver Code Ends