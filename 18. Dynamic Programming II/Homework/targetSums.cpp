#include<iostream>
#include<map>
using namespace std;
int main(){

return 0;
}
class Solution {
public:

    int solveUsingRecursion(vector<int>& nums, int target , int i){
        // base case
        if(i == nums.size()){
            if(target == 0){
                return 1;
            }
            return 0;
        }

        // ek case solve krdo
        int plus = solveUsingRecursion(nums , target - nums[i] , i+1);
        int minus = solveUsingRecursion(nums , target + nums[i] , i+1);

        return plus + minus;
    }

    int solveUsingMemo(vector<int>& nums, int target , int i , map<pair<int , int> , int>&dp){
        // base case
        if(i == nums.size()){
            if(target == 0){
                return 1;
            }
            return 0;
        }

        if(dp.find({i , target}) != dp.end()){
            return dp[{i , target}];
        }

        // ek case solve krdo
        int plus = solveUsingMemo(nums , target - nums[i] , i+1 , dp);
        int minus = solveUsingMemo(nums , target + nums[i] , i+1 , dp);

        dp[{i , target}] = plus + minus;
        return dp[{i , target}];
    }

    int solveUsingTab(vector<int>&nums , int t){
        map<pair<int , int> , int>dp; // {i , target}
        dp[{nums.size() , 0}] = 1;        

        int sum = 0;
        for(auto i : nums){
            sum += i;
        }
        for(int i = nums.size()-1 ; i>=0 ; i--){
            for(int target = -sum ; target <= sum ; target++){
                // int plus = dp[{i+1 , target - nums[i]}];
                // int minus = dp[{i+1 , target + nums[i]}];

                int plus = dp.find({i+1 , target - nums[i]}) != dp.end() ? dp[{i+1 , target - nums[i]}] :0;
                int minus = dp.find({i+1 , target + nums[i]}) != dp.end() ? dp[{i+1 , target + nums[i]}] :0;

                dp[{i , target}] = plus + minus;
            }
        }
        return dp[{0 , t}];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // return solveUsingRecursion(nums , target , 0);   

        // map<pair<int , int> , int>dp; // {i , target} -> no. of ways
        // return solveUsingMemo(nums , target , 0 , dp);  

        return solveUsingTab(nums , target);  
    }
};