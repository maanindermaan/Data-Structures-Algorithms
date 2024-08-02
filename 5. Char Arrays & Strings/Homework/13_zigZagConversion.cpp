#include<iostream>
#include<vector>
using namespace std;

string convertZigZag(string s , int numRows){
    if(numRows == 1){
        return s;
    }

    vector<string> zigzag(numRows); // size will be of numRows only

    int i = 0 , row = 0;
    bool direction = 1; // 1 -> means -> Top->Bottom
    while(true){
        if(direction){
            // T->B
            while(row<numRows && i<s.size()){
                zigzag[row++].push_back(s[i++]); // row++ and i++
            }
            row = numRows - 2;
        }
        else{
            // B->T
            while(row>=0 && i<s.size()){
                zigzag[row--].push_back(s[i++]);
            }
            row = 1; // direction change hui to row ko 1 kardo 
        }
        direction = !direction; 
        if(i>=s.size()){
            break;
        }
    }

    // Reading values line by line
    string ans = " "; // because we want our answer in string
    for(int i=0 ; i<zigzag.size() ; i++){
        ans = ans + zigzag[i];
    }
    return ans;
}

int main(){
    string s = "ABCDEFGHIJ";
    int numRows = 3;

    string ans = convertZigZag(s , numRows);
    cout<<ans;
return 0;
}




// Soltion 2
class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1){
            return s;
        }
        // Making a 2d matrix
        vector<vector<char>> matrix(numRows, vector<char>(s.size(), ' '));
        
        // inserting
        int row = 0;
        bool goingDown = false;

        for(int i=0 ; i<s.size() ; i++){
            matrix[row][i] = s[i];

            if(row == 0 || row == numRows - 1){
                goingDown = !goingDown;
            }

            row += goingDown ? 1 : -1;
        }

        // reading
        string ans = "";

        for(int i=0 ; i<numRows ; i++){
            for(int j=0 ; j<s.size() ; j++){
                if(matrix[i][j] != ' '){
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};