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

Node *insertIntoBST(Node *root, int data)
{

    if (root == NULL)
    {
        // This is the first node we have to create
        root = new Node(data);
        return root;
    }

    // Not the first node

    if (root->data > data)
    {
        // insert in left
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
        // if(root->data < data)
        // insert into right
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}


void fun(Node* root , unordered_map<int , bool>&visited , bool&ans){
    if(root == 0){
        return;
    }

    // NLR
    visited[root->data] = true;
    if(root->left == NULL && root->right == NULL){
        // Leaf Node
        int xplus1 = root->data + 1; // x is root->data here

        // Because xminus1 can be at 1 as well and we have to take only positive integers
        int xminus1;
        if(root->data - 1 ==0){
            xminus1 = root->data;
        }
        else{
            xminus1 = root->data - 1;
        }

        if(visited.find(xplus1) != visited.end() && visited.find(xminus1) != visited.end()){
            // entry found
            ans = true; // HAAN DEAD END HAI BHAIIIII
        }
        return;
    }

    fun(root->left , visited , ans);
    fun(root->right , visited , ans);


}


bool isDeadEnd(Node* root){
    bool ans = false; // tells if there is a dead end or not
    unordered_map<int , bool>visited;
    fun(root , visited , ans);
    return ans;
}


int main()
{
    Node *root = NULL;

    cout << "enter the data for node : " << endl;
    takeInput(root);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Printing Tree : " << endl;
    levelOrderTraversalLineWise(root);

    bool ans = isDeadEnd(root);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Dead End is : "<<ans;
}




// Approach 2
class Solution{
  public:
    bool helper(Node* root , int mini , int maxi){
        if(root == NULL){
            return false;
        }
        
        if(maxi - mini <= 2){
            return true;
        }
        
        if(root->data > mini && root->data < maxi){
            bool leftAns = helper(root->left , mini , root->data);
            bool rightAns = helper(root->right , root->data , maxi);
            
            return leftAns || rightAns;
        }   
        else{
            return false;
        }
        
    }
  
    bool isDeadEnd(Node *root)
    {
        int mini = 0;
        int maxi = 10002;
        
        return helper(root , mini , maxi);
    }
};