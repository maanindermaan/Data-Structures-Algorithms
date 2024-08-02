#include<iostream>
using namespace std;
int main(){

return 0;
}

class Solution {
public:
    int maxLen = 1 , start = 0;
    bool solve(string& s , int i , int j){
        // base case
        if(i>=j){
            return true;
        }
        // solving for one case
        bool flag = false;
        if(s[i] == s[j]){
            flag = solve(s , i+1 , j-1);
        }
        // if it was a palindrome
        if(flag){
            int currLen = j-i+1;
            if(maxLen < currLen){
                maxLen = currLen;
                start = i;
            }
        }
        return flag;
    }


    bool solveDP(string& s , int i , int j , vector<vector<int>>&dp){
        // base case
        if(i>=j){
            return true;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        // solving for one case
        bool flag = false;
        if(s[i] == s[j]){
            flag = solve(s , i+1 , j-1);
        }
        // if it was a palindrome
        if(flag){
            int currLen = j-i+1;
            if(maxLen < currLen){
                maxLen = currLen;
                start = i;
            }
        }
        dp[i][j] = flag;
        return dp[i][j];
    }

    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1));
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                // bool t = solve(s , i , j);
                bool t = solveDP(s , i , j , dp);
            }
        }
        return s.substr(start , maxLen);
    }
};