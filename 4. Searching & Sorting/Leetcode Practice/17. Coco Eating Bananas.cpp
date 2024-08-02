#include<iostream>
#include<vector>
using namespace std;
int main(){
return 0;
}

class Solution {
public:

    // bool isPossible(vector<int>&arr , int mid , int h){
    //     int hours_till_now = 0;

    //     for(int i=0 ; i<arr.size() ; i++){
    //         // 1.jab k bada hai arr[i] se k->mid here
    //         if(mid >= arr[i]){
    //             hours_till_now++;
    //         }
    //         else{
    //             int value = arr[i];
    //             while(value > 0){
    //                 value = value - mid;
    //                 hours_till_now++;
    //             }
    //         }
    //     }
    //     if(hours_till_now <= h){
    //         return true;
    //     }
    //     else{
    //         return false;
    //     }
    // }

    bool isPossible(vector<int>&arr , int mid , int h){
        long long int hours_till_now = 0;

        for(int i=0 ; i<arr.size() ; i++){
            hours_till_now += ceil(static_cast<double>(arr[i]) / static_cast<double>(mid));
        }
        if(hours_till_now <= h){
            return true;
        }
        else{
            return false;
        }
    }

    int minEatingSpeed(vector<int>& arr, int h) {
        int start = 1;
        int end = *max_element(arr.begin(), arr.end());
        int ans = -1;

        while(start <= end){
            // base case
            int mid = start + (end-start)/2;
            if(isPossible(arr , mid , h)){
                // store and move left
                ans = mid;
                end = mid-1;
            }
            else{
                // move right
                start = mid+1;
            }
        }
        return ans;
    }
};