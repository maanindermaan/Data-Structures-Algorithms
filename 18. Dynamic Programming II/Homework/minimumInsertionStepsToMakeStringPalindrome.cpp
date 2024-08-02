#include<iostream>
using namespace std;
int main(){

return 0;
}

class Solution {
public:

    int solveUsingSO(string& text1 , string& text2 , int i , int j){
        vector<int>next(text2.length()+1 , 0);
        vector<int>curr(text2.length()+1 , 0);


        for(int ind = text1.length()-1 ; ind>=0 ; ind--){
            for(int jnd = text2.length()-1 ; jnd>=0 ; jnd--){

                int ans = 0;
                
                if(text1[ind] == text2[jnd]){
                    ans = 1 + next[jnd+1];
                }
                else{
                    ans = max(curr[jnd+1] , next[jnd]);
                }
                curr[jnd] = ans;
            }
            // SHIFT MOST IMPORTANT
            next = curr;
        }
        return curr[j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int i = 0; 
        int j = 0;

        return solveUsingSO(text1 , text2 , i , j);
    }

    int longestPalindromeSubseq(string& s) {
        string text1 = s;

        reverse(s.begin() , s.end());

        string text2 = s;

        return longestCommonSubsequence(text1 , text2);
    }


    int minInsertions(string s) {
        int length_of_lcs = longestPalindromeSubseq(s);
        int length_of_string = s.size()-1;

        return (length_of_string - length_of_lcs)+1;
    }
};