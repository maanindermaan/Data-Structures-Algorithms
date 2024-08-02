#include <iostream>
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
        ans = 1 + solveUsingRecursion(a, b, i + 1, j + 1);
    }
    else
    {
        ans = 0 + max(solveUsingRecursion(a, b, i, j + 1), solveUsingRecursion(a, b, i + 1, j));
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

int longestPalindromicSubsequence(string s)
{

    // Normal string
    string first = s;
    reverse(s.begin(), s.end());

    // reversed string
    string second = s;

    //  call previous function
    int i = 0;
    int j = 0;

    // 1.
    // return solveUsingRecursion(first, second, i, j);

    // 2.
    // vector<vector<int>> dp(first.length(), vector<int>(second.length(), -1));
    // return solveUsingMem(first, second, i, j, dp);

    // 3.
    // return solveUsingTab(first, second, i, j);

    // 4.
    return solveUsingSO(first, second, i, j);
}

int main()
{
    string s = "abbccccbbadca";
    cout << longestPalindromicSubsequence(s);
    return 0;
}