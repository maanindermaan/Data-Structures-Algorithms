#include <iostream>
using namespace std;

int solveUsingRecursion(string &a, string &b, int i, int j)
{
    //  base case
    if (i == a.length())
    {
        return b.length() - j;
    }

    if (j == b.length())
    {
        return a.length() - i;
    }

    int ans = 0;
    // char match condition, agar match kargya toh dono iterators ko aage badado
    if (a[i] == b[j])
    {
        ans = solveUsingRecursion(a, b, i + 1, j + 1);
    }
    // char doesnot match condition
    else
    {
        // nahi match kiya toh yeah teen operations aise perform honge
        // operations perform kardo
        int insert = 1 + solveUsingRecursion(a, b, i, j + 1);
        int deleted = 1 + solveUsingRecursion(a, b, i + 1, j);
        int replace = 1 + solveUsingRecursion(a, b, i + 1, j + 1);
        ans = min(insert, min(deleted, replace));
    }
    return ans;
}

int solveUsingMem(string &a, string &b, int i, int j, vector<vector<int>> &dp)
{

    // base case
    if (i == a.length())
    {
        return b.length() - j;
    }

    if (j == b.length())
    {
        return a.length() - i;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    if (a[i] == b[j])
    {
        ans = solveUsingMem(a, b, i + 1, j + 1, dp);
    }
    else
    {
        // operation perform karo
        int insert = 1 + solveUsingMem(a, b, i, j + 1, dp);
        int deleted = 1 + solveUsingMem(a, b, i + 1, j, dp);
        int replace = 1 + solveUsingMem(a, b, i + 1, j + 1, dp);
        ans = min(insert, min(deleted, replace));
    }
    dp[i][j] = ans;
    return dp[i][j];
}

int solveUsingTab(string a, string b)
{
    vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));

    for (int j = 0; j <= b.length(); j++)
    {
        dp[a.length()][j] = b.length() - j;
    }

    for (int i = 0; i <= a.length(); i++)
    {
        dp[i][b.length()] = a.length() - i;
    }

    for (int i = a.length() - 1; i >= 0; i--)
    {
        for (int j = b.length() - 1; j >= 0; j--)
        {
            int ans = 0;
            if (a[i] == b[j])
            {
                ans = dp[i + 1][j + 1];
            }
            else
            {
                // operation perform karo
                int insert = 1 + dp[i][j + 1];
                int deleted = 1 + dp[i + 1][j];
                int replace = 1 + dp[i + 1][j + 1];
                ans = min(insert, min(deleted, replace));
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

int solveUsingTabSO(string a, string b)
{
    vector<int>next (b.length()+1 , 0);
    vector<int>curr (b.length()+1 , 0);

    for (int j = 0; j <= b.length(); j++)
    {
        next[j] = b.length() - j;
    }

    for (int i = a.length() - 1; i >= 0; i--)
    {
        // every row starts here
        // Yha galti karoge
        curr[b.length()] = a.length() - i;
        for (int j = b.length() - 1; j >= 0; j--)
        {
            int ans = 0;
            if (a[i] == b[j])
            {
                ans = next[j + 1];
            }
            else
            {
                // operation perform karo
                int insert = 1 + curr[j + 1];  // i -> current row
                int deleted = 1 + next[j];  // i+1 ->next row
                int replace = 1 + next[j + 1];
                ans = min(insert, min(deleted, replace));
            }
            curr[j] = ans;
        }
        // shift we are going up
        next = curr;
    }
    return next[0];
}
int minDistance(string word1, string word2)
{
    if (word1.length() == 0)
        return word2.length();

    if (word2.length() == 0)
        return word1.length();
    int i = 0;
    int j = 0;

    // 1.
    // return solveUsingRecursion(word1, word2, i, j);

    // 2.
    // vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
    // return solveUsingMem(word1, word2, i, j, dp);

    // 3.
    return solveUsingTab(word1, word2);
}

int main()
{
    string word1 = "horse";
    string word2 = "ros";

    cout << minDistance(word1, word2);
    return 0;
}

// practice
// #include <iostream>
// using namespace std;

// int solveUsingRecursion(string &a, string &b, int i, int j)
// {
//     // base case
//     // i pura traverse ho chuka hai
//     if (i == a.length())
//     {
//         return b.length() - j;
//     }
//     if (j == b.length())
//     {
//         return a.length() - i;
//     }

//     // recursive case
//     int ans = 0;
//     if (a[i] == b[j])
//     {
//         ans = solveUsingRecursion(a, b, i + 1, j + 1);
//     }
//     else
//     {
//         int inserted = 1 + solveUsingRecursion(a, b, i, j + 1);
//         int deleted = 1 + solveUsingRecursion(a, b, i + 1, j);
//         int replaced = 1 + solveUsingRecursion(a, b, i + 1, j + 1);

//         ans = min(inserted, min(deleted, replaced));
//     }
//     return ans;
// }

// int solveUsingMem(string &a, string &b, int i, int j, vector<vector<int>> &dp)
// {
//     if (i == a.length())
//     {
//         return b.length() - j;
//     }
//     if (j == b.length())
//     {
//         return a.length() - i;
//     }
//     if (dp[i][j] != -1)
//     {
//         return dp[i][j];
//     }

//     // recursive case
//     int ans = 0;
//     if (a[i] == b[j])
//     {
//         ans = solveUsingMem(a, b, i + 1, j + 1, dp);
//     }
//     else
//     {
//         int inserted = 1 + solveUsingMem(a, b, i, j + 1, dp);
//         int deleted = 1 + solveUsingMem(a, b, i + 1, j, dp);
//         int replaced = 1 + solveUsingMem(a, b, i + 1, j + 1, dp);

//         ans = min(inserted, min(deleted, replaced));
//     }

//     dp[i][j] = ans;
//     return dp[i][j];
// }

// int solveUsingTab(string a, string b, int i, int j)
// {
//     vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, -1));

//     // base case
//     for (int col = 0; col < b.length(); col++)
//     {
//         dp[a.length()][col] = b.length() - j;
//     }
//     for (int row = 0; row < a.length(); row++)
//     {
//         dp[row][b.length()] = a.length() - i;
//     }

//     for (int row = a.length() - 1; row >= 0; row--)
//     {
//         for (int col = b.length() - 1; col >= 0; col--)
//         {
//             int ans = 0;
//             if (a[row] == b[col])
//             {
//                 ans = dp[row + 1][col + 1];
//             }
//             else
//             {
//                 int inserted = 1 + dp[row][col + 1];
//                 int deleted = 1 + dp[row + 1][col];
//                 int replaced = 1 + dp[row + 1][col + 1];

//                 ans = min(inserted, min(deleted, replaced));
//             }

//             dp[row][col] = ans;
//         }
//     }
//     return dp[i][j];
// }

// int solveUsingTabSO(string a, string b, int i, int j)
// {
//     vector<int> curr(b.length() + 1, 0);
//     vector<int> next(b.length() + 1, 0);

//     // base case
//     for (int col = 0; col < b.length(); col++)
//     {
//         next[col] = b.length() - j;
//     }

//     for (int row = a.length() - 1; row >= 0; row--)
//     {
//         curr[b.length()] = a.length()-i;
//         for (int col = b.length() - 1; col >= 0; col--)
//         {
//             int ans = 0;
//             if (a[row] == b[col])
//             {
//                 ans = next[col + 1];
//             }
//             else
//             {
//                 int inserted = 1 + curr[col + 1];
//                 int deleted = 1 + next[col];
//                 int replaced = 1 + next[col + 1];

//                 ans = min(inserted, min(deleted, replaced));
//             }

//             curr[col] = ans;
//         }
//         // shift
//         next = curr; 
//     }
//     return curr[j];
// }
// int minDistance(string word1, string word2)
// {
//     if (word1.length() == 0)
//         return word2.length();

//     if (word2.length() == 0)
//         return word1.length();
//     int i = 0;
//     int j = 0;

//     // 1.
//     // return solveUsingRecursion(word1, word2, i, j);

//     // 2.
//     // vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
//     // return solveUsingMem(word1, word2, i, j, dp);

//     // 3.
//     // return solveUsingTab(word1, word2, i, j);

//     // 4.
//     return solveUsingTabSO(word1, word2, i, j);
// }

// int main()
// {
//     string word1 = "horse";
//     string word2 = "ros";

//     cout << minDistance(word1, word2);
//     return 0;
// }