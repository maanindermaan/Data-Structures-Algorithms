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


Node* makeNodeToParentMappingAndFindTargetNode(Node* root , unordered_map<Node* , Node*>& parentMapping , int target){
    // 1. Using Level Order Traversal

    // 2. Creating Queue
    queue<Node*> q;

    // 3. Create a target node where out target lies
    Node* targetNode = NULL;

    // 4. Push root into q
    q.push(root);

    // 5. Create mapping for root
    parentMapping[root] = NULL;

    while(!q.empty()){
        Node* frontNode = q.front();
        q.pop();

        if(frontNode->data == target){
            targetNode = frontNode;
        }

        // 6. Now for left and right
        if(frontNode->left){
            q.push(frontNode->left);
            parentMapping[frontNode->left] = frontNode;
        }

        if(frontNode->right){
            q.push(frontNode->right);
            parentMapping[frontNode->right] = frontNode;
        }
    }
    return targetNode;
}


int burnTheTree(Node *targetNode, unordered_map<Node *, Node *> &parentMapping)
{

    // 1. Ek map create krdo Node se BOOL tak
    unordered_map<Node *, bool> isBurnt;

    queue<Node *> q;

    int time = 0;

    // 2. Queue mein target node ko push krdo or isBurnt ko true mark krdo ab humne target wali node ko burn krdiya hai
    q.push(targetNode);
    isBurnt[targetNode] = true;

    while (!q.empty())
    {
        bool isFireSpreaded = false;
        for (int i = 0; i < q.size(); i++)
        {
            Node *frontNode = q.front();
            q.pop();

            // 3. Left mein aag lagao
            if(frontNode->left && isBurnt[frontNode->left] == false){
                q.push(frontNode->left);
                isBurnt[frontNode->left] = true;
                isFireSpreaded = true;
            }

            // 4. Right mein aag lagao
            if(frontNode->right && isBurnt[frontNode->right] == false){
                q.push(frontNode->right);
                isBurnt[frontNode->right] = true;
                isFireSpreaded = true;
            }

            // 5. Parent mein aag laga do
            if(parentMapping[frontNode] && isBurnt[parentMapping[frontNode]] == false){
                q.push(parentMapping[frontNode]);
                isBurnt[parentMapping[frontNode]] = true;
                isFireSpreaded = true;
            }
        }
        if(isFireSpreaded == true){
            time++;
        }
    }
    return time;
}

int minTime(Node *root, int target)
{
    unordered_map<Node *, Node *> parentMapping; // Node to Parent Node mapping
    Node *targetNode = makeNodeToParentMappingAndFindTargetNode(root, parentMapping, target);

    return burnTheTree(targetNode, parentMapping);
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
            cout << temp->data << " "
                 << " "
                 << " ";

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


Node *makeNodeToParentMappingAndFindTargetNode(Node *root, unordered_map<Node *, Node *> &parentMapping, int target)
{
    // Using Level Order Traversal
    queue<Node *> q;
    Node *targetNode = NULL;
    q.push(root);
    parentMapping[root] = NULL;

    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();

        if (frontNode->data == target)
        {
            targetNode = frontNode;
        }
        if (frontNode->left)
        {
            q.push(frontNode->left);
            parentMapping[frontNode->left] = frontNode;
        }
        if (frontNode->right)
        {
            q.push(frontNode->right);
            parentMapping[frontNode->right] = frontNode;
        }
    }
    return targetNode;
}




