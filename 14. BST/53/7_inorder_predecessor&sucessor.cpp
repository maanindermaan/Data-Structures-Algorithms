#include<iostream>
using namespace std;
int main(){

return 0;
}

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

class Solution {
public:
    Node* maxVal(Node* root) {
        Node* temp = root;
        while (temp && temp->right != NULL) {
            temp = temp->right;
        }
        return temp;
    }

    Node* minVal(Node* root) {
        Node* temp = root;
        while (temp && temp->left != NULL) {
            temp = temp->left;
        }
        return temp;
    }

    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
        if (root == NULL) {
            return;
        }

        // If key is present at root
        if (root->key == key) {
            // The maximum value in left subtree is predecessor
            if (root->left != NULL) {
                pre = maxVal(root->left);
            }

            // The minimum value in right subtree is successor
            if (root->right != NULL) {
                suc = minVal(root->right);
            }
            return;
        }

        // If key is smaller than root's key, go to left subtree
        if (key < root->key) {
            suc = root;
            findPreSuc(root->left, pre, suc, key);
        }
        // If key is greater than root's key, go to right subtree
        else {
            pre = root;
            findPreSuc(root->right, pre, suc, key);
        }
    }
};