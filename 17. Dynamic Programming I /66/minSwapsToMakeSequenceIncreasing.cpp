#include<iostream>
using namespace std;

int solveUsingRecursion(int count , vector<int>& nums1 , vector<int>& nums2 , int i){
    // base case
    if(i < 0){
        return 0;
    }
    if(i >= nums1.size()){
        return 0;
    }

    // one case
    if(nums2[i] > nums2[i+1]){
        swap(nums1[i+1] , nums2[i+1]);
        solveUsingRecursion(count+1 , nums1 , nums2 , i);
    }

    return count;
}

int minSwap(vector<int>& nums1 , vector<int>& nums2){
    int count = 0;
    for(int i=0 ; i<nums1.size() ; i++){
        return solveUsingRecursion(count , nums1 , nums2 , i);
    }
}

int main(){
    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);
    nums1.push_back(8);

    vector<int> nums2;
    nums2.push_back(5);
    nums2.push_back(6);
    nums2.push_back(7);
    nums2.push_back(4);

    cout<<minSwap(nums1 , nums2);
return 0;
}