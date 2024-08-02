#include <iostream>
#include <vector>
using namespace std;

// exponential T.C.
bool solveUsingRecursion(int index, vector<int> &nums, int target)
{
    // base case
    int n = nums.size();
    if (index >= n)
    {
        return false;
    }

    if (target < 0)
    {
        return false;
    }
    if (target == 0)
    {
        return true;
    }

    // include-exclude
    bool include = 0;
    if (nums[index] <= target)
    {
        include = solveUsingRecursion(index + 1, nums, target - nums[index]);
    }
    bool exclude = solveUsingRecursion(index + 1, nums, target) + 0;

    return (exclude || include);
}

// O(n*m) T.C. and O(n*m) S.C.
bool solveUsingMem(int index, vector<int> &nums, int target, vector<vector<int>> &dp)
{
    // base case
    int n = nums.size();
    if (index >= n)
    {
        return false;
    }
    if (target < 0)
    {
        return false;
    }
    if (target == 0)
    {
        return true;
    }

    // checking if already exists
    if (dp[index][target] != -1)
    {
        return dp[index][target];
    }

    // include-exclude
    bool include = 0;
    if (nums[index] <= target)
    {
        include = solveUsingMem(index + 1, nums, target - nums[index], dp);
    }
    bool exclude = solveUsingMem(index + 1, nums, target, dp);

    dp[index][target] = exclude || include;

    return dp[index][target];
}

// O(n*m) T.C. and O(n*m) S.C.
bool solveUsingTabulation(vector<int> &nums, int target)
{
    int n = nums.size();

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    for (int i = 0; i < n; i++)
    {
        // row ->index , col -> target
        dp[i][0] = 1; // 0th col ke liye 1
    }
    // yha pe index n-1 and we are adding +1 in index below in inlcude. so it will become index = n-1+1 = n. So we existed n index in vector size
    // ulta loop chaladiya dono hi case mein
    for (int index = n - 1; index >= 0; index--)
    {
        for (int t = 1; t <= target; t++)
        {
            bool include = false;
            if (t - nums[index] >= 0)
            {
                include = dp[index + 1][t - nums[index]];
            }

            bool exclude = dp[index + 1][t];

            dp[index][t] = include || exclude;
        }
    }

    return dp[0][target]; // because ans n-1 se build hota hota 0 ki taraf aarha hai, see in
}

// O(n*m) T.C. and O(n ) S.C.
bool solveUsingTabulationSO(vector<int> &nums, int target)
{
    int n = nums.size();

    vector<int> curr(target+1  , 0);
    vector<int> next(target+1  , 0);

    next[0] = 1;
    
    for (int index = n - 1; index >= 0; index--) // uper ki taraf bhagrha hai next to current. so next = current
    {
        for (int t = 1; t <= target; t++)
        {
            bool include = false;
            if (t - nums[index] >= 0)
            {
                include = next[t - nums[index]];
            }

            bool exclude = next[t];

            curr[t] = include || exclude;
        }
        // shift most important
        next = curr; // we are going from n-1 to 0.
    }

    return curr[target]; 
}

bool solveUsingTabulationSOEXTREME(vector<int> &nums, int target)
{
    int n = nums.size();

    vector<int> next(target+1  , 0);

    next[0] = 1;
    
    for (int index = n - 1; index >= 0; index--) // uper ki taraf bhagrha hai next to current. so next = current
    {
        for (int t = 1; t <= target; t++)
        {
            bool include = false;
            if (t - nums[index] >= 0)
            {
                include = next[t - nums[index]];
            }

            bool exclude = next[t];

            next[t] = include || exclude;
        }
        // shift most important
    }

    return next[target]; 
}

bool canPartition(vector<int> &nums)
{
    // Find the total sum
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }

    // checking for odd case
    if (sum & 1)
    {
        return false;
    }

    // Calculate target from sum
    int target = sum / 2;
    int index = 0;

    // 1. Recursion
    // bool ans = solveUsingRecursion(index, nums, target);

    // 2. Top-Down Approach (Memoisation)
    // vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
    // bool ans = solveUsingMem(index, nums, target, dp);

    // 3. Bottom-Up Approach(Tabulation)
    // bool ans = solveUsingTabulation(nums, target);

    // 4. Space Optimatisation
    // bool ans = solveUsingTabulationSO(nums, target);
 
    // 5. Space Optimatisation Extreme
    bool ans = solveUsingTabulationSOEXTREME(nums, target);

    return ans;
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(11);
    nums.push_back(5);

    if (canPartition(nums))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
































