#include<iostream>
using namespace std;
int main(){

return 0;
}
class Solution {
public:

    int solveUsingRecursion(vector<int>&prices , int i , int buy , int limit){
        if(i >= prices.size()){
            return 0;
        }

        if(limit == 0){
            return 0;
        }

        int profit = 0;

        if(buy){
            int buyProfit = -prices[i] + solveUsingRecursion(prices , i+1 , 0 , limit);//this is sell and P = S-B
            int ignoreProfit = 0 + solveUsingRecursion(prices , i+1 , 1 , limit);
            profit = max(buyProfit , ignoreProfit);
        }
        // sell case
        else{
            int sellProfit = prices[i] + solveUsingRecursion(prices , i+1 , 1 , limit-1);
            int ignoreProfit = 0 + solveUsingRecursion(prices , i+1 , 0 , limit); // as we are not buying so buy = 0
            profit = max(sellProfit , ignoreProfit);
        }
        return profit;
    }


    int solveUsingMemo(vector<int>&prices , int i , int buy , int limit , vector<vector<vector<int>>>&dp){
        if(i >= prices.size()){
            return 0;
        }

        if(limit == 0){
            return 0;
        }

        int profit = 0;

        if(dp[i][buy][limit] != -1){
            return dp[i][buy][limit];
        }

        if(buy){
            int buyProfit = -prices[i] + solveUsingMemo(prices , i+1 , 0 , limit , dp);
            int ignoreProfit = 0 + solveUsingMemo(prices , i+1 , 1 , limit , dp);
            profit = max(buyProfit , ignoreProfit);
        }
        // sell case
        else{
            int sellProfit = prices[i] + solveUsingMemo(prices , i+1 , 1 , limit-1 , dp);
            int ignoreProfit = 0 + solveUsingMemo(prices , i+1 , 0 , limit , dp);
            profit = max(sellProfit , ignoreProfit);
        }
        dp[i][buy][limit] = profit;
        return dp[i][buy][limit];
    }

    int solveUsingTab(vector<int>&prices , int i , int buy , int k){
        vector<vector<vector<int>>>dp(prices.size()+1 , vector<vector<int>>(2 , vector<int>(k+1 , 0)));

        for(int i = prices.size()-1 ; i>=0 ; i--){
            for(int buy = 0 ; buy < 2 ; buy++){
                for(int limit = 1; limit < k+1 ; limit++){ 

                    int profit = 0;

                    if(buy){
                        int buyProfit = -prices[i] + dp[i+1][0][limit];
                        int ignoreProfit = dp[i+1][1][limit];
                        profit = max(buyProfit , ignoreProfit);
                    }
                    // sell case
                    else{
                        int sellProfit = prices[i] + dp[i+1][1][limit-1];
                        int ignoreProfit = dp[i+1][0][limit];
                        profit = max(sellProfit , ignoreProfit);
                    }
                    dp[i][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][k];
    }


    int solveUsingSOBASIC(vector<int>&prices , int i , int buy , int k){
        vector<vector<int>>curr(2 , vector<int>(k+1 , 0));
        vector<vector<int>>next(2 , vector<int>(k+1 , 0));

        for(int i = prices.size()-1 ; i>=0 ; i--){
            for(int buy = 0 ; buy < 2 ; buy++){
                for(int limit = 1; limit < k+1 ; limit++){ 

                    int profit = 0;

                    if(buy){
                        int buyProfit = -prices[i] + next[0][limit];
                        int ignoreProfit = next[1][limit];
                        profit = max(buyProfit , ignoreProfit);
                    }
                    // sell case
                    else{
                        int sellProfit = prices[i] + next[1][limit-1];
                        int ignoreProfit = next[0][limit];
                        profit = max(sellProfit , ignoreProfit);
                    }
                    curr[buy][limit] = profit;
                }
            }
            // shift
            next = curr;
        }
        return curr[1][k];
    }


    int solveUsingSO(vector<int>&prices , int i , int buy , int k){

        vector<vector<vector<int>>>dp(2 , vector<vector<int>>(2 , vector<int>(k+1 , 0)));

        for(int i = prices.size()-1 ; i>=0 ; i--){
            for(int buy = 0 ; buy < 2 ; buy++){
                for(int limit = 1; limit < k+1 ; limit++){ 

                    int profit = 0;

                    if(buy){
                        int buyProfit = -prices[i] + dp[1][0][limit];
                        int ignoreProfit = dp[1][1][limit];
                        profit = max(buyProfit , ignoreProfit);
                    }
                    // sell case
                    else{
                        int sellProfit = prices[i] + dp[1][1][limit-1];
                        int ignoreProfit = dp[1][0][limit];
                        profit = max(sellProfit , ignoreProfit);
                    }
                    dp[0][buy][limit] = profit;
                }
            }
            // next = curr
            dp[1] = dp[0];
        }
        return dp[0][1][k];
    }



    int maxProfit(int k, vector<int>& prices) {
        // return solveUsingRecursion(prices , 0 , true , k);

        // vector<vector<vector<int>>>dp(prices.size()+1 , vector<vector<int>>(2 , vector<int>(k+1 , -1)));
        // return solveUsingMemo(prices , 0 , true , k , dp);

        // return solveUsingTab(prices , 0 , true , k);

        return solveUsingSOBASIC(prices , 0 , true , k);

        // return solveUsingSO(prices , 0 , true , k);
    }
};
