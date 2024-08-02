#include<iostream>
#include<vector>
using namespace std;
int main(){

return 0;
}

// 1.
// void recursiveSol(vector<vector<int>>& ans , vector<int>& arr , long long sum , int i , vector<int> pushing){
//     // base case
//     if(sum == 0){
//         ans.push_back(pushing);
//         return;
//     }

//     if( i>=arr.size() || sum<0){
//         return;
//     }

//     // one case solve
//     pushing.push_back(arr[i]);
//     long long subtract = static_cast<long long>(arr[i]);
//     recursiveSol(ans, arr, sum-subtract, i+1, pushing);
// }

// vector<vector<int>> subarraysWithSumK(vector<int> a, long long k) {
//     vector<vector<int>>ans;
//     vector<int>pushing;
//     for(int i=0 ; i<a.size() ; i++){
//         recursiveSol(ans , a , k , i , pushing);
//     }
//     return ans;
// }

// 2. (with backtrack)
// void recursiveSol(vector<vector<int>>& ans , vector<int>& arr , long long sum , int i , vector<int>& pushing){
//     // base case
//     if(sum == 0){
//         ans.push_back(pushing);
//         return;
//     }

//     if( i>=arr.size() || sum<0){
//         return;
//     }

//     // one case solve
//     pushing.push_back(arr[i]);
//     // long long subtract = static_cast<long long>(arr[i]);
//     recursiveSol(ans, arr, sum-arr[i], i+1, pushing);
//     pushing.pop_back();
// }

// vector<vector<int>> subarraysWithSumK(vector<int> a, long long k) {
//     vector<vector<int>>ans;
//     vector<int>pushing;
//     for(int i=0 ; i<a.size() ; i++){
//         recursiveSol(ans , a , k , i , pushing);
//     }
//     return ans;
// }


// 3. Correct approach
class Solution {
public:
    int recursiveSol(vector<int>& arr, int sum, int start, int n) {
        // Base case
        if (start == n) {
            return 0;
        }
        
        int current_sum = 0;
        int count = 0;

        // Iterate through the array considering subarrays starting from 'start'
        for (int i = start; i < n; ++i) {
            current_sum += arr[i];

            // If the current sum is equal to the target sum, increment count
            if (current_sum == sum) {
                count++;
            }
        }

        // Recursively call for the next starting index
        return count + recursiveSol(arr, sum, start + 1, n);
    }

    int subarraySum(vector<int>& nums, int k) {
        return recursiveSol(nums, k, 0, nums.size());
    }
};
