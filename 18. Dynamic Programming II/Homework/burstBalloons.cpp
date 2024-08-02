#include<iostream>
using namespace std;
int main(){
    
return 0;
}
class Solution {
public:

    int solve(vector<int>&nums , int start , int end){
        // base case
        if(start > end){
            return 0;
        }

        int coins = INT_MIN;

        for(int i = start ; i<=end ; i++){
            coins = max(coins   ,   
            ((nums[start-1] * nums[i] * nums[end+1]) + 
            solve(nums , start , i-1) + 
            solve(nums , i+1 , end)));
        }
        return coins;
    }

    int solveMemo(vector<int>&nums , int start , int end , vector<vector<int>>&dp){
        // base case
        if(start > end){
            return 0;
        }

        if(dp[start][end] != -1){
            return dp[start][end];
        }

        int coins = INT_MIN;

        for(int i = start ; i<=end ; i++){
            coins = max(coins   ,   
            ((nums[start-1] * nums[i] * nums[end+1]) + 
            solveMemo(nums , start , i-1 , dp) + 
            solveMemo(nums , i+1 , end , dp)));
        }
        dp[start][end] = coins;
        return dp[start][end];
    }

    int solveTab(vector<int>&nums){
        vector<vector<int>>dp(nums.size()+1 , vector<int>(nums.size()+1 , 0));

        for(int start = nums.size()-2 ; start>=1 ; start--){
            for(int end = start ; end <= nums.size()-2 ; end++){ // end == start due to base condition
                int coins = INT_MIN;

                for(int i = start ; i<=end ; i++){
                    coins = max(coins   ,   
                    ((nums[start-1] * nums[i] * nums[end+1]) + 
                    dp[start][i-1] + 
                    dp[i+1][end]));
                }
                dp[start][end] = coins;
            }
        }
        return dp[1][nums.size()-2];
    }



    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin() , 1);
        nums.insert(nums.end() , 1);

        // return solve(nums , 1 , nums.size()-2);

        // vector<vector<int>>dp(nums.size()+1 , vector<int>(nums.size()+1 , -1));
        // return solveMemo(nums , 1 , nums.size()-2 , dp);

        return solveTab(nums);
    }
};