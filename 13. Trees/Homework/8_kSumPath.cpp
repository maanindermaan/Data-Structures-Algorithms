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


int ans  = 0;
void pathFromOneRoot(Node* root , int targetSum){
    if(root == NULL){
        return;
    }

    // Preorder traversal
    if(targetSum == root->data){
        ans++;
    }
    pathFromOneRoot(root->left , targetSum - root->data);
    pathFromOneRoot(root->right , targetSum - root->data);

} 

// Iss function mein bhi mai preorder travesal daldunga kyunki zruri ni hai ki first hi root ho hmesha. 
// Ab fir hum saaro ko check krlenge
int pathSum(Node* root , int targetSum){
    if(root != NULL){
        pathFromOneRoot(root , targetSum);
        pathSum(root->left , targetSum);
        pathSum(root->right , targetSum);
    }
    return ans;
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

Node *buildTrees()
{
    int data;
    cout << "Enter the data : ";
    cin >> data;

    // Base Case
    if (data == -1)
    {
        return NULL;
    }

    // Step A , B and C
    Node *root = new Node(data);

    cout << "Enter data for left part of " << data << " node" << endl;
    root->left = buildTrees();

    cout << "Enter data for right part of " << data << " node" << endl;
    root->right = buildTrees();

    return root;
}


int main()
{
    Node *root = NULL;
    root = buildTrees();
    cout<<endl;
    cout<<endl;
    levelOrderTraversalLineWise(root);
    cout<<endl;
    cout<<endl;
    int targetSum;
    cout<<"Enter the value of target Sum : ";
    cin>>targetSum;
    cout<<endl;
    cout<<endl;
    cout<<pathSum(root , targetSum);

    return 0;
}



// Approach 2
// class Solution {
// public:
//     int ans = 0;
//     void recursiveHelper(TreeNode* root, int targetSum , long long int sum){
//         if(root == NULL){
//             return;
//         }

//         sum += root->val;

//         if(sum == targetSum){
//             ans++;
//         }
//         recursiveHelper(root->left , targetSum , sum);
//         recursiveHelper(root->right , targetSum , sum);
//     }

//     int pathSum(TreeNode* root , int targetSum){
//         if(root != NULL){
//             recursiveHelper(root , targetSum ,0);
//             pathSum(root->left , targetSum);
//             pathSum(root->right , targetSum);
//         }
//         return ans;
//     }
// };