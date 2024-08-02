#include<iostream>
#include<vector>
using namespace std;
int main(){
    
return 0;
}
class Solution {
public:
    // brute force
    // int singleNonDuplicate(vector<int>& nums) {
    //     int ans = 0;
    //     for(int i=0 ; i<nums.size() ; i++){
    //         ans = ans ^ nums[i];
    //     }
    //     return ans;
    // }

    int singleNonDuplicate(vector<int>& arr) {

        // boundary cases
        if(arr.size() == 1){
            return arr[0];
        }
        if(arr[0] != arr[1]){
            return arr[0];
        }
        if(arr[arr.size()-1] != arr[arr.size()-2]){
            return arr[arr.size()-1];
        }

        int start = 1;
        int end = arr.size()-2;

        while(start <= end){
            int mid = start + (end-start)/2;

            if(arr[mid-1] != arr[mid] && arr[mid] != arr[mid+1] && mid-1>=0 && mid+1<arr.size()){
                return arr[mid];
            }

            // if(mid%2 == 0){
            //     // 1. left side answer
            //     if(arr[mid] == arr[mid-1]){
            //         end = mid-1;
            //     }
            //     // 2. right side answer
            //     else if(arr[mid] == arr[mid+1]){
            //         start = mid+1;
            //     }
            // }

            // else if(mid%2 == 1){
            //     // 1. right side answer
            //     if(arr[mid] == arr[mid-1]){
            //         start = mid+1;
            //     }
            //     // 2. left side answer
            //     else if(arr[mid] == arr[mid+1]){
            //         end = mid-1;
            //     }
            // }

            // OR
            // We are in left go to right
            if((mid%2 == 0 && arr[mid] == arr[mid+1]) || (mid%2==1 && arr[mid] == arr[mid-1])){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return -1;
    }
};