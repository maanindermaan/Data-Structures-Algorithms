#include<iostream>
#include<stack>
using namespace std;
int main(){

return 0;
}

class Solution {
  public:
    int priority(char ch){
        if(ch == '^'){
            return 3;
        }    
        else if(ch == '*' || ch == '/'){
            return 2;
        }    
        else if(ch == '+' || ch == '-'){
            return 1;
        }    
        return -1;
    }
    
    
    string infixToPostfix(string s) {
        string ans = "";
        stack<char>st;
        
        if(s.empty()){
            return ans;
        }
        int i = 0;
        while(i<s.size()){
            char ch = s[i];
            
            if(isalnum(ch)){
                ans.push_back(ch);
            }
            
            else if(ch == '('){
                st.push(ch);
            }
            
            else if(ch == ')'){
                while(!st.empty() && st.top() != '('){
                    ans.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
            
            else{
                while(!st.empty() && priority(ch) <= priority(st.top())){
                    ans.push_back(st.top());
                    st.pop();
                }
                st.push(ch);
            }
            i++;
        }
        
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};