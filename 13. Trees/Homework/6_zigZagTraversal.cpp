#include <iostream>
#include <algorithm>
#include <queue>
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

vector<vector<int>> zigZagTraversal(Node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }

    bool LtoR = true;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int width = q.size();
        vector<int> Level1;

        for (int i = 0; i < width; i++) // Iterate over the current level
        {
            Node *frontNode = q.front();
            q.pop();

            if (LtoR)
            {
                Level1.push_back(frontNode->data);
            }
            else
            {
                Level1.insert(Level1.begin(), frontNode->data);
            }

            if (frontNode->left)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }

        LtoR = !LtoR;
        ans.push_back(Level1);
    }

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

    cout << endl;
    cout << endl;

    vector<vector<int>> ans = zigZagTraversal(root);

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






// Approach 2
// class Solution {
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         vector<vector<int>> ans;
//         // 1. Base Case
//         if (root == NULL)
//         {
//             return {};
//         }

//         // 2. create a map for storing horizontal distance -> topNode(data)
//         map<int, vector<int > >  mapping;

//         // 3 We will store a pair consisting of Node and Horizonatal distance
//         queue<pair<TreeNode *, int > > q;

//         // 4 Push initial value
//         q.push(make_pair(root, 0));

//         // 5 Level Order Traversal
//         while (!q.empty())
//         {
//             pair<TreeNode *, int> temp = q.front();
//             q.pop();

//             TreeNode *frontNode = temp.first;
//             int horizontalDistance = temp.second;

//             mapping[horizontalDistance].push_back(frontNode->val);

//             // 5.2 If left exists
//             if (frontNode->left)
//             {
//                 q.push(make_pair(frontNode->left, horizontalDistance + 1));
//             }

//             // 5.3 If right exists
//             if (frontNode->right)
//             {
//                 q.push(make_pair(frontNode->right, horizontalDistance + 1));
//             }
//         }

//         for (auto i : mapping)
//         {
//             if (i.first % 2 == 0)
//             {
//                 ans.push_back(i.second);
//             }
//             else
//             {
//                 vector<int>reversed;
//                 // Print in reverse order
//                 for (int j = i.second.size() - 1; j >= 0; j--)
//                 {
//                     reversed.push_back(i.second[j]);
//                 }
//                 ans.push_back(reversed);
//             }
//         }
//         return ans;
//     }
// };
