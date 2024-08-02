// This question is really important don't consider this as an easy question really a hard one to crack
#include <iostream>
#include <vector>
#include <map>
using namespace std;

void dfs(int x, int y, int oldColor, int newColor, map<pair<int, int>, bool> &vis, vector<vector<int>> &arr)
{
    vis[{x, y}] = true;
    arr[x][y] = newColor; // jha visited hai vha color insert krdo, ye recursion se hota rhega

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (newX >= 0 && newX < arr.size() && newY >= 0 && newY < arr[0].size() &&
            !vis[{newX, newY}] && arr[newX][newY] == oldColor) // jis par bhi jarhe ho vo tumhara old color ke equal hona chiye
        {
            dfs(newX, newY, oldColor, newColor, vis, arr);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int oldColor = image[sr][sc];
    map<pair<int, int>, bool> vis;

    // never modify actual data
    vector<vector<int>> ans = image;
    dfs(sr, sc, oldColor, color, vis, ans);
    return ans;
}

int main()
{
    vector<vector<int>> image{
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};

    int sr = 1;
    int sc = 1;
    int color = 2;

    vector<vector<int>> ans = floodFill(image, sr, sc, color);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans.size(); j++)
        {
            cout << ans[i][j]<<" "<<" ";
        }
        cout << endl;
    }
    return 0;
}



// practice
#include <iostream>
#include <vector>
#include <map>
using namespace std;

void dfs(int row , int col , map<pair<int , int> , bool>& visited , vector<vector<int>>& arr , int oldColor , int newColor){
    // 1. Mark initial elements true and color that with required color
    visited[{row,col}] =true;
    arr[row][col] = newColor;

    // 2. Find adjacent neighbours to this row , col. Note we only have this row and col so update accordinly
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    for(int i=0 ; i<4; i++){
        // 3. finding new neighbours i.e. new box's coordinates
        int newX = dx[i] + row;
        int newY = dy[i] + col;

        // 4. checking boundary conditons and also checking whether the block is having oldcolor 1 or not 
        if(newX >= 0 && newX < arr.size() && newY >=0 && newY < arr[0].size() && arr[newX][newY] == oldColor && !visited[{newX, newY}]){
            dfs(newX , newY , visited , arr , oldColor , newColor);
        }
    }
    
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int oldColor = image[sr][sc];

    map<pair<int , int> , bool>visited;

    vector<vector<int>>ans = image;

    dfs(sr , sc , visited , ans , oldColor , color);

    return ans;
}

int main()
{
    vector<vector<int>> image{
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};

    int sr = 1;
    int sc = 1;
    int color = 2;

    vector<vector<int>> ans = floodFill(image, sr, sc, color);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans.size(); j++)
        {
            cout << ans[i][j]<<" "<<" ";
        }
        cout << endl;
    }
    return 0;
}