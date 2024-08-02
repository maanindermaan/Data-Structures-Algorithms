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




vector<int> inorderTraversalUsingMorrisTraversal(Node* root){
    vector<int>ans;
    Node* curr = root;

    // 1. While current is not NULL
    while(curr){
        // 2. If left node is NULL, then visit it and go right
        if(curr->left == NULL){
            // 2.1 Visit it
            ans.push_back(curr->data);

            // 2.2 Go right now i.e. moving up only
            curr = curr->right;
        }

        // 3. Left is not NULL
        else{
            // 3.1 Find inorder Predecessor
            Node* inorderPredecessor = curr->left;
            while(inorderPredecessor->right != curr && inorderPredecessor->right){ // otherwise we would have been stucked into a loop
                inorderPredecessor = inorderPredecessor->right;
            }

            // 3.2 If predecessor right Node is NULL then go left after establishing the link from predecessor to curr
            if(inorderPredecessor->right == NULL){
                // 3.2.1 Establishing Link
                inorderPredecessor->right = curr;

                // 3.2.2 Going to left after establishing the link
                curr = curr->left;
            }
            
            // 3.3 If right node is not NULL
            else{
                // 3.3.1 Left is already visited, Go right after visiting curr Node, while removing the link;
                inorderPredecessor->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right; 
            }

        }
    }

    // 1. While curr is not NULL
    // while(curr){
    //     // 2. If left is NULL
    //     if(curr->left = NULL){
    //         ans.push_back(root->data);
    //         curr = curr->right;
    //     }

    //     // 3. Left is not NULL
    //     else{
    //         Node* ip = curr->left;
    //         while(ip->right != curr && ip->right != NULL){
    //             ip = ip->right;
    //         }

    //         // ip right is NULL
    //         if(ip->right == NULL){
    //             ip->right = curr;
    //             curr = curr->left;
    //         }

    //         // right is not NULL
    //         else{
    //             ip->right = NULL;
    //             ans.push_back(root->data);
    //             curr = curr->right;
    //         }
    //     }
    // }

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

    vector<int> ans = inorderTraversalUsingMorrisTraversal(root);
    for(int i=0 ; i<ans.size() ; i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}
