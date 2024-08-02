#include <iostream>
using namespace std;

// 1. Using Recursion
int solveUsingRecursion(vector<int> &coins, int amount)
{
    // 1. Base Case
    if (amount == 0)
    {
        return 0;
    }
    if (amount < 0)
    {
        return INT_MAX; // int max jab bhi aaye samaj jao ki value -ve hui thi. We will apply condition ki jab bhi ans int max aaye matlab valid nahi hai or agar valid nahi hai to return -1
    }

    int mini = INT_MAX;

    // 2. Apply calls for every coin
    for (int i = 0; i < coins.size(); i++)
    {
        // 3. Recursive calls
        int ans = solveUsingRecursion(coins, amount - coins[i]);

        // 4. Valid ans
        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1); // +1 uske liye jisko minus kiya hai usko bhi consider krna padega
        }
    }
    return mini;
}

// 2. Using topDownApproach
int solveUsingTopDownApproach(vector<int> &coins, int amount, vector<int> &dp)
{
    // 1. Base Case
    if (amount == 0)
    {
        return 0;
    }
    if (amount < 0)
    {
        return INT_MAX; // int max jab bhi aaye samaj jao ki value -ve hui thi. We will apply condition ki jab bhi ans int max aaye matlab valid nahi hai or agar valid nahi hai to return -1
    }

    // step 3 : ans already exits or not
    if (dp[amount] != -1)
    {
        return dp[amount];
    }
    int mini = INT_MAX;

    // 2. Apply calls for every coin
    for (int i = 0; i < coins.size(); i++)
    {
        // 3. Recursive calls
        int ans = solveUsingTopDownApproach(coins, amount - coins[i], dp);

        // 4. Valid ans
        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1); // +1 uske liye jisko minus kiya hai usko bhi consider krna padega
        }
    }
    // step 2 : save ans in DP
    dp[amount] = mini;
    return dp[amount];
}

// 3. Using Bottom Up Approach
int solveUsingBottomUpApproach(vector<int> &coins, int amount)
{

    // step 1 : create dp array
    vector<int> dp(amount + 1, INT_MAX); // because we are storing min Number always so we take INT_MAX

    // step 2 : Base Case Update (dekho)

    dp[0] = 0;

    // step 3 : we are going from 0 to target(amount) by analysing from tree or topDown Approach
    // step 3 : check the range and flow of top down approach and code accordingly
    for (int i = 1; i <= amount; i++)
    { // becuase for i=0 base case is already there
        // i amount banane ke liye mujhe saare coins ki call marni hai
        for (int j = 0; j < coins.size(); j++)
        {
            // code uper se uthalao and change krdo dimag lagake
            // recursive calls ko dp se replace krdo
            // change recursion to dp
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX)
            {
                int ans = dp[i - coins[j]];
                dp[i] = min(dp[i], ans + 1);
            }
        }
    }
    return dp[amount];
}

// 3. Using Bottom Up Approach
int solveUsingBottomUpApproach2(vector<int> &coins, int amount)
{
    // step1: create dp array
    vector<int> dp(amount + 1, INT_MAX);
    // step2: base case dekho
    dp[0] = 0;
    // step3: check the range and flow of top down approach and code accordingly
    for (int target = 1; target <= amount; target++)
    {
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            if (target - coins[i] >= 0)
            {
                int ans = dp[target - coins[i]];
                if (ans != INT_MAX)
                {
                    mini = min(mini, 1 + ans);
                }
            }
        }
        dp[target] = mini;
    }
    return dp[amount];
}

int coinChange(vector<int> &coins, int amount)
{
    // 1.
    // int ans = solveUsingRecursion(coins , amount);
    // if(ans == INT_MAX){
    //     return -1;
    // }
    // else{
    //     return ans;
    // }

    // 2.
    // // step 1 : create dp array
    // vector<int> dp(amount + 1, -1);
    // int ans = solveUsingTopDownApproach(coins, amount, dp);
    // if (ans == INT_MAX)
    // {
    //     return -1;
    // }
    // else
    // {
    //     return ans;
    // }

    // 3.
    // int ans = solveUsingBottomUpApproach2(coins, amount);
    // if (ans == INT_MAX)
    // {
    //     return -1;
    // }
    // else
    // {
    //     return ans;
    // }
}

int main()
{
    vector<int> coins;
    coins.push_back(1);
    coins.push_back(2);
    coins.push_back(5);

    int amount = 11;

    cout << coinChange(coins, amount);
    return 0;
}