// Error
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int recursiveSELL(vector<int>&nums , int& sell , int start , int i){
    // base case
    if(i >= nums.size()){
        return sell;
    }
    
    // one case solve
    if(i >= start && sell < nums[i]){
        sell = nums[i];
    }
    
    // recusive call
    return recursiveSELL(nums , sell , start , i+1);
}

int recursiveBUY(vector<int>&nums , int buy , int& start , int i){
    // base case
    if(i >= nums.size()){
        return buy;
    }
    
    
    // one case solve
    if(buy > nums[i]){
        buy = nums[i];
        start = i;
    }
    
    // recusive call
    return recursiveBUY(nums , buy , start , i+1);
}

int main() {
    vector<int>nums{7,1,5,4,6,4};
    int buy = INT_MAX;
    int sell = INT_MIN;
    int start = -1;
    
    buy = recursiveBUY(nums , buy ,start , 0);
    sell = recursiveSELL(nums , sell , start , 0);
    
    cout<<buy<<" "<<sell<<endl;
    
    return 0;
}






// Correct version
class Solution {
public:
    int maxRecursionUtil(vector<int>& nums , int start , int end , int ans){
        // base case
        if(end >= nums.size()){
            return ans;
        }

        // one case
        if(ans < (nums[end] - nums[start])){
            ans = nums[end] - nums[start];
        }

        return maxRecursionUtil(nums , start , end+1 , ans);
    }

    int maxRecursion(vector<int>& nums){
        // cannot buy and sell on same day
        int maxProfit = 0;
        for(int start=0 ; start<nums.size() ; start++){
            int end = start;
            maxProfit = max(maxProfit, maxRecursionUtil(nums , start , end , 0));
        }
        return maxProfit;
    }

    // subarray type problem and finding the max profit
    int maxProfit(vector<int>& prices) {
        return maxRecursion(prices);
    }
};