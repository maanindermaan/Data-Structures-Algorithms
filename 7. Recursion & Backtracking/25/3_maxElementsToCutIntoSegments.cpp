#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

int solve(int rodLength , int x , int y , int z){
    // Base Case
    if(rodLength == 0){
        return 0;
    }
    if(rodLength < 0){
        return INT_MIN; // invalid soltuion
    }

    // Ek case solve karlo baaki recursion dekhlega;
    int ans1 = solve(rodLength-x , x , y , z) + 1;
    int ans2 = solve(rodLength-y , x , y , z) + 1;
    int ans3 = solve(rodLength-z , x , y , z) + 1;

    int maxi = max(ans1 , max(ans2 , ans3));

    return maxi;
}

int main(){
    int rodLength = 7;
    int x = 5;
    int y = 2;
    int z = 2;

    int ans = solve(rodLength , x , y , z);
    // Invalid ans
    if(ans<0){
        return 0;
    }
    cout<<"The maximum elements to cut into segments is : "<<ans;
return 0;
}