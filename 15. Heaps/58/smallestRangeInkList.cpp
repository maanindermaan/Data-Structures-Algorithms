// 1
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    int row;
    int col;

    node(int d, int r, int c)
    {
        data = d;
        row = r;
        col = c;
    }
};

class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

vector<int> smallestRange(vector<vector<int>> &nums)
{
    int mini = INT_MAX;
    int maxi = INT_MIN;

    priority_queue<node *, vector<node *>, compare> minHeap;

    int k = nums.size();
    for (int i = 0; i < k; i++)
    {
        int element = nums[i][0];
        maxi = max(maxi, element);
        mini = min(mini, element);
        node *temp = new node(element, i, 0);
        minHeap.push(temp);
    }

    int ansStart = mini;
    int ansEnd = maxi;

    while (!minHeap.empty())
    {
        node *top = minHeap.top();
        int topelement = top->data;
        int topRow = top->row;
        int topCol = top->col;
        minHeap.pop();

        // mini updated -> range updated -> ans updated
        mini = topelement;

        // check for answer
        int currRange = maxi - mini;
        int ansRange = ansEnd - ansStart;
        if (currRange < ansRange)
        {
            ansStart = mini;
            ansEnd = maxi;
        }

        // check for new element in the same list
        if (topCol + 1 < nums[topRow].size())
        {
            maxi = max(maxi, nums[topRow][topCol + 1]);
            node *newNode = new node(nums[topRow][topCol + 1], topRow, topCol + 1);
            minHeap.push(newNode);
        }
        else
        {
            // there is no element int the same array or list
            break;
        }
    }
    vector<int> ans;
    ans.push_back(ansStart);
    ans.push_back(ansEnd);
    return ans;
}

int main()
{

    return 0;
}


// 2
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    int row;
    int col;

    Node(int d, int r, int c)
    {
        data = d;
        row = r;
        col = c;
    }
};

class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

vector<int> smallestRange(vector<vector<int>> &nums)
{
    int mini = INT_MAX;
    int maxi = INT_MIN;

    priority_queue<Node *, vector<Node *>, compare> minHeap;

    int k = nums.size();

    for (int i = 0; i < k; i++)
    {
        Node *temp = new Node(nums[i][0], i, 0);
        int element = temp->data;
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(temp);
    }

    int ansStart = mini;
    int ansEnd = maxi;

    while (!minHeap.empty())
    {
        Node *temp = minHeap.top();

        int topElement = temp->data;
        int topRow = temp->row;
        int topCol = temp->col;
        minHeap.pop();

        mini = topElement;

        int currRange = maxi - mini;
        int ansRange = ansEnd - ansStart;

        if (currRange < ansRange)
        {
            ansStart = mini;
            ansEnd = maxi;
        }

        if (topCol + 1 < nums[topRow].size())
        {
            maxi = max(maxi, nums[topRow][topCol + 1]);
            Node *newNode = new Node(nums[topRow][topCol + 1], topRow, topCol + 1);
            minHeap.push(newNode);
        }
        else
        {
            break;
        }
    }
    vector<int> ans;
    ans.push_back(ansStart);
    ans.push_back(ansEnd);
    return ans;
}

int main()
{

    return 0;
}
