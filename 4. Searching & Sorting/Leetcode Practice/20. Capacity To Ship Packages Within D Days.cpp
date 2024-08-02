#include<iostream>
#include<vector>

using namespace std;
int main(){

return 0;
}
class Solution {
public:
    bool isPossible(vector<int>&arr , int days , int capacity){
        int sum = 0;
        int days_covered = 1;
        for(int i=0; i<arr.size() ; i++){
            if(arr[i] + sum > capacity){
                days_covered++;
                sum = arr[i];
                if(days_covered > days){
                    return false;
                }
            }
            else{
                sum += arr[i];
            }
        }
        return true;
    }


    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin() , weights.end());
        int end = 0;
        for(int i=0 ; i<weights.size() ; i++){
            end += weights[i];
        }
        int ans = end;

        while(start <= end){
            int mid = start + (end-start)/2;
            if(isPossible(weights , days , mid)){
                // store and go for minimum
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