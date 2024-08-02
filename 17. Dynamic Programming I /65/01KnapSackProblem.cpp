#include <iostream>
#include <vector>
using namespace std;

// index-> here is index of last item
// You can do opposite as well. Ye n->0 (R->L) hai tum (L->R) banalo
int solveUsingRecursion(int weight[], int value[], int index, int capacity)
{
    // Base Case ->1 item
    if (index == 0)
    {
        if (weight[index] <= capacity)
        {
            return value[index];
        }
        else
        {
            return 0;
        }
    }

    // inlcude-exclude
    int include = 0;
    if (weight[index] <= capacity)
    {
        include = solveUsingRecursion(weight, value, index - 1, capacity - weight[index]) + value[index];
    }
    int exclude = solveUsingRecursion(weight, value, index - 1, capacity) + 0;

    int ans = max(include, exclude);

    return ans;
}

int solveUsingMem(int weight[], int value[], int index, int capacity, vector<vector<int>> &dp)
{
    // Base Case ->1 item
    if (index == 0)
    {
        if (weight[index] <= capacity)
        {
            return value[index];
        }
        else
        {
            return 0;
        }
    }
    if (dp[index][capacity] != -1)
    {
        return dp[index][capacity];
    }

    // inlcude-exclude
    int include = 0;
    if (weight[index] <= capacity)
    {
        include = solveUsingMem(weight, value, index - 1, capacity - weight[index], dp) + value[index];
    }
    int exclude = solveUsingMem(weight, value, index - 1, capacity, dp) + 0;

    dp[index][capacity] = max(include, exclude);

    return dp[index][capacity];
}

int solveUsingTabulation(int weight[], int value[], int n, int capacity)
{
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    // 0th row ke liye ye wala logic chalega i.e 0th row
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            dp[0][w] = value[0];
        }
        else
        {
            dp[0][w] = 0;
        }
    }

    // reverse loops L->R. We choose R->L in topDown
    for (int index = 1; index < n; index++)
    {
        for (int wt = 0; wt <= capacity; wt++)
        {
            int include = 0;
            if (weight[index] <= wt)
            {
                include = dp[index - 1][wt - weight[index]] + value[index];
            }
            int exclude = dp[index - 1][wt] + 0;

            dp[index][wt] = max(include, exclude);
        }
    }
    return dp[n - 1][capacity];
}

int solveUsingSpaceOptimisation(int weight[], int value[], int n, int capacity)
{
    // we have to make two 1D arrays
    vector<int> prev(capacity + 1); // we are considering 0 as previous
    vector<int> curr(capacity + 1);

    // 0th row ke liye ye wala logic chalega i.e 0th row
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            prev[w] = value[0];
        }
        else
        {
            prev[w] = 0;
        }
    }

    // reverse loops L->R. We choose R->L in topDown
    for (int index = 1; index < n; index++)
    {
        for (int wt = 0; wt <= capacity; wt++)
        {
            int include = 0;
            if (weight[index] <= wt)
            {
                include = prev[wt - weight[index]] + value[index];
            }
            int exclude = prev[wt] + 0;

            curr[wt] = max(include, exclude);
        }
        // shift -> yha galti karunga bhar aayega ye loop ke
        prev = curr;
    }
    return curr[capacity];
}

int solveUsingSpaceOptimisationEXTREME(int weight[], int value[], int n, int capacity)
{
    // we will do this in single 1D array
    vector<int> curr(capacity + 1);

    // 0th row ke liye ye wala logic chalega i.e 0th row
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            curr[w] = value[0];
        }
        else
        {
            curr[w] = 0;
        }
    }

    // reverse loops L->R. We choose R->L in topDown
    for (int index = 1; index < n; index++)
    {
        for (int wt = capacity; wt >= 0; wt--)
        {
            int include = 0;
            if (weight[index] <= wt)
            {
                include = curr[wt - weight[index]] + value[index];
            }
            int exclude = curr[wt] + 0;

            curr[wt] = max(include, exclude);
        }
        // shift -> yha galti karunga bhar aayega ye loop ke
        curr = curr;
    }
    return curr[capacity];
}

int main()
{
    int weight[] = {4, 5, 1};
    int value[] = {1, 2, 3};
    int n = 3;
    int capacity = 4;

    // 1
    // int ans = solveUsingRecursion(weight, value, n - 1, capacity);

    // 2
    // Because of 2D dp. 2 parameters are changing index and capacity
    // vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
    // int ans = solveUsingMem(weight, value, n - 1, capacity, dp);

    // 3
    // int ans = solveUsingTabulation(weight, value, n, capacity);

    // 4.
    // int ans = solveUsingSpaceOptimisation(weight, value, n, capacity);

    // 5.
    int ans = solveUsingSpaceOptimisationEXTREME(weight, value, n, capacity);

    cout << "Ans: " << ans << endl;
    return 0;
}