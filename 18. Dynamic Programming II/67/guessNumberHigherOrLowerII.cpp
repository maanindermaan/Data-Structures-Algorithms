#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int solveUsingRecursion(int start, int end)
{
    // base case
    if (start >= end)
    {
        // single element hoga tab bhi penality nhi lgegi
        return 0;
    }

    int ans = INT_MAX;

    for (int i = start; i <= end; i++)
    {
        ans = min(ans, i + max(solveUsingRecursion(start, i - 1), solveUsingRecursion(i + 1, end)));
    }

    return ans;
}

// t.c -> O(n3)(worst) s.c ->O(n2)
int solveUsingMemo(int start, int end, vector<vector<int>> &dp)
{
    // base case
    if (start >= end)
    {
        // single element hoga tab bhi penality nhi lgegi
        return 0;
    }
    if (dp[start][end] != -1)
    {
        return dp[start][end];
    }

    int ans = INT_MAX;

    for (int i = start; i <= end; i++)
    {
        ans = min(ans, i + max(solveUsingMemo(start, i - 1, dp), solveUsingMemo(i + 1, end, dp)));
    }
    dp[start][end] = ans;
    return dp[start][end];
}

// t.c -> O(n3) s.c ->O(n2)
int solveUsingTab(int start, int end)
{
    vector<vector<int>> dp(end + 2, vector<int>(end + 2, 0)); // {start , end}; {start = 0->N ; end = N->0}
    // base case
    // No need as 0 is already there

    for (int s = end; s >= 1; s--)
    {
        for (int e = 1; e <= end; e++)
        {
            // base case
            if (s >= e)
            {
                continue;
            }
            else
            {
                int ans = INT_MAX;
                for (int i = s; i <= e; i++)
                {
                    ans = min(ans, i + max(dp[s][i - 1], dp[i + 1][e]));
                }
                dp[s][e] = ans;
            }
        }
    }
    return dp[start][end];
}

int solveUsingTabII(int n)
{
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int start = n; start >= 1; start--)
    {
        for (int end = 1; end <= n; end++)
        {

            //    BHULUNGA
            if (start >= end)
                continue;
            else
            {
                int ans = INT_MAX;
                for (int i = start; i <= end; i++)
                {
                    ans = min(ans, i + max(dp[start][i - 1], dp[i + 1][end]));
                }
                dp[start][end] = ans;
            }
        }
    }
    return dp[1][n];
}

int getMoneyAmount(int n)
{
    // 1. Recursion
    // return solveUsingRecursion(1,n);

    // 2. Memoisation
    // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1)); // {start , end}; {start = 0->N ; end = N->0}
    // return solveUsingMemo(1, n, dp);

    // 2. Tabulation
    // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1)); // {start , end}; {start = 0->N ; end = N->0}
    // return solveUsingTab(1, n);

    // 3. Tabulation other way
    return solveUsingTabII(n);
}

int main()
{
    int n = 10;
    cout << getMoneyAmount(n);
    return 0;
}










// #include <iostream>
// #include <vector>
// #include <limits.h>
// using namespace std;

// int solveUsingRecursion(int start, int end)
// {
//     // base case
//     if (start >= end)
//     {
//         return 0;
//     }

//     // recursive case
//     int ans = INT_MAX;
//     for (int i = start; i <= end; i++)
//     {
//         ans = min(ans, i + max(solveUsingRecursion(start, i - 1), solveUsingRecursion(i + 1, end)));
//     }
//     return ans;
// }

// int solveUsingMemo(int start, int end, vector<vector<int>> &dp)
// {
//     // base case
//     if (start >= end)
//     {
//         return 0;
//     }
//     if (dp[start][end] != -1)
//     {
//         return dp[start][end];
//     }

//     // recursive case
//     int ans = INT_MAX;
//     for (int i = start; i <= end; i++)
//     {
//         ans = min(ans, i + max(solveUsingMemo(start, i - 1, dp), solveUsingMemo(i + 1, end, dp)));
//     }
//     dp[start][end] = ans;
//     return dp[start][end];
// }

// int solveUsingTab(int start, int end)
// {

//     vector<vector<int>> dp(end + 2, vector<int>(end + 2, 0));

//     for (int s = end; s >= 1; s--) // 0 case already handled
//     {
//         for (int e = 1; e <= end; e++)
//         {
//             // BHULUNGA
//             if (s >= e)
//             {
//                 continue;
//             }
//             else
//             {
//                 // recursive case
//                 int ans = INT_MAX;
//                 for (int i = s; i <= e; i++)
//                 {
//                     ans = min(ans, i + max((dp[s][i - 1]), dp[i + 1][e]));
//                 }
//                 dp[s][e] = ans;
//             }
//         }
//     }
//     return dp[start][end];
// }

// int getMoneyAmount(int n)
// {
//     // 1. Recursion
//     // return solveUsingRecursion(1,n);

//     // 2. Memoisation
//     // vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1)); // {start , end};
//     // return solveUsingMemo(1 , n , dp);

//     // 3. Tabulation
//     return solveUsingTab(1, n);
// }

// int main()
// {
//     int n = 10;
//     cout << getMoneyAmount(n);
//     return 0;
// }