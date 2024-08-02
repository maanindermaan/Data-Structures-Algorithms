#include<iostream>
using namespace std;
int main(){

return 0;
}
class Solution {
public:

    vector<string> solve(string& s , unordered_map<string , bool>& dict , int i){
        if(i == s.size()){
            return {""};
        }
        vector<string>ans;
        string word;

        for(int j = i ; j<s.size() ; j++){
            // ek valid word banao pehle
            word.push_back(s[j]);
            // checking if this word is valid or not
            if(dict.find(word) == dict.end()){
                // nahi mila continue you word making process
                continue;
            }

            // agar ek valid word hai toh ab :-
            // mujhe right se bhi chahiye hoga
            // jitne digit aachuke hai usse aage se hi shuru karenge so j+1
            auto right = solve(s , dict , j+1);
            // ab iske right se ek ek krke uthao or use ans mein daldo
            for(auto eachRightPart : right){
                string endPart;
                if(eachRightPart.size()>0){
                    endPart = " " + eachRightPart;
                }
                ans.push_back(word + endPart);
            }
        }
        return ans;
    }

    // har i ke corresponding vector<string> banti hai vo saare combinations ko bana deti hai
    unordered_map<int ,vector<string>>dp;

    vector<string> solveDP(string& s , unordered_map<string , bool>& dict , int i){
        if(i == s.size()){
            return {""};
        }

        if(dp.find(i) != dp.end()){
            return dp[i];
        }

        vector<string>ans;
        string word;

        for(int j = i ; j<s.size() ; j++){
            // ek valid word banao pehle
            word.push_back(s[j]);
            // checking if this word is valid or not
            if(dict.find(word) == dict.end()){
                // nahi mila continue you word making process
                continue;
            }

            // agar ek valid word hai toh ab :-
            // mujhe right se bhi chahiye hoga
            // jitne digit aachuke hai usse aage se hi shuru karenge so j+1
            auto right = solveDP(s , dict , j+1);
            // ab iske right se ek ek krke uthao or use ans mein daldo
            for(auto eachRightPart : right){
                string endPart;
                if(eachRightPart.size()>0){
                    endPart = " " + eachRightPart;
                }
                ans.push_back(word + endPart);
            }
        }
        dp[i] = ans;
        return dp[i];
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // mujhe baar baar check karna padega word valid hai ya nahi toh ek unordered map banadete hai jo ki <string , bool> hoga , isse find karne emin asani hogi ki particular given word valid word hai ya nahi
        unordered_map<string , bool>dict;
        for(auto word : wordDict){
            dict[word] = 1;
        }
        // return solve(s , dict , 0);

        return solveDP(s , dict , 0 );
    }
};