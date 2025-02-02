#include<iostream>
using namespace std;
int main(){

return 0;
}

class Solution {
public:

    bool solve(string& s1, string& s2, string& s3 , int i , int j , int k){
        // base case
        if(i == s1.size() && j == s2.size() && k == s3.size()){
            return true;
        }
        bool flag = false;
        // now for s1 case
        if(i < s1.size() && s1[i] == s3[k]){
            flag = flag || solve(s1 , s2 , s3 , i+1 , j , k+1);
        }

        if(j < s2.size() && s2[j] == s3[k]){
            flag = flag || solve(s1 , s2 , s3 , i , j+1 , k+1);
        }

        return flag;
    }

    bool solveMemo(string& s1, string& s2, string& s3 , int i , int j , int k , vector<vector<vector<int>>>&dp){
        // base case
        if(i == s1.size() && j == s2.size() && k == s3.size()){
            return true;
        }

        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }
        
        bool flag = false;
        // now for s1 case
        if(i < s1.size() && s1[i] == s3[k]){
            flag = flag || solveMemo(s1 , s2 , s3 , i+1 , j , k+1 , dp);
        }

        // for s2 case
        if(j < s2.size() && s2[j] == s3[k]){
            flag = flag || solveMemo(s1 , s2 , s3 , i , j+1 , k+1 , dp);

        }

        dp[i][j][k] = flag;
        return dp[i][j][k];
    }

    int solveTab(string& s1, string& s2, string& s3){
        
        // base case
        vector<vector<vector<int>>>dp(s1.size()+1 , vector<vector<int>>(s2.size()+1 , vector<int>(s3.size()+1 , 0)));

        dp[s1.size()][s2.size()][s3.size()] = 1;


        for(int i = s1.size() ; i>=0 ; i--){
            for(int j = s2.size() ; j>=0 ; j--){
                for(int k = s3.size() ; k>=0 ; k--){

                    // baecasue humne uper base case mein khudse yeah daldia hai toh agar reach hogai so i dont wanna calculate this
                    if(i == s1.size() && j == s2.size() && k == s3.size()){
                        continue;
                    }

                    bool flag = false;
                    // now for s1 case
                    if(i < s1.size() && s1[i] == s3[k]){
                        flag = flag || dp[i+1][j][k+1];
                    }

                    // for s2 case
                    if(j < s2.size() && s2[j] == s3[k]){
                        flag = flag || dp[i][j+1][k+1];

                    }

                    dp[i][j][k] = flag;
                }
            }
        }
        return dp[0][0][0];
    }


    bool isInterleave(string s1, string s2, string s3) {
        // return solve(s1 , s2 , s3 , 0 , 0 , 0);

        // vector<vector<vector<int>>>dp(s1.size()+1 , vector<vector<int>>(s2.size()+1 , vector<int>(s3.size()+1 , -1)));

        // return solveMemo(s1 , s2 , s3 , 0 , 0 , 0 , dp);

        return solveTab(s1 , s2 , s3);
    }
};