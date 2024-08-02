#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 1. TLE
class Solution {
public:
    void recursiveHelper(vector<int>& nums, int& maxi, int sum, int index) {
        // base case 
        if (index == nums.size()) {
            return;
        }

        sum += nums[index];

        maxi = max(sum, maxi);
            
        recursiveHelper(nums, maxi, sum, index + 1);

        sum -= nums[index];
    }

    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;  // reset sum for each new starting index
            recursiveHelper(nums, maxi, sum, i);
        }
        return maxi;
    }
};

// 2.

class Solution {
public:
    int maxSubArrayHelper(vector<int>&arr , int start , int end){
        // base case
        if(start == end){
            return arr[start];
        }
        int maxLeftBorderSum = INT_MIN, maxRightBorderSum = INT_MIN;
        int mid = start + (end - start) / 2;

        int maxLeftSum = maxSubArrayHelper(arr , start , mid);
        int maxRightSum = maxSubArrayHelper(arr , mid+1 , end);

        // Max Cross Border Sum
        int leftBorderSum = 0, rightBorderSum = 0;
        // for left cross border max sum
        for(int i=mid ; i>=start ; i--){
            leftBorderSum += arr[i];
            if(leftBorderSum > maxLeftBorderSum){
                maxLeftBorderSum = leftBorderSum;
            }
        }

        // for right cross border max sum
        for(int i=mid+1 ; i<=end ; i++){
            rightBorderSum += arr[i];
            if(rightBorderSum > maxRightBorderSum){
                maxRightBorderSum = rightBorderSum;
            }
        }
        
        int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;

        return max(maxLeftSum , max(maxRightSum , crossBorderSum));
    }

    int maxSubArray(vector<int>& nums) {
        return maxSubArrayHelper(nums , 0 , nums.size()-1);
    }
};