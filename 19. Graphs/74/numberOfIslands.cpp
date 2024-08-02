#include <iostream>
#include <map>
#include <queue>
using namespace std;

void bfs(map<pair<int, int>, bool> &visited, int row, int col, vector<vector<char>> &grid)
{
    queue<pair<int, int>> q; // {0,0}
    // initial steps

    q.push({row, col});
    visited[{row, col}] = true;

    while (!q.empty())
    {
        pair<int, int> fnode = q.front();
        q.pop();

        int x = fnode.first;
        int y = fnode.second;

        // I can move in 4 directions
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];

            //  kya meri grid mein 1 pada hai uss position par or vo visited nahi hai tabhi i will insert in queue
            if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() &&
                !visited[{newX, newY}] && grid[newX][newY] == '1')
            {
                q.push({newX, newY});
                visited[{newX, newY}] = true;
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{

    map<pair<int, int>, bool> visited; // {row,col}->true
    int count = 0;

    for (int row = 0; row < grid.size(); row++)
    {
        for (int col = 0; col < grid[0].size(); col++)
        {
            // usi ko call krenge jha 1 pada hoga simple
            // yha galti karunga
            if (!visited[{row, col}] && grid[row][col] == '1')
            {
                bfs(visited, row, col, grid);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<char>> grid{
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};

    cout << numIslands(grid);
    return 0;
}






// practice
// #include <iostream>
// #include <map>
// #include <queue>
// using namespace std;

// void bfs(int row, int col, unordered_map<pair<int, int>, bool> &visited, vector<vector<char>> &grid)
// {
//     // 1. create a queue
//     queue<pair<int, int>> q;

//     // 2. push intial values to queue
//     q.push({row , col});

//     // 3. mark visited 
//     visited[{row , col}]= true;

//     // 4. now extract element and find neigbours of the element that is present on front of q
//     while(!q.empty()){
//         auto fnode = q.front();
//         int x = fnode.first; // row
//         int y = fnode.second; // col

//         // 5. Now find all the neighbours corresponding to this x and y or this row and col
//         int dx[] = {-1 , 0 , 1 , 0};
//         int dy[] = {0 , 1 , 0 , -1};

//         for(int i=0 ; i<4 ; i++){
//             int newX = x+dx[i];
//             int newY = y+dy[i];

//             // 6. Check your conditions for visited and push into queue
//             if(newX >=0 && newX<grid.size() && newY>=0 && newY<grid[0].size() && !visited[{newX , newY}] && grid[newX][newY] == '1'){
//                 q.push({newX , newY});
//                 visited[{newX , newY}] = true;
//             }
//         }
//     }
// }

// int numIslands(vector<vector<char>> &grid)
// {
//     unordered_map<pair<int, int>, bool> visited;

//     int count = 0;

//     // 1. iterate over adjacency matrix
//     for (int row = 0; row < grid.size(); row++)
//     {
//         for (int col = 0; col < grid[row].size(); col++)
//         {
//             // check whether that row or col is already visited or not and if at that position 1 is present
//             // or not
//             if (!visited[{row, col}] && grid[row][col] == '1')
//             {
//                 bfs(row, col, visited, grid);
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// int main()
// {
//     vector<vector<char>> grid{
//         {'1', '1', '1', '1', '0'},
//         {'1', '1', '0', '1', '0'},
//         {'1', '1', '0', '0', '0'},
//         {'0', '0', '0', '0', '0'}};

//     cout << numIslands(grid);
//     return 0;
// }