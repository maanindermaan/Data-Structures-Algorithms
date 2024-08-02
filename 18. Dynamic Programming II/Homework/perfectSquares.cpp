#include<iostream>
using namespace std;
int main(){
    
return 0;
}
class Solution {
public:

    int solveUsingRecursion(int n){
        // 1. base case
        if(n == 0){
            return 1;
        }
        // no such sq. root found
        if(n<0){
            return 0;
        }

        // 2. recursive case
        int ans = INT_MAX;
        int i = 1;
        int end = sqrt(n);

        while(i <= end){
            // find perfect squares
            int perfectSquares = i*i;
            int numberOfPerfectSquare = 1 + solveUsingRecursion(n - perfectSquares);

            // update the ans
            if(numberOfPerfectSquare < ans){
                ans = numberOfPerfectSquare;
            }
            // update i 
            // yahi bhulunga
            i++;
        }
        return ans;
    }

    int solveUsingMemo(int n , vector<int>&dp){
        // 1. base case
        if(n == 0){
            return 1;
        }
        // no such sq. root found
        if(n<0){
            return 0;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        // 2. recursive case
        int ans = INT_MAX;
        int i = 1;
        int end = sqrt(n);

        while(i <= end){
            // find perfect squares
            int perfectSquares = i*i;
            int numberOfPerfectSquare = 1 + solveUsingMemo(n - perfectSquares , dp);

            // update the ans
            if(numberOfPerfectSquare < ans){
                ans = numberOfPerfectSquare;
            }
            // update i 
            // yahi bhulunga
            i++;
        }
        dp[n] = ans;
        return dp[n];
    }

    int solveUsingTab(int n){

        vector<int>dp(n+1 , 0);
        dp[0] = 1;

        for(int i = 1 ; i<= n ; i++){
            // 2. recursive case
            int ans = INT_MAX;
            int start = 1;
            int end = sqrt(i);

            while(start <= end){
                // find perfect squares
                int perfectSquares = start*start;
                int numberOfPerfectSquare = 1 + dp[i - perfectSquares];

                // update the ans
                if(numberOfPerfectSquare < ans){
                    ans = numberOfPerfectSquare;
                }
                // update i 
                // yahi bhulunga
                start++;
            }
            dp[i] = ans;
        }
        return dp[n];
    }




    int numSquares(int n) {
        // return solveUsingRecursion(n) - 1;

        // vector<int>dp(n+1 , -1);
        // return solveUsingMemo(n , dp) - 1;

        return solveUsingTab(n)-1;
    }
};