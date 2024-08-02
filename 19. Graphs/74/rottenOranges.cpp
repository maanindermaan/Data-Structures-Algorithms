#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    queue<pair<pair<int, int>, int>> q; // {Coordinates , time }
    // orignal grid ki copy banali
    vector<vector<int>> arr = grid;
    // insert all rotten oranges in queue

    int count = 0;
    int ansTime = 0;

    for (int row = 0; row < grid.size(); row++)
    {
        for (int col = 0; col < grid[row].size(); col++)
        {
            if (grid[row][col] == 2)
            {
                // rotten orange found
                pair<int, int> coordinate = make_pair(row, col);
                q.push({coordinate, 0}); // initially time is 0 only
            }
        }
    }

    // x.1 iss uper wale for loop se total fresh oranges ka count nikal sikta hai

    while (!q.empty())
    {
        // auto fnode = q.front();


        pair < pair<int, int>, int > fnode = q.front();
        q.pop();
        int x = fnode.first.first;
        int y = fnode.first.second;
        int time = fnode.second;

        // bool kuchRottKia = false; no neeed of this flag

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];

            // jha par tum rott karne wale ho vhapar fresh orange pada bhi hai ya nahi pada hai
            if (newX >= 0 && newX < arr.size() && newY >= 0 && newY < arr[0].size() && arr[newX][newY] == 1)
            { // 1 - fresh orange
                // if these conditions satify then only i will rott otherwise i will not
                pair<int, int> newCoordinates = make_pair(newX, newY);
                ansTime = max(ansTime, time + 1);
                q.push({newCoordinates, time + 1});

                // mark rotten
                arr[newX][newY] = 2; // rotted

                // x.2 Orange ko rott karte wakte fresh oranges ka count-- hosakta hai
            }
        }
    }

    // if any fresh orange is pending return -1
    // check for fresh orange
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            if (arr[i][j] == 1)
            {
                return -1;
            }
        }
    }

    // x.3 without using these for loops just check whther fresh oranges count is >0 , if >0 return -1 simple
    return ansTime;
}

int main()
{
    vector<vector<int>> grid{
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}};

    cout << orangesRotting(grid);
    return 0;
}







#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    queue<pair<pair<int, int>, int>> q; // {coordinates , time}
    vector<vector<int>> arr = grid;
    int count = 0;
    int ansTime = 0;

    for (int row = 0; row < arr.size(); row++)
    {
        for (int col = 0; col < arr[0].size(); col++)
        {
            if (grid[row][col] == 2)
            {
                q.push({{row, col}, 0});
                // pair<int , int> coordinates = make_pair(row , col);
                // q.push({coordinates , 0});
            }
        }
    }

    while (!q.empty())
    {
        auto fnode = q.front();
        q.pop();
        int x = fnode.first.first;
        int y = fnode.first.second;
        int time = fnode.second;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int newX = dx[i] + x;
            int newY = dy[i] + y;

            if (newX >= 0 && newX < arr.size() && newY >= 0 && newY < arr[0].size() && arr[newX][newY] == 1)
            {
                // i have to rott it here
                ansTime = max(ansTime, time + 1);
                q.push({{newX, newY}, time + 1});
                arr[newX][newY] = 2;
            }
        }
    }

    // agar koi bachgya tooh return false
    for (int row = 0; row < arr.size(); row++)
    {
        for (int col = 0; col < arr[0].size(); col++)
        {
            if (arr[row][col] == 1)
            {
                return -1;
            }
        }
    }
    return ansTime;
}

int main()
{
    vector<vector<int>> grid{
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}};

    cout << orangesRotting(grid);
    return 0;
}