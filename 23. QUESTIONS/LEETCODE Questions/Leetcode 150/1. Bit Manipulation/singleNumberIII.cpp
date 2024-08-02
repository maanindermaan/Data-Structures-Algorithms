// class Solution {
// public:
//     vector<int> singleNumber(vector<int>& nums) {
//         // 1.
//         // vector<int> ans;
//         // unordered_map<int ,int>mapping;
//         // for(int i=0 ; i<nums.size() ; i++){
//         //     mapping[nums[i]]++;
//         // }

//         // for(auto num : nums){
//         //     if(mapping[num] == 1){
//         //         ans.push_back(num);
//         //     }
//         // }
//         // return ans;


//         // 2.
//         // sort(nums.begin(), nums.end());
//         // for(int i = 0; i < nums.size()-1; i++){      //255677
//         //     if(nums[i]==nums[i+1]){
//         //         nums.erase(nums.begin()+i,nums.begin()+i+2);
//         //         i--;
//         //     }
//         // }
//         // return nums;


//         // 3.
//         int xorResult = 0;
    
//         // Step 1: XOR all elements in the vector to find the XOR of the two unique numbers
//         for (int num : nums) {
//             xorResult ^= num;
//         }

//         // Find the rightmost set bit in xorResult
//         int rightmostSetBit = 1;
//         while ((xorResult & rightmostSetBit) == 0) {
//             rightmostSetBit <<= 1;
//         }

//         int unique1 = 0;
//         int unique2 = 0;

//         // Step 2: Partition the vector into two subvectors based on the rightmost set bit
//         for (int num : nums) {
//             if ((num & rightmostSetBit) == 0) {
//                 unique1 ^= num;
//             } else {
//                 unique2 ^= num;
//             }
//         }

//         // Return the two unique numbers as a vector
//         return vector<int>{unique1, unique2};

//     }
// };