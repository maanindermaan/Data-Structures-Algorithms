#include <iostream>
#include <vector>
using namespace std;

int solveUsingRecursion(int n, int k, int target)
{
    // Base Case
    if (n == 0 && target == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    if (n != 0 && target == 0)
    {
        return 0;
    }
    if (n == 0 && target != 0)
    {
        return 0;
    }

    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += solveUsingRecursion(n - 1, k, target - i);
    }
    return ans;
}

int solveUsingMem(int n, int k, int target, vector<vector<int>> &dp) // n->0 && target->0
{
    // Base Case
    if (n == 0 && target == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    if (n != 0 && target == 0)
    {
        return 0;
    }
    if (n == 0 && target != 0)
    {
        return 0;
    }

    if (dp[n][target] != -1)
    {
        return dp[n][target];
    }

    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        if ((target - i) >= 0)
        {
            ans += solveUsingMem(n - 1, k, target - i, dp); // going from n->0 and target->0
        }
    }
    dp[n][target] = ans;
    return dp[n][target];
}

int solveUsingTabulation(int n, int k, int target) // ulta loop 0/1->n && 0/1 -> target {forward loop}
{
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    // base case
    dp[0][0] = 1; // { n , target}

    for (int index = 1; index <= n; index++) // n
    {
        for (int t = 1; t <= target; t++) // target
        {

            int ans = 0;
            for (int faces = 1; faces <= k; faces++)
            {
                if ((t - faces) >= 0)
                {
                    ans += dp[index - 1][t - faces]; // going from n->0 and target->0
                }
            }
            dp[index][t] = ans;
        }
    }
    return dp[n][target];
}

int solveUsingTabulationSO(int n, int k, int target)
{
    vector<int> prev(target + 1, 0);
    vector<int> curr(target + 1, 0);
    // base case

    prev[0] = 1; // { n , target}
    curr[0] = 1; // { n , target}

    for (int index = 1; index <= n; index++) // n
    {
        for (int t = 1; t <= target; t++) // target
        {

            int ans = 0;
            for (int faces = 1; faces <= k; faces++)
            {
                if ((t - faces) >= 0)
                {
                    ans += prev[t - faces]; // going from n->0 and target->0
                }
            }
            curr[t] = ans;
        }
        // shfiting-> after one loop in 2D. before one loop we can't shift
        prev = curr;
    }
    return curr[target];
}


int solveUsingTabulationSOEXTREME(int n, int k, int target)
{
    vector<int> curr(target + 1, 0);
    // base case

    curr[0] = 1; // { n , target}

    for (int index = 1; index <= n; index++) // n
    {
        for (int t = target ; t >= 0; t--) // target, ulta loop if single array
        {

            int ans = 0;
            for (int faces = 1; faces <= k; faces++)
            {
                if ((t - faces) >= 0)
                {
                    ans += curr[t - faces]; // going from n->0 and target->0
                }
            }
            curr[t] = ans;
        }
        // No shifting
    }
    return curr[target];
}

int numRollsToTarget(int n, int k, int target)
{
    // 1. Using Recursion
    // return solveUsingRecursion(n , k , target);

    // 2. Using Memoisation
    // vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    // return solveUsingMem(n, k, target, dp);

    // 3. Using tabulation
    // return solveUsingTabulation(n, k, target);

    // 4. Using Space Optimisation
    // return solveUsingTabulationSO(n, k, target);

    // 5. Using Space Optimisation Extreme
    return solveUsingTabulationSOEXTREME(n, k, target);
}

int main()
{
    int n = 2;
    int k = 6;
    int target = 7;

    int ans = numRollsToTarget(n, k, target);
    cout << ans;
    return 0;
}