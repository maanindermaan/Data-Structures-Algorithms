#include<iostream>
#include<vector>
using namespace std;
int main(){

return 0;
}


// 1. Works for most of the cases but not all some errors -> this is include exlude pattern
class Solution {
public:

    bool isPossible(vector<int>&numbers , vector<vector<int>>ans){
        // sort first
        sort(numbers.begin() , numbers.end());

        for(auto it : ans){
            sort(it.begin() , it.end());
            if(it == numbers){
                return false;
            }
        }
        return true;
    }

    void recursiveHelper(vector<int>&candidates , int target , vector<vector<int>>&ans, vector<int>&numbers , int index){
        // base case
        if(target == 0 && index == candidates.size() && isPossible(numbers , ans)){
            ans.push_back(numbers);
            return;
        }

        if (index >= candidates.size() || target < 0) {
            return;
        }

        // one case solve
        if(candidates[index] <= target){
            numbers.push_back(candidates[index]);
            recursiveHelper(candidates , target-candidates[index] , ans , numbers , index+1);
            // vaapis uper jaate hue pop kardo 
            numbers.pop_back();
        }

        recursiveHelper(candidates , target , ans , numbers , index+1);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>numbers;

        recursiveHelper(candidates , target , ans , numbers , 0);

        return ans;
    }
};

// 2. Best Approach -> This works for for loop pattern
class Solution {
public:
    void recursiveHelper(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& numbers, int index) {
        // Base case: if target is zero, we found a valid combination
        if (target == 0) {
            ans.push_back(numbers);
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            // Skip duplicates
            // we choose the first occurance only rest we ignore it
            if (i > index && candidates[i] == candidates[i - 1]) continue;

            // Include the current candidate
            if (candidates[i] <= target) {
                numbers.push_back(candidates[i]);
                recursiveHelper(candidates, target - candidates[i], ans, numbers, i + 1);
                numbers.pop_back(); // Backtrack
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> numbers;

        // Sort candidates to handle duplicates
        sort(candidates.begin(), candidates.end());

        recursiveHelper(candidates, target, ans, numbers, 0);

        return ans;
    }
};