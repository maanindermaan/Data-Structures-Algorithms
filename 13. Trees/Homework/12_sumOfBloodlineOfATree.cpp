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

// pair<int , int> height(Node* root){
//     if(root == NULL){
//         return {0,0};
//     }

//     pair<int , int> lh = height(root->left);
//     pair<int , int> rh = height(root->right);
//     int sum = root->data;

//     if(lh.first == rh.first){
//         // same height case
//         sum += max(lh.second , rh.second);
//     }

//     // Left tree is big
//     else if(lh.first > lh.second){
//         sum += lh.first;
//     }

//     // Right tree is big
//     else if(lh.first < lh.second){
//         sum += lh.second;
//     }

//     return {max(lh.first , rh.first) + 1 , sum};
// }

pair<int , int> height(Node* root){ // (height , data)
    // 1. Base Case
    if(root == NULL){
        return {0,0};
    }

    // 2. Calculate height recursively
    pair<int , int> lh = height(root->left);
    pair<int , int> rh = height(root->right);

    // 3. Also find sum 
    int sum = root->data;

    // 4. Check if they have same height 
    if(lh.first == rh.first){
        sum += max(lh.second , rh.second);
    }

    // 5. When height of left tree is big
    if(lh.first > rh.first){
        sum += lh.second;
    }
    // 6. When height of right tree is big
    if(lh.first < rh.first){
        sum += rh.second;
    }

    return {max(lh.first , rh.first) + 1 , sum};
}

int sumOfBloodline(Node *root)
{
    pair<int , int> h = height(root); // (height , data)

    return h.second;
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
    cout << sumOfBloodline(root);

    return 0;
}
