#include<iostream>
#include<queue>
#include<vector>
#include<limits.h>
using namespace std;

int maxElementOfSubarray(vector<int>&nums , int k){
    deque<int>dq;
    int ans = INT_MIN;

    // process first k windows
    for(int i=0 ; i<k ; i++){
        // pop the smallest emenet index if it is in front
        while(!dq.empty() && nums[dq.back()] <= nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    // find 1st elemts's ans
    ans = max(ans , nums[dq.front()]);

    // for remainig windows
    for(int i=k ; i<nums.size() ; i++){
        if(!dq.empty() && i-k >= dq.front()){
            dq.pop_front();
        }
        while(!dq.empty() && nums[dq.back()] <= nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);

        // finding max ans;
        ans = max(ans , nums[dq.front()]);
    }
    return ans;
}

int main(){
    vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    int ans = maxElementOfSubarray(nums, k);

    cout<<ans;
    return 0;
return 0;
}