#include <iostream>
#include <algorithm>
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

// void solve(Node *root, int targetSum, int currSum, vector<int> path, vector<vector<int>> &ans)
// {
//     // Base Case
//     if (root == NULL)
//     {
//         return;
//     }

//     // Leaf Node-> check Sum
//     if (root->left == NULL && root->right == NULL)
//     {
//         path.push_back(root->data);
//         currSum += root->data;
//         if (currSum == targetSum)
//         {
//             ans.push_back(path);
//         }
//         return;
//     }

//     // Jis bhi node pe khade ho use include krlo
//     path.push_back(root->data);
//     currSum += root->data;

//     // Left and right calls
//     solve(root->left, targetSum, currSum, path, ans);
//     solve(root->right, targetSum, currSum, path, ans);
// }



// void solve(Node *root, int targetSum, int currSum, vector<int> path, vector<vector<int>> &ans)
// {
//     // Base Case
//     if (root == NULL)
//     {
//         return;
//     }

//     // Leaf node
//     if(root->right == NULL && root->left == NULL){
//         path.push_back(root->data);
//         currSum += root->data;

//         if(currSum == targetSum){
//             ans.push_back(path);
//         }
//         return;
//     }

//     // If not leaf then also include it
//     path.push_back(root->data);
//     currSum += root->data;

//     // Left and right recursive Calls
//     solve(root->left,targetSum , currSum , path , ans);
//     solve(root->right,targetSum , currSum , path , ans);
// }

// With Backtracking
void solve(Node *root, int targetSum, int currSum, vector<int> path, vector<vector<int>> &ans)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    // Leaf Node-> check Sum
    if (root->left == NULL && root->right == NULL)
    {
        //    Include curr node
        path.push_back(root->data);
        currSum += root->data;
        //  check for currSum
        if (currSum == targetSum)
        {
            ans.push_back(path);
        }

        //   exclude currNode
        path.pop_back();
        currSum -= root->data;
        return;
    }

    // Jis bhi node pe khade ho use include krlo
    path.push_back(root->data);
    currSum += root->data;

    // Left and right calls
    solve(root->left, targetSum, currSum, path, ans);
    solve(root->right, targetSum, currSum, path, ans);

    // Backtracking
    path.pop_back();
    currSum -= root->data;
}

vector<vector<int>> pathSum(Node *root, int targetSum)
{
    vector<vector<int>> ans;
    int currSum = 0;
    vector<int> path;

    solve(root, targetSum, currSum, path, ans);
    return ans;
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

    int targetSum;
    cout << "Enter the value of targetSum : ";
    cin >> targetSum;

    vector<vector<int>> ans = pathSum(root, targetSum);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}







// 1. Approach without backtracking
// class Solution {
// public:
//     bool recursiveHelper(TreeNode* root, int& sum , int targetSum){
//         if(root == NULL){
//             return false;
//         }

//         sum += root->val;

//         if(root->left == NULL && root->right == NULL){
//             return sum == targetSum;
//         }


//         bool leftAns = recursiveHelper(root->left , sum , targetSum);
//         bool rightAns = recursiveHelper(root->right , sum , targetSum);

//         sum -= root->val;

//         return leftAns || rightAns;
//     }

//     bool hasPathSum(TreeNode* root, int targetSum) {
//         if(root == NULL){
//             return false;
//         }
//         int sum = 0;
//         return recursiveHelper(root , sum , targetSum);
//     }
// };




// 2. Approach with backtracking
// class Solution {
// public:
//     bool recursiveHelper(TreeNode* root, int& sum , int targetSum){
//         if(root == NULL){
//             return false;
//         }

//         sum += root->val;

//         if(root->left == NULL && root->right == NULL){
//             if(sum == targetSum){
//                 return true;
//             }
//         }


//         bool leftAns = recursiveHelper(root->left , sum , targetSum);
//         bool rightAns = recursiveHelper(root->right , sum , targetSum);

//         sum -= root->val;

//         return leftAns || rightAns;
//     }

//     bool hasPathSum(TreeNode* root, int targetSum) {
//         if(root == NULL){
//             return false;
//         }
//         int sum = 0;
//         return recursiveHelper(root , sum , targetSum);
//     }
// };
