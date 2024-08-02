#include<iostream>
using namespace std;
int main(){

return 0;
}

class Solution {
public:
    string expandAroundIndex(string s , int i , int j){
        while(i>=0 && j<s.size() && s[i] == s[j]){
            i--;
            j++;
        }
        return s.substr(i+1 , j-i-1);
    }

    string longestPalindrome(string s) {
        // using expand around index approach 
        string maxiglobal = "";
        string maxilocal = "";

        for(int i=0 ; i<s.size(); i++){
            string odd = expandAroundIndex(s , i , i); // aaa
            string even = expandAroundIndex(s , i , i+1); // ababac

            if(odd.size() > even.size()){
                maxilocal = odd;
            }
            else{
                maxilocal = even;
            }

            if(maxilocal.size() > maxiglobal.size()){
                maxiglobal = maxilocal;
            }
        }
        return maxiglobal;
    }
};