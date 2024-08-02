#include<iostream>
using namespace std;
int main(){

return 0;
}
class Solution {
public:

    int solveUsingRecursion(string& s1 , string &s2 , int i , int j){
        //base case
        int cost = 0;

        if(i==s1.size() || j == s2.size()){
            for(int x = i ; x<s1.size() ; x++){
                cost += s1[x];
            }
            for(int x = j ; x<s2.size() ; x++){
                cost += s2[x];
            }
        }
        // kuch bhi remove na karo
        else if(s1[i] == s2[j]){
            cost = solveUsingRecursion(s1 , s2 , i+1 , j+1);
        }
        else{
            // deleting string1's character
            int cost1 = s1[i] + solveUsingRecursion(s1 , s2 , i+1 , j);

            // deleting string2's character
            int cost2 = s2[j] + solveUsingRecursion(s1 , s2 , i , j+1);

            cost = min(cost1 , cost2);
        }
        return cost;
    }

    int solveUsingMemo(string& s1 , string &s2 , int i , int j , vector<vector<int>>&dp){
        //base case
        int cost = 0;

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i==s1.size() || j == s2.size()){
            for(int x = i ; x<s1.size() ; x++){
                cost += s1[x];
            }
            for(int x = j ; x<s2.size() ; x++){
                cost += s2[x];
            }
        }
        // kuch bhi remove na karo
        else if(s1[i] == s2[j]){
            cost = solveUsingMemo(s1 , s2 , i+1 , j+1 , dp);
        }
        else{
            // deleting string1's character
            int cost1 = s1[i] + solveUsingMemo(s1 , s2 , i+1 , j , dp);

            // deleting string2's character
            int cost2 = s2[j] + solveUsingMemo(s1 , s2 , i , j+1 , dp);

            cost = min(cost1 , cost2);
        }
        dp[i][j] = cost;
        return dp[i][j];
    }

    int solveUsingTab(string& s1 , string& s2){
        vector<vector<int>>dp(s1.size()+1 , vector<int>(s2.size()+1 , 0));
        // base case
        for(int i = s1.size()-1 ; i>=0 ; i--){
            dp[i][s2.size()] = s1[i] + dp[i+1][s2.size()];
        }
        for(int j = s2.size()-1 ; j>=0 ; j--){
            dp[s1.size()][j] = s2[j] + dp[s1.size()][j+1];
        }

        for(int i = s1.size()-1 ; i>=0 ; i--){
            for(int j = s2.size()-1 ; j>=0 ; j--){
                int cost = 0;
                if(s1[i] == s2[j]){
                    cost = dp[i+1][j+1];
                }
                else{
                    // deleting string1's character
                    int cost1 = s1[i] + dp[i+1][j];

                    // deleting string2's character
                    int cost2 = s2[j] + dp[i][j+1];

                    cost = min(cost1 , cost2);
                }
                dp[i][j] = cost;
            }
        }
        return dp[0][0];
    }

    int minimumDeleteSum(string s1, string s2) {
        // return solveUsingRecursion(s1,s2,0,0);

        // vector<vector<int>>dp(s1.size()+1 , vector<int>(s2.size()+1 , -1));
        // return solveUsingMemo(s1 , s2 , 0 , 0 , dp);

        return solveUsingTab(s1 , s2);
    }
};