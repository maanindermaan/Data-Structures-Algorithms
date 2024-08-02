#include<iostream>
#include<vector>
#include<unordered_set>
#include<set>
using namespace std;
int main(){

return 0;
}
// 1. GPT METHOD
class Solution {
public:
    void recursiveHelper(vector<vector<int>>&ans , vector<int>&nums , int index){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }

        unordered_set<int>seen;
        for(int i=index ; i<nums.size() ; i++){
            if(seen.find(nums[i]) != seen.end()){
                continue;
            }
            seen.insert(nums[i]);

            swap(nums[index] , nums[i]);

            recursiveHelper(ans , nums , index+1);

            swap(nums[index] , nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        recursiveHelper(ans , nums , 0);
        return ans;
    }
};

// 2. Set based at end
class Solution {
public:
    void recursiveHelper(vector<vector<int>>&ans , vector<int>&nums , int index){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=index ; i<nums.size() ; i++){

            swap(nums[index] , nums[i]);

            recursiveHelper(ans , nums , index+1);

            swap(nums[index] , nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        recursiveHelper(ans , nums , 0);
        set<vector<int>>st;
        for (auto e:ans) {
            st.insert(e);
        }
        ans.clear();
        for(auto e:st){
            ans.push_back(e);
        }
        return ans;
    }
};
