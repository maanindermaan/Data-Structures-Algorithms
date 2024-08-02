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



void flattenBTintoLL(Node* root){
    Node* curr = root;
    // 1. While curr is not NULL
    while(curr){
        // 2. If curr->left is available
        if(curr->left){
            // 2.1 Find Predecessor
            Node* pred = curr->left;
            while(pred->right){
                pred = pred->right;
            }

            // 2.2 Establish link from pred->right to curr->right
            pred->right = curr->right;

            // 2.3 Update curr->right
            curr->right = curr->left;

            // 2.4 Update curr->left
            curr->left = NULL;

        }
        // 3 Move curr forward
        curr = curr->right;
    }
}

// void flattenBTintoLL(Node* root){
//     Node* curr = root;
//     // 1. While curr is not NULL
//     while(curr){
//         // 2. Agar left node hai toh
//         if(curr->left){
//             // 3. pehle to ip nikallo
//             Node* ip = curr->left;
//             while(ip->right != NULL){
//                 ip = ip->right;
//             }

//             // 4. Ab iss ip ko right wale pe jod do
//             //             1
//             //            / \  
//             //           2   5
//             //          / \   \ 
//             //         3   4   6

//             // 4.1 
//             ip->right = curr->right;
//             curr->right = curr->left;
//             curr->left = NULL;
//         }
//         curr= curr->right;
//     }
// }



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

    flattenBTintoLL(root);
    cout<<endl;
    cout<<endl;
    levelOrderTraversalLineWise(root);
    cout<<endl;
    cout<<endl;

    return 0;
}
