#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int main(){

return 0;
}

class Solution {
public:
    int binarySearch(vector<int>&arr){
        int ans = INT_MAX;
        int start = 0;
        int end = arr.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;

            if(arr[start] <= arr[end]){
               if(arr[start] < ans){
                   ans = arr[start];
               }
                break;
            }

            if(arr[mid]>=arr[start]){
                // left Subarray
                // store min and eliminate
                if(arr[start] < ans){
                    ans = arr[start];
                }
                start = mid+1;
            }
            else{
                // Right Subaaray
                // store and elmininate min
                if(arr[end] < ans){
                    ans = arr[mid];
                }
                end = mid-1;
            }
        }
        return ans;
    }
    int findMin(vector<int>& nums){
        return binarySearch(nums);
    }
};