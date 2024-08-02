#include <iostream>
#include <vector>
using namespace std;

// Exponential T.C.
int solveUsingRecursion(vector<int> &arr, int curr, int prev)
{
    // base case
    if (curr >= arr.size())
    {
        return 0;
    }
    // include
    int include = 0;
    if (prev == -1 || arr[curr] > arr[prev]) // koi bhi element nahi aaya hai abhi tak
    {
        include = 1 + solveUsingRecursion(arr, curr + 1, curr);
    }

    // exlclude
    int exclude = solveUsingRecursion(arr, curr + 1, prev);

    int ans = max(include, exclude);

    return ans;
}

// T.C. = O(N2) AND S.C. = O(N2) + O(N2)
int solveUsingMem(vector<int> &arr, int curr, int prev, vector<vector<int>> &dp)
{
    if (curr >= arr.size())
    {
        return 0;
    }

    if (dp[curr][prev + 1] != -1)
        return dp[curr][prev + 1];

    // include
    int include = 0;
    if (prev == -1 || arr[curr] > arr[prev])
        include = 1 + solveUsingMem(arr, curr + 1, curr, dp);

    // excude
    int exclude = 0 + solveUsingMem(arr, curr + 1, prev, dp);

    dp[curr][prev + 1] = max(include, exclude);
    return dp[curr][prev + 1];
}

// T.C. = O(N2) AND S.C. = O(N2)
int solveUsingTab(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            // include
            int include = 0;
            if (prev == -1 || arr[curr] > arr[prev])  // no need of prev+1 becuase at prev == -1 we are handling it in or condition
                include = 1 + dp[curr + 1][curr + 1]; // +1 for adjustment in col

            // excude
            int exclude = 0 + dp[curr + 1][prev + 1];

            dp[curr][prev + 1] = max(include, exclude);
        }
    }
    return dp[0][0];
}

// T.C. = O(N2) AND S.C. = O(N)
int solveUsingTabSO(vector<int> &arr)
{
    int n = arr.size();
    // vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
    vector<int> currRow(n + 1, 0);
    vector<int> nextRow(n + 1, 0);

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            // include
            int include = 0;
            if (prev == -1 || arr[curr] > arr[prev])
                include = 1 + nextRow[curr + 1];

            // excude
            int exclude = 0 + nextRow[prev + 1];

            currRow[prev + 1] = max(include, exclude);
        }
        // shift
        nextRow = currRow;
    }
    return nextRow[0];
}

// SOLTUION WITH T.C. = O(N * LOGN)

int solveOptimal(vector<int> &arr)
{
    if (arr.size() == 0){
        return 0;
    }
    vector<int> ans;
    ans.push_back(arr[0]);

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > ans.back()) // current element answer ke last element se bada hai
        {
            // include
            ans.push_back(arr[i]);
        }
        else
        {
            // replace
            // bada nahi hai toh
            // overwrite
            // find index of just bada element(GIVEN BY BINARY SEARCH)
            // we are using binary search
            // niche wali line just bade element ka index find out krke dega jisse aapko current element replace krna hai
            int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin(); // lowerbound cpp reference
            ans[index] = arr[i];
        }
    }
    return ans.size();
}

int lengthOfLIS(vector<int> &nums)
{
    int curr = 0;
    int prev = -1;

    // 1.
    // int ans = solveUsingRecursion(nums, curr, prev);

    // // 2.
    // int n = nums.size();
    // vector<vector<int> > dp(n, vector<int>(n+1, -1));
    // int ans = solveUsingMem(nums, curr, prev, dp);

    // 3.
    // int ans = solveUsingTab(nums);

    // 4.
    int ans = solveUsingTabSO(nums);
    return ans;
}

int main()
{
    vector<int> nums;
    nums.push_back(10);
    nums.push_back(9);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(7);
    nums.push_back(101);
    nums.push_back(18);

    cout << lengthOfLIS(nums);
    return 0;
}

// practice
// #include <iostream>
// #include <vector>
// using namespace std;

// // Exponential T.C.
// int solveUsingRecursion(vector<int> &arr, int curr, int prev)
// {
//     // base case
//     if (curr >= arr.size())
//     {
//         return 0;
//     }
//     int include = 0;
//     if (prev == -1 || arr[curr] > arr[prev])
//     {
//         include = 1 + solveUsingRecursion(arr, curr + 1, curr);
//     }

