#include<iostream>
#include<vector>
using namespace std;
int main(){

return 0;
}

// 1. very bad TC
class Solution {
public:
    bool isSafe(vector<vector<char>>& board, char ch , int i , int j){
        if((i >= 0 && i <board.size()) && (j >= 0 && j < board[0].size()) &&(board[i][j] == ch)){
            return true;
        }
        return false;
    }


    bool recursiveHelper(vector<vector<char>>& board, string word , int wordIndex , int i , int j){
        if(wordIndex == word.size()){
            return true;
        }

        if(!isSafe(board , word[wordIndex] , i , j)){
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#';

        bool flag = recursiveHelper(board, word, wordIndex+1 , i+1 , j) ||
                    recursiveHelper(board, word, wordIndex+1 , i-1 , j) ||
                    recursiveHelper(board, word, wordIndex+1 , i , j+1) ||
                    recursiveHelper(board, word, wordIndex+1 , i , j-1);
        
        board[i][j] = temp;

        return flag;
    }

    bool exist(vector<vector<char>>& board, string word){
        for(int i=0 ; i<board.size() ; i++){
            for(int j=0 ; j<board[0].size() ; j++){
                if(recursiveHelper(board , word , 0 , i , j)){
                    return true;
                }
            }
        }
        return false;
    }
};

// 2. Binary Search Aproach donot working 
class Solution {
public:
    bool isSafe(vector<vector<char>>& board, char ch, int i, int j) {
        return i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && board[i][j] == ch;
    }

    bool recursiveHelper(vector<vector<char>>& board, string word, int wordIndex, int i, int j) {
        if (wordIndex == word.size()) {
            return true;
        }

        if (!isSafe(board, word[wordIndex], i, j)) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#';

        bool flag = recursiveHelper(board, word, wordIndex + 1, i + 1, j) ||
                    recursiveHelper(board, word, wordIndex + 1, i - 1, j) ||
                    recursiveHelper(board, word, wordIndex + 1, i, j + 1) ||
                    recursiveHelper(board, word, wordIndex + 1, i, j - 1);

        board[i][j] = temp;

        return flag;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        int totalElements = rows * cols;

        int s = 0;
        int e = totalElements - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            int rowIndex = mid / cols;
            int colIndex = mid % cols;

            char element = board[rowIndex][colIndex];

            if (element == word[0]) {
                if (recursiveHelper(board, word, 0, rowIndex, colIndex)) {
                    return true;
                }
            }

            if (element < word[]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return false;
    }
};

// 3. More optimised method
