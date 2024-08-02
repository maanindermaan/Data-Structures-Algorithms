#include<iostream>
using namespace std;
int main(){
    
return 0;
}
class Solution {
public:

    int solveUsingRecursion(vector<int>& nums , int start , int end){
        // 1. base case
        if(start == end){
            return nums[start];
        }

        // difference = P1 - P2;
        // nums[start] -> score by P1
        // nums[end] -> score by P1
        // 2. One case solving
        int diffByStart = nums[start] - solveUsingRecursion(nums , start+1 , end);
        int diffByEnd = nums[end] - solveUsingRecursion(nums , start , end-1);

        return max(diffByStart , diffByEnd);
    }

    int solveUsingMemo(vector<int>& nums , int start , int end , vector<vector<int>>&dp){
        // 1. base case
        if(start == end){
            return nums[start];
        }

        if(dp[start][end] != -1){
            return dp[start][end];
        }

        // 2. One case solving
        int diffByStart = nums[start] - solveUsingMemo(nums , start+1 , end , dp);
        int diffByEnd = nums[end] - solveUsingMemo(nums , start , end-1 , dp);

        dp[start][end] = max(diffByStart , diffByEnd);
        return dp[start][end];
    }

    int solveUsingTab(vector<int>& nums){
        vector<vector<int>>dp(nums.size()+1 , vector<int>(nums.size()+1 , 0));
        
        // base case
        for(int i=0 ; i<nums.size() ; i++){
            dp[i][i] = nums[i];
        }

        int i = nums.size(); // humne nums.size() liya because nums.size()-1 pe answer nahi tha
        for(int start = nums.size()-1 ; start>=0 ; start--){
            for(int end = i ; end< nums.size() ; end++){
                int diffByStart = nums[start] - dp[start+1][end];
                int diffByEnd = nums[end] - dp[start][end-1];
                dp[start][end] = max(diffByStart , diffByEnd);
            }
            // iski help se end uper jarha hai
            --i;
        } 
        return dp[0][nums.size()-1];
    }

    bool predictTheWinner(vector<int>& nums) {
        // already used conditions here 
        // return solveUsingRecursion(nums , 0 , nums.size()-1) >= 0; 

        // vector<vector<int>>dp(nums.size()+1 , vector<int>(nums.size()+1 , -1));
        // return solveUsingMemo(nums , 0 , nums.size()-1 , dp) >= 0; 

        return solveUsingTab(nums) >= 0;
    }
};