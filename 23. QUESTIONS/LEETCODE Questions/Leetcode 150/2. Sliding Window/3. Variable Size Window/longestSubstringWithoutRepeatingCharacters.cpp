// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int i = 0;
//         int j = 0;

//         int len = INT_MAX;
//         int sum = 0;

//         while(j < nums.size()){
//             // 1. update sum
//             sum += nums[j];

//             // 2. If sum found
//             while(sum >= target){
//                 len = min(len , j-i+1);
//                 sum = sum - nums[i];
//                 i++;
//             }
//             j++;
//         }
//         if(len == INT_MAX){
//             return 0;
//         }

//         return len;
//     }
// };