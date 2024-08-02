#include<iostream>
using namespace std;
int main(){

return 0;
}


struct Node
{
    int data;
    Node* left, * right;
}; 


class Solution
{
public:
    int sumTree(Node* root) {
        if (root == NULL) {
            return 0;
        }
        
        int leftAns = sumTree(root->left);
        int rightAns = sumTree(root->right);
        int currAns = root->data;
        
        int currVal = leftAns + rightAns + currAns;
        
        return currVal;
    }

    bool checkSumTree(Node* root) {
        // An empty tree is considered a Sum Tree
        if (root == NULL) {
            return true;
        }
        
        // Leaf node is considered a Sum Tree
        if (root->left == NULL && root->right == NULL) {
            return true;
        }
        
        int leftAns = 0, rightAns = 0;

        if (root->left != NULL) leftAns = sumTree(root->left);
        if (root->right != NULL) rightAns = sumTree(root->right);
        
        // Check if root's data is equal to sum of left and right subtrees
        if (root->data == leftAns + rightAns) {
            // Recursively check left and right subtrees
            return checkSumTree(root->left) && checkSumTree(root->right);
        }
        
        return false;
    }

    bool isSumTree(Node* root) {
        return checkSumTree(root);
    }
};