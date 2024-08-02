// USING MAPS
#include<iostream>
#include<vector> 
#include<unordered_map>
using namespace std;

unordered_map<int , bool>leftCheck;
unordered_map<int , bool>upperLeftDiagonalCheck;
unordered_map<int , bool>bottomLeftDiagonalCheck;

void printSolution(vector< vector<char>>& board , int n){
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
}


bool isSafe(int row , int col , vector< vector<char>>& board , int n){
    if(leftCheck[row] == true){
        return false;
    }
    else if(upperLeftDiagonalCheck[n-1+col-row] == true){
        return false;
    }
    else if(bottomLeftDiagonalCheck[row+col] == true){
        return false;
    }
    return true;
}

void solve(vector< vector<char>>& board , int col , int n){
    // Base Case
    if(col>=n){
        printSolution(board , n);
        return;
    }

    // 1 case solve karna haii baaki recursion sambhal lega
    // col 0 ke har row ke andar Q1 place karane ka try karna haix
    for(int row = 0 ; row<n ; row++){
        if(isSafe(row , col , board , n)){
            // rakh do 
            board[row][col] = 'Q';
            leftCheck[row] = true;
            upperLeftDiagonalCheck[n-1+col-row] = true;
            bottomLeftDiagonalCheck[row+col] = true;
            
            // Recursive Call
            solve(board , col+1 , n);
            leftCheck[row] = false;
            upperLeftDiagonalCheck[n-1+col-row] = false;
            bottomLeftDiagonalCheck[row+col] = false;
            // Backtracking :
            board[row][col] = '-';
        }
    }
}

int main(){
    int n = 4;
    // 0 -> Empty Cell
    // 1 -> Queen at the cell
    vector< vector<char>>board(n , vector<char>(n , '-')); // n*n matrix
    int col = 0;

    solve(board , col , n);
return 0;
}