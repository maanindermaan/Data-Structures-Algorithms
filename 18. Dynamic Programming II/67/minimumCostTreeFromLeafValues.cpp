#include <iostream>
#include <vector>
#include <limits.h>
#include <map>
using namespace std;

int solveUsingRecursion(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right)
{
    // base case
    if (left == right)
        return 0;

    int ans = INT_MAX;

    for (int i = left; i < right; i++)
    {
        ans = min(ans,
                  maxi[{left, i}] * maxi[{i + 1, right}] + solveUsingRecursion(arr, maxi, left, i) + solveUsingRecursion(arr, maxi, i + 1, right));
    }
    return ans;
}

int solveUsingMem(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right, vector<vector<int>> &dp)
{
    // base case
    if (left == right)
        return 0;

    if (dp[left][right] != -1)
    {
        return dp[left][right];
    }

    int ans = INT_MAX;

    for (int i = left; i < right; i++)
    {
        ans = min(ans,
                  maxi[{left, i}] * maxi[{i + 1, right}] + solveUsingMem(arr, maxi, left, i, dp) + solveUsingMem(arr, maxi, i + 1, right, dp));
    }
    dp[left][right] = ans;
    return dp[left][right];
}


int solveUsingTab(vector<int> &arr, map<pair<int, int>, int> &maxi)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int left = n - 1; left >= 0; left--)
    {
        for (int right = 0; right <= n - 1; right++)
        {
            // BHULUNGA
            if (left >= right)
                continue;
            else
            {
                // valid range
                int ans = INT_MAX;

                for (int i = left; i < right; i++)
                {
                    ans = min(ans,
                              maxi[{left, i}] * maxi[{i + 1, right}] + dp[left][i] + dp[i + 1][right]);
                }
                dp[left][right] = ans;
            }
        }
    }
    return dp[0][n - 1];
}

int mctFromLeafValues(vector<int> &arr)
{
    map<pair<int, int>, int> maxi;
    // pre-computation
    for (int i = 0; i < arr.size(); i++)
    {
        // pair<int,int> p;
        // p.first = i;
        // p.second=i;
        // maxi[p] = arr[i];

        maxi[{i, i}] = arr[i];
        for (int j = i + 1; j < arr.size(); j++)
        { 
            maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
        }
    }
    int n = arr.size();

    // 1.
    // int ans = solveUsingRecursion(arr, maxi, 0, n - 1);

    // 2.
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    int ans = solveUsingMem(arr, maxi, 0, n - 1, dp);

    // 3.
    int ans = solveUsingTab(arr, maxi);
    return ans;
}

int main()
{
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(6);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(8);

    cout << mctFromLeafValues(arr);
    return 0;
}




// #include <iostream>
// #include <vector>
// #include <limits.h>
// #include <map>
// using namespace std;


// int solveUsingRecursion(vector<int>&arr , map<pair<int , int> , int>& maxi , int left , int right){
//     // base case
//     if(left == right){ // single node ke uper aagye i.e. leaf node hai
//         return 0; // hume leaf node ka sum toh store hi nahi karna toh return 0;
//     }

//     int ans = INT_MAX;
//     for(int i=left ; i<right; i++){
//         ans = min(ans , 
//         (maxi[{left , i}] * maxi[{i+1 , right}])
//         + solveUsingRecursion(arr , maxi , left , i)
//         + solveUsingRecursion(arr , maxi , i+1 , right));
//     }

//     return ans;
// }

// int solveUsingMem(vector<int>&arr , map<pair<int , int> , int>& maxi , int left , int right , vector<vector<int>>& dp){
//     // base case
//     if(left == right){ // single node ke uper aagye i.e. leaf node hai
//         return 0; // hume leaf node ka sum toh store hi nahi karna toh return 0;
//     }
//     if(dp[left][right] != -1){
//         return dp[left][right];
//     }
    

//     int ans = INT_MAX;
//     for(int i=left ; i<right; i++){
//         ans = min(ans , 
//         (maxi[{left , i}] * maxi[{i+1 , right}])
//         + solveUsingMem(arr , maxi , left , i , dp)
//         + solveUsingMem(arr , maxi , i+1 , right , dp));
//     }
//     dp[left][right] = ans;

//     return dp[left][right];
// }

// int solveUsingTab(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right)
// {
//     int n = arr.size();
//     vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

//     for (int l = n - 1; l >= 0; l--)
//     {
//         for (int r = 0; r <= n - 1; r++)
//         {
//             // BHULUNGA
//             if(l >= r){
//                 continue;
//             }
//             else{
//                 int ans = INT_MAX;
//                 for (int i = l; i < r; i++)
//                 {
//                     ans = min(ans,
//                             (maxi[{l, i}] * maxi[{i + 1, r}]) 
//                             + solveUsingMem(arr, maxi, l, i, dp) 
//                             + solveUsingMem(arr, maxi, i + 1, r, dp));
//                 }
//                 dp[l][r] = ans;
//             }
//         }
//     }
//     return dp[left][right];
// }

// int mctFromLeafValues(vector<int> &arr)
// {
//     map<pair<int , int> , int> maxi;

//     for(int i=0 ; i<arr.size() ; i++){
//         maxi[{i,i}] = arr[i];
//         for(int j = i+1 ; j<arr.size() ; j++){
//             maxi[{i,j}] = max(arr[j] , maxi[{i,j-1}]);
//         }
//     }
//     int n = arr.size();

//     // 1. Recursion
//     // int ans = solveUsingRecursion(arr, maxi, 0, n - 1);

//     // 2.
//     // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1)); // {left , right}. left->0->n and right n->0
//     // int ans = solveUsingMem(arr, maxi, 0, n - 1, dp);

//     // 3.
//     int ans = solveUsingTab(arr, maxi , 0 , n-1);
//     return ans;
// }

// int main()
// {
//     vector<int> arr;
//     arr.push_back(2);
//     arr.push_back(4);
//     arr.push_back(6);
//     arr.push_back(1);
//     arr.push_back(3);
//     arr.push_back(8);

//     cout << mctFromLeafValues(arr);
//     return 0;
// }




