#include <iostream>
#include <vector>
using namespace std;

// 1. Recursive Solution
int recSolve(int n)
{
    // base case
    if (n == 1 || n == 0)
    {
        return n;
    }
    int ans = recSolve(n - 1) + recSolve(n - 2);
    return ans;
}

// 2. Recursion + Memoisation
int topDownSolve(int n, vector<int> &dp)
{
    // base case
    if (n == 1 || n == 0)
    {
        return n;
    }

    // step3: check if ans ALREADY EXISTS
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // step2: replace ans with dp[n]
    dp[n] = topDownSolve(n - 1, dp) + topDownSolve(n - 2, dp);
    return dp[n];
}

// 3. tabulation method
int bottomUpSolve(int n)
{
    // step1: create a dp array
    vector<int> dp(n + 1, -1);

    // step2: observe base case in above solution
    dp[0] = 0;
    if (n == 0)
    {
        return dp[0];
    }

    dp[1] = 1;
    if (n == 1)
    {
        return dp[1];
    }

    // step3: topDown approach me n kaise travel krra h
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int spaceOptSOlve(int n)
{
    // step1 : base case replace array with variables
    int prev2 = 0;
    int prev1 = 1;
    int curr;

    if(n == 0){
        return prev2;
    }

    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int fib(int n)
{
    // 1.
    // int ans = recSolve(n);
    // return ans;

    // 2.
    // step : 1 -> create DP array
    // vector<int> dp(n + 1, -1);
    // int ans = topDownSolve(n, dp);
    // return ans;

    // 3.
    int ans = bottomUpSolve(n);
    return ans;

    // 4.
    // return spaceOptSOlve(n);
}

int main()
{
    int n = 10;
    cout << fib(10);

    return 0;
}