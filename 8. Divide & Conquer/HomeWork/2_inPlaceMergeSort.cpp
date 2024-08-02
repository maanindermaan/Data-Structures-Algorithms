#include<iostream>
#include<vector>
using namespace std;
int main(){

return 0;
}

class Solution {
public:
    void mergeTwoSortedArrays(vector<int>&arr , int s , int mid , int e){
        int total_len = e-s+1;
        int gap = (total_len / 2) + (total_len % 2);

        while(gap>0){
            int i = s , j = s + gap;
            while(j<=e){
                if(arr[i] > arr[j]){
                    swap(arr[i] , arr[j]);
                }
                ++i;
                ++j;
            }
            gap = gap <= 1 ? 0 : (gap/2) + (gap%2);
        }
    }

    void mergeSort(vector<int>&arr , int s , int e){
        if (s >= e) {
            return; // Base case: single element or invalid array
        }

        int mid = s + (e - s) / 2;

        mergeSort(arr, s, mid); // Sort the left half
        mergeSort(arr, mid + 1, e); // Sort the right half

        mergeTwoSortedArrays(arr, s, mid, e); // Merge the sorted halves
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums , 0 , nums.size()-1);
        return nums;
    }
};