#include<iostream>
#include<vector>
using namespace std;
int main(){

return 0;
}

// 1.
class Solution {
  public:
    void recursiveHelper(vector<int>&arr , int n , vector<int>&ans , int sum , int index){
        // base case
        if(index == n){
            ans.push_back(sum);
            return;
        }
        
        // include
        recursiveHelper(arr , n , ans , sum+arr[index] , index+1);
        
        // exclude
        recursiveHelper(arr , n , ans , sum , index+1);
        
    }
  
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int>ans;
        recursiveHelper(arr , n , ans , 0 , 0);
        return ans;
    }
};