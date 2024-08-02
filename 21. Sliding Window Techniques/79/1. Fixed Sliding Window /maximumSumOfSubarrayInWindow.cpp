#include<iostream>
#include<queue>
#include<vector>
#include<limits.h>
using namespace std;

int maximumSumOfSubarrayInWindow(vector<int>&nums , int k){
    int sumOfSubarray=0;
    int maxSum = INT_MIN;

    // process first k windows
    for(int i= 0 ; i<k ; i++){
        sumOfSubarray += nums[i];
    }

    // finding the max of first window
    maxSum = max(maxSum , sumOfSubarray);

    // for remaining window
    // we are not adding all the elements we are just removing the excluded element and then adding the 
    // new element
    for(int i=k ; i<nums.size() ; i++){
        // last elemnt ko sum se remove krdo
        sumOfSubarray -= nums[i-k];
        // add the current element 
        sumOfSubarray += nums[i];

        maxSum = max(sumOfSubarray , maxSum);
    }
    return maxSum;
}

int main(){
    vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    int ans = maximumSumOfSubarrayInWindow(nums, k);

    cout<<ans;
    return 0;
return 0;
}



