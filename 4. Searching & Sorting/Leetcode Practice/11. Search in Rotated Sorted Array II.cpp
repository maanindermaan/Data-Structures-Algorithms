#include<iostream>
#include<vector>
using namespace std;
int main(){

return 0;
}

class Solution {
public:

    bool binarySearch(vector<int>&arr , int key){
        int start = 0;
        int end = arr.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;

            if(arr[mid]==key){
                return true;
            }

            if(arr[start] == arr[mid] && arr[mid] == arr[end]){
                start++;
                end--;
                continue;
            }
            else if(arr[mid]<=arr[end]){
                // Right Subarray
                if(key>arr[mid] && key<=arr[end]){
                    start = mid+1;
                } 
                else{
                    end = mid-1;
                }
            }
            else{
                // Left Subaaray
                if(key>=arr[start] && key<arr[mid]){
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
            }
        }
        return false;
    }

    bool search(vector<int>& nums, int target) {
        // base case
        if(nums.size()==1){
            if(nums[0] == target){
                return true;
            }
            else{
                return false;
            }
        }

        if(binarySearch(nums , target)){
            return true;
        }
        else{
            return false;
        }
    }
};