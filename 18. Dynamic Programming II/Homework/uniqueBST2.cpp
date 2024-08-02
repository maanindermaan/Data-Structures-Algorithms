#include<iostream>
using namespace std;
int main(){

return 0;
}

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

#include <map>
#include <vector>

class Solution {
public:

    vector<TreeNode*> allPossibleBSTs(int start, int end) {
        // base case
        if (start > end) {
            return {nullptr}; // Use nullptr instead of 0
        }

        if (start == end) {
            return {new TreeNode(start)};
        }

        vector<TreeNode*> ans;
        for (int i = start; i <= end; i++) {
            // Left and right subtrees
            vector<TreeNode*> left = allPossibleBSTs(start, i - 1);
            vector<TreeNode*> right = allPossibleBSTs(i + 1, end);

            for (int j = 0; j < left.size(); j++) {
                for (int k = 0; k < right.size(); k++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }

    std::map<std::pair<int, int>, std::vector<TreeNode*>> dp; // Use std::map

    vector<TreeNode*> allPossibleBSTsDP(int start, int end) {
        // Base cases
        if (start > end) {
            return {nullptr};
        }
        if (start == end) {
            return {new TreeNode(start)};
        }

        // Check if the result is already computed
        if (dp.find({start, end}) != dp.end()) {
            return dp[{start, end}];
        }

        vector<TreeNode*> ans;
        for (int i = start; i <= end; i++) {
            // Left and right subtrees
            vector<TreeNode*> left = allPossibleBSTsDP(start, i - 1);
            vector<TreeNode*> right = allPossibleBSTsDP(i + 1, end);

            for (int j = 0; j < left.size(); j++) {
                for (int k = 0; k < right.size(); k++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }

        // Store the result in the map
        dp[{start, end}] = ans;
        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return allPossibleBSTsDP(1, n);
    }
};




#include<iostream>
#include<map>
using namespace std;
int main(){

return 0;
}

//   Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    vector<TreeNode*> allPossibleBSTs(int start , int end){
        // base case
        if(start > end){
            return {nullptr};
        }

        if(start == end){
            return {new TreeNode(start)};
        }

        vector<TreeNode*>ans;
        for(int i = start ; i<=end ; i++){
            // left and right se saare bst lakar do mujhe
            // its a sort of post order traversal
            vector<TreeNode*> left = allPossibleBSTs(start , i-1);
            vector<TreeNode*> right = allPossibleBSTs(i+1 , end);

            for(int j = 0 ; j< left.size() ; j++){
                for(int k = 0 ; k<right.size() ; k++){
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }

    std::map<std::pair<int, int>, std::vector<TreeNode*>> dp;
    vector<TreeNode*> allPossibleBSTsDP(int start , int end){
        // base case
        if(start > end){
            return {0};
        }

        if(start == end){
            return {new TreeNode(start)};
        }

        if (dp.find({start, end}) != dp.end()) {
            return dp[{start, end}];
        }

        vector<TreeNode*>ans;
        for(int i = start ; i<=end ; i++){
            // left and right se saare bst lakar do mujhe
            // its a sort of post order traversal
            vector<TreeNode*> left = allPossibleBSTs(start , i-1);
            vector<TreeNode*> right = allPossibleBSTs(i+1 , end);
            for(int j = 0 ; j< left.size() ; j++){
                for(int k = 0 ; k<right.size() ; k++){
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }
        dp[{start, end}] = ans;
        return dp[{start, end}];
    }

    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return {0};
        // return allPossibleBSTs(1 , n);
        return allPossibleBSTsDP(1 , n);
    }
};



