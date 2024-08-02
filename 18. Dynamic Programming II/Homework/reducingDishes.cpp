#include<iostream>
using namespace std;
int main(){

return 0;
}

class Solution {
public:

    int solve(vector<int>& satisfaction , int index , int time){
        if(index == satisfaction.size()){
            return 0;
        }

        // solving one case
        int includeLikeTime = time*satisfaction[index] + solve(satisfaction , index+1 , time+1);
        int excludeLikeTime = solve(satisfaction , index+1 , time);

        return max(includeLikeTime , excludeLikeTime);
    }

    int solveMemo(vector<int>& satisfaction , int index , int time , vector<vector<int>>&dp){
        if(index == satisfaction.size()){
            return 0;
        }
        if(dp[index][time] != -1){
            return dp[index][time];
        }

        // solving one case
        int includeLikeTime = time*satisfaction[index] + solveMemo(satisfaction , index+1 , time+1 , dp);
        int excludeLikeTime = solveMemo(satisfaction , index+1 , time , dp);

        dp[index][time] = max(includeLikeTime , excludeLikeTime);
        return dp[index][time];
    }

    int solveTab(vector<int>& satisfaction){
        vector<vector<int>>dp(satisfaction.size()+1 , vector<int>(satisfaction.size()+2 , 0));

        for(int index = satisfaction.size()-1 ; index>=0 ; index--){
            for(int time = satisfaction.size() ; time>=1 ; time--){

                int includeLikeTime = time*satisfaction[index] + dp[index+1][time+1];
                int excludeLikeTime = dp[index+1][time];
                dp[index][time] = max(includeLikeTime , excludeLikeTime);
            }
        }
        return dp[0][1];
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        // 1. sort it
        sort(satisfaction.begin() , satisfaction.end());

        // return solve(satisfaction , 0 , 1);

        // vector<vector<int>>dp(satisfaction.size()+1 , vector<int>(satisfaction.size()+1 , -1));
        // return solveMemo(satisfaction , 0 , 1 , dp);

        return solveTab(satisfaction);
    }
};