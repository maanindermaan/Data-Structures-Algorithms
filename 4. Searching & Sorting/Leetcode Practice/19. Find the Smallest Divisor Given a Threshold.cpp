#include<iostream>
#include<vector>
using namespace std;
int main(){

return 0;
}

class Solution {
public:

    bool isPossible(vector<int>&arr , int threshold , int divisor){
        int sum = 0;
        for(int i=0 ; i<arr.size() ; i++){
            sum += ceil(arr[i] / static_cast<double>(divisor));
        }
        return sum <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;
        int end = *max_element(nums.begin() , nums.end());
        int ans = end;

        while(start <= end){
            int mid = start + (end-start)/2;
            if(isPossible(nums , threshold , mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};