#include <iostream>
#include <algorithm>
#include <map>
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

void printRightView(Node* root , int level , vector<int> &ans){
    //  1. Base Case
    if(root == NULL){
        return;
    }

    // 2. Value Store
    if(level == ans.size()){
        ans.push_back(root->data);
    }

    // 3. Right
    printRightView(root->right , level+1 , ans);

    // 4. Left
    printRightView(root->left , level+1 , ans);
}

int main()
{
    Node *root = buildTrees();
    vector<int>ans;
    int level = 0;
    printRightView(root , level , ans);
    
    for(int i=0 ; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}