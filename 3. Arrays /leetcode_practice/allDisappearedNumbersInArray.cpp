#include<iostream>
using namespace std;
int main(){

return 0;
}
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int>arr(nums.size() , 0);
    vector<int>ans;
    for(int i=0 ; i<nums.size() ; i++){
        int index = nums[i]-1;
        arr[index] = nums[nums[i]-1];
    }
    for(int i=0 ; i<nums.size() ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    for(int i=0 ; i<nums.size() ; i++){
        if(arr[i] == 0){
            ans.push_back(i+1);
        }
    }
    return ans;
}
};
