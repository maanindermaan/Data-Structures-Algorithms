#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// running on indexes not nodes 
void dfs(int src, unordered_map<int, bool> &visited, vector<vector<int>> &isConnected)
{
    visited[src] = true;
    // row -> src; src is passend via 0 1 2(for loop where function is called) src is index now so no problem now 
    // col -> nbr we will write a loop for it
    for (int col = 0; col < isConnected[src].size(); col++)
    { // col starts from 0 1 2
        if (src != col && isConnected[src][col] == 1)  // this (src != col) condition is not that important because meanwhile if src == col we are checking ahead in visited conditon if it is false it will never enter into that loop
        {
            // col is a nbr
            if (!visited[col])
            {
                dfs(col, visited, isConnected);
            }
        }
    }
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    unordered_map<int, bool> visited;
    int count = 0;
    int n = isConnected.size();
    // i represents nodes here
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, isConnected);
            count++;
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> isConnected{
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}};

    cout << findCircleNum(isConnected);
    return 0;
}









// // practice
// #include <iostream>
// #include <unordered_map>
// #include <vector>
// using namespace std;

// // running on indexes not nodes 
// void dfs(int src, unordered_map<int, bool> &visited, vector<vector<int>> &isConnected)
// {
//     visited[src] = true;

//     int n = isConnected[0].size();

//     for(int col = 0 ;col<n ; col++){
//         if(src != col && isConnected[src][col] == 1){
//             if(!visited[col]){
//                 dfs(col , visited , isConnected);
//             }
//         }
//     }   
// }

// int findCircleNum(vector<vector<int>> &isConnected)
// {
//     unordered_map<int , bool>visited;
//     int n = isConnected.size();

//     int count = 0;

//     for(int row = 0 ; row < n ; row++){
//         if(!visited[row]){
//             dfs(row , visited , isConnected);
//             count++;
//         }
//     }   
//     return count;
// }

// int main()
// {
//     vector<vector<int>> isConnected{
//         {1, 1, 0},
//         {1, 1, 0},
//         {0, 0, 1}};

//     cout << findCircleNum(isConnected);
//     return 0;
// }