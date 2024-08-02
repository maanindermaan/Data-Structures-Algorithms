#include<iostream>
using namespace std;
int main(){
return 0;
}

class Solution {
public:

    int solve(vector<int>&sv , int i){
        if(i == sv.size()) return 0;

        int ans = INT_MIN;
        int total = 0;
        for(int X = 1 ; X<=3 ; X++){
            if(i+X-1 >= sv.size()) break;
            total += sv[i+X-1];
            ans = max(ans , total - solve(sv , i+X));
        }
        return ans;
    }

    int solveMemo(vector<int>&sv , int i , vector<int>&dp){
        if(i == sv.size()) return 0;

        if(dp[i] != -1) return dp[i];
        int ans = INT_MIN;
        int total = 0;
        for(int X = 1 ; X<=3 ; X++){
            if(i+X-1 >= sv.size()) break;
            total += sv[i+X-1];
            ans = max(ans , total - solveMemo(sv , i+X , dp));
        }
        dp[i] = ans;
        return dp[i];
    }

    int solveTab(vector<int>&sv){
        vector<int>dp(sv.size()+1 , 0);

        for(int i = sv.size()-1 ; i>=0 ; i--){
            int ans = INT_MIN;
            int total = 0;
            for(int X = 1 ; X<=3 ; X++){
                if(i+X-1 >= sv.size()) break;
                total += sv[i+X-1];
                ans = max(ans , total - dp[i+X]);
            }
            dp[i] = ans;
        }
        return dp[0];
    }

    string stoneGameIII(vector<int>& stoneValue) {
        // int ans = solve(stoneValue , 0);

        // vector<int>dp(stoneValue.size()+1 , -1);
        // int ans = solveMemo(stoneValue , 0 , dp);

        int ans = solveTab(stoneValue);
        if(ans > 0) return "Alice";
        if(ans < 0) return "Bob";
        return "Tie";
    }
};