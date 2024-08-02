// LIS LONGEST INCREAING SUBSEQUENCE

// TLE -> optimise it accordinly
#include <iostream>
using namespace std;

bool check(vector<int> &a, vector<int> &b)
{
    if (b[0] < a[0] && b[1] < a[1])
        return true;
    else
        return false;
}

int solveUsingTabSO(vector<vector<int>> &arr)
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
            if (prev == -1 || check(arr[curr] , arr[prev]))
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

int maxRussianDolls(vector<vector<int>> &envelops)
{
    // 2. sort the 2D array
    sort(envelops.begin(), envelops.end()); // sorted according to first element of every corresponding array if no custom comprator is used
    
    // 3. Apply lis logic
    int ans = solveUsingTabSO(envelops);

    return ans;
}

int main()
{
    vector<vector<int>> envelops{
        {5 , 4},
        {6 , 4},
        {6 , 7},
        {2 , 3}}; // {width , height}

    cout << maxRussianDolls(envelops);
    return 0;
}





#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;



int lis(vector<int>& ans, int n) {
        if (n == 0) {
            return 0;
        }
        
        vector<int> result;
        result.push_back(ans[0]);
        
        for (int i = 1; i < n; i++) {
            if (ans[i] > result.back()) {
                result.push_back(ans[i]);
            }
            else {
                int index = lower_bound(result.begin(), result.end(), ans[i]) - result.begin();
                result[index] = ans[i];
            }
        }
        
        return result.size();
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // SORT THE VECTOR
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        
        vector<int> ans;
        for (auto i : envelopes) {
            ans.push_back(i[1]);
        }
        
        int n = ans.size();
        return lis(ans, n);
    }
    
int main()
{
    vector<vector<int>> envelops{
        {5 , 4},
        {6 , 4},
        {6 , 7},
        {2 , 3}}; // {width , height}

    cout << maxEnvelopes(envelops);
    return 0;
}

