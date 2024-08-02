#include<iostream>
using namespace std;
int main(){

return 0;
}

class Solution {
public:
    void recursiveHelper(int elements , int target , vector<vector<int>>&ans , vector<int>&part , int index){
        // base case
        if(elements == 0 && target == 0){
            ans.push_back(part);
            return;
        }
        for(int i=index ; i<10 ; i++){
            part.push_back(i);
            recursiveHelper(elements-1 , target-i , ans , part , i+1);
            part.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>part;

        recursiveHelper(k , n , ans , part , 1);
        return ans;
    }
};