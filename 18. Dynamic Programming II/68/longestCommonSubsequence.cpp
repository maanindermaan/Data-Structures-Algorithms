#include <iostream>
#include <vector>
using namespace std;

int solveUsingRecursion(string a, string b, int i, int j)
{
    if (i == a.length())
    {
        return 0;
    }
    if (j == b.length())
    {
        return 0;
    }

    int ans = 0;
    if (a[i] == b[j])
    {
        ans = 1 + solveUsingRecursion(a, b, i + 1, j + 1);
    }
    else
    {
        ans = 0 + max(solveUsingRecursion(a, b, i, j + 1), solveUsingRecursion(a, b, i + 1, j));
    }
    return ans;
}

int solveUsingMem(string &a, string &b, int i, int j, vector<vector<int>> &dp)
{
    if (i == a.length())
    {
        return 0;
    }
    if (j == b.length())
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans = 0;
    if (a[i] == b[j])
    {
        ans = 1 + solveUsingMem(a, b, i + 1, j + 1 , dp);
    }
    else
    {
        ans = 0 + max(solveUsingMem(a, b, i, j + 1 , dp), solveUsingMem(a, b, i + 1, j , dp));
    }
    dp[i][j] = ans;
    return dp[i][j];
}

int solveUsingTab(string &a, string &b, int i, int j)
{
    vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));

    for (int row = a.length() - 1; row >= 0; row--)
    {
        for (int col = b.length() - 1; col >= 0; col--)
        {
            int ans = 0;
            if (a[row] == b[col])
            {
                ans = 1 + dp[row + 1][col + 1];
            }
            else
            {
                ans = 0 + max(dp[row][col + 1], dp[row + 1][col]);
            }
            dp[row][col] = ans;
        }
    }
    return dp[i][j];
}

int solveUsingSO(string &a, string &b, int i, int j)
{
    vector<int> next(b.length() + 1, 0);
    vector<int> curr(b.length() + 1, 0);

    for (int row = a.length() - 1; row >= 0; row--)
    {
        for (int col = b.length() - 1; col >= 0; col--)
        {
            int ans = 0;
            if (a[row] == b[col])
            {
                ans = 1 + next[col + 1];
            }
            else
            {
                ans = 0 + max(curr[col + 1], next[col]);
            }
            curr[col] = ans;
        }
        // shift
        next = curr;
    }
    return curr[j];
}

int solveUsingSOEXTREME(string &a, string &b, int i, int j)
{
    vector<int> next(b.length() + 1, 0);

    for (int row = a.length() - 1; row >= 0; row--)
    {
        for (int col = b.length() - 1; col >= 0; col--)
        {
            int ans = 0;
            if (a[row] == b[col])
            {
                ans = 1 + next[col + 1];
            }
            else
            {
                ans = 0 + max(next[col + 1], next[col]);
            }
            next[col] = ans;
        }
        // shift
        // next = curr;
    }
    return next[j];
}

int maxLen(string text1, string text2)
{
    int i = 0;
    int j = 0;

    // 1.
    // return solveUsingRecursion(text1, text2, i, j);

    // 2.
    // vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
    // return solveUsingMem(text1, text2, i, j, dp);

    // 3.
    // return solveUsingTab(text1, text2, i, j);

    // 4.
    return solveUsingSO(text1, text2, i, j);
}

int main()
{
    string text1 = "abcde";
    string text2 = "acde";

    cout << maxLen(text1, text2);
    return 0;
}

// practice
// #include <iostream>
// #include <vector>
// using namespace std;

// int solveUsingRecursion(string a, string b, int i, int j)
// {
//     // Base case
//     if (i == a.length())
//     {
//         return 0;
//     }
//     if (j == b.length())
//     {
//         return 0;
//     }

//     int ans = 0;
//     if (a[i] == b[j])
//     {
//         ans = 1 + solveUsingRecursion(a, b, i + 1, j + 1);
//     }
//     else
//     {
//         ans = max(solveUsingRecursion(a, b, i, j + 1), solveUsingRecursion(a, b, i + 1, j));
//     }
//     return ans;
// }

// int solveUsingMem(string a, string b, int i, int j, vector<vector<int>> &dp)
// {
//     // Base case
//     if (i == a.length())
//     {
//         return 0;
//     }
//     if (j == b.length())
//     {
//         return 0;
//     }
//     if (dp[i][j] != -1)
//     {
//         return dp[i][j];
//     }

//     int ans = 0;
//     if (a[i] == b[j])
//     {
//         ans = 1 + solveUsingMem(a, b, i + 1, j + 1,dp);
//     }
//     else
//     {
//         ans = max(solveUsingMem(a, b, i, j + 1 , dp), solveUsingMem(a, b, i + 1, j , dp));
//     }
//     dp[i][j] = ans;
//     return dp[i][j];
// }

// int solveUsingTab(string a, string b, int i, int j) // i = 0->n amd j = 0->n
// {
//     vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));
//     // Base case
//     for (int row = a.length(); row >= 0; row--)
//     {
//         for (int col = b.length(); col >= 0; col--)
//         {
//             // jha jha i hai vha vha row and j ki jagah col
//             int ans = 0;
//             if (a[row] == b[col])
//             {
//                 ans = 1 + dp[row + 1][col + 1];
//             }
//             else
//             {
//                 ans = max(dp[row][col + 1], dp[row + 1][col]);
//             }
//             dp[row][col] = ans;
//         }
//     }
//     return dp[i][j];
// }

// int solveUsingSO(string a, string b, int i, int j)
// {
//     vector<int>curr(b.length()+1 , 0);
//     vector<int>next(b.length()+1 , 0);
    
//     for (int row = a.length(); row >= 0; row--)
//     {
//         for (int col = b.length(); col >= 0; col--)
//         {
//             // jha jha i hai vha vha row and j ki jagah col
//             int ans = 0;
//             if (a[row] == b[col])
//             {
//                 ans = 1 + next[col + 1];
//             }
//             else
//             {
//                 ans = max(curr[col + 1], next[col]);
//             }
//             curr[col] = ans;
//         }
//     }
//     return curr[j];
// }

// int maxLen(string text1, string text2)
// {
//     int i = 0;
//     int j = 0;

//     // 1.
//     // return solveUsingRecursion(text1, text2, i, j);

//     // 2.
//     // vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, -1));
//     // return solveUsingMem(text1, text2, i, j, dp);

//     // 3.
//     // return solveUsingTab(text1, text2, i, j);

//     // 4.
//     // return solveUsingSO(text1, text2, i, j);
// }

// int main()
// {
//     string text1 = "abcde";
//     string text2 = "acde";

//     cout << maxLen(text1, text2);
//     return 0;
// }