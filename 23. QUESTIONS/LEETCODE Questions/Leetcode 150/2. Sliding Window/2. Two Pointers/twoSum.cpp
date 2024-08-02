// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         int i = 0;
//         int j = numbers.size()-1;
//         vector<int> ans;

//         while(i<j){
//             // 1. if target == sum
//             if(numbers[i] + numbers[j] == target){
//                 ans.push_back(i+1);
//                 ans.push_back(j+1);
//                 break;
//             }
//             // 2. if sum > target
//             else if(numbers[i] + numbers[j] > target){
//                 j--;
//             }
//             // 3. if sum < target
//             else{
//                 i++;
//             }
//         }
//         return ans;
//     }
// };