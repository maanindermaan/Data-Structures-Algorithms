#include<iostream>
#include<vector>
using namespace std;
int main(){

return 0;
}

// 1.
class Solution {
public:
    void recursiveHelper(vector<int>&candidates , int target , vector<vector<int>>&ans, vector<int>numbers , int start){
        // base case
        if(target == 0){
            ans.push_back(numbers);
            return;
        }

        if(target < 0){
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            vector<int>newNumbers(numbers);
            newNumbers.push_back(candidates[i]);
            recursiveHelper(candidates, target - candidates[i], ans, newNumbers, i);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>numbers;

        recursiveHelper(candidates , target , ans , numbers , 0);

        return ans;
    }
};



// 2. Better Solution with backtracking
class Solution {
public:
    void recursiveHelper(vector<int>&candidates , int target , vector<vector<int>>&ans, vector<int>&numbers , int start){
        // base case
        if(target == 0){
            ans.push_back(numbers);
            return;
        }

        if(target < 0){
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            numbers.push_back(candidates[i]);
            recursiveHelper(candidates, target - candidates[i], ans, numbers, i);
            numbers.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>numbers;

        recursiveHelper(candidates , target , ans , numbers , 0);

        return ans;
    }
};


// 3. Striver's Approach
class Solution {
public:
    void recursiveHelper(vector<int>&candidates , int target , vector<vector<int>>&ans, vector<int>&numbers , int index){
        // base case
        if(target == 0 && index == candidates.size()){
            ans.push_back(numbers);
            return;
        }

        if (index >= candidates.size() || target < 0) {
            return;
        }

        // one case solve
        if(candidates[index] <= target){
            numbers.push_back(candidates[index]);
            recursiveHelper(candidates , target-candidates[index] , ans , numbers , index);
            // vaapis uper jaate hue pop kardo 
            numbers.pop_back();
        }

        recursiveHelper(candidates , target , ans , numbers , index+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>numbers;

        recursiveHelper(candidates , target , ans , numbers , 0);

        return ans;
    }
};