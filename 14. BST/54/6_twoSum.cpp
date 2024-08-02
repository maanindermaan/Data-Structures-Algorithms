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

void storeInInorder(Node* root , vector<int>&inorder){
    if(root == NULL){
        return;
    }

    storeInInorder(root->left , inorder);

    inorder.push_back(root->data);

    storeInInorder(root->right , inorder);

}


bool findTarget(Node* root , int target){
    vector<int>inorder;
    storeInInorder(root , inorder);

    int s = 0;
    int e = inorder.size() - 1;

    while(s < e){
        int sum = inorder[s] + inorder[e];
        
        if(sum == target){
            return true;
        }

        if(sum > target){
            e--;
        }

        else{
            s++;
        }
    }

    return false;
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
    cout<<"Enter the target sum : ";
    int target;
    cin>>target;
    bool ans = findTarget(root , target);
    cout << endl;
    cout << endl;
    cout<<ans;
    return 0;
}



// eroor
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool recursiveHelper(TreeNode* root, int k , int& sum , int& k_val){
        if(root == NULL){
            return false;
        }

        sum += root->val; 
        k_val--;
        if(sum == k && k_val == 0){
            return true;
        }
        bool left , right;
        if(k - sum > root->val){
            // right call
            if(root->right != NULL) right = recursiveHelper(root->right , k , sum, k_val);
        }
        else{
            // left call
            if(root->left != NULL) left = recursiveHelper(root->left , k , sum , k_val);
        }
        sum -= root->val;
        k_val++;
        return left || right;
    }

    bool findTarget(TreeNode* root, int k) {
        int sum = 0;
        int k_val = 2;
        return recursiveHelper(root , k , sum , k_val);
    }
};