// #include <iostream>
// #include <vector>
// using namespace std;

// int solveUsingRecursion(int weight[], int value[], int index, int capacity)
// {
//     // Base Case ->1 item
//     if (index == 0)
//     {
//         if (weight[index] <= capacity)
//         {
//             return value[index];
//         }
//         else
//         {
//             return 0;
//         }
//     }

//     // recursive case
//     int include = 0;
//     if (weight[index] <= capacity)
//     {
//         include = solveUsingRecursion(weight, value, index - 1, capacity - weight[index]) + value[index];
//     }
//     int exclude = solveUsingRecursion(weight, value, index - 1, capacity) + 0;

//     return max(include, exclude);
// }

// int solveUsingMem(int weight[], int value[], int index, int capacity, vector<vector<int>> &dp)
// {
//     // Base Case ->1 item
//     if (index == 0)
//     {
//         if (weight[index] <= capacity)
//         {
//             return value[index];
//         }
//         else
//         {
//             return 0;
//         }
//     }

//     if (dp[index][capacity] != -1)
//     {
//         return dp[index][capacity];
//     }

//     // recursive case
//     int include = 0;
//     if (weight[index] <= capacity)
//     {
//         include = solveUsingMem(weight, value, index - 1, capacity - weight[index], dp) + value[index];
//     }
//     int exclude = solveUsingMem(weight, value, index - 1, capacity, dp) + 0;

//     dp[index][capacity] = max(include, exclude);

//     return dp[index][capacity];
// }

// int solveUsingTabulation(int weight[], int value[], int index, int capacity)
// {
//     // Base Case ->1 item
//     vector<vector<int>> dp(index + 1, vector<int>(capacity + 1, 0));
//     // 0th row ke liye ye wala logic chalega i.e 0th row
//     for (int w = weight[0]; w <= capacity; w++)
//     {
//         if (weight[0] <= capacity)
//         {
//             dp[0][w] = value[0];
//         }
//         else
//         {
//             return 0;
//         }
//     }

//     for (int i = 1; i <= index; i++)
//     {
//         for (int j = 0; j <= capacity; j++)
//         {
//             int include = 0;
//             if (weight[i] <= j)
//             {
//                 include = dp[i - 1][j - weight[i]] + value[i];
//             }
//             int exclude = dp[i - 1][j] + 0;

//             dp[i][j] = max(include, exclude);

//         }
//     }
//     return dp[index][capacity];
// }


// int solveUsingTabulation(int weight[], int value[], int index, int capacity)
// {
//     // Base Case ->1 item
//     vector<vector<int>> dp(index + 1, vector<int>(capacity + 1, 0));
//     // 0th row ke liye ye wala logic chalega i.e 0th row
//     for (int w = weight[0]; w <= capacity; w++)
//     {
//         if (weight[0] <= capacity)
//         {
//             dp[0][w] = value[0];
//         }
//         else
//         {
//             return 0;
//         }
//     }

//     for (int i = 1; i <= index; i++)
//     {
//         for (int j = 0; j <= capacity; j++)
//         {
//             int include = 0;
//             if (weight[i] <= j)
//             {
//                 include = dp[i - 1][j - weight[i]] + value[i];
//             }
//             int exclude = dp[i - 1][j] + 0;

//             dp[i][j] = max(include, exclude);

//         }
//     }
//     return dp[index][capacity];
// }



// int solveUsingSpaceOptimisation(int weight[], int value[], int index, int capacity)
// {
//     vector<int> prev(capacity + 1);
//     vector<int> curr(capacity + 1);

//     // 0th row ke liye ye wala logic chalega i.e 0th row
//     for (int w = weight[0]; w <= capacity; w++)
//     {
//         if (weight[0] <= capacity)
//         {
//             prev[0] = value[0];
//         }
//         else
//         {
//             return 0;
//         }
//     }

//     for (int i = 1; i <= index; i++)
//     {
//         for (int j = 0; j <= capacity; j++)
//         {
//             int include = 0;
//             if (weight[i] <= j)
//             {
//                 include = prev[j - weight[i]] + value[i];
//             }
//             int exclude = prev[j] + 0;

//             curr[j] = max(include, exclude);

//         }
//     }
//     return curr[capacity];
// }
// int solveUsingSpaceOptimisationEXTREME(int weight[], int value[], int index, int capacity)
// {
//     vector<int> curr(capacity + 1);

//     // 0th row ke liye ye wala logic chalega i.e 0th row
//     for (int w = weight[0]; w <= capacity; w++)
//     {
//         if (weight[0] <= capacity)
//         {
//             curr[0] = value[0];
//         }
//         else
//         {
//             return 0;
//         }
//     }

//     for (int i = 1; i <= index; i++)
//     {
//         for (int j = capacity; j >=0 ; j--)
//         {
//             int include = 0;
//             if (weight[i] <= j)
//             {
//                 include = curr[j - weight[i]] + value[i];
//             }
//             int exclude = curr[j] + 0;

