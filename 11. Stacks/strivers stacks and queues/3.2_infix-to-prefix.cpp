#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
    int priority(char ch) {
        if (ch == '^') {
            return 3;
        }
        else if (ch == '*' || ch == '/') {
            return 2;
        }
        else if (ch == '+' || ch == '-') {
            return 1;
        }
        return -1;
    }

    string infixToPrefix(string s) {
        string ans = "";
        stack<char> st;

        if (s.empty()) {
            return ans;
        }
        int i = 0;
        while (i < s.size()) {
            char ch = s[i];

            if (isalnum(ch)) {
                ans.push_back(ch);
            }
            else if (ch == '(') {
                st.push(ch);
            }
            else if (ch == ')') {
                while (!st.empty() && st.top() != '(') {
                    ans.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
            else {
                while (!st.empty() && priority(ch) < priority(st.top())) {
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

int main() {
    Solution sol;
    string infix = "(A+B)*C-D+F";
    reverse(infix.begin() , infix.end());
    for(int i=0 ; i<infix.size() ; i++){
        if(infix[i] == '('){
            infix[i] = ')';
        }
        else if(infix[i] == ')'){
            infix[i] = '(';
        }
    }
    string prefix = sol.infixToPrefix(infix);
    reverse(prefix.begin() , prefix.end());
    cout << "Infix expression: " << infix << endl;
    cout << "Postfix expression: " << prefix << endl;
    return 0;
}
