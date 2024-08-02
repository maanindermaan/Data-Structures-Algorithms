#include<iostream>
using namespace std;
int main(){
return 0;
}

class Solution {
public:

    int solveUsingRecursion(vector<int>&prices , int i , int buy , int &fee){
        if(i >= prices.size()){
            return 0;
        }

        int profit = 0;

        if(buy){
            int buyProfit = -prices[i] + solveUsingRecursion(prices , i+1 , 0 , fee);//this is sell and P = S-B
            int ignoreProfit = 0 + solveUsingRecursion(prices , i+1 , 1 , fee);
            profit = max(buyProfit , ignoreProfit);
        }
        // sell case
        else{
            int sellProfit = prices[i] + solveUsingRecursion(prices , i+1 , 1 , fee) - fee; // 1 Transaction completed
            int ignoreProfit = 0 + solveUsingRecursion(prices , i+1 , 0 , fee); // as we are not buying so buy = 0. Buy nahi kar sakte because selling is pending we are just skipping it though
            profit = max(sellProfit , ignoreProfit);
        }
        return profit;
    }

    int solveUsingMemo(vector<int>&prices , int i , int buy , vector<vector<int>>&dp , int &fee){
        if(i >= prices.size()){
            return 0;
        }

        if(dp[i][buy] != -1){
            return dp[i][buy];
        }

        int profit = 0;

        if(buy){
            int buyProfit = -prices[i] + solveUsingMemo(prices , i+1 , 0 , dp , fee);//this is sell and P = S-B
            int ignoreProfit = 0 + solveUsingMemo(prices , i+1 , 1 , dp , fee);
            profit = max(buyProfit , ignoreProfit);
        }
        // sell case
        else{
            int sellProfit = prices[i] + solveUsingMemo(prices , i+1 , 1 , dp , fee) - fee;
            int ignoreProfit = 0 + solveUsingMemo(prices , i+1 , 0 , dp , fee); // as we are not buying so buy = 0
            profit = max(sellProfit , ignoreProfit);
        }
        dp[i][buy] = profit;
        return dp[i][buy];
    }


    int solveUsingTab(vector<int>&prices , int i , int buy , int &fee){
        vector<vector<int>>dp(prices.size()+1 , vector<int>(2 , 0));

        for(int row = prices.size() - 1 ; row >=0 ; row--){ // i
            for(int col = 0 ; col <= buy ; col++){ // buy
                int profit = 0;

                if(col){
                    int buyProfit = -prices[row] + dp[row+1][0];
                    int ignoreProfit = 0 + dp[row+1][1];
                    profit = max(buyProfit , ignoreProfit);
                }
                // sell case
                else{
                    int sellProfit = prices[row] + dp[row+1][1] - fee;
                    int ignoreProfit = 0 + dp[row+1][0];
                    profit = max(sellProfit , ignoreProfit);
                }
                dp[row][col] = profit;
            }
        }
        return dp[i][buy];
    }


    int solveUsingSO(vector<int>&prices , int i , int buy , int &fee){
        vector<int>curr(2 , 0);
        vector<int>next(2 , 0);

        for(int row = prices.size() - 1 ; row >=0 ; row--){ // i
            for(int col = 0 ; col <= buy ; col++){ // buy
                int profit = 0;

                if(col){
                    int buyProfit = -prices[row] + next[0];
                    int ignoreProfit = 0 + next[1];
                    profit = max(buyProfit , ignoreProfit);
                }
                // sell case
                else{
                    int sellProfit = prices[row] + next[1] - fee;
                    int ignoreProfit = 0 + next[0];
                    profit = max(sellProfit , ignoreProfit);
                }
                curr[col] = profit;
            }
            // shift
            next = curr;
        }
        return curr[buy];
    }

    int solveUsingSOEXTREME(vector<int>&prices , int i , int buy , int& fee){
        // vector<int>curr(2 , 0);
        vector<int>next(2 , 0);

        for(int row = prices.size() - 1 ; row >=0 ; row--){ // i
            for(int col = 0 ; col <= buy ; col++){ // buy
                int profit = 0;

                if(col){
                    int buyProfit = -prices[row] + next[0];
                    int ignoreProfit = 0 + next[1];
                    profit = max(buyProfit , ignoreProfit);
                }
                // sell case
                else{
                    int sellProfit = prices[row] + next[1] - fee;
                    int ignoreProfit = 0 + next[0];
                    profit = max(sellProfit , ignoreProfit);
                }
                next[col] = profit;
            }
            // shift
            // next = curr;
        }
        return next[buy];
    }

    int maxProfit(vector<int>& prices , int fee) {
        // return solveUsingRecursion(prices , 0 , true , fee);

        // vector<vector<int>>dp(prices.size()+1 , vector<int>(2 , -1));
        // return solveUsingMemo(prices , 0 , true , dp , fee);

        // return solveUsingTab(prices , 0 , true , fee);

        // return solveUsingSO(prices , 0 , true , fee);

        return solveUsingSOEXTREME(prices , 0 , true , fee);
    }
};