
//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

#include<iostream>
using namespace std;
int main(){

return 0;
}
class Solution {
public:

    int solveUsingRecursion(TreeNode* root){
        if(!root){
            return 0;
        }

        // do variables for rob and dont rob
        int robThisHouse = 0 , dontRobThisHouse = 0;

        // include exlude principle 
        // 1. rob condition (include)

        robThisHouse += root->val;
        if(root->left){
            robThisHouse += solveUsingRecursion(root->left->left) + solveUsingRecursion(root->left->right);
        }

        if(root->right){
            robThisHouse += solveUsingRecursion(root->right->left) + solveUsingRecursion(root->right->right);
        }

        // 2. dont rob condition(exclude)

        dontRobThisHouse += solveUsingRecursion(root->left) + solveUsingRecursion(root->right);

        return max(robThisHouse , dontRobThisHouse);
    }

    int solveUsingMemo(TreeNode* root , unordered_map<TreeNode* , int>&dp){
        if(!root){
            return 0;
        }

        // if(dp[root]){
        //     return dp[root];
        // }

        if(dp.find(root) != dp.end()){
            return dp[root];
        }

        // do variables for rob and dont rob
        int robThisHouse = 0 , dontRobThisHouse = 0;

        // include exlude principle 
        // 1. rob condition (include)

        robThisHouse += root->val;
        if(root->left){
            robThisHouse += solveUsingMemo(root->left->left , dp) + solveUsingMemo(root->left->right , dp);
        }

        if(root->right){
            robThisHouse += solveUsingMemo(root->right->left , dp) + solveUsingMemo(root->right->right , dp);
        }

        // 2. dont rob condition(exclude)

        dontRobThisHouse += solveUsingMemo(root->left , dp) + solveUsingMemo(root->right , dp);

        dp[root] = max(robThisHouse , dontRobThisHouse);

        return dp[root];

    }

    int rob(TreeNode* root) {
        // return solveUsingRecursion(root);

        // we use unordered map instead of vector 
        unordered_map<TreeNode* , int>dp;
        return solveUsingMemo(root , dp);
    }
};