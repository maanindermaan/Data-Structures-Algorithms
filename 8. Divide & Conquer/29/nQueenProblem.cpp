#include<iostream>
#include<vector> 
using namespace std;

void printSolution(vector< vector<char > > & board , int n){
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
}


bool isSafe(int row , int col , vector< vector<char > > & board , int n){
    // check karna chahte hai ki kya mai current cell[row][col] par queen rakh sakta hu ya nahi
    int i=row;
    int j=col;

    // 1-> checking row
    while(j >= 0){
        if(board[i][j] == 'Q'){
            return false;
        }
        j--;
    }

    // 2-> checking upper left diagonal
    i=row;
    j=col;
    while(i>=0 && j>=0){
        if(board[i][j] == 'Q'){
            return false;
        }
        j--;
        i--;
    }

    // 3-> checking bottom left diagonal
    i=row;
    j=col;
    while(i<n && j>=0){
        if(board[i][j] == 'Q'){
            return false;
        }
        j--;
        i++;
    }

    // Kahi bhi queen nahi mili matlab position safe hai so return true
    return true;
}

void solve(vector< vector<char > > & board , int col , int n){
    // Base Case
    if(col>=n){
        printSolution(board , n);
        return;
    }

    // 1 case solve karna haii baaki recursion sambhal lega
    // col 0 ke har row ke andar Q1 place karane ka try karna hai
    for(int row = 0 ; row<n ; row++){
        if(isSafe(row , col , board , n)){
            // rakh do 
            board[row][col] = 'Q';
            // Recursive Call
            solve(board , col+1 , n);
            // Backtracking :
            board[row][col] = '-';
        }
    }
}

int main(){
    int n = 4;
    // 0 -> Empty Cell
    // 1 -> Queen at the cell
    vector< vector<char > > board(n , vector<char>(n , '-')); // n*n matrix
    int col = 0;

    solve(board , col , n);
return 0;
}