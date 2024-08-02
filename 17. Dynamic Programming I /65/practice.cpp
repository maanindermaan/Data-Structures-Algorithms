#include<iostream>
using namespace std;

int solveUsingRecursion(int n , int k){
    // 1. Base Case
    if(n==1){
        return k;
    }

    if(n==2){
        return k*k;
    }

    // Recursive relation
    int ans = (solveUsingRecursion(n-1 , k) + solveUsingRecursion(n-2 , k))*(k-1);

    return ans;
}

int solveUsingMem(int n , int k , vector<int>&dp){
    // 1. Base Case
    if(n==1){
        return k;
    }

    if(n==2){
        return k*k;
    }
    // step 2 : 
    if(dp[n] != -1){
        return dp[n];
    }

    // Recursive relation
    dp[n] = (solveUsingMem(n-1 , k , dp) + solveUsingMem(n-2 , k , dp))*(k-1);

    // step 3 : 
    return dp[n];
}





int solveUsingTab(int n , int k){
    // 1. Base Case
    vector<int> dp(n+1 , 0);

    dp[1] = k;
    dp[2] = k*k;

    for(int i=3 ; i<=n ; i++){
        dp[i] = (dp[i-1] + dp[i-2])*(k-1);
    }

    return dp[n];
}

int solveUsingSpace(int n , int k){
    // 1. Base Case

    int prev2 = k;
    int prev1 = k*k;
    int curr = 0;

    for(int i=3 ; i<=n ; i++){
        curr = (prev1 + prev2)*(k-1);
        prev2  = prev1;
        prev1 = curr;
    }

    return curr;
}

int main()
{
    int n = 4;
    int k = 3;
    // int ans  = solveUsingRecursion(n,k);

    // vector<int> dp(n + 1, -1);
    // int ans = solveUsingMem(n, k, dp);


    // int ans = solveUsingTab(n, k);


    int ans = solveUsingSpace(n, k);
    cout << ans;
    return 0;
}