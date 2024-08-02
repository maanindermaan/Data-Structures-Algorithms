#include<iostream>
#include<stack>

using namespace std;
int main(){

return 0;
}

// 1. Using stacks
class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        string ans = "";

        for(char c : s){
            if(c == '('){
                if(!st.empty()){
                    ans += c;
                }
                st.push(c);
            }
            else{
                st.pop();
                if(!st.empty()){
                    ans += c;
                }
            }
        }
        return ans;
    }
};

// 2. Using Vector 
string removeOuterParentheses(string s) {
        vector<char>vt;
        string ans = "";

        for(char c : s){
            if(c == '('){
                if(!vt.empty()){
                    ans += c;
                }
                vt.push_back(c);
            }
            else{
                vt.pop_back();
                if(!vt.empty()){
                    ans += c;
                }
            }
        }
        return ans;
    }