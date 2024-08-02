#include<iostream>
using namespace std;
int main(){

return 0;
}

class Solution {
public:

    void convertStrsToNumStrs(vector<string>& strs, int m, int n , vector<pair<int , int>>&numStrs){
        for(auto i : strs){
            int zeroes = 0;
            int ones = 0;
            for(auto j : i){
                if(j == '0'){
                    zeroes++;
                }
                if(j == '1'){
                    ones++;
                }
            }
            numStrs.push_back({zeroes , ones});
        }
    }

    int solveUsingRecursion(vector<pair<int , int>>&numStrs , int i , int m, int n){
        if(i == numStrs.size()){
            return 0;
        }

        int zeroes = numStrs[i].first;
        int ones = numStrs[i].second;
        int include = 0 , exclude = 0;

        // if positive then only include possible
        if(m-zeroes >= 0 && n-ones >= 0){
            include = 1 + solveUsingRecursion(numStrs , i+1 , m-zeroes , n-ones);
        }
        exclude = solveUsingRecursion(numStrs , i+1 , m , n);

        return max(include , exclude);
    }

    int solveUsingMemo(vector<pair<int , int>>&numStrs , int i , int m, int n , vector<vector<vector<int>>>&dp){
        if(i == numStrs.size()){
            return 0;
        }

        if(dp[i][m][n] != -1){
            return dp[i][m][n];
        }

        int zeroes = numStrs[i].first;
        int ones = numStrs[i].second;
        int include = 0 , exclude = 0;

        // if positive then only include possible
        if(m-zeroes >= 0 && n-ones >= 0){
            include = 1 + solveUsingMemo(numStrs , i+1 , m-zeroes , n-ones , dp);
        }
        exclude = solveUsingMemo(numStrs , i+1 , m , n , dp);

        dp[i][m][n] = max(include , exclude);
        return dp[i][m][n];
    }

    int solveUsingTab(vector<pair<int , int>>&numStrs , int zero, int one){
        vector<vector<vector<int>>>dp(numStrs.size()+1 , vector<vector<int>>(zero+1 , vector<int>(one+1 , 0)));

        for(int i = numStrs.size()-1 ; i>=0 ; i--){
            for(int m = 0 ; m <= zero ; m++){
                for(int n = 0 ; n <= one ; n++){
                    int zeroes = numStrs[i].first;
                    int ones = numStrs[i].second;
                    int include = 0 , exclude = 0;

                    // if positive then only include possible
                    if(m-zeroes >= 0 && n-ones >= 0){
                        include = 1 + dp[i+1][m-zeroes][n-ones];
                    }
                    exclude = dp[i+1][m][n];

                    dp[i][m][n] = max(include , exclude);
                }
            }
        }
        return dp[0][zero][one];
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        // firstly converting this strs to vector pair<no. of zeros , no. of ones>
        vector<pair<int , int>>numStrs;
        convertStrsToNumStrs(strs , m , n , numStrs);

        // return solveUsingRecursion(numStrs , 0 , m , n);

        // vector<vector<vector<int>>>dp(numStrs.size()+1 , vector<vector<int>>(m+1 , vector<int>(n+1 , -1)));
        // return solveUsingMemo(numStrs , 0 , m , n , dp);

        return solveUsingTab(numStrs , m , n);
    }
};