#include<iostream>
using namespace std;
int main(){
    
return 0;
}
// LIS USED HERE
class Solution {
public:
    // converting into lis array by taking each element as pivot
    int optimalBinarySolution(vector<int>&arr ,  vector<int>&lis){
        if(arr.size() == 0){
            return 0;
        }

        // starting mein 1 hi tha
        lis.push_back(1);
        vector<int>ans;

        // 1st element ko push krdiya maine
        ans.push_back(arr[0]);

        for(int i=1 ; i<arr.size() ; i++){
            // include case
            if(arr[i] > ans.back()){
                ans.push_back(arr[i]);
                lis.push_back(ans.size());
            }
            else{
                // replace case
                // finding index
                int index = lower_bound(ans.begin() , ans.end() , arr[i]) - ans.begin(); // lower bound format
                ans[index] = arr[i];
                lis.push_back(index + 1);
            }
        }
        return ans.size();
    }

    int minimumMountainRemovals(vector<int>& nums) {
        // make 2 vectors
        vector<int>lis , lds;
        // make lis and lds array by taking each element as pivot;

        optimalBinarySolution(nums , lis);
        reverse(nums.begin() , nums.end());
        optimalBinarySolution(nums , lds);

        // Now we have got out lds and list array;
        int max_mountain_size = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++){
            if(lis[i] == 1 || lds[nums.size()-i-1] == 1){
                // mountain valid nahi banega
                continue;
            }
            int initial = lis[i]+lds[nums.size()-i-1]-1;
            max_mountain_size = max(max_mountain_size , initial);
        }

        return nums.size() - max_mountain_size;
    }
};