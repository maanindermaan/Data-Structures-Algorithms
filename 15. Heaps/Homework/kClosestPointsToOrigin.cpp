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

    Node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
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

vector<pair<int, int>> kClosestPoints(vector<vector<int>> &arr, int n, int k)
{
    priority_queue<Node *, vector<Node *>, compare> minHeap;
    vector<pair<int, int>> ans;

    for (int i = 0; i < n; i++)
    {
        int distance = arr[i][0] * arr[i][0] + arr[i][1] * arr[i][1];
        Node *temp = new Node(distance, i, 0);
        minHeap.push(temp);
    }

    while (k-- && !minHeap.empty())
    {
        Node *temp = minHeap.top();
        minHeap.pop();
        int ansRow = temp->row;
        int ansCol = temp->col;

        ans.push_back(make_pair(arr[ansRow][ansCol], arr[ansRow][ansCol + 1]));

        delete temp; // Free the memory of the Node object
    }

    return ans;
}

int main()
{
    vector<vector<int>> arr{{1, 3},
                            {-2, 2},
                            {-3, 3},
                            {1, 2},
                            {1, 1},
                            {0, 0}

    };

    int n = arr.size();
    int k = 1;
    vector<pair<int, int>> ans = kClosestPoints(arr, n, k);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << "(" << ans[i].first << ", " << ans[i].second << ")" << endl;
    }
    return 0;
}





// class Node
// {
// public:
//     int data;
//     int row;
//     int col;

//     Node(int data, int row, int col)
//     {
//         this->data = data;
//         this->row = row;
//         this->col = col;
//     }
// };

// class compare
// {
// public:
//     bool operator()(Node *a, Node *b)
//     {
//         return a->data > b->data;
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
//         priority_queue<Node *, vector<Node *>, compare> minHeap;
//         vector<vector<int>> ans;

//         for (int i = 0; i < points.size(); i++)
//         {
//             int distance = ((points[i][0] * points[i][0]) + (points[i][1] * points[i][1]));
//             Node *temp = new Node(distance, i, 0);
//             minHeap.push(temp);
//         }

//         while (k-- && !minHeap.empty())
//         {
//             Node *temp = minHeap.top();
//             minHeap.pop();
//             int ansRow = temp->row;
//             int ansCol = temp->col;

//             ans.push_back({points[ansRow][ansCol], points[ansRow][ansCol + 1]});

//             delete temp; // Free the memory of the Node object
//         }

//         return ans;
//     }
// };
