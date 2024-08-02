#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solve(vector<int>&arr , int rodLength){
    // Base Case
    if(rodLength == 0){
        return 0; // 0 banane ke liye 0 elements hi lagenege
    }
    if(rodLength < 0){
        return INT_MIN;
    }

    // ek case solve krdo baaki recursion smabhal lega
    int maxi = INT_MIN;
    for(int i=0 ; i<arr.size() ; i++){
        int ans = solve(arr , rodLength - arr[i]);
        if(ans != INT_MIN)
        maxi = std::max(maxi, ans + 1);
    }

    return maxi;
}

int main(){
    vector<int>arr{5,2,2};
    int rodLength = 7;

    int ans = solve(arr , rodLength);
    cout<<"The answer is : "<<ans;
return 0;
}
