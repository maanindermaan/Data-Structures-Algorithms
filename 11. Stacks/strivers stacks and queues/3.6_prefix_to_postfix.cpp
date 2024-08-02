#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

string postfixToInfix(string s) {
    stack<string> st;

    if (s.empty()) {
        return s;
    }
    int i = s.size()-1;
    while (i >= 0) {
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
            
            string con = t1+t2+ch;
            st.push(con);
        }
        i--;
    }

    return st.top();
}

int main() {
    string prefix = "/-AB*+DEF";
    
    string postfix = postfixToInfix(prefix);
    
    cout << "Infix expression: " << postfix << endl;
    
    return 0;
}
