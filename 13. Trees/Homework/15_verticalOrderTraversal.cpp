#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
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


void verticalOrderTraversal(Node *&root)
{
    // 1. Base Case
    if (root == NULL)
    {
        return;
    }

    // 2. create a map for storing horizontal distance -> topNode(data)
    map<int, vector<int>> mapping;

    // 3 We will store a pair consisting of Node and Horizonatal distance
    queue<pair<Node *, int>> q;

    // 4 Push initial value
    q.push(make_pair(root, 0));

    // 5 Level Order Traversal
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int horizontalDistance = temp.second;

        mapping[horizontalDistance].push_back(frontNode->data);

        // 5.2 If left exists
        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, horizontalDistance - 1));
        }

        // 5.3 If right exists
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, horizontalDistance + 1));
        }
    }

    // 6. Answer is there in map extract it from there
    cout << "printing the answer" << endl;

    for (auto i : mapping)
    {
        cout << i.first << " -> ";
        for (int num : i.second)
        {
            cout << num << " ";
        }
        cout << endl;
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
    Node *root = buildTrees();
    verticalOrderTraversal(root);
    return 0;
}