//     int exclude = solveUsingRecursion(arr, curr + 1, prev);

//     int ans = max(include, exclude);

//     return ans;
// }

// // T.C. = O(N2) AND S.C. = O(N2) + O(N2)
// int solveUsingMem(vector<int> &arr, int curr, int prev, vector<vector<int>> &dp)
// {
//     // prev = prev+1 in memo
//     // base case
//     if (curr >= arr.size())
//     {
//         return 0;
//     }
//     if (dp[curr][prev + 1] != -1)
//     {
//         return dp[curr][prev];
//     }
//     int include = 0;
//     if (prev == -1 || arr[curr] > arr[prev])
//     {
//         include = 1 + solveUsingMem(arr, curr + 1, curr, dp);
//     }

//     int exclude = solveUsingMem(arr, curr + 1, prev, dp);

//     int ans = max(include, exclude);

//     dp[curr][prev + 1] = ans;

//     return dp[curr][prev + 1];
// }

// // T.C. = O(N2) AND S.C. = O(N2)
// int solveUsingTab(vector<int> &arr, int curr, int prev)
// {
//     int n = arr.size();
//     vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

//     for (int current = n - 1; current >= 0; current--)
//     {
//         for (int previous = current - 1; previous >= -1; previous--)
//         {
//             int include = 0;
//             if (previous == -1 || arr[current] > arr[previous])
//             {
//                 include = 1 + dp[current + 1][current + 1];
//             }

//             int exclude = dp[current + 1][previous + 1];

//             int ans = max(include, exclude);

//             dp[current][previous + 1] = ans;
//         }
//     }
//     return dp[curr][prev + 1];
// }

// // // T.C. = O(N2) AND S.C. = O(N)
// // int solveUsingTabSO(vector<int> &arr, int curr, int prev)
// // {
// //     int n = arr.size();
// //     vector<int> currVector(n + 1, 0);
// //     vector<int> nextVector(n + 1, 0);

// //     for (int current = n - 1; current >= 0; current--)
// //     {
// //         for (int previous = current - 1; previous >= -1; previous--)
// //         {
// //             int include = 0;
// //             if (previous == -1 || arr[current] > arr[previous])
// //             {
// //                 include = 1 + nextVector[current + 1];
// //             }

// //             int exclude = nextVector[previous + 1];

// //             int ans = max(include, exclude);

// //             currVector[previous + 1] = ans;
// //         }
// //         // shifting 
// //         nextVector = currVector;
// //     }
// //     return currVector[prev + 1];
// // }

// // // SOLTUION WITH T.C. = O(N * LOGN)

// // int solveOptimal(vector<int> &arr)
// // {
// //     if(arr.size() == 0){
// //         return 0;
// //     }

// //     // push first element into ans array
// //     vector<int>ans;

// //     ans.push_back(arr[0]);

// //     // push rest of the elements as well
// //     for(int i=0 ; i<arr.size() ; i++){
// //         // include
// //         if(arr[i] > ans.back()){
// //             ans.push_back(arr[i]);
// //         }
// //         else{
// //             // replace by finding index
// //             int index = lower_bound(ans.begin() , ans.end() , arr[i])-ans.begin();
// //             ans[index] = arr[i];
// //         }
// //     }
// //     return ans.size();
// // }

// // int lengthOfLIS(vector<int> &nums)
// // {
// //     int curr = 0;
// //     int prev = -1;

// //     // 1.
// //     // int ans = solveUsingRecursion(nums, curr, prev);

// //     // // 2.
// //     // int n = nums.size();
// //     // vector<vector<int> > dp(n, vector<int>(n+1, -1));
// //     // int ans = solveUsingMem(nums, curr, prev, dp);

// //     // 3.
// //     // int ans = solveUsingTab(nums, curr, prev);

// //     // 4.
// //     int ans = solveUsingTabSO(nums, curr, prev);
// //     return ans;
// // }

// // int main()
// // {
// //     vector<int> nums;
// //     nums.push_back(10);
// //     nums.push_back(9);
// //     nums.push_back(2);
// //     nums.push_back(5);
// //     nums.push_back(3);
// //     nums.push_back(7);
// //     nums.push_back(101);
// //     nums.push_back(18);

// //     cout << lengthOfLIS(nums);
// //     return 0;
// // }