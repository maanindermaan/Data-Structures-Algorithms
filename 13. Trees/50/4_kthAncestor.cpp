// APPROACH - 1
// #include <iostream>
// #include <algorithm>
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

// bool kthAncestor(Node *root, Node* &p, int& k)
// {
//     // Base Case
//     if (root == NULL)
//     {
//         return false;
//     }

//     // check for p
//     if (root->data == p->data)
//     {
//         return true;
//     }

//     bool leftAns = kthAncestor(root->left, p, k);
//     bool rightAns = kthAncestor(root->right, p, k);

//     // wapis aarhe hoge to check left or right se ans mila ya nahi
//     if(leftAns == true || rightAns == true){
//         k--;
//     }

//     if(k==0){
//         cout<<"Answer is : "<<root->data<<endl;
//         k=-1;
//     }

//     return leftAns||rightAns;
// }

// Node *buildTrees()
// {
//     int data;
//     cout << "Enter the data : ";
//     cin >> data;

//     // Base Case
//     if (data == -1)
//     {
//         return NULL;
//     }

//     // Step A , B and C
//     Node *root = new Node(data);

//     cout << "Enter data for left part of " << data << " node" << endl;
//     root->left = buildTrees();

//     cout << "Enter data for right part of " << data << " node" << endl;
//     root->right = buildTrees();

//     return root;
// }

// int main()
// {
//     Node *root = NULL;

//     root = buildTrees();

//     int p_val, q_val;
//     cout << "Enter the value of node p: ";
//     cin >> p_val;

//     Node *p = new Node(p_val);

//     int k;
//     cout<<"Enter the value of k : ";
//     cout<<endl;
//     cin>>k;

//     bool found = kthAncestor(root, p, k);

//     return 0;
// }





// APPROACH - 2
#include <iostream>
#include <vector>
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

bool kthAncestor(Node *root, Node *&p, int &k, vector<int> &ancestors)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == p->data)
    {
        ancestors.push_back(root->data);
        return true;
    }
    ancestors.push_back(root->data);

    bool left = kthAncestor(root->left, p, k, ancestors);
    bool right = kthAncestor(root->right, p, k, ancestors);

    if (left || right)
    {
        while (k > 0)
        {
            cout << ancestors[ancestors.size() - 1 - k] << endl;
            k = 0;
            return true;
        }
        return true;
    }
    // ancestors.pop_back();
    return false;
}

Node *buildTree()
{
    int data;
    cout << "Enter the data : ";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *root = new Node(data);

    cout << "Enter data for the left part of " << data << " node" << endl;
    root->left = buildTree();

    cout << "Enter data for the right part of " << data << " node" << endl;
    root->right = buildTree();

    return root;
}

int main()
{
    Node *root = NULL;
    root = buildTree();

    int p_val, q_val;
    cout << "Enter the value of node p: ";
    cin >> p_val;

    Node *p = new Node(p_val);

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    vector<int> ancestors;
    bool found = kthAncestor(root, p, k, ancestors);

    return 0;
}





// Appraoch 1 -> In GFG
// Node* findP(Node *root, int node) {
//     if (root == NULL) {
//         return NULL;
//     }
    
//     if (root->data == node) {
//         return root;
//     }
    
//     Node* leftAns = findP(root->left, node);
//     if (leftAns != NULL) {
//         return leftAns;
//     }
    
//     Node* rightAns = findP(root->right, node);
//     return rightAns;
// }

// int kthAncestorHelper(Node* root, Node* p, int &k) {
//     if (root == NULL) {
//         return -1;
//     }
//     if (root->data == p->data) {
//         return p->data;
//     }
    
//     int leftAns = kthAncestorHelper(root->left, p, k);
//     int rightAns = kthAncestorHelper(root->right, p, k);
    
//     if (leftAns != -1 || rightAns != -1) {
//         k--;
//     }
    
//     if (k == 0) {
//         return root->data;
//     }
    
//     return (leftAns != -1) ? leftAns : rightAns;
// }

// int kthAncestor(Node *root, int k, int node) {
//     Node* p = findP(root, node);
    
//     int result = kthAncestorHelper(root, p, k);
    
//     // If the kth ancestor does not exist, return -1
//     if (result == node) {
//         return -1;
//     }
    
//     return result;
// }




// Approach 2 in GFG
Node* findP(Node *root, int node) {
    if (root == NULL) {
        return NULL;
    }
    
    if (root->data == node) {
        return root;
    }
    
    Node* leftAns = findP(root->left, node);
    if (leftAns != NULL) {
        return leftAns;
    }
    
    Node* rightAns = findP(root->right, node);
    return rightAns;
}

bool kthAncestorHelper(Node* root, Node* p, int &k, vector<int>& ancestors) {
    if (root == NULL) {
        return false;
    }
    
    if (root->data == p->data) {
        return true;
    }
    
    ancestors.push_back(root->data);

    // kyunki mujhe isme dhundna hai toh dono mein se kisi pe bhi milje koi chakkar ni 
    if (kthAncestorHelper(root->left, p, k, ancestors) || kthAncestorHelper(root->right, p, k, ancestors)) {
        return true;
    }
    
    // nikaldo usko jisko daala hai bhai boht hua bas
    ancestors.pop_back();
    return false;
}

int kthAncestor(Node *root, int k, int node) {
    Node* p = findP(root, node);
    if (p == NULL) {
        return -1;
    }
    
    vector<int> ancestors;
    bool found = kthAncestorHelper(root, p, k, ancestors);
    
    if (found && k <= ancestors.size()) {
        return ancestors[ancestors.size() - k];
    }
    
    // If the kth ancestor does not exist, return -1
    return -1;
}