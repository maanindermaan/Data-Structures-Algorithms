#include<iostream>
using namespace std;
int main(){

return 0;
}

class Solution {
public:

    int solveUsingRecursion(vector<int>& nums1, vector<int>& nums2 , int i , int p1 , int p2){
        // base case 
        if(i == nums1.size()){
            return 0;
        }

        int swap = INT_MAX , noswap = INT_MAX;
        // swapping condition 
        if(p1 < nums2[i] && p2 < nums1[i]){
            swap = 1 + solveUsingRecursion(nums1 , nums2 , i+1 , nums2[i] , nums1[i]);
        }

        // no swapping condition
        if(p1 < nums1[i] && p2 < nums2[i]){
            noswap = solveUsingRecursion(nums1 , nums2 , i+1 , nums1[i] , nums2[i]);
        }
        return min(swap , noswap);
    }


    int solveUsingMemo(vector<int>& nums1, vector<int>& nums2 , int i , int p1 , int p2 , vector<vector<int>>&dp , int isswap){
        // base case 
        if(i == nums1.size()){
            return 0;
        }

        if(dp[i][isswap] != -1){
            return dp[i][isswap];
        }

        int swap = INT_MAX , noswap = INT_MAX;
        // swapping condition 
        // isswap 1 -> swapping , 0-> not swapping
        if(p1 < nums2[i] && p2 < nums1[i]){
            swap = 1 + solveUsingMemo(nums1 , nums2 , i+1 , nums2[i] , nums1[i] , dp , 1);
        }

        // no swapping condition
        if(p1 < nums1[i] && p2 < nums2[i]){
            noswap = solveUsingMemo(nums1 , nums2 , i+1 , nums1[i] , nums2[i] , dp , 0);
        }
        dp[i][isswap] = min(swap , noswap);
        return dp[i][isswap];
    }

    int solveUsingTab(vector<int>& nums1, vector<int>& nums2){
        // base case 
        vector<vector<int>>dp(nums1.size()+1 , vector<int>(2,0));
        for(int i = nums1.size()-1 ; i>=1 ; i--){
            for(int j = 1 ; j >=0 ; j--){
                    int p1 = nums1[i-1];
                    int p2 = nums2[i-1];
                    // recursive call ke baad p1 and p2 reverse i.e. swap hochuke honge MEMO wale function mein
                    // so we update it here as well when j = 1 i.e. in case of swap

                    if(j){
                        swap(p1 , p2);
                    }

                    int swap = INT_MAX , noswap = INT_MAX;
                    // swapping condition 
                    // isswap 1 -> swapping , 0-> not swapping
                    if(p1 < nums2[i] && p2 < nums1[i]){
                        swap = 1 + dp[i+1][1];
                    }

                    // no swapping condition
                    if(p1 < nums1[i] && p2 < nums2[i]){
                        noswap = dp[i+1][0];
                    }
                    dp[i][j] = min(swap , noswap);
                }
            }
            return dp[1][0];
        }


    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // return solveUsingRecursion(nums1 , nums2 , 0 , -1 , -1);

        // we will take only 2 conditions swap or no swap only
        // we will not take whole array
        // vector<vector<int>>dp(nums1.size()+1 , vector<int>(2,-1));
        // return solveUsingMemo(nums1 , nums2 , 0 , -1 , -1 , dp , 0);

        nums1.insert(nums1.begin() , -1);
        nums2.insert(nums2.begin() , -1);
        return solveUsingTab(nums1 , nums2);
    }
};