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

void printLeftView(Node* root , int level , vector<int> &ans){
    //  1. Base Case
    if(root == NULL){
        return;
    }

    // 2. Value Store
    if(level == ans.size()){
        ans.push_back(root->data);
    }

    // 3. Left
    printLeftView(root->left , level+1 , ans);

    // 4. Right
    printLeftView(root->right , level+1 , ans);
}

int main()
{
    Node *root = buildTrees();
    vector<int>ans;
    int level = 0;
    printLeftView(root , level , ans);
    
    for(int i=0 ; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}





// Approach 2
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> ans;
    if (!root) return ans;  // Handle the case when the root is NULL

    map<int, int> mp;  // {level, data}
    queue<pair<Node*, int>> q;  // {node, level}
    
    q.push({root, 0});
    
    while (!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();
        
        Node* frontNode = temp.first;
        int level = temp.second;
        
        if (mp.find(level) == mp.end()) {
            // Insert the first node we encounter at each level
            mp[level] = frontNode->data;
        }
        
        if (frontNode->left != NULL) {
            q.push({frontNode->left, level + 1});
        }
        
        if (frontNode->right != NULL) {
            q.push({frontNode->right, level + 1});
        }
    }
    
    for (auto i : mp) {
        ans.push_back(i.second);
    }
    return ans;
}