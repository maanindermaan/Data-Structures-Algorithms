#include<iostream>
using namespace std;
int main(){

return 0;
}

class Solution {
public:

    int solveUsingRecursion(vector<int>&prices , int i , int buy){
        if(i >= prices.size()){
            return 0;
        }

        int profit = 0;
        // buy case -> agar buy krrha hu to dobara buy ni kar sakta, agar buy nhi kia toh i can buy
        if(buy){
            int buyProfit = -prices[i] + solveUsingRecursion(prices , i+1 , 0);//this is sell and P = S-B
            int ignoreProfit = 0 + solveUsingRecursion(prices , i+1 , 1);
            profit = max(buyProfit , ignoreProfit);
        }
        // sell case -> agar sell karrha hu toh i can buy futher , agar sell ni kia toh can't buy
        else{
            int sellProfit = prices[i] + solveUsingRecursion(prices , i+1 , 1);
            int ignoreProfit = 0 + solveUsingRecursion(prices , i+1 , 0); // as we are not selling and without sell we can't buy further so buy = 0
            profit = max(sellProfit , ignoreProfit);
        }
        return profit;
    }

    int solveUsingMemo(vector<int>&prices , int i , int buy , vector<vector<int>>&dp){
        if(i >= prices.size()){
            return 0;
        }

        if(dp[i][buy] != -1){
            return dp[i][buy];
        }

        int profit = 0;

        if(buy){
            int buyProfit = -prices[i] + solveUsingMemo(prices , i+1 , 0 , dp);//this is sell and P = S-B
            int ignoreProfit = 0 + solveUsingMemo(prices , i+1 , 1 , dp);
            profit = max(buyProfit , ignoreProfit);
        }
        // sell case
        else{
            int sellProfit = prices[i] + solveUsingMemo(prices , i+1 , 1 , dp);
            int ignoreProfit = 0 + solveUsingMemo(prices , i+1 , 0 , dp); // as we are not buying so buy = 0
            profit = max(sellProfit , ignoreProfit);
        }
        dp[i][buy] = profit;
        return dp[i][buy];
    }


    int solveUsingTab(vector<int>&prices , int i , int buy){
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
                    int sellProfit = prices[row] + dp[row+1][1];
                    int ignoreProfit = 0 + dp[row+1][0];
                    profit = max(sellProfit , ignoreProfit);
                }
                dp[row][col] = profit;
            }
        }
        return dp[i][buy];
    }


    int solveUsingSO(vector<int>&prices , int i , int buy){
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
                    int sellProfit = prices[row] + next[1];
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

    int solveUsingSOEXTREME(vector<int>&prices , int i , int buy){
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
                    int sellProfit = prices[row] + next[1];
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

    int maxProfit(vector<int>& prices) {
        // return solveUsingRecursion(prices , 0 , true);

        // vector<vector<int>>dp(prices.size()+1 , vector<int>(2 , -1));
        // return solveUsingMemo(prices , 0 , true , dp);

        // return solveUsingTab(prices , 0 , true);

        // return solveUsingSO(prices , 0 , true);

        return solveUsingSOEXTREME(prices , 0 , true);
    }
};