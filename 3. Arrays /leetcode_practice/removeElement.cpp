#include<iostream>
using namespace std;
int main(){

return 0;
}


// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         int i=0;
//         int j=nums.size()-1;
        
//         if(nums.size()-1 == 1){
//             return 0;
//         }

//         while(i<=j){
//             while(nums[i] == val){
//                 swap(nums[i] , nums[j]);
//                 j--;
//             }
//             i++;
//         }
//         return i;
//     }
// };

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        int n = nums.size(); // Store size in a variable for efficiency

        for (int i = 0; i < n; i++) {
            if (nums[i] != val) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};
