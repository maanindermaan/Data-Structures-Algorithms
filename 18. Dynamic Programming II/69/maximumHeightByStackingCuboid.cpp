#include <iostream>
using namespace std;

bool check(vector<int> &a, vector<int> &b)
{
    if (b[0] <= a[0] && b[1] <= a[1] && b[2] <= a[2])
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
            if (prev == -1 || check(arr[curr], arr[prev]))
                include = arr[curr][2] + nextRow[curr + 1];

            // excude
            int exclude = 0 + nextRow[prev + 1];

            currRow[prev + 1] = max(include, exclude);
        }
        // shift
        nextRow = currRow;
    }
    return nextRow[0];
}

int maxHeight(vector<vector<int>> &cuboids)
{
    // 1. For height to be max -> sort every array
    for (auto &a : cuboids)
    {
        sort(a.begin(), a.end()); // sorting inside array
    }

    // 2. sort the 2D array
    sort(cuboids.begin(), cuboids.end()); // sorted according to first element of every corresponding array if no custom comprator is used

    // 3. Apply lis logic
    int ans = solveUsingTabSO(cuboids);

    return ans;
}

int main()
{
    vector<vector<int>> cuboids{
        {50, 45, 20},
        {95, 37, 53},
        {45, 23, 12}};

    cout << maxHeight(cuboids);
    return 0;
}




class Solution {
public:

bool check(vector<int>&a , vector<int>&b){
    if(a[0] >= b[0] && a[1] >= b[1] && a[2] >= b[2]){
        return true;
    }
    else{
        return false;
    }
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
            if (prev == -1 || check(arr[curr], arr[prev]))
                include = arr[curr][2] + nextRow[curr + 1];

            // excude
            int exclude = 0 + nextRow[prev + 1];

            currRow[prev + 1] = max(include, exclude);
        }
        // shift
        nextRow = currRow;
    }
    return nextRow[0];
}
    int maxHeight(vector<vector<int>>& cuboids) {

        // jo random the ab increasing order mein aagye hai
       for(auto &a : cuboids){
           sort(a.begin() , a.end());
       }

        // sort according to first element
       sort(cuboids.begin() , cuboids.end());

        // call function 
        return solveUsingTabSO(cuboids);
    }
};