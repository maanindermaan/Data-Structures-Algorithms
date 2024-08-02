// TLE
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node()
    {
    }

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

void build(int &i, int min, int max, vector<int> &arr)
{
    if (i >= arr.size())
    {
        return;
    }

    if (arr[i] > min && arr[i] < max)
    {
        int rootData = arr[i++];
        // Left call
        build(i, min, rootData, arr);
        // Right call
        build(i, rootData, max, arr);
    }
}

bool ValidBSTfromPreorder(vector<int> &arr)
{
    int min = INT_MIN;
    int max = INT_MAX;
    int i = 0;
    build(i, min, max, arr);
    return i == arr.size();
}

int main()
{
    vector<int> arr{10, 8, 7, 9, 20, 15, 21};

    if (ValidBSTfromPreorder(arr))
    {
        cout << "YES it is valid BST";
    }
    else
    {
        cout << "No it is not valid";
    }
}