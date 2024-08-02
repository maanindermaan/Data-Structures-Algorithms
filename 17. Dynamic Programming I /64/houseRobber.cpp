#include <iostream>
using namespace std;

// 1. Using Recursion
// n -> represents the index of current house
int solveUsingRecursion(vector<int> &nums, int n) // n is last index
{
    // 1. Base Case
    if (n < 0)
        return 0;
    if (n == 0)
    {
        return nums[0];
    }

    // include-exclude case
    int include = solveUsingRecursion(nums, n - 2) + nums[n]; // humne nums[n] mein include kiya hai
    int exclude = solveUsingRecursion(nums, n - 1) + 0;       // in exclude we donot add anything

    return max(include, exclude);
}

// solveUsingTopDownApproach
int solveUsingMemoisation(vector<int> &nums, int n, vector<int> &dp)
{
    // 1. Base Case
    if (n < 0)
        return 0;
    if (n == 0)
    {
        return nums[0];
    }
    // step 3 : Check if already present
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // include-exclude case
    int include = solveUsingMemoisation(nums, n - 2, dp) + nums[n]; // humne nums[n] mein include kiya hai
    int exclude = solveUsingMemoisation(nums, n - 1, dp) + 0;       // in exclude we donot add anything

    // step 2 : Store in dp array
    dp[n] = max(include, exclude);
    return dp[n];
}

// 3. Using Tabulation (Bottom Up Approach)
int solveUsingTabulation(vector<int> &nums, int n)
{
    // step 1 : create dp array
    vector<int> dp(n + 1, 0); // maximum chahiye to ya to use INT_MIN or use 0

    // step 2 : Base Case Update
    dp[0] = nums[0];

    // step 3 : topDown mein n->0 isme 0->n;
    for (int i = 1; i <= n; i++)
    {
        // change recursion to dp
        int include = dp[i - 2] + nums[i]; // i is traversing over n
        int exclude = dp[i - 1] + 0;
        dp[i] = max(include, exclude);
    }
    return dp[n];
}

// 3. Using Tabulation (Bottom Up Approach)-> CORRECTED
int solveUsingTabulation2(vector<int> &nums, int n)
{
    // step 1 : create dp array
    vector<int> dp(n + 1, 0); // maximum chahiye to ya to use INT_MIN or use 0

    // step 2 : Base Case Update
    dp[0] = nums[0];

    // step 3 : topDown mein n->0 isme 0->n;
    for (int i = 1; i <= n; i++)
    {
        // change recursion to dp

        int temp = 0;
        if (i - 2 >= 0)
            temp = dp[i - 2];

        int include = temp + nums[i];
        int exclude = dp[i - 1] + 0;
        dp[i] = max(include, exclude);
    }
    return dp[n];
}

// 4. Using spaceOptimisedSolution
int spaceOptimisedSolution(vector<int> &nums, int n)
{
    int prev2 = 0;
    int prev1 = nums[0];
    int curr = 0;

    for (int i = 1; i <= n; i++)
    {
        // replace dp with prev
        int temp = 0;
        if (i - 2 >= 0)
            temp = prev2;

        int include = temp + nums[i];
        int exclude = prev1 + 0;
        curr = max(include, exclude);

        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int rob(vector<int> &nums)
{
    // // 1. Using recursion
    // int n = nums.size() - 1;
    // return solveUsingRecursion(nums, n);

    // 2. Using Memiosation (Top Down Approach)
    // int n = nums.size() - 1;
    // // step 1 : create dp array
    // vector<int> dp(n + 1, -1);
    // return solveUsingMemoisation(nums, n, dp);

    // // 3. Using Tabulation (Bottom Up Approach)
    // int n = nums.size() - 1;
    // return solveUsingTabulation2(nums, n);

    // 3. Using Space Optimisation
    int n = nums.size() - 1;
    return spaceOptimisedSolution(nums, n);
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);

    cout << rob(nums);
    return 0;
}