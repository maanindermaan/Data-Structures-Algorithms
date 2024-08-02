#include<iostream>
using namespace std;
int main(){

return 0;
}

class Solution {
public:

    int solve(string& s , string& t , int i , int j){
        // base case
        if(j == t.size()){
            return 1;
        }
        if(i == s.size()){
            return 0;
        }
        int ans = 0;
        if(s[i] == t[j]){
            ans += solve(s , t , i+1 , j+1);
        }

        ans += solve(s , t , i+1 , j);

        return ans;
    }


    int solveMemo(string& s , string& t , int i , int j , vector<vector<int>>&dp){
        // base case
        if(j == t.size()){
            return 1;
        }
        if(i == s.size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 0;
        if(s[i] == t[j]){
            ans += solveMemo(s , t , i+1 , j+1 , dp);
        }

        ans += solveMemo(s , t , i+1 , j , dp);

        dp[i][j] = ans;
        return dp[i][j];
    }

    int solveTab(string& s , string& t){
        vector<vector<int>>dp(s.size()+1 , vector<int>(t.size()+1 , 0));

        // base case
        for(int i = 0 ; i<=s.size() ; i++){ 
            dp[i][t.size()] = 1;
        }

        for(int i = s.size()-1 ; i >= 0 ; i--){
            for(int j = t.size()-1 ; j >= 0 ; j--){
                long long ans = 0; // this was shwoing error previously
                if(s[i] == t[j]){
                    ans += dp[i+1][j+1];
                }

                ans += dp[i+1][j];

                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int numDistinct(string s, string t) {
        // return solve(s , t , 0 , 0);

        // vector<vector<int>>dp(s.size()+1 , vector<int>(t.size()+1 , -1));
        // return solveMemo(s , t , 0 , 0 , dp);

        return solveTab(s , t);

    }
};