int burnTheTree(Node *targetNode, unordered_map<Node *, Node *> &parentMapping)
{
    unordered_map<Node *, bool> isBurnt;
    queue<Node *> q; // currently set on fire nodes
    int time = 0;

    q.push(targetNode);
    isBurnt[targetNode] = true;

    while (!q.empty())
    {
        bool isFireSpreaded = false; // agar aage fire spread horhi hai tohi mai time ko ++ krunga
        for (int i = 0; i < q.size(); i++)
        {
            Node *frontNode = q.front();
            q.pop();

            // left aag spread kardo
            if (frontNode->left && !isBurnt[frontNode->left])
            {
                q.push(frontNode->left);
                isBurnt[frontNode->left] = true;
                isFireSpreaded = true;
            }

            // Right aag spread kardo
            if (frontNode->right && !isBurnt[frontNode->right])
            {
                q.push(frontNode->right);
                isBurnt[frontNode->right] = true;
                isFireSpreaded = true;
            }

            // Parent pe bhi aag spread krdo
            if (parentMapping[frontNode] && !isBurnt[parentMapping[frontNode]])
            {
                q.push(parentMapping[frontNode]);
                isBurnt[parentMapping[frontNode]] = true;
                isFireSpreaded = true;
            }
        }
        if (isFireSpreaded == true)
        {
            time++;
        }
    }
    return time;
}





int main()
{
    Node *root = NULL;
    root = buildTrees();
    cout << endl;
    cout << endl;
    levelOrderTraversalLineWise(root);
    cout << endl;
    cout << endl;
    int target;
    cin >> target;
    cout << minTime(root, target);
    return 0;
}




// 100% correct 
// class Solution {
// public:
//     // This function creates a mapping from each node to its parent and also finds the target node
//     Node* makeNodeToParentMappingAndFindTargetNode(Node* root, unordered_map<Node*, Node*>& parentMapping, int target) {
//         Node* targetNode = NULL;
//         queue<Node*> q;
//         q.push(root);
//         parentMapping[root] = NULL;

//         while (!q.empty()) {
//             Node* frontNode = q.front();
//             q.pop();

//             if (frontNode->data == target) {
//                 targetNode = frontNode;
//             }

//             if (frontNode->left) {
//                 q.push(frontNode->left);
//                 parentMapping[frontNode->left] = frontNode;
//             }

//             if (frontNode->right) {
//                 q.push(frontNode->right);
//                 parentMapping[frontNode->right] = frontNode;
//             }
//         }

//         return targetNode;
//     }

//     // This function simulates burning the tree starting from the target node
//     int burnTheTree(Node* targetNode, unordered_map<Node*, Node*>& parentMapping) {
//         queue<Node*> q;
//         unordered_map<Node*, bool> isBurnt;

//         q.push(targetNode);
//         isBurnt[targetNode] = true; // Mark target node as burnt
//         int time = 0;

//         while (!q.empty()) {
//             bool isFireSpread = false;
//             int size = q.size(); // Correctly use the size of the queue at the current level

//             for (int i = 0; i < size; i++) { // Use 'size' instead of 'q.size()' in the loop
//                 Node* frontNode = q.front();
//                 q.pop();

//                 if (frontNode->left && isBurnt[frontNode->left] == false) {
//                     q.push(frontNode->left);
//                     isBurnt[frontNode->left] = true;
//                     isFireSpread = true;
//                 }

//                 if (frontNode->right && isBurnt[frontNode->right] == false) {
//                     q.push(frontNode->right);
//                     isBurnt[frontNode->right] = true;
//                     isFireSpread = true;
//                 }

//                 if (parentMapping[frontNode] && isBurnt[parentMapping[frontNode]] == false) {
//                     q.push(parentMapping[frontNode]);
//                     isBurnt[parentMapping[frontNode]] = true;
//                     isFireSpread = true;
//                 }
//             }
//             if (isFireSpread == true) {
//                 time++;
//             }
//         }
//         return time;
//     }

//     // This function finds the minimum time to burn the tree starting from the target node
//     int minTime(Node* root, int target) {
//         unordered_map<Node*, Node*> parentMapping; // Node to Parent Node mapping
//         Node* targetNode = makeNodeToParentMappingAndFindTargetNode(root, parentMapping, target);

//         return burnTheTree(targetNode, parentMapping);
//     }
// };