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






// vector<Node *> ans;
// unordered_map<string, int> subTreeMapping;

// string preorderTraversal(Node *root)
// {
//     if (root == NULL)
//     {
//         return "NULL";
//     }

//     string curr = to_string(root->data);
//     string left = preorderTraversal(root->left);
//     string right = preorderTraversal(root->right);

//     string s = curr + "," + left + "," + right; //(NLR)

//     if (subTreeMapping.find(s) != subTreeMapping.end())
//     {
//         // Agar entry aagyi hai to
//         if (subTreeMapping[s] == 1)
//         {
//             // ek hi baar aagyi thi or ab dobara aarhi hai. Matlab duplicate
//             ans.push_back(root);
//         }
//         subTreeMapping[s]++;
//     }
//     else
//     {
//         // Agar entry nahi mili toh
//         subTreeMapping[s] = 1;
//     }
//     return s;
// }


vector<Node *> ans;
unordered_map<string, int> subTreeMapping;

string preorderTraversal(Node *root)
{
    // 1. Base Case
    if(root == NULL){
        return "NULL";
    }

    // 2. Find currNode , LeftNode and Right Node into a string
    string curr = to_string(root->data);

    // 3. Similarly find left and right through recursion
    string left = preorderTraversal(root->left);
    string right = preorderTraversal(root->right);

    string s = curr + " , " + left + " , " + right;

    // 4. Check for entry in map
    if(subTreeMapping.find(s) != subTreeMapping.end()){
        // 5. entry mil gyi, pehle se kuch pada hai
        if(subTreeMapping[s] == 1){
            // 6. Matlab pehle se ek entry padi thi ab ek or mil gyi matlab duplicate
            ans.push_back(root);
        }
        subTreeMapping[s]++;
    }
    else{
        // 7. Entry nhi mili toh daldo
        subTreeMapping[s] = 1;
    }
    return s;
}

vector<Node *> duplicate(Node *root)
{
    preorderTraversal(root);
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
    Node *root = buildTrees();

    cout<<endl;
    cout<<endl;

    levelOrderTraversalLineWise(root);

    cout<<endl;
    cout<<endl;

    vector<Node*> ans = duplicate(root);

    for(int i=0 ; i<ans.size() ; i++){
        cout<<ans[i]->data<<" ";
    }

    return 0;
}
