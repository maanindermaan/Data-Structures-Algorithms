#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int i, int j, int row, int col, int arr[3][3], vector<vector<bool > > & visited) {
    if (i >= 0 && i < row && j >= 0 && j < col && arr[i][j] == 1 && !visited[i][j]) {
        return true;
    }
    return false;
}

void solveMaze(int arr[3][3], int row, int col, int i, int j, vector<vector<bool > > & visited, vector<string>& path, string output) {
    // Base Case
    if (i == row - 1 && j == col - 1) {
        // answer found
        path.push_back(output);
        return;
    }

    // Down -> i+1, j
    if (isSafe(i + 1, j, row, col, arr, visited)) {
        visited[i + 1][j] = true;
        solveMaze(arr, row, col, i + 1, j, visited, path, output + 'D'); // concatenation. We can also write output.push_back('D')
        // Backtracks
        visited[i + 1][j] = false;
    }
    // Left -> i, j-1
    if (isSafe(i, j - 1, row, col, arr, visited)) {
        visited[i][j - 1] = true;
        solveMaze(arr, row, col, i, j - 1, visited, path, output + 'L');
        // Backtracks
        visited[i][j - 1] = false;
    }
    // Right -> i, j+1
    if (isSafe(i, j + 1, row, col, arr, visited)) {
        visited[i][j + 1] = true;
        solveMaze(arr, row, col, i, j + 1, visited, path, output + 'R');
        // Backtracks
        visited[i][j + 1] = false;
    }
    // Up -> i-1, j
    if (isSafe(i - 1, j, row, col, arr, visited)) {
        visited[i - 1][j] = true;
        solveMaze(arr, row, col, i - 1, j, visited, path, output + 'U');
        // Backtracks
        visited[i - 1][j] = false;
    }
}
int main(){
    int maze[3][3]= {{1,0,0},
                    {1,1,0},
                    {1,1,1}}; 

    if(maze[0][0] == 0){
        cout<<"No path available ";
        return 0;
    }

    int row = 3;
    int col = 3;

    // 2D Vector Array intitiallized with FALSE
    vector<vector<bool > > visited(row , vector<bool>(row , false));
    // source ki value ko 0 mark kardiya 
    visited[0][0] = true;

    vector<string>path; //-> jo ki saare paths store kregi
    string output = ""; //->intially empty isme hum answer create krrhe honge

    solveMaze(maze , row , col , 0 , 0 , visited , path , output); // 0 - > source ka x coordiante 0-> source ka y coordinates

    // Printing The Results
    for(int i=0 ; i<path.size() ; i++){
        cout<<path[i]<<" ";
    }

    if(path.size() == 0){
        cout<<"No path available ";
        return 0;
    }
return 0;
}