// #include <iostream>
// #include <vector>
// using namespace std;

// bool solveUsingRecursionII(int index, int target, vector<int> &nums)
// {
//     // base case
//     int n = nums.size();
//     if (target < 0)
//     {
//         return false;
//     }
//     if (target == 0)
//     {
//         return true;
//     }
//     if (index >= n)
//     {
//         return false;
//     }

//     // include-exclude pattern
//     bool include = solveUsingRecursionII(index + 1, target - nums[index], nums);
//     bool exclude = solveUsingRecursionII(index + 1, target, nums);

//     return (include || exclude);
// }

// bool solveUsingMemII(int index, int target, vector<int> &nums, vector<vector<int>> &dp)
// {
//     // base case
//     int n = nums.size();
//     if (target < 0)
//     {
//         return false;
//     }
//     if (target == 0)
//     {
//         return true;
//     }
//     if (index >= n)
//     {
//         return false;
//     }
//     if (dp[index][target] != -1)
//     {
//         return dp[index][target];
//     }
//     // include-exclude pattern
//     bool include = solveUsingMemII(index + 1, target - nums[index], nums, dp);
//     bool exclude = solveUsingMemII(index + 1, target, nums, dp);

//     dp[index][target] = (include || exclude);

//     return dp[index][target];
// }

// bool solveUsingTabulationII(int index, int target, vector<int> &nums)
// {

//     vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, 0)); //{index(0->N) , target(target->0)}

//     // base case
//     int n = nums.size();
//     for (int i = 0; i < n; i++)
//     {
//         dp[i][0] = 1;
//     }

//     // Loops ulte chalenege
//     for (int i = n - 1; i >= 0; i--)
//     {
//         for (int j = 1; j <= target; j++)
//         {
//             bool include = false;
//             if (j - nums[i] >= 0)
//             {
//                 include = dp[i + 1][j - nums[i]];
//             }
//             bool exclude = dp[i + 1][j];

//             dp[i][j] = (include || exclude);
//         }
//     }
//     return dp[index][target];
// }

// bool solveUsingSOII(int index, int target, vector<int> &nums)
// {

//     vector<int> curr(target + 1, 0);
//     vector<int> next(target + 1, 0);

//     // base case
//     int n = nums.size();
//     curr[0] = 1;
//     next[0] = 1;

//     // Loops ulte chalenege
//     for (int i = n - 1; i >= 0; i--)
//     {
//         for (int j = 1; j <= target; j++)
//         {
//             bool include = false;
//             if (j - nums[i] >= 0)
//             {
//                 include = next[j - nums[i]];
//             }
//             bool exclude = next[j];

//             curr[j] = (include || exclude);
//         }
//         next = curr;
//     }
//     return curr[target];
// }


// bool solveUsingSOEXTREME(int index, int target, vector<int> &nums)
// {
//     vector<int> next(target + 1, 0);

//     // base case
//     int n = nums.size();
//     next[0] = 1;

//     // Loops ulte chalenege
//     for (int i = n - 1; i >= 0; i--)
//     {
//         for (int j = target; j >= 0; j--)
//         {
//             bool include = false;
//             if (j - nums[i] >= 0)
//             {
//                 include = next[j - nums[i]];
//             }
//             bool exclude = next[j];

//             next[j] = (include || exclude);
//         }
//         // next = curr;
//     }
//     return next[target];
// }

// bool partitionEqualSubsetSum(vector<int> &nums)
// {

//     int sum = 0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         sum += nums[i];
//     }
//     int target = sum / 2;
//     int index = 0;

//     // 1. Recursion
//     // return solveUsingRecursionII(index , target , nums);

//     // 2. Top-Down
//     // vector<vector<int>>dp(nums.size()+1 , vector<int>(target+1 , -1)); //{index(0->N) , target(N->0)}
//     // return solveUsingMemII(index , target , nums , dp);

//     // 3. Bottom-Up
//     // return solveUsingTabulationII(index , target , nums);

//     // 4. Space OPT
//     // return solveUsingSOII(index, target, nums);

//     // 5. Space OPT EXTREME
//     return solveUsingSOEXTREME(index, target, nums);
// }

// int main()
// {
//     vector<int> nums;
//     nums.push_back(1);
//     nums.push_back(5);
//     nums.push_back(11);
//     nums.push_back(5);

//     cout << partitionEqualSubsetSum(nums);
//     return 0;
// }