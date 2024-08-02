#include<iostream>
using namespace std;
int main(){

return 0;
}

class Solution {
public:
// The below is trail 2

    int solve(vector<vector<int>>& env , int prev , int curr){
        // 1. base cases
        if(curr == env.size()){
            return 0;
        }

        // 2. include-exclude pattern
        int include = INT_MIN;
        // env prev ki width choti honi chahiye env curr ki width se
        // and
        // env prev ki height choti honi chahiye env curr ki height se
        if(prev == -1 || (env[prev][0] < env[curr][0] && env[prev][1] < env[curr][1])){
            include = 1 + solve(env , curr , curr+1);
        }
        int exclude = solve(env , prev , curr+1);

        return max(include , exclude);
    }


    int solveMemo(vector<vector<int>>& env , int prev , int curr , vector<vector<int>>&dp){
        // 1. base cases
        if(curr == env.size()){
            return 0;
        }
        if(dp[prev+1][curr] != -1){
            return dp[prev+1][curr];
        }

        // 2. include-exclude pattern
        int include = INT_MIN;
        // env prev ki width choti honi chahiye env curr ki width se
        // and
        // env prev ki height choti honi chahiye env curr ki height se
        if(prev == -1 || (env[prev][0] < env[curr][0] && env[prev][1] < env[curr][1])){
            include = 1 + solveMemo(env , curr , curr+1 , dp);
        }
        int exclude = solveMemo(env , prev , curr+1 , dp);

        dp[prev+1][curr] =  max(include , exclude);
        return dp[prev+1][curr];
    }

    static bool comp(vector<int>&a , vector<int>&b){
        // agar width barabar hai toh badi height wala aana chahiye
        if(a[0] == b[0]){
            return a[1] > b[1];
        }
        // otherwise sort width wise
        return a[0] < b[0];
    }

    int optimalBinarySolution(vector<vector<int>>&arr){
        // sort envelopes in increasing by width 
        // and if wi == wj , increasing by height

        sort(arr.begin() , arr.end() , comp);

        // RUN LIS ON HEIGHT PART ONLY
        if(arr.size() == 0){
            return 0;
        }

        vector<int>ans;

        // 1st element ko push krdiya maine
        ans.push_back(arr[0][1]);

        for(int i=1 ; i<arr.size() ; i++){
            // include case
            if(arr[i][1] > ans.back()){
                ans.push_back(arr[i][1]);
            }
            else{
                // replace case
                // finding index
                int index = lower_bound(ans.begin() , ans.end() , arr[i][1]) - ans.begin(); // lower bound format
                ans[index] = arr[i][1];
            }
        }
        return ans.size();
    }


    int maxEnvelopes(vector<vector<int>>& envelopes){
        // sort the vector
        sort(envelopes.begin() , envelopes.end());
        // return solve(envelopes , -1 , 0);

        // vector<vector<int>>dp(envelopes.size()+1 , vector<int>(envelopes.size()+1 , -1));
        // return solveMemo(envelopes , -1 , 0 , dp);

        return optimalBinarySolution(envelopes);
    }
};  