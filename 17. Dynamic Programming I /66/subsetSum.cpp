#include <iostream>
#include <vector>
using namespace std;

bool solveUsingRecursion(int index, int sum, vector<int> &nums)
{
    // base case
    int n = nums.size();
    if (sum < 0)
    {
        return false;
    }
    if (sum == 0)
    {
        return true;
    }
    if (index >= n)
    {
        return false;
    }

    // include-exclude pattern
    bool include = solveUsingRecursion(index + 1, sum - nums[index], nums);
    bool exclude = solveUsingRecursion(index + 1, sum, nums);

    return (include || exclude);
}

bool solveUsingMem(int index, int sum, vector<int> &nums, vector<vector<int>> &dp)
{
    // base case
    int n = nums.size();
    if (sum < 0)
    {
        return false;
    }
    if (sum == 0)
    {
        return true;
    }
    if (index >= n)
    {
        return false;
    }
    if (dp[index][sum] != -1)
    {
        return dp[index][sum];
    }
    // include-exclude pattern
    bool include = solveUsingMem(index + 1, sum - nums[index], nums, dp);
    bool exclude = solveUsingMem(index + 1, sum, nums, dp);

    dp[index][sum] = (include || exclude);

    return dp[index][sum];
}

bool solveUsingTabulation(int index, int target, vector<int> &nums)
{

    vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, 0)); //{index(0->N) , target(target->0)}

    // base case
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    // Loops ulte chalenege
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j <= target; j++)
        {
            bool include = false;
            if (j - nums[i] >= 0)
            {
                include = dp[i + 1][j - nums[i]];
            }
            bool exclude = dp[i + 1][j];

            dp[i][j] = (include || exclude);
        }
    }
    return dp[index][target];
}

bool solveUsingSpaceOptimisation(int index, int target, vector<int> &nums)
{

    vector<int> curr(target + 1, 0);
    vector<int> next(target + 1, 0);

    // base case
    int n = nums.size();
    curr[0] = 1;
    next[0] = 1;

    // Loops ulte chalenege
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j <= target; j++)
        {
            bool include = 0;
            if (j - nums[i] >= 0)
            {
                include = next[j - nums[i]];
            }
            bool exclude = next[j];

            curr[j] = (include || exclude);
        }
        next = curr;
    }
    return curr[target];
}


bool solveUsingSpaceOptimisationEXTREME(int index, int target, vector<int> &nums)
{
    vector<int> next(target + 1, 0);

    // base case
    int n = nums.size();
    next[0] = 1;

    // Loops ulte chalenege
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = target; j >= 0; j--)
        {
            bool include = 0;
            if (j - nums[i] >= 0)
            {
                include = next[j - nums[i]];
            }
            bool exclude = next[j];

            next[j] = (include || exclude);
        }
        // next = curr;
    }
    return next[target];
}

bool isSubsetSum(vector<int> &arr , int sum)
{
    int index = 0;

    // 1. Recursion
    // return solveUsingRecursion(index , sum , arr);

    // // 2. Top-Down
    // vector<vector<int>>dp(arr.size()+1 , vector<int>(sum+1 , -1)); //{index(0->N) , sum(sum->0)}
    // return solveUsingMem(index , sum , arr , dp);

    // 3. Bottom-Up
    // return solveUsingTabulation(index , sum , arr);

    // 4. Space OPT
    // return solveUsingSpaceOptimisation(index, sum, arr);

    // 5. Space OPT EXTREME
    return solveUsingSpaceOptimisationEXTREME(index, sum, arr);
}

int main()
{
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(34);
    arr.push_back(4);
    arr.push_back(12);
    arr.push_back(5);
    arr.push_back(2);
    int sum = 9;

    cout << isSubsetSum(arr , sum);
    return 0;
}