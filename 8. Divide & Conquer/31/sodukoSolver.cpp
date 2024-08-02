#include<iostream>
#include<vector>
using namespace std;


bool isSafe(int value , vector<vector<char > > & board , int row , int col){
    
    int n = board.size();
    for(int i=0 ; i<n ; i++){
        // row check
        if(board[row][i] == value){
            return false;
        }

        // col check
        if(board[i][col] == value){
            return false;
        }

        // 3*3 check
        if(board[3*(row/3) + (i/3)][3*(col/3) + (i%3)] == value){  // to get another value : board[3*(row/3) + (i/3)][3*(col/3) + (i%3)]
            return false;
        }
    }

    return true;
}


// this function returns true or false basis on we found a solution or not
bool solve(vector<vector<char > > & board){

    int n = board.size();

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            // Check for empty cell
            if(board[i][j] == '.'){ //  . -> signifies empty
            // try to fill values from 1 - 9
                for(char value = '1'; value <='9' ; value++){
                    // check for safety
                    if(isSafe(value , board  , i , j)){
                        // insert 
                        board[i][j] = value;
                        // baaki recursion smabal lega
                        bool remainingBoardSolution = solve(board);
                        if(remainingBoardSolution == true){
                            return true; // mujhe sirf unique ek hi solution chahiye saare ke saare nahi chahiye
                        }
                        else{
                            // backtracking agar solution na milte to 
                            board[i][j] = '.';
                        }
                    }
                }
                // if 1 se 9 tak koi bhi value ka solution nahi nikla , current cell par , that means piche kahi pe galti kari hai , go back by returning false; 
                return false;
            }
        }
    }
    // all cells filled
    return true;
}

int main(){
    // 0-> represents empty cell 
    vector<vector<char > > board{
        {'4', '5', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '2', '.', '7', '.', '6', '3', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '2', '8'},
        {'.', '.', '.', '9', '5', '.', '.', '.', '.'},
        {'.', '8', '6', '.', '.', '.', '2', '.', '.'},
        {'.', '2', '.', '6', '.', '.', '7', '5', '.'},
        {'.', '.', '.', '.', '.', '.', '4', '7', '6'},
        {'.', '7', '.', '.', '4', '5', '.', '.', '.'},
        {'.', '.', '8', '.', '.', '9', '.', '.', '.'}
    };

    solve(board);

    int n = board.size();
    
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    

return 0;
}