//             curr[j] = max(include, exclude);

//         }
//     }
//     return curr[capacity];
// }

// int main()
// {
//     int weight[] = {4, 5, 1};
//     int value[] = {1, 2, 3};
//     int n = 3;
//     int capacity = 4;

//     // 1
//     // int ans = solveUsingRecursion(weight, value, n - 1, capacity);

//     // 2
//     // vector<vector<int>>dp(n+1 , vector<int> (capacity+1 , -1));
//     // int ans = solveUsingMem(weight, value, n - 1, capacity, dp);

//     // 3
//     // int ans = solveUsingTabulation(weight, value, n, capacity);

//     // 4.
//     // int ans = solveUsingSpaceOptimisation(weight, value, n, capacity);

//     // 5.
//     int ans = solveUsingSpaceOptimisationEXTREME(weight, value, n, capacity);

//     cout << "Ans: " << ans << endl;
//     return 0;
// }




































#include <iostream>
#include <vector>
using namespace std;

// index-> here is index of last item
// You can do opposite as well. Ye n->0 (R->L) hai tum (L->R) banalo
int solveUsingRecursion(int weight[], int value[], int index, int capacity)
{
    // base case
    if(index == 0){
        if(weight[index] <= capacity){
            return value[index];
        }
        else{
            return 0;
        }
    }

    // recursive case
    int include = 0;
    if(weight[index] <= capacity){
        include = solveUsingRecursion(weight , value , index-1 , capacity - weight[index]) + value[index];
    }
    int exclude = solveUsingRecursion(weight , value , index-1 , capacity);

    return max(include , exclude);
}

int solveUsingMem(int weight[], int value[], int index, int capacity, vector<vector<int>> &dp)
{
    // base case
    if(index == 0){
        if(weight[index] <= capacity){
            return value[index];
        }
        else{
            return 0;
        }
    }

    if(dp[index][capacity] != -1){
        return dp[index][capacity];
    }

    // recursive case
    int include = 0;
    if(weight[index] <= capacity){
        include = solveUsingRecursion(weight , value , index-1 , capacity - weight[index]) + value[index];
    }
    int exclude = solveUsingRecursion(weight , value , index-1 , capacity);

    dp[index][capacity] = max(include , exclude);
    return dp[index][capacity];
}

int solveUsingTabulation(int weight[], int value[], int index, int capacity)
{
    vector<vector<int>>dp(index+1 , vector<int>(capacity+1 , 0));

    for(int w = weight[0] ; w <= capacity ; w++){
        if(weight[0] <= capacity){
            dp[0][w] = value[0];
        }
        else{
            dp[0][w] = 0;
        }
    }

    // 2. loops for index and capacity
    for(int i = 1 ; i <= index ; i++){
        for(int j = 0 ; j <= capacity ; j++){
            int include = 0;
            if(weight[i] <= j){
                include = dp[i-1][j - weight[i]] + value[i];
            }
            int exclude = dp[i-1][j];

            dp[i][j] = max(include , exclude);
        }
    }
    return dp[index][capacity];
}

int solveUsingSpaceOptimisation(int weight[], int value[], int index, int capacity)
{
    vector<int>prev(capacity+1 , 0);
    vector<int>curr(capacity+1 , 0);

    for(int w = weight[0] ; w <= capacity ; w++){
        if(weight[0] <= capacity){
            prev[w] = value[w];
        }
        else{
            prev[w] = 0;
        }
    }

    for(int i = 1 ; i <= index ; i++){
        for(int j = 0 ; j <= capacity ; j++){
            int include = 0;
            if(weight[i] <= j){
                include = prev[j - weight[i]] + value[i];
            }
            int exclude = prev[j];

            curr[j] = max(include , exclude);
        }
        prev = curr;
    }
    return curr[capacity];
}





int solveUsingSpaceOptimisationEXTREME(int weight[], int value[], int index, int capacity)
{
    vector<int>curr(capacity+1 , 0);

    for(int w = weight[0] ; w <= capacity ; w++){
        if(weight[0] <= capacity){
            curr[w] = value[w];
        }
        else{
            curr[w] = 0;
        }
    }

    for(int i = 1 ; i <= index ; i++){
        for(int j = 0 ; j <= capacity ; j++){
            int include = 0;
            if(weight[i] <= j){
                include = curr[j - weight[i]] + value[i];
            }
            int exclude = curr[j];

            curr[j] = max(include , exclude);
        }
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
    int ans = solveUsingTabulation(weight, value, n, capacity);

    // 4.
    // int ans = solveUsingSpaceOptimisation(weight, value, n, capacity);

    // 5.
    // int ans = solveUsingSpaceOptimisationEXTREME(weight, value, n, capacity);

    cout << "Ans: " << ans << endl;
    return 0;
}