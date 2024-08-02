// // brute force
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(nums.begin() , nums.end());
//         int target = 0;
//         vector<vector<int>> finalAns;
//         set<vector<int>> s;
//         for(int i=0 ; i<nums.size() ; i++){
//             int j = i+1;
//             int k = nums.size()-1;

//             while(j<k){
//                 if(nums[i] + nums[j] + nums[k] == target){
//                     s.insert({nums[i] , nums[j] , nums[k]});
//                     j++;
//                     k--;
//                 }


//                 else if(nums[i] + nums[j] + nums[k] > target){
//                     k--;
//                 }

//                 else{
//                     j++;
//                 }
//             }
//         }
//         for(auto i : s){
//             finalAns.push_back(i);
//         }
//         return finalAns;
//     }
// };