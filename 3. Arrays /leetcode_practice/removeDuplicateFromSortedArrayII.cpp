#include<iostream>
using namespace std;

// 1.
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1;
        for(int i=1 ; i<nums.size() ; i++){
            if(nums[i] != nums[i-1]){

                if(nums[j] == nums[j-1]){
                    j++;
                }

                nums[j] = nums[i];
                j++;
            }
        }
        return j+1;
    }
};

// 2.
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n; // No need to process if the array has 0, 1, or 2 elements
        }

        int j = 2; // Initialize a pointer to keep track of the position to overwrite duplicates
        
        for (int i = 2; i < n; i++) {
            if (nums[i] != nums[j - 2]) {
                nums[j] = nums[i]; // Only update when the current element is different from two positions behind
                j++;
            }
        }
        
        return j;
    }
};


int main(){

return 0;
}