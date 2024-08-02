#include<iostream>
using namespace std;
int main(){

return 0;
}
class Solution {
public:

    bool check(vector<string>& wordDict , string& s){
        for(auto i : wordDict){
            if(s == i){
                return true;
            }
        }
        return false;
    }

    bool solveUsingRecursion(string& s, vector<string>& wordDict , int start){
        // 1. base case
        if(start == s.size()){
            return true;
        }

        // 2. Ek case sambhal lo
        string word = "";
        bool flag = false;

        for(int i=start ; i<s.size() ; i++){
            word += s[i];
            if(check(wordDict , word)){
                // 3. Baaki recursion sambhal lega
                // word ko mujhe banate rehna hai
                flag = flag || solveUsingRecursion(s , wordDict , i+1);
            }
        }
        return flag;
    }

    bool solveUsingMemo(string& s, vector<string>& wordDict , int start , vector<int>&dp){
        // 1. base case
        if(start == s.size()){
            return true;
        }

        if(dp[start] != -1){
            return dp[start];
        }

        // 2. Ek case sambhal lo
        string word = "";
        bool flag = false;

        for(int i=start ; i<s.size() ; i++){
            word += s[i];
            if(check(wordDict , word)){
                // 3. Baaki recursion sambhal lega
                // word ko mujhe banate rehna hai
                flag = flag || solveUsingMemo(s , wordDict , i+1 , dp);
            }
        }
        dp[start] = flag;
        return dp[start];
    }

    bool solveUsingTab(string& s, vector<string>& wordDict){
        vector<int>dp(s.size()+1 , true);

        for(int start = s.size()-1 ; start >=0 ; start--){
            // 2. Ek case sambhal lo
            string word = "";
            bool flag = false;

            for(int i=start ; i<s.size() ; i++){
                word += s[i];
                if(check(wordDict , word)){
                    // 3. Baaki recursion sambhal lega
                    // word ko mujhe banate rehna hai
                    flag = flag || dp[i+1];
                }
            }
            dp[start] = flag;
        }
        return dp[0];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        // return solveUsingRecursion(s , wordDict , 0);

        // vector<int>dp(s.size() , -1);
        // return solveUsingMemo(s , wordDict , 0 , dp);

        return solveUsingTab(s , wordDict);
    }
};