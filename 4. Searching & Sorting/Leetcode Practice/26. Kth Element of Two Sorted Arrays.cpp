#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
int main(){

return 0;
}
#include<limits.h>
int kthElement(vector<int> &nums1, vector<int>& nums2, int n1, int n2, int k){

    int n = n1+n2;

    if(n1>n2){
        return kthElement(nums2 , nums1 , n2 , n1 , k);
    }

    int start = max(k-n2 , 0);
    int end = min(n1 , k);
    int left = k;

    while(start <= end){
        int mid1 = start + (end-start)/2;
        int mid2 = left - mid1;
        int l1 = INT_MIN , l2 = INT_MIN;
        int r1 = INT_MAX , r2 = INT_MAX;

        if(mid1 < n1){
            r1 = nums1[mid1];
        }
        if(mid2 < n2){
            r2 = nums2[mid2];
        }
        if(mid1 - 1 >= 0){
            l1 = nums1[mid1-1];
        }
        if(mid2 - 1 >= 0){
            l2 = nums2[mid2-1];
        }

        // Match 
        if(l1<=r2 && l2 <= r1){
            return max(l1 , l2);
        }

        // Right part go to left
        else if(l1 > r2){
            end = mid1-1;
        }
        // left part goto right
        else{
            start = mid1+1;
        }
    }
    return 0;
}