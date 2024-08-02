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

void printTopView(Node* &root){
    // 1. Base Case
    if(root == NULL){
        return;
    }

    // 2. create a map for storing horizontal distance -> topNode(data)
    map<int,int> mapping;

    // 3 We will store a pair consisting of Node and Horizonatal distance
    queue<pair<Node* , int>> q;

    // 4 Push initial value
    q.push(make_pair(root , 0));

    // 5 Level Order Traversal
    while(!q.empty()){
        pair<Node* , int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int horizontalDistance = temp.second;

        // 5.1 Jo bhi horizontal distance aaya hai , check if answer for that hd already exists in map or not
        if(mapping.find(horizontalDistance) == mapping.end()){ // no entry
                // 5.1.2 Create Entry
                mapping[horizontalDistance] = frontNode->data;
        }

        // 5.2 If left exists
        if(frontNode->left){
            q.push(make_pair(frontNode->left , horizontalDistance - 1));
        }

        // 5.3 If right exists
        if(frontNode->right){
            q.push(make_pair(frontNode->right , horizontalDistance + 1));
        }
    }

    // 6. Answer is there in map extract it from there
    cout<<"printing the answer"<<endl; 

    for(auto i : mapping){
        cout<<i.first<<" -> "<<i.second<<endl;
    }

    // for(auto i=mapping.begin() ; i != mapping.end(); i++){
    //     cout<<i->first <<" -> "<<i->second;
    // }
}


// void printTopView(Node* &root){
//     // Base Case
//     if(root == NULL){
//         return;
//     }

//     // Level Order Traversal
//     queue<pair<Node* , int>> q; // Node , HD

//     map<int , int> mapping; // HD -> Data

//     q.push(make_pair(root , 0));

//     while(!q.empty()){
//         pair<Node* , int> temp = q.front();
//         q.pop();

//         Node* frontNode = temp.first;
//         int HD = temp.second;

//         // Check for entry
//         if(mapping.find(HD) == mapping.end()){
//             // No entry found
//             // Good create entry
//             mapping[HD] = frontNode->data;
//         }

//         // insert left and right
//         if(frontNode->left){
//             q.push(make_pair(frontNode->left , HD-1));
//         }

//         if(frontNode->right){
//             q.push(make_pair(frontNode->right , HD+1));
//         }
//     }

//     // Now answer exists in map
//     for(auto i : mapping){
//         cout<<i.first<<"->"<<i.second;
//     }
    
// }

int main()
{
    Node* root = buildTrees();
    printTopView(root);
    return 0;
}