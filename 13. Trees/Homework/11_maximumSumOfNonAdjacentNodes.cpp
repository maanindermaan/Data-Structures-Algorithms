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


pair<int , int> getSumHelper(Node* root){   
//             // (1+7+6)=14  1 (max(2,7) + max(5,6) = 13) -> max(13,14) -> 14
//             //            / \  
//             //     (2,7) 2   5  (5,6)
//             //          / \   \ 
//             //   (0,0) 3   4   6 (0,0)     (include currNode , exclude currNode)
//                          (0,0) 
// 1 2 3 -1 -1 4 -1 -1 5 -1 6 -1 -1
    if(root == NULL){
        return {0,0};
    } 

    pair<int , int> leftSum = getSumHelper(root->left);
    pair<int , int> rightSum = getSumHelper(root->right);

    // Sum including the node
    int a = root->data + leftSum.second + rightSum.second;

    // Sum exlcuding the node
    int b = max(leftSum.first, leftSum.second) + max(rightSum.first, rightSum.second);


    return {a,b};
}


int getSum(Node* root){
    pair<int , int> ans = getSumHelper(root);
    return max(ans.first , ans.second);
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
    cout<<getSum(root);
    
    return 0;
}
