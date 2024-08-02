#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

string postfixToInfix(string s) {
    stack<string> st;

    if (s.empty()) {
        return s;
    }
    int i = 0;
    while (i < s.size()) {
        char ch = s[i];
        string initial = "";
        initial.push_back(ch);
        
        if (isalnum(ch)) {
            st.push(initial);
        }
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            
            string con = '(' + t2 + ch + t1 + ')';
            st.push(con);
        }
        i++;
    }

    return st.top();
}

int main() {
    string postfix = "AB-DE+F*/";
    
    string infix = postfixToInfix(postfix);
    
    cout << "Infix expression: " << infix << endl;
    
    return 0;
}
