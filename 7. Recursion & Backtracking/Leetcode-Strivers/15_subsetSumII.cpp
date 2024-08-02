#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main(){

return 0;
}

// 1. -> Using Sets (to keep original elements)
class Solution {
public:

    void recursiveHelper(vector<int>&nums , vector<int>part , set<vector<int>>&ans , int i){
        if(i>=nums.size()){
            ans.insert(part);
            return;
        }

        // exclude 
        recursiveHelper(nums , part , ans , i+1);

        part.push_back(nums[i]); // OR YOU CAN SIMPLY DO output = output + str[i]
        recursiveHelper(nums , part , ans , i+1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans_set;
        vector<int>part;
        sort(nums.begin(), nums.end());

        recursiveHelper(nums , part , ans_set , 0);

        vector<vector<int>> ans(ans_set.begin(), ans_set.end());
        return ans;
    }
};

// 2. -> Striver's approach
class Solution {
public:

    void recursiveHelper(vector<int>&nums , vector<int>&part , vector<vector<int>>&ans , int index){
        ans.push_back(part);

        for(int i=index ; i<nums.size() ; i++){
            if(i != index && nums[i] == nums[i-1]){
                continue;
            }
            part.push_back(nums[i]);
            recursiveHelper(nums , part , ans , i+1);
            part.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>part;
        sort(nums.begin(), nums.end());

        recursiveHelper(nums , part , ans , 0);

        
        return ans;
    }
};