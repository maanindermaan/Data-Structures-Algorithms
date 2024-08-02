// 0 index se shuru hone wali saari subarray (incomplete)
#include <iostream>
#include <vector>
using namespace std;

void printSubarray(vector<int>& nums , int s , int e){
    // base case
    if(e>=nums.size()){
        return;
    }
    
    // one solution
    for(int i=s ; i<=e ; i++){
        cout<<nums[i];
    }
    cout<<endl;
    
    // recursive call
    printSubarray(nums , s , e+1);
}

int main() {
    vector<int>nums{1,2,3,4,5};
    printSubarray(nums , 0 , 0);

    return 0;
}

// rest and all (complete)
#include <iostream>
#include <vector>
using namespace std;

void printSubarrayUtil(vector<int>& nums , int s , int e){
    // base case
    if(e>=nums.size()){
        return;
    }
    
    // one solution
    for(int i=s ; i<=e ; i++){
        cout<<nums[i];
    }
    cout<<endl;
    
    // recursive call
    printSubarrayUtil(nums , s , e+1);
}

void printSubarray(vector<int>&nums){
    for(int start = 0; start < nums.size() ; start ++){
        int end = start;
        printSubarrayUtil(nums , start , end);
    }
}

int main() {
    vector<int>nums{1,2,3,4,5};
    printSubarray(nums);

    return 0;
}