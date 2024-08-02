#include<vector>
#include<iostream>
using namespace std;
int main(){

return 0;
}
class Solution {
public:
    int houseRobber(vector<int>& nums , int i){
        // base case
        if(i >= nums.size()){
            return 0;
        }

        // include
        int include = nums[i] + houseRobber(nums , i+2);

        // exclude 
        int exclude = 0 + houseRobber(nums , i+1);

        return max(include , exclude);
    }

    int rob(vector<int>& nums) {
        return houseRobber(nums , 0);
